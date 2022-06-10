void RintanganMenujuRoom1(){
  Berdiri();
  
  BacaSensor();
  LcdDisplay();

  
  while(!(kompasValue >= min_range_west || kompasValue <= max_range_west))
  {
    modeGerak="ki3";
    LcdDisplay();
    Putar("kiri", 32, 35);
    BacaSensor();

  }
  modeGerak="mj";
  LcdDisplay();
  
  MajuAwal();
  Maju(30);

  int kondisiMaju=1, simpang;
  simpang=0;//flag yang menyimpan keadaan robot menemukan simpang 4 di sekitar, nilai ini nantinya digunakan untuk keluar dari while
  while(simpang==0){
    BacaSensor();
    LcdDisplay();

    
    if(kompasValue<min_range_north && kompasValue>min_range_south){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMaju==1) Berdiri();
      Putar("kanan", 32, 30); 
      modeGerak="r1";
      LcdDisplay();
      kondisiMaju=0;
      
    } else if(kompasValue>max_range_north && kompasValue<min_range_north){//robot terlalu ke kanan sehingga perlu memutar ke kiri
      if (kondisiMaju==1) Berdiri();
      modeGerak="r1";
      LcdDisplay();
      Putar("kiri", 32, 30); 
      kondisiMaju=0;
      
    } else if((par_l==0 || par_l>40) && (par_r>=40 || par_r==0) && (par_f>=55 && par_f<=70)){//robot menemukan simpangan kiri
      simpang=1;//lanjut ke rintangan berikutnya
      
    } else if((par_l==0 || par_l>40) && (par_r>=40 || par_r==0) && (par_f<55)){
      MundurAwal();
      for(int i=0; i<=2;i++) Mundur(30);
      Berdiri();
      kondisiMaju=0;
      
    } else{//robot lurus sehingga meneruskan untuk maju
      if (kondisiMaju==0) MajuAwal();
      
      modeGerak="r1";
      LcdDisplay();
      
      Maju(30);
      
      kondisiMaju=1;
    }
  }


  Berdiri();
  BacaSensor();
  LcdDisplay();
  
  while(!((kompasValue >= min_range_north && kompasValue <= max_range_north)))
  {
    modeGerak="ka1";
    LcdDisplay();
    
    Putar("kanan", 32, 30);
    BacaSensor();
    LcdDisplay();
  }
}
