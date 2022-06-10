void RintanganPuing2(){
  MundurAwal();//persiapan robot maju
  Mundur(50);

  BacaSensor();
  LcdDisplay();
  int kondisiMundur=1, dindingRuang1, max_north_puing2 = 100, min_north_puing2 = 83;
  dindingRuang1=0;
  
  //robt berjalan mundur memasuki rintangan puing ke-2 hingga menemukan dinding di belakangnya
  while(dindingRuang1==0){
    
    if(kompasValue>max_north_puing2 && (par_l<=30) && (par_r<=30)){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMundur==1) Berdiri();
      modeGerak="p2i";
      LcdDisplay();
      Putar("kiri", 32, 50);//berputar sejauh 32 derajat 
      kondisiMundur=0;
      
    } else if(kompasValue<min_north_puing2 && (par_l<=30) && (par_r<=30)){//robot terlalu ke kanan sehingga perlu memutar ke kiri
        if (kondisiMundur==1) Berdiri();
        modeGerak="p2a";
        LcdDisplay();
        Putar("kanan", 32, 50); //berputar sejauh 32 derajat 
        kondisiMundur=0;
      
    } else if((par_b<50)){//robot menemukan lokasi ruang pemadaman
        dindingRuang1=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk mundur
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
//  while(!(kompasValue >= min_range_north && kompasValue <= max_range_north))
//  {
//    modeGerak="ki5";
//    LcdDisplay();
//    Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
//    
//    BacaSensor();
//    LcdDisplay();
//  }
//  Berdiri();
//  BacaSensor();
//  LcdDisplay();
}

void KeluarRintanganPuing2(){
  Berdiri();
  MajuAwal();
  Maju(50);
//  while(true) Maju(50);
//  MundurAwal();//persiapan robot maju
//  Mundur(50);

  BacaSensor();
  LcdDisplay();
  int kondisiMaju=1, dindingSave1;
  dindingSave1=0;
  
  //robt berjalan mundur memasuki rintangan puing ke-2 hingga menemukan dinding di belakangnya
  while(dindingSave1==0){
    
    if(kompasValue>max_range_north){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMaju==1) Berdiri();
      modeGerak="kp2i";
      LcdDisplay();
      Putar("kiri", 30, 50);//berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if(kompasValue<min_range_north){//robot terlalu ke kanan sehingga perlu memutar ke kiri
        if (kondisiMaju==1) Berdiri();
        modeGerak="kp2a";
        LcdDisplay();
        Putar("kanan", 30, 50); //berputar sejauh 32 derajat 
        kondisiMaju=0;
      
    } else if((par_b<50)){//robot menemukan lokasi ruang pemadaman
        dindingSave1=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk mundur
        if (kondisiMaju==0) MundurAwal();

        modeGerak="kp2";
        LcdDisplay();
        
        Mundur(50);
        kondisiMaju=1;
    }
    BacaSensor();
    LcdDisplay();
}
}
