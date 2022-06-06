#include <MPU6050_light.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <Servo.h>
#include <QMC5883LCompass.h>
#include "MLX90621.h"
#include <Pixy2.h>
#include <Servo.h>


LiquidCrystal_I2C lcd(0x27,16,2);

Servo servoLFT,//left front top     (range depan=47,  belakang=125) jangkauan = 78
      servoLFM,//left front middle  (range atas=39,   bawah=117)    jangkauan = 78
      servoLFB,//left front bottom  (range dalam=41,  luar=136)     jangkauan = 95
      
      servoLBT,//left back top      (range depan=58,  belakang=130) jangkauan = 72
      servoLBM,//left back middle   (range atas=35,   bawah=113)    jangkauan = 78
      servoLBB,//left back bottom   (range dalam=36,  luar=131)     jangkauan = 95
      
      servoRFT,//right front top    (range depan=128, belakang=50)  jangkauan = 78
      servoRFM,//right front middle (range atas=137,  bawah=59)     jangkauan = 78
      servoRFB,//right front bottom (range dalam=140, luar=45)      jangkauan = 95
      
      servoRBT,//right back top     (range depan=132, belakang=60)  jangkauan = 72
      servoRBM,//right back middle  (range atas=142,  bawah=64)     jangkauan = 78
      servoRBB,//right back bottom   (range dalam=140, luar=45)     jangkauan = 95
      servoTes
      ;

//servo top
int lftForward=60,  lftBackward=138,
    lbtForward=58,  lbtBackward=130,
    rftForward=128, rftBackward=50,
    rbtForward=132, rbtBackward=60,
    rftTegak, rbtTegak, 
    lftTegak, lbtTegak;

//servo middle
int lfmUp=39,   lfmDown=117,
    lbmUp=35,   lbmDown=113,
    rfmUp=136,  rfmDown=58,
//    rfmUp=137,  rfmDown=59, //nilai lama
    rbmUp=142,  rbmDown=64,
    rfmTegak,   rbmTegak, 
    lfmTegak,   lbmTegak;

//servo bottom
int lfbIn=41,   lfbOut=136,
    lbbIn=36,   lbbOut=131,
    rfbIn=140,  rfbOut=45,
    rbbIn=140,  rbbOut=45,
    lfbTegak,   lbbTegak,
    rfbTegak,   rbbTegak;

//posisi servo saat ini
int posisiLFT=0, posisiLFM=0, posisiLFB=0,
    posisiLBT=0, posisiLBM=0, posisiLBB=0,
    posisiRFT=0, posisiRFM=0, posisiRFB=0,
    posisiRBT=0, posisiRBM=0, posisiRBB=0;

//waktu delay perpindahan servo untuk 1 derajat
int delayWaktu=4;


//kompas
QMC5883LCompass compass;
int min_range_south, max_range_south, min_range_north, max_range_north, min_range_east, max_range_east, min_range_west, max_range_west;
int calibrationData[3][2];
bool changed = false;
bool done = false;
int t = 0;
int c = 0;

//pixy
#define ambil  0
#define letak  1
Pixy2 pixy;
Servo fire;

//Kamera termal
MLX90621 termal; // create an instance of the Sensor class


//IMU
MPU6050 mpu(Wire);


