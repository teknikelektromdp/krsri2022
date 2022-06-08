void RintanganNaikTurunLama(){//original
  BacaSensor();
  LcdDisplay();

  int keluarNaikTurun = 0;

  BerdiriNaik();
  NaikMajuAwal();
  
  BacaSensor();
  LcdDisplay();

  while(keluarNaikTurun==0){
    NaikMaju();
    
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



void RintanganNaikTurun(){//test
  BacaSensor();
  LcdDisplay();

  int keluarNaikTurun = 0, nilai0=0;

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
