void RintanganPuing2(){
  MundurAwal();//persiapan robot maju
  Mundur(50);

  BacaSensor();
  LcdDisplay();
  int kondisiMundur=1, dindingRuang1;
  dindingRuang1=0;
  
  while(dindingRuang1==0){
    if((par_ld>=22 && par_ld<30) || (par_l<=10 && par_l>0)){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMundur==1) Berdiri();
      modeGerak="p2";
      LcdDisplay();
      Putar("kiri", 32, 50);//berputar sejauh 32 derajat 
      kondisiMundur=0;
      
    } else if((par_rd<30 && par_rd>=22) || (par_r<=10 && par_r>00)){//robot terlalu ke kanan sehingga perlu memutar ke kiri
      if (kondisiMundur==1) Berdiri();
      modeGerak="p2";
      LcdDisplay();
      Putar("kanan", 32, 50); //berputar sejauh 32 derajat 
      kondisiMundur=0;
      
    } else if((par_g<10 || par_g<40) && (par_l>=10 && par_l<30) && (par_r>=10 && par_r<30)){//robot menemukan simpangan kiri
      dindingRuang1=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk maju
      if (kondisiMundur==0) MundurAwal();

      modeGerak="p2";
      LcdDisplay();
      
      Mundur(50);
      kondisiMundur=1;
    }
    BacaSensor();
    LcdDisplay();
  }



  //Mempersiapkan untuk melakukan pemadaman dan penyelamatan
  Berdiri();
  
  BacaSensor();
  LcdDisplay();
  while(!(kompasValue >= min_range_north && kompasValue <= max_range_north))
  {
    modeGerak="ki5";
    LcdDisplay();
    Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
    
    BacaSensor();
    LcdDisplay();
  }
  Berdiri();
  BacaSensor();
  LcdDisplay();
}
