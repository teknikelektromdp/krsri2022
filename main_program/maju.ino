////////////
// prosedur berjalan
////////////
int majuDepan=40;
int majuBelakang=30;
int majuDorong=-30;

void MajuAwal() {
  //memposisikan kaki untuk pergerakan awal
  ServoMovementDouble("RFT", majuDorong, "LBT", majuDorong);
  delay(1);
}

//gabungan prosedur maju
void Maju(int tinggiAngkat){
  MajuKanan(tinggiAngkat);
  MajuKananDorong();
  MajuKiri(tinggiAngkat);
  MajuKiriDorong();
}

void MajuKanan(int tinggiAngkat //ketinggian servo middle yang diangkat
) {
  //majukan kaki kanan belakang bersamaan dengan menaikkannya
  ServoMovementDouble("RBT", (majuBelakang/2), "RBM", tinggiAngkat);

  //majukan kaki kanan belakang bersamaan dengan menurunkannya
  ServoMovementDouble("RBT", majuBelakang, "RBM", 0);
  delay(1);
  
  //majukan kaki kanan depan bersamaan dengan menaikkannya
  ServoMovementDouble("RFT", (majuDepan/2), "RFM", tinggiAngkat);

  //majukan kaki kanan depan bersamaan dengan menurunkannya
  ServoMovementDouble("RFT", majuDepan, "RFM", 0);
  delay(1);
}

void MajuKananDorong() {
  //kaki kanan depan, kanan belakang, dan kaki kiri depan bersiap untuk menekan ke bawah
  ServoMovementTriple("RFB", 5, "RBB", 5, "LFB", 5);
  ServoMovementTriple("RFM", -5, "RBM", -5, "LFM", -5);
  delay(1);

  //kedua kaki kanan dan kaki kiri depan mendorong ke depan
  ServoMovementTriple("RFT", 0, "RBT", majuDorong, "LFT", majuDorong);
  delay(1);

  //kembalikan sudut kedua kaki kanan dan kaki kiri depan 
  ServoMovementTriple("RFB", 0, "RBB", 0, "LFB", 0);
  ServoMovementTriple("RFM", 0, "RBM", 0, "LFM", 0);
  delay(1);
}

void MajuKiri(int tinggiAngkat //ketinggian servo middle yang diangkat
) {
  //majukan kaki kiri belakang bersamaan dengan menaikkannya
  ServoMovementDouble("LBT", (majuBelakang/2), "LBM", tinggiAngkat);

  //majukan kaki kiri belakang bersamaan dengan menurunkannya
  ServoMovementDouble("LBT", majuBelakang, "LBM", 0);
  delay(1);
  
  //majukan kaki kiri depan bersamaan dengan menaikkannya
  ServoMovementDouble("LFT", (majuDepan/2), "LFM", tinggiAngkat);

  //majukan kaki kiri depan bersamaan dengan menurunkannya
  ServoMovementDouble("LFT", majuDepan, "LFM", 0);
  delay(1);
}

void MajuKiriDorong() {
  //kedua kaki kiri dan kaki kanan depan untuk menekan ke bawah
  ServoMovementTriple("LFB", 5, "LBB", 5, "RFB", 5);
  ServoMovementTriple("LFM", -5, "LBM", -5, "RFM", -5);
  delay(1);

  //kedua kaki kiri dan kaki kanan depan mendorong ke depan
  ServoMovementTriple("LFT", 0, "LBT", majuDorong, "RFT", majuDorong);
  delay(1);

  //kembalikan sudut kedua kaki kiri dan kaki kanan depan
  ServoMovementTriple("LFB", 0, "LBB", 0, "RFB", 0);
  ServoMovementTriple("LFM", 0, "LBM", 0, "RFM", 0);
  delay(1);
}