void setup() {
  Serial.begin(9600); //170ms a 19k2, 28ms a 115k2
  
  servoLFT.attach(44);  servoLFM.attach(46);  servoLFB.attach(6);
  servoLBT.attach(9);   servoLBM.attach(4);   servoLBB.attach(2);
  servoRFT.attach(7);   servoRFM.attach(10);  servoRFB.attach(8);  
  servoRBT.attach(3);   servoRBM.attach(5);   servoRBB.attach(12);

  lftTegak=lftForward + 43; lbtTegak=lbtForward + 32;
  rftTegak=rftForward - 43; rbtTegak=rbtForward - 32;
  
  lfmTegak=lfmUp + 50; lbmTegak=lbmUp + 50;
  rfmTegak=rfmUp - 50; rbmTegak=rbmUp - 50;

  lfbTegak=lfbIn + 51; lbbTegak=lbbIn + 51;
  rfbTegak=rfbIn - 51; rbbTegak=rbbIn - 51;


  //Inisiasi kamera termal
  termal.setRefreshRate(RATE_8HZ);
  termal.setResolution(RES_17bit);
  termal.setEmissivity(1.0);
  termal.initialize ();

  //Inisiasi lcd
  lcd.init();
  lcd.backlight();
  lcd.print("Start!");
  
  fire.attach(45);
  pixy.init();

  compass.init();

  //Close the grip
  pixy.setServos(500, 25);//berurut ke arah luar  (angkat, jepit), (angkat=0, turun=500), (jepit=25, buka=500)
//  pixy.setLamp(1, 0);
//  padam(200);

  
//IMU
  Wire.begin();
  mpu.begin();
  //Start calculating the offset
  delay(1000);
  lcd.clear();
  mpu.calcOffsets(true,true);

}





