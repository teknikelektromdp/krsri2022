void RintanganHomeMaju() {
  //robot maju 
  MajuAwal();
  Maju(30);

  int kondisiMaju=1, dinding1;
  dinding1=0;//flag yang menyimpan keadaan robot menemukan dinding di depan, nilai ini nantinya digunakan untuk keluar dari while
  while(dinding1==0){
    BacaSensor();
    LcdDisplay();

    if(kompasValue< min_range_south){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMaju==1) Berdiri();
      modeGerak = "hm";
      LcdDisplay();
      Putar("kanan", 32, 30);//berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if(kompasValue>max_range_south){//robot terlalu ke kanan sehingga perlu memutar ke kiri
      if (kondisiMaju==1) Berdiri();
      modeGerak = "hm";
      LcdDisplay();
      Putar("kiri", 32, 30); //berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if((par_l ==0 ||par_l>24)&& par_f<=20){//robot menemukan dinding di depan
      dinding1=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk maju
      if (kondisiMaju==0) MajuAwal();

      modeGerak = "hm";
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
    modeGerak="ki1";
    LcdDisplay();
    
    Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
    BacaSensor();
    LcdDisplay();
  }
  modeGerak = "mj";
  BacaSensor();
  LcdDisplay();
}
