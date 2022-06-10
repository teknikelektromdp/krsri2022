void RintanganNaikTurunLama(){//original
  BacaSensor();
  LcdDisplay();

  int keluarNaikTurun = 0, nilai0=0;

  BerdiriNaik();
  NaikMajuAwal();
  
  BacaSensor();
  LcdDisplay();

  //double check nilai sensor belakang, untuk mengetahui posisi robot pada rintangan naik turun pada tanjakan atau turunan
  while(!(nilai0>=2)){
    if(par_b==0){
      nilai0 = nilai0 + 1;
    }
    else{
      nilai0 = 0;
    }
    NaikMaju();
    BacaSensor();
    modeGerak="nt";
    LcdDisplay();
  }
  
  Berdiri();
  MajuAwal();
  
  while(keluarNaikTurun==0){
    Maju(30);
    
    BacaSensor();
    modeGerak="nt";
    LcdDisplay();
    
    if ((par_f<45 && par_f>0) && (par_r>40 || par_r==0)) {
      keluarNaikTurun=1;
    } else if((par_f<50 && par_f>0) && (par_l >=40 || par_l == 0)){
      keluarNaikTurun=1;
    } else if((par_r>40 || par_r==0) && (par_l >=40 || par_l == 0)){
      keluarNaikTurun=1;
    } else {
      keluarNaikTurun=0;
    }
  }
  
  Berdiri();
  modeGerak="R1";
  LcdDisplay();
}

//awal gerakan kiri
//sensor yang diambil, sensor belakang, kiri, kanan.
//parameter sensor belakang yang diambil 1 meter, untuk menjadi acuan kalau robot telah mencapai titik puncak rintangan naik turun



void RintanganNaikTurun(){//awalan kiri
  BacaSensor();
  LcdDisplay();

  int keluarNaikTurun = 0, nilai0=0, kondisiMaju;

  BerdiriNaik();
  NaikMajuAwalKiri();
  
  BacaSensor();
  LcdDisplay();

  //double check nilai sensor belakang, untuk mengetahui posisi robot pada rintangan naik turun pada tanjakan atau turunan
  while(!(nilai0>=2)){
    if(par_b==0){
      nilai0 = nilai0 + 1;
    }
    else{
      nilai0 = 0;
    }
    NaikMajuGerakKiri();
    BacaSensor();
    modeGerak="nt";
    LcdDisplay();
  }
  
  Berdiri();
  MajuAwal();
  
  while(keluarNaikTurun==0){
    if (kondisiMaju==0) MajuAwal();
    Maju(30);
    kondisiMaju=1;
    BacaSensor();
    modeGerak="nt";
    LcdDisplay();

    if(kompasValue<min_range_north){

      if (kondisiMaju==1) Berdiri();
      modeGerak="tnt";
      LcdDisplay();
      Putar("kanan", 32, 50); //berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if(kompasValue>max_range_north){
      if (kondisiMaju==1) Berdiri();
      modeGerak="tnt";
      LcdDisplay();
      Putar("kiri", 32,50); //berputar sejauh 32 derajat 
      kondisiMaju=0;
    }
    else if ((par_f<70 && par_f>0) && (par_r>=40 || par_r==0)) {
      keluarNaikTurun=1;
    } else if((par_f<70 && par_f>0) && (par_l >=40 || par_l == 0)){
      keluarNaikTurun=1;
    } else if((par_r>40 || par_r==0) && (par_l >=40 || par_l == 0)){
      keluarNaikTurun=1;
    } else {
      keluarNaikTurun=0;
    }
  }
  
  Berdiri();
  modeGerak="R1";
  LcdDisplay();
}


void RintanganTanjakan(){
  //robot mendudukan dirinya
  ServoWrite("LFT",0);  ServoWrite("RFT",0);
  ServoWrite("LBT",0);  ServoWrite("RBT",0);

  ServoWrite("LFM",50);  ServoWrite("RFM",50);
  ServoWrite("LBM",50);  ServoWrite("RBM",50);

  ServoWrite("LFB",-50);  ServoWrite("RFB",-50);
  ServoWrite("LBB",-50);  ServoWrite("RBB",-50);
  delay(200);
  BacaSensor();
  LcdDisplay();

  //angkat kaki ke atas
  ServoWrite("LFB",44);  ServoWrite("RFB",44);
  ServoWrite("LBB",44);  ServoWrite("RBB",44);
  delay( 4*(50+44) );
  BacaSensor();
  LcdDisplay();

  int posisiPuncak=0;
  while (posisiPuncak==0) {
    //pindahkan kaki ke depan
    ServoWrite("LFT",43);  ServoWrite("RFT",43);
    ServoWrite("LBT",32);  ServoWrite("RBT",32);
    delay( 4*(35+43) );
    BacaSensor();
    LcdDisplay();

    //dorong kaki ke bawah
    ServoWrite("LFB",-50);  ServoWrite("RFB",-50);
    ServoWrite("LBB",-50);  ServoWrite("RBB",-50);
    delay( 4*(50+44) );
    BacaSensor();
    LcdDisplay();

    //dorong ke belakang
    ServoWrite("LFT",-35);  ServoWrite("RFT",-35);
    ServoWrite("LBT",-40);  ServoWrite("RBT",-40);
    delay( 4*(35+43) );
    BacaSensor();
    LcdDisplay();

    //angkat kaki ke atas
    ServoWrite("LFB",44);  ServoWrite("RFB",44);
    ServoWrite("LBB",44);  ServoWrite("RBB",44);
    delay( 4*(50+44) );
    BacaSensor();
    LcdDisplay();

    if ((par_b>= 80) && (kompasValue>=min_range_north && kompasValue<=max_range_north)) posisiPuncak=1;
//    if (par_b>80) posisiPuncak=1;
  }
}
