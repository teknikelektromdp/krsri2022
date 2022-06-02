#include <Servo.h>

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
      servoRBB//right back bottom   (range dalam=140, luar=45)      jangkauan = 95
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
    rfmTegak, rbmTegak, 
    lfmTegak, lbmTegak;

//servo bottom
int lfbIn=41,   lfbOut=136,
    lbbIn=36,   lbbOut=131,
    rfbIn=140,  rfbOut=45,
    rbbIn=140,  rbbOut=45,
    lfbTegak, lbbTegak,
    rfbTegak, rbbTegak;

//posisi servo saat ini
int posisiLFT=0, posisiLFM=0, posisiLFB=0,
    posisiLBT=0, posisiLBM=0, posisiLBB=0,
    posisiRFT=0, posisiRFM=0, posisiRFB=0,
    posisiRBT=0, posisiRBM=0, posisiRBB=0;


void setup() {
  servoLFT.attach(2);  servoLFM.attach(3);  servoLFB.attach(4);  
  servoLBT.attach(5);  servoLBM.attach(6);  servoLBB.attach(7);  
  servoRFT.attach(8);  servoRFM.attach(9);  servoRFB.attach(10);  
  servoRBT.attach(46);  servoRBM.attach(12);  servoRBB.attach(44);

  lftTegak=lftForward + 43; lbtTegak=lbtForward + 32;
  rftTegak=rftForward - 43; rbtTegak=rbtForward - 32;
  
  lfmTegak=lfmUp + 50; lbmTegak=lbmUp + 50;
  rfmTegak=rfmUp - 50; rbmTegak=rbmUp - 50;

  lfbTegak=lfbIn + 51; lbbTegak=lbbIn + 51;
  rfbTegak=rfbIn - 51; rbbTegak=rbbIn - 51;

}

void loop() {
  delay(1000);
  berdiri();
  delay(5000);


  int kondisi=0;

  while (kondisi==0){
    MajuKananBelakang();
    delay(50);
    MajuKiriDepan();
    delay(50);
    MajuKiriBelakang();
    delay(50);
    MajuKananDepan();
    delay(50);  
  }



  delay(10000);
}

void berdiri(){
  servoLFT.write(SudutReal("LFT",0));   servoRFT.write(SudutReal("RFT",0));
  servoLBT.write(SudutReal("LBT",0)); servoRBT.write(SudutReal("RBT",0));

  servoLFM.write(SudutReal("LFM",0));   servoRFM.write(SudutReal("RFM",0));
  servoLBM.write(SudutReal("LBM",0));   servoRBM.write(SudutReal("RBM",0));

  servoLFB.write(SudutReal("LFB",0));   servoRFB.write(SudutReal("RFB",0));
  servoLBB.write(SudutReal("LBB",0));   servoRBB.write(SudutReal("RBB",0));
}


/**
 * fungsi membatasi nilai minimum dan maksimum
 */
int NilaiBatas(int nilai, int nilaiMin, int nilaiMax){
  if (nilai>nilaiMax) nilai=nilaiMax;
  else if (nilai<nilaiMin) nilai=nilaiMin;
  return nilai;
}

/** 
 * fungsi mendapatkan sudut sebenarnya dari servo 
 * servoTujuan diisi dengan kode LFT, LBT, RFT, dst
 * nilai diisi dengan sudut yang diinginkan
 */
