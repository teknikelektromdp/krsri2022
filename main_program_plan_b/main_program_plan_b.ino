#include <MPU6050_light.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <Servo.h>
#include <QMC5883LCompass.h>
#include <MLX90621.h>
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
int kompasValue;//menyimpan nilai kompas

//paralax
int par_l, par_ld, par_f, par_rd, par_r, par_g, par_b;//menyimpan nilai paralax

String modeGerak;//menyimpan mode pergerakan

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
//  Serial.begin(9600); //170ms a 19k2, 28ms a 115k2

  //servo untuk kaki
  servoLFT.attach(44);  servoLFM.attach(46);  servoLFB.attach(6);
  servoLBT.attach(9);   servoLBM.attach(4);   servoLBB.attach(2);
  servoRFT.attach(7);   servoRFM.attach(10);  servoRFB.attach(8);  
  servoRBT.attach(3);   servoRBM.attach(5);   servoRBB.attach(12);
  //servo untuk CO2
  fire.attach(45);  fire.write(10); 

  lftTegak=lftForward + 43; lbtTegak=lbtForward + 32;
  rftTegak=rftForward - 43; rbtTegak=rbtForward - 32;
  
  lfmTegak=lfmUp + 50; lbmTegak=lbmUp + 50;
  rfmTegak=rfmUp - 50; rbmTegak=rbmUp - 50;

  lfbTegak=lfbIn + 51; lbbTegak=lbbIn + 51;
  rfbTegak=rfbIn - 51; rbbTegak=rbbIn - 51;


  //inisialisasi termal
  TermalSetup();
  
  //Inisiasi lcd
  LcdSetup();


  //inisialisasi kompas
  CompassSetup();

  //inisialisasi pixy
  pixy.init();
  //Close the grip
  pixy.setServos(500, 25);//berurut ke arah luar  (angkat, jepit), (angkat=0, turun=500), (jepit=25, buka=500)
//  pixy.setLamp(1, 0);
//  padam(200);

  
//IMU
//  Wire.begin();
//  mpu.begin();
//  //Start calculating the offset
//  delay(1000);
//  lcd.clear();
//  mpu.calcOffsets(true,true);

}





void loop() {
  lcd.clear();
  
  BacaSensor();
  LcdDisplay();


//  for(int i=0; i<10; i++){
//    Padam(500);
//    delay(1000);
//  }
/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////Algorima rute/////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
  Berdiri();

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
  //Robot menaiki tanjakan
  RintanganTanjakan();  
  
  //robot berada pada posisi puncak, kemudian menuruni rintangan
//  RintanganNaikTurunLama();
  RintanganNaikTurun();

  //Setelah selesai dengan rintangan naik-turun
  RintanganMenujuRoom1();

  //robot melalui rintangan puing 2
  RintanganPuing2();



  /**
   * Penyelamatan dan pemadaman
   */
  Pemadaman();

  
  Padam(300);
  delay(1000);
  Padam(300);

  KeluarRintanganPuing2();
  
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
}
