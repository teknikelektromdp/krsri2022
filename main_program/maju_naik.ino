////////////
// prosedur berjalan pada tanjakan
////////////
int naikMajuDepan=40;
int naikMajuBelakang=30;
int naikMajuDorong=-30;

void NaikMajuAwal() {
  //memposisikan kaki untuk pergerakan awal
  ServoMovementDouble("RFT", BerdiriSudut("RFT", naikMajuDorong), "LBT", BerdiriSudut("LBT", naikMajuDorong));
  delay(1);
}

//gabungan prosedur maju naik
void NaikMaju(){
    NaikMajuKanan();
    NaikMajuKananDorong();
    NaikMajuKiri();
    NaikMajuKiriDorong();
}

void NaikMajuKanan() {
  //majukan kaki kanan belakang bersamaan dengan menaikkannya
  ServoMovementDouble("RBT", BerdiriSudut("RBT", (naikMajuBelakang/2)), "RBM", BerdiriSudut("RBM", 78));
  //majukan kaki kanan belakang bersamaan dengan menurunkannya
  ServoMovementDouble("RBT", BerdiriSudut("RBT", naikMajuBelakang), "RBM", BerdiriSudut("RBM", 0));
  delay(1);
  
  //majukan kaki kanan depan bersamaan dengan menaikkannya
  ServoMovementDouble("RFT", BerdiriSudut("RFT", (naikMajuDepan/2)), "RFM", BerdiriSudut("RFM", 40));
  //majukan kaki kanan depan bersamaan dengan menurunkannya
  ServoMovementDouble("RFT", BerdiriSudut("RFT", naikMajuDepan), "RFM", BerdiriSudut("RFM", 0));
  delay(1);
}

void NaikMajuKananDorong() {
  //kaki kanan depan, kanan belakang, dan kaki kiri depan bersiap untuk menekan ke bawah
//  ServoMovementTriple("RFB", 5, "RBB", 5, "LFB", 5);
//  ServoMovementTriple("RFM", -5, "RBM", -5, "LFM", -5);
//  delay(1);

  //kedua kaki kanan dan kaki kiri depan mendorong ke depan
  ServoMovementTriple("RFT", BerdiriSudut("RFT", 0), 
                      "RBT", BerdiriSudut("RBT", naikMajuDorong), 
                      "LFT", BerdiriSudut("LFT", naikMajuDorong));
  delay(1);

  //kembalikan sudut kedua kaki kanan dan kaki kiri depan 
//  ServoMovementTriple("RFB", 0, "RBB", 0, "LFB", 0);
//  ServoMovementTriple("RFM", 0, "RBM", 0, "LFM", 0);
//  delay(1);
}

void NaikMajuKiri() {
  //majukan kaki kiri belakang bersamaan dengan menaikkannya
  ServoMovementDouble("LBT", BerdiriSudut("LBT", (naikMajuBelakang/2)), "LBM", BerdiriSudut("LBM", 78));
  //majukan kaki kiri belakang bersamaan dengan menurunkannya
  ServoMovementDouble("LBT", BerdiriSudut("LBT", naikMajuBelakang), "LBM", BerdiriSudut("LBM", 0));
  delay(1);
  
  //majukan kaki kiri depan bersamaan dengan menaikkannya
  ServoMovementDouble("LFT", BerdiriSudut("LFT", (naikMajuDepan/2)), "LFM", BerdiriSudut("LFM", 40));
  //majukan kaki kiri depan bersamaan dengan menurunkannya
  ServoMovementDouble("LFT", BerdiriSudut("LFT", naikMajuDepan), "LFM", BerdiriSudut("LFM", 0));
  delay(1);
}

void NaikMajuKiriDorong() {
  //kedua kaki kiri dan kaki kanan depan untuk menekan ke bawah
//  ServoMovementTriple("LFB", 5, "LBB", 5, "RFB", 5);
//  ServoMovementTriple("LFM", -5, "LBM", -5, "RFM", -5);
//  delay(1);

  //kedua kaki kiri dan kaki kanan depan mendorong ke depan
  ServoMovementTriple("LFT", BerdiriSudut("LFT", 0), 
                      "LBT", BerdiriSudut("LBT", naikMajuDorong), 
                      "RFT", BerdiriSudut("RFT", naikMajuDorong));
  delay(1);

  //kembalikan sudut kedua kaki kiri dan kaki kanan depan
//  ServoMovementTriple("LFB", 0, "LBB", 0, "RFB", 0);
//  ServoMovementTriple("LFM", 0, "LBM", 0, "RFM", 0);
//  delay(1);
}