int SudutReal(String servoTujuan, int nilai) {
  int nilaiReal;
  
  if (servoTujuan.equals("LFT")) {//-35 s/d 43
    nilaiReal = (lftTegak - NilaiBatas(nilai, -35, 43));
  } else if (servoTujuan.equals("LBT")) {//-40 s/d 32
    nilaiReal = (lbtTegak - NilaiBatas(nilai, -40, 32));
  } else if (servoTujuan.equals("RFT")) {//-35 s/d 43
    nilaiReal = (rftTegak + NilaiBatas(nilai, -35, 43));
  } else if (servoTujuan.equals("RBT")) {//-40 s/d 32
    nilaiReal = (rbtTegak + NilaiBatas(nilai, -40, 32));
  } else if (servoTujuan.equals("LFM")) {//-28 s/d 50
    nilaiReal = (lfmTegak - NilaiBatas(nilai, -28, 50));
  } else if (servoTujuan.equals("LBM")) {//-28 s/d 50
    nilaiReal = (lbmTegak - NilaiBatas(nilai, -28, 50));
  } else if (servoTujuan.equals("RFM")) {//-28 s/d 50
    nilaiReal = (rfmTegak + NilaiBatas(nilai, -28, 50));
  } else if (servoTujuan.equals("RBM")) {//-28 s/d 50
    nilaiReal = (rbmTegak + NilaiBatas(nilai, -28, 50));
  } else if (servoTujuan.equals("LFB")) {//-51 s/d 44
    nilaiReal = (lfbTegak + NilaiBatas(nilai, -51, 44));
  } else if (servoTujuan.equals("LBB")) {//-51 s/d 44
    nilaiReal = (lbbTegak + NilaiBatas(nilai, -51, 44));
  } else if (servoTujuan.equals("RFB")) {//-51 s/d 44
    nilaiReal = (rfbTegak - NilaiBatas(nilai, -51, 44));
  } else if (servoTujuan.equals("RBB")) {//-51 s/d 44
    nilaiReal = (rbbTegak - NilaiBatas(nilai, -51, 44));
  } else {//kondisi error akan terjadi robot berdiri selama 2 detik
    berdiri();
    delay(2000);
  }
  return nilaiReal;
}

/**
 * fungsi untuk menggerakkan servo dan sekaligus menyimpan sudut servo saat ini
 */
void ServoWrite(String servoNama, int sudut) {
  Servo servoPakai;
  if (servoNama.equals("LFT")) {
    servoPakai=servoLFT;  posisiLFT=sudut;
  } else if (servoNama.equals("LFM")) {
    servoPakai=servoLFM;  posisiLFM=sudut;
  } else if (servoNama.equals("LFB")) {
    servoPakai=servoLFB;  posisiLFB=sudut;
  
  } else if (servoNama.equals("LBT")) {
    servoPakai=servoLBT;  posisiLBT=sudut;
  } else if (servoNama.equals("LBM")) {
    servoPakai=servoLBM;  posisiLBM=sudut;
  } else if (servoNama.equals("LBB")) {
    servoPakai=servoLBB;  posisiLBB=sudut;
  
  } else if (servoNama.equals("RFT")) {
    servoPakai=servoRFT;  posisiRFT=sudut;
  } else if (servoNama.equals("RFM")) {
    servoPakai=servoRFM;  posisiRFM=sudut;
  } else if (servoNama.equals("RFB")) {
    servoPakai=servoRFB;  posisiRFB=sudut;
  
  } else if (servoNama.equals("RBT")) {
    servoPakai=servoRBT;  posisiRBT=sudut;
  } else if (servoNama.equals("RBM")) {
    servoPakai=servoRBM;  posisiRBM=sudut;
  } else if (servoNama.equals("RBB")) {
    servoPakai=servoRBB;  posisiRBB=sudut;
  }
  
  servoPakai.write(SudutReal(servoNama,sudut));
}

/**
 * Fungsi menggerakkan servo dengan perlahan
 */
void ServoMovementSingle(String servoNama, int sudutBaru) {
  int sudutLama, pengali, jarak;
  
  sudutLama=PosisiServo(servoNama);

  if (sudutLama < sudutBaru) {
    jarak=sudutBaru-sudutLama;
    pengali=1;
  } else if (sudutLama > sudutBaru) {
    jarak=sudutLama-sudutBaru;
    pengali=-1;
  } else {//untuk sudutLama sama dengan sudutBaru
    jarak=0;
    pengali=1;
  }

  for (int i=1; i<=jarak; i++) {
    ServoWrite(servoNama, sudutLama + (pengali * i));
    delay(10);
  }
}

void ServoMovementDouble(String servoNama1, int sudutBaru1, String servoNama2, int sudutBaru2) {
  int sudutLama1, pengali1, jarak1,
      sudutLama2, pengali2, jarak2;
      
  sudutLama1=PosisiServo(servoNama1);
  sudutLama2=PosisiServo(servoNama2);

  if (sudutLama1 < sudutBaru1) {
    jarak1=sudutBaru1-sudutLama1;
    pengali1=1;
  } else if (sudutLama1 > sudutBaru1) {
    jarak1=sudutLama1-sudutBaru1;
    pengali1=-1;
  } else {//untuk sudutLama sama dengan sudutBaru
    jarak1=0;
    pengali1=1;
  }

  if (sudutLama2 < sudutBaru2) {
    jarak2=sudutBaru2-sudutLama2;
    pengali2=1;
  } else if (sudutLama2 > sudutBaru2) {
    jarak2=sudutLama2-sudutBaru2;
    pengali2=-1;
  } else {//untuk sudutLama sama dengan sudutBaru
    jarak2=0;
    pengali2=1;
  }

  for (int i=1; i<=jarak1; i++) {
    ServoWrite(servoNama1, sudutLama1 + (pengali1 * i));
    ServoWrite(servoNama2, sudutLama2 + (pengali2 * i));
    delay(10);
  }
}

