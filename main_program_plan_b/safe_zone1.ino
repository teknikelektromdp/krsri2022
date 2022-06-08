void SafeZone1(){
  MajuAwal();//persiapan robot maju
  Maju(50);


  int kondisiMaju=1, dindingSaveZone1;
  dindingSaveZone1=0;
  while(dindingSaveZone1==0){
    BacaSensor();
   
    LcdDisplay();
    
    if((par_ld<=13 && par_ld>0) || (par_l<=10 && par_l>0)){
      if (kondisiMaju==1) Berdiri();
      Putar("kanan", 32, 50); //berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if((par_rd<=13 && par_rd>0) || (par_r<=10 && par_r>0)){
      if (kondisiMaju==1) Berdiri();
      Putar("kiri", 32, 50); //berputar sejauh 32 derajat 
      kondisiMaju=0;
      
    } else if((par_f<=20 && par_f>0)){//robot di depan lilin dan korban
      dindingSaveZone1=1;//lanjut ke penyelamatan
      
    } else{
      if (kondisiMaju==0) MajuAwal();
      Maju(50);

      kondisiMaju=1;
    }
  }

  
  Berdiri();
  
  BacaSensor();
  LcdDisplay();
  while(!(kompasValue >= min_range_south && kompasValue <= max_range_south))
  {
    modeGerak="ki6";
    LcdDisplay();
    
    Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
    
    BacaSensor();
    LcdDisplay();
  }
  Berdiri();
  BacaSensor();
  LcdDisplay();
}
