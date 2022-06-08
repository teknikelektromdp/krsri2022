void RintanganPuing1(){
  //persiapan robot maju dengan awalan kiri
  //kendala: robot terlalu condong ke dinding sebelah kiri, dan membuat robot tersangkut pada siku dinding
  //solusi: memulai pergerakan dari kaki kiri untuk menghindari kendala tersebut
  MajuAwalKiri();
  MajuGerakKiri(50);


  int kondisiMaju=1, dinding2;
  dinding2=0;
  
  while(dinding2==0){
    BacaSensor();
    LcdDisplay();
    
    if((par_ld<=13 && par_ld>0) || (par_l<=10 && par_l>0)){
      if (kondisiMaju==1) Berdiri();
      modeGerak="p1";
      LcdDisplay();
      Putar("kanan", 32, 50); //berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if((par_rd<=13 && par_rd>0) || (par_r<=10 && par_r>0)){
      if (kondisiMaju==1) Berdiri();
      modeGerak="p1";
      LcdDisplay();
      Putar("kiri", 32,50); //berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if((par_l==0 || par_l>40) && (par_f<=25 && par_f>0)){//robot menemukan simpangan kiri
      dinding2=1;//lanjut ke rintangan berikutnya 
      
    } else if((par_rd>15 && par_rd<=35) && (par_f<=25 && par_f>0)){//robot menemukan simpangan kiri
      dinding2=1;//lanjut ke rintangan berikutnya 
      
    } else{
      if (kondisiMaju==0) MajuAwalKiri();
      
      modeGerak="p1";
      LcdDisplay();
      
      MajuGerakKiri(50);

      kondisiMaju=1;
    }
  }



  //robot memutar arah haluan
  Berdiri();
  BacaSensor();
  LcdDisplay();
  while(!(kompasValue >= min_range_north && kompasValue <= max_range_north))
  {
    modeGerak="ki2";
    LcdDisplay();
    
    Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
    
    BacaSensor();
    LcdDisplay();
  }
  modeGerak="mj";
  BacaSensor();
  LcdDisplay();
}
