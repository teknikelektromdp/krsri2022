void RintanganHomeMaju() {
  //robot maju 
  MajuAwal();
  Maju(30);

  int kondisiMaju=1, dinding1;
  dinding1=0;//flag yang menyimpan keadaan robot menemukan dinding di depan, nilai ini nantinya digunakan untuk keluar dari while
  while(dinding1==0){
    BacaSensor();
    LcdDisplay();

    if((par_ld<=13 && par_ld>0) || (par_l<=10 && par_l>0)){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMaju==1) Berdiri();
      modeGerak = "home maju";
      LcdDisplay();
      Putar("kanan", 32, 30);//berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if((par_rd<=13 && par_rd>0) || (par_r<=10 && par_r>0)){//robot terlalu ke kanan sehingga perlu memutar ke kiri
      if (kondisiMaju==1) Berdiri();
      modeGerak = "home maju";
      LcdDisplay();
      Putar("kiri", 32, 30); //berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if((par_l==0 || par_l>40) && (par_f<=25 && par_f>0)){//robot menemukan simpangan kiri
      dinding1=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk maju
      if (kondisiMaju==0) MajuAwal();

      modeGerak = "home maju";
      LcdDisplay();
      Maju(30);

      kondisiMaju=1;
    }
  }


  
  // memutar posisi hingga menghadap puing 1
  Berdiri();
  BacaSensor();
  LcdDisplay();
  while(!(kompasValue >= min_range_east && kompasValue <= max_range_east))
  {
    modeGerak="kiri1";
    LcdDisplay();
    
    Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
    BacaSensor();
    LcdDisplay();
  }
  modeGerak = "maju";
  BacaSensor();
  LcdDisplay();
}