/**
 * Fungsi mendapatkan sudut saat ini dari servo
 */
int PosisiServo(String servoNama) {
  if (servoNama.equals("LFT")) return posisiLFT;
  else if (servoNama.equals("LFM")) return posisiLFM;
  else if (servoNama.equals("LFB")) return posisiLFB;
  
  else if (servoNama.equals("LBT")) return posisiLBT;
  else if (servoNama.equals("LBM")) return posisiLBM;
  else if (servoNama.equals("LBB")) return posisiLBB;
  
  else if (servoNama.equals("RFT")) return posisiRFT;
  else if (servoNama.equals("RFM")) return posisiRFM;
  else if (servoNama.equals("RFB")) return posisiRFB;
  
  else if (servoNama.equals("RBT")) return posisiRBT;
  else if (servoNama.equals("RBM")) return posisiRBM;
  else if (servoNama.equals("RBB")) return posisiRBB;  
}

//langkah ke-1
void MajuKananBelakang() {
  //posisikan kaki CoG ke posisi angkat kaki
  ServoMovementDouble("RFT",-10, "LBT",-10);
  delay(50);

  //angkat kaki kanan belakang
  ServoMovementSingle("RBM", 50);
  delay(50);

  //majukan kaki kanan belakang
  ServoMovementSingle("RBT",40);
  delay(50);

  //turunkan kaki kanan belakang
  ServoMovementSingle("RBM", 0);
  delay(50);

  //dorong kaki kanan belakang
  ServoMovementSingle("RBT",0);
  delay(50);

  //posisikan kaki CoG ke tegak lurus
  ServoMovementDouble("RFT",0, "LBT",0);
  delay(50);
}

//langkah ke-2
void MajuKiriDepan() {
  //posisikan kaki CoG ke posisi angkat kaki
  ServoMovementDouble("RFT",10, "LBT",10);
  delay(50);

  //angkat kaki kiri depan
  ServoMovementSingle("LFM", 50);
  delay(50);

  //majukan kaki kiri depan
  ServoMovementSingle("LFT",40);
  delay(50);

  //turunkan kaki kiri depan
  ServoMovementSingle("LFM", 0);
  delay(50);

  //dorong kaki kiri depan
  ServoMovementSingle("LFT",0);
  delay(50);

  //posisikan kaki CoG ke tegak lurus
  ServoMovementDouble("RFT",0, "LBT",0);
  delay(50);
}

//langkah ke-3
void MajuKiriBelakang() {
  //posisikan kaki CoG ke posisi angkat kaki
  ServoMovementDouble("LFT",-10, "RBT",-10);
  delay(50);

  //angkat kaki kiri belakang
  ServoMovementSingle("LBM", 50);
  delay(50);

  //majukan kaki kiri belakang
  ServoMovementSingle("LBT",40);
  delay(50);

  //turunkan kaki kiri belakang
  ServoMovementSingle("LBM", 0);
  delay(50);

  //dorong kaki kiri belakang
  ServoMovementSingle("LBT",0);
  delay(50);

  //posisikan kaki CoG ke tegak lurus
  ServoMovementDouble("LFT",0, "RBT",0);
  delay(50);
}

//langkah ke-4
void MajuKananDepan() {
  //posisikan kaki CoG ke posisi angkat kaki
  ServoMovementDouble("LFT",10, "RBT",10);
  delay(50);

  //angkat kaki kanan depan
  ServoMovementSingle("RFM", 50);
  delay(50);

  //majukan kaki kanan depan
  ServoMovementSingle("RFT",40);
  delay(50);

  //turunkan kaki kanan depan
  ServoMovementSingle("RFM", 0);
  delay(50);

  //dorong kaki kanan depan
  ServoMovementSingle("RFT",0);
  delay(50);

  //posisikan kaki CoG ke tegak lurus
  ServoMovementDouble("LFT",0, "RBT",0);
  delay(50);
}
