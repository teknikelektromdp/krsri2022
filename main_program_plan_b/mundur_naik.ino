////////////
// prosedur berjalan mundur
////////////
int naikMundurDepan=-30;
int naikMundurBelakang=-20;
int naikMundurDorong=20;
int naikMundurKakiDepan=78;
int naikMundurKakiBelakang=40;

//memposisikan kaki untuk pergerakan awal
void NaikMundurAwal(String sisi) {
  if (sisi.equals("kiri")) NaikMundurAwalKiri();
  else NaikMundurAwalKanan();
  delay(1);
}

//gabungan prosedur mundur(reversed)(diperbaiki besok)
void NaikMundur(String sisi){
  if (sisi.equals("kiri")) {
    NaikMundurKanan();
    NaikMundurKananDorong();
    NaikMundurKiri();
    NaikMundurKiriDorong();    
  } else {
    NaikMundurKiri();
    NaikMundurKiriDorong();    
    NaikMundurKanan();
    NaikMundurKananDorong();
  }
}

void NaikMundurAwalKiri() {
  //memposisikan kaki untuk pergerakan awal
  ServoMovementDouble(
    "LFT", BerdiriSudutMundur("LFT",mundurDorong), 
    "RBT", BerdiriSudutMundur("RBT",mundurDorong)
  );
  delay(1);
}

void NaikMundurAwalKanan() {
  //memposisikan kaki untuk pergerakan awal
  ServoMovementDouble(
    "LFT", BerdiriSudutMundur("RFT",mundurDorong), 
    "RBT", BerdiriSudutMundur("LBT",mundurDorong)
  );
  delay(1);
}


//ketinggian kaki middle naik maksimal
void NaikMundurKiri() {
  //mundurkan kaki kiri depan bersamaan dengan menaikkannya
  ServoMovementDouble(
    "LFT", BerdiriSudutMundur("LFT",(mundurDepan/2)), 
    "LFM", BerdiriSudutMundur("LFM",naikMundurKakiDepan)
  );
  //mundurkan kaki kiri depan bersamaan dengan menurunkannya
  ServoMovementDouble(
    "LFT", BerdiriSudutMundur("LFT",mundurDepan), 
    "LFM", BerdiriSudutMundur("LFM",0)
  );
  delay(1);
  
  //mundurkan kaki kiri belakang bersamaan dengan menaikkannya
  ServoMovementDouble(
    "LBT", BerdiriSudutMundur("LBT",(mundurBelakang/2)), 
    "LBM", BerdiriSudutMundur("LBM",naikMundurKakiBelakang)
  );
  //mundurkan kaki kiri belakang bersamaan dengan menurunkannya
  ServoMovementDouble(
    "LBT", BerdiriSudutMundur("LBT",mundurBelakang), 
    "LBM", BerdiriSudutMundur("LBM",0)
  );
  delay(1);
}

void NaikMundurKiriDorong() {
  //kedua kaki kiri dan kaki kanan belakang untuk menekan ke bawah
  ServoMovementDouble(
    "LBB", BerdiriSudutMundur("LBB",5), 
    "RBB", BerdiriSudutMundur("RBB",5)
  );
  ServoMovementDouble(
    "LBM", BerdiriSudutMundur("LBM",-5), 
    "RBM", BerdiriSudutMundur("RBM",-5)
  );
  delay(1);

  //kedua kaki kiri dan kaki kanan belakang mendorong ke belakang
  ServoMovementTriple(
    "LBT", BerdiriSudutMundur("LBT",0), 
    "LFT", BerdiriSudutMundur("LFT",mundurDorong), 
    "RBT", BerdiriSudutMundur("RBT",mundurDorong)
  );
  delay(1);

  //kembalikan sudut kedua kaki kiri dan kaki kanan belakang
  ServoMovementDouble(
    "LBB", BerdiriSudutMundur("LBB",0), 
    "RBB", BerdiriSudutMundur("RBB",0)
  );
  ServoMovementDouble(
    "LBM", BerdiriSudutMundur("LBM",0), 
    "RBM", BerdiriSudutMundur("RBM",0)
  );
  delay(1);
}

//ketinggian servo middle naik maksimal
void NaikMundurKanan() {
  //mundurkan kaki kanan depan bersamaan dengan menaikkannya
  ServoMovementDouble(
    "RFT", BerdiriSudutMundur("RFT",(mundurBelakang/2)), 
    "RFM", BerdiriSudutMundur("RFM",naikMundurKakiDepan)
  );
  //mundurkan kaki kanan depan bersamaan dengan menurunkannya
  ServoMovementDouble(
    "RFT", BerdiriSudutMundur("RFT",mundurBelakang),
    "RFM", BerdiriSudutMundur("RFM",0)
  );
  delay(1);
  
  //mundurkan kaki kanan belakang bersamaan dengan menaikkannya
  ServoMovementDouble(
    "RBT", BerdiriSudutMundur("RBT",(mundurDepan/2)), 
    "RBM", BerdiriSudutMundur("RBM",naikMundurKakiBelakang)
  );
  //mundurkan kaki kanan belakang bersamaan dengan menurunkannya
  ServoMovementDouble(
    "RBT", BerdiriSudutMundur("RBT",mundurDepan),
    "RBM", BerdiriSudutMundur("RBM",0)
  );
  delay(1);
}

void NaikMundurKananDorong() {
  //kaki kedua kaki kanan, dan kaki kiri belakang bersiap untuk menekan ke bawah
  ServoMovementDouble(
    "RBB", BerdiriSudutMundur("RBB",5),
    "LBB", BerdiriSudutMundur("LBB",5)
  );
  ServoMovementDouble(
    "RBM", BerdiriSudutMundur("RBM",-5),
    "LBM", BerdiriSudutMundur("LBM",-5)
  );
  delay(1);

  //kedua kaki kanan dan kaki kiri belakang mendorong ke depan
  ServoMovementTriple(
    "RBT", BerdiriSudutMundur("RBT",0),
    "RFT", BerdiriSudutMundur("RFT",mundurDorong),
    "LBT", BerdiriSudutMundur("LBT",mundurDorong)
  );
  delay(1);

  //kembalikan sudut kedua kaki kanan dan kaki kiri belakang 
  ServoMovementDouble(
    "RBB", BerdiriSudutMundur("RBB",0), 
    "LBB", BerdiriSudutMundur("LBB",0)
  );
  ServoMovementDouble(
    "RBM", BerdiriSudutMundur("RBM",0), 
    "LBM", BerdiriSudutMundur("LBM",0)
  );
  delay(1);
}