void loop() {
  lcd.clear();
  

//  for(int i=0; i<10; i++){
//    Padam(500);
//    delay(1000);
//  }
/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////Algorima rute/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
  Berdiri();
  delay(200);
  
  /**
   * robot menentukan hadap keluar home
   */
  RintanganHome();

  
  /**
   * Keadaan robot maju menelusuri jalan sebelum rintangan puing pertama
   * sampai robot menghadap puing
   * angkat 30 derajat sampai saat ini yang tercepat untuk maju
   * angkat 50 derajat untuk melewati puing
   */
  RintanganHomeMaju();


  /**
   * Robot melewati rintangan puing 1
   */
  RintanganPuing1();


  /**
   * Robot melalui rintangan naik-turun
   */
  NaikTurun();

  //Setelah selesai dengan rintangan naik-turun
  MenujuRoom1();

  //robot melalui rintangan puing 2
  RintanganPuing2();



  /**
   * Penyelamatan dan pemadaman
   */
      Berdiri();
      int apiAda=0, apiSuhu=45;
      double termalBaca=TermalMaxTemp();
  
      if (termalBaca>=apiSuhu){
        apiAda=1;
        lcd.setCursor(0,0);
        lcd.print(termalBaca); lcd.print(" api");
      }
      else {
        while(apiAda==0){
  
          int i=0;
          while(apiAda==0 && i<=30) {
            i++;
            ServoWrite("LFT", i);
            ServoWrite("RFT", -i);
            ServoWrite("LBT", i);
            ServoWrite("RBT", -i);
            termalBaca=TermalMaxTemp();
            delay(50);
            if (termalBaca>=apiSuhu) apiAda=1;
            lcd.clear();
            lcd.setCursor(0,0); lcd.print(termalBaca);lcd.print(i);

            lcd.setCursor(0,1); lcd.print("padam");
          }
  
          //memutar badan robot jika api masih belum ketemu pada saat pencarian sebelumnya
          if (apiAda==0){
            //majukan kaki kiri belakang bersamaan dengan menaikkannya
            ServoMovementDouble("LFT", 15, "LFM", 40);
            //majukan kaki kiri belakang bersamaan dengan menurunkannya
            ServoMovementDouble("LFT", 0, "LFM", 0);
            delay(50);
            
            //majukan kaki kiri belakang bersamaan dengan menaikkannya
            ServoMovementDouble("LBT", 15, "LBM", 40);
            //majukan kaki kiri belakang bersamaan dengan menurunkannya
            ServoMovementDouble("LBT", 0, "LBM", 0);
            delay(50);
    
            //majukan kaki kiri belakang bersamaan dengan menaikkannya
            ServoMovementDouble("RBT", -15, "RBM", 40);
            //majukan kaki kiri belakang bersamaan dengan menurunkannya
            ServoMovementDouble("RBT", 0, "RBM", 0);
            delay(50);
    
            //majukan kaki kiri belakang bersamaan dengan menaikkannya
            ServoMovementDouble("RFT", -15, "RFM", 40);
            //majukan kaki kiri belakang bersamaan dengan menurunkannya
            ServoMovementDouble("RFT", 0, "RFM", 0);
            delay(50);
            lcd.clear();
            lcd.setCursor(0,0); lcd.print(termalBaca);
            lcd.setCursor(0,1); lcd.print("padam");
          }
        }
      }
  
//      Padam(200);
    lcd.clear();
    lcd.print("Done");

    
  /**
   * robot kembali ke safe zone
    Berdiri();
    MajuAwal();
    while(Paralax("front")>30){
      MajuKanan(50);
      MajuKananDorong();
      MajuKiri(50);
      MajuKiriDorong();
    }
    compass.init();
    CompassCalibration(); 
    compass.read();
    InitAzimuth();
    AdjustRobotPositionSelatan();
    Grip(1);

*/



/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////Algorima stop/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
delay(10000000000000000000000);



//  Berdiri();
//
//  BerdiriNaik();
//
//  NaikMajuAwal();
//  while(Paralax("front")==0 || Paralax("front")>60){
//    NaikMajuKanan();
//    NaikMajuKananDorong();
//    NaikMajuKiri();
//    NaikMajuKiriDorong();
//  }
//
//    int par_ld, par_rd, par_r, par_l, par_f;
//    par_ld=Paralax("leftDiagonal");
//    par_rd=Paralax("rightDiagonal");
//    par_r=Paralax("right");
//    par_l=Paralax("left");
//    par_f=Paralax("front");
//    lcd.clear();
//
//    lcd.setCursor(0,0); lcd.print("LD");lcd.print(par_ld); lcd.print(" RD");lcd.print(par_rd);lcd.print(" R");lcd.print(par_r);
//    lcd.setCursor(0,1); lcd.print("L");lcd.print(par_l);lcd.print(" F");lcd.print(par_f);
//
//
//    delay(100000000);




//
//    Padam(500);

//    Berdiri();
//    MajuAwal();
//    while(Paralax("front")>30){
//      MajuKanan(50);
//      MajuKananDorong();
//      MajuKiri(50);
//      MajuKiriDorong();
//    }
//    compass.init();
//    CompassCalibration(); 
//    compass.read();
//    InitAzimuth();
//    AdjustRobotPositionSelatan();
//    Grip(1);




    
//    while(termalBaca<40){
//      lcd.setCursor(0,0); lcd.print(termalBaca);
//      for(int a=0;a<=30; a++){
//        ServoWrite("LFT", a);
//        ServoWrite("RFT", -a);
//        ServoWrite("LBT", a);
//        ServoWrite("RBT", -a);
//        termalBaca=TermalMaxTemp();
//        delay(1000);
//        lcd.clear();
//        lcd.setCursor(0,0); lcd.print(termalBaca);
//        lcd.setCursor(0,1); lcd.print(a);
//      }
      

    
//    if(termal.getMaxTemp()>=45){
//      lcd.setCursor(12, 1);lcd.print("api");
//    }
//    else{
//      lcd.setCursor(12, 1); lcd.print("   ");
//    }
//    delay(1000);


//    MajuAwal();
//    while((Paralax("front")==0 || Paralax("front")>60) && !(Paralax("left")==0 && Paralax("right")==0)){
//      MajuKanan(30);
//      MajuKananDorong();
//      MajuKiri(30);
//      MajuKiriDorong();
//    }
//  MenujuRoom1();
//  
//  Berdiri();
//
//  MundurAwal();
//  while(true){
//    MundurKiri(50);
//    MundurKiriDorong();
//    MundurKanan(50);
//    MundurKananDorong();


//    delay(100000000);

}
