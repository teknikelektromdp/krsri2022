////////////
// prosedur berjalan mundur
////////////
int mundurDepan=-30;
int mundurBelakang=-20;
int mundurDorong=20;

void MundurAwal() {
  //memposisikan kaki untuk pergerakan awal
  ServoMovementDouble("RFT", mundurDorong, "LBT", mundurDorong);
  delay(1);
}

void MundurKiri(int tinggiAngkat //ketinggian servo middle yang diangkat
) {
  //mundurkan kaki kiri depan bersamaan dengan menaikkannya
  ServoMovementDouble("LFT", (mundurDepan/2), "LFM", tinggiAngkat);
  //mundurkan kaki kiri depan bersamaan dengan menurunkannya
  ServoMovementDouble("LFT", mundurDepan, "LFM", 0);
  delay(1);
  
  //mundurkan kaki kiri belakang bersamaan dengan menaikkannya
  ServoMovementDouble("LBT", (mundurBelakang/2), "LBM", tinggiAngkat);
  //mundurkan kaki kiri belakang bersamaan dengan menurunkannya
  ServoMovementDouble("LBT", mundurBelakang, "LBM", 0);
  delay(1);
}

void MundurKiriDorong() {
  //kedua kaki kiri dan kaki kanan belakang untuk menekan ke bawah
  ServoMovementTriple("LBB", 5, "LFB", 5, "RBB", 5);
  ServoMovementTriple("LBM", -5, "LFM", -5, "RBM", -5);
  delay(1);

  //kedua kaki kiri dan kaki kanan belakang mendorong ke belakang
  ServoMovementTriple("LBT", 0, "LFT", mundurDorong, "RBT", mundurDorong);
  delay(1);

  //kembalikan sudut kedua kaki kiri dan kaki kanan belakang
  ServoMovementTriple("LBB", 0, "LFB", 0, "RBB", 0);
  ServoMovementTriple("LBM", 0, "LFM", 0, "RBM", 0);
  delay(1);
}

void MundurKanan(int tinggiAngkat //ketinggian servo middle yang diangkat
) {
  //mundurkan kaki kanan depan bersamaan dengan menaikkannya
  ServoMovementDouble("RFT", (mundurBelakang/2), "RFM", tinggiAngkat);
  //mundurkan kaki kanan depan bersamaan dengan menurunkannya
  ServoMovementDouble("RFT", mundurBelakang, "RFM", 0);
  delay(1);
  
  //mundurkan kaki kanan belakang bersamaan dengan menaikkannya
  ServoMovementDouble("RBT", (mundurDepan/2), "RBM", tinggiAngkat);
  //mundurkan kaki kanan belakang bersamaan dengan menurunkannya
  ServoMovementDouble("RBT", mundurDepan, "RBM", 0);
  delay(1);
}

void MundurKananDorong() {
  //kaki kedua kaki kanan, dan kaki kiri belakang bersiap untuk menekan ke bawah
  ServoMovementTriple("RBB", 5, "RFB", 5, "LBB", 5);
  ServoMovementTriple("RBM", -5, "RFM", -5, "LBM", -5);
  delay(1);

  //kedua kaki kanan dan kaki kiri belakang mendorong ke depan
  ServoMovementTriple("RBT", 0, "RFT", mundurDorong, "LBT", mundurDorong);
  delay(1);

  //kembalikan sudut kedua kaki kanan dan kaki kiri belakang 
  ServoMovementTriple("RBB", 0, "RFB", 0, "LBB", 0);
  ServoMovementTriple("RBM", 0, "RFM", 0, "LBM", 0);
  delay(1);
}

void SafetyMundur(){
  int kondisiMundur=1, par_ld, par_rd, par_r, par_l, par_f, par_g, dindingRuang1;
  dindingRuang1=0;//flag yang menyimpan keadaan robot menemukan dinding di depan, nilai ini nantinya digunakan untuk keluar dari while
  while(dindingRuang1==0){
    par_ld=Paralax("leftDiagonal");
    par_rd=Paralax("rightDiagonal");
    par_r=Paralax("right");
    par_l=Paralax("left");
    par_f=Paralax("front");
    par_g=Paralax("gripper");
    lcd.clear();

    lcd.setCursor(0,0); lcd.print("LD");lcd.print(par_ld); lcd.print(" RD");lcd.print(par_rd);lcd.print(" R");lcd.print(par_r);lcd.print(" L");lcd.print(par_l);
    lcd.setCursor(10,1); lcd.print("F");lcd.print(par_f); lcd.print(" G");lcd.print(par_g);

    
    if((par_ld>=22 && par_ld<30) || (par_l<=10 && par_l>0)){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMundur==1) Berdiri();
//      lcd.setCursor(10,0); lcd.print("kanan");
      Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
      kondisiMundur=0;
      
    } else if((par_rd<30 && par_rd>=22) || (par_r<=10 && par_r>0)){//robot terlalu ke kanan sehingga perlu memutar ke kiri
      if (kondisiMundur==1) Berdiri();
//      lcd.setCursor(10,1); lcd.print("kiri");
      Putar("kanan", 32, 30); //berputar sejauh 32 derajat 
      kondisiMundur=0;
      
    } else if((par_g<10 || par_g<40) && (par_l>=10 && par_l<30) && (par_r>=10 && par_r<30)){//robot menemukan simpangan kiri
      dindingRuang1=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk maju
      if (kondisiMundur==0) MundurAwal();

      MundurKiri(30);
      MundurKiriDorong();
      MundurKanan(30);
      MundurKananDorong();

      kondisiMundur=1;
    }
  }
}
