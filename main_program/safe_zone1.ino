void SafeZone1(){
  MajuAwal();//persiapan robot maju
  MajuKanan(50);
  MajuKananDorong();
  MajuKiri(50);
  MajuKiriDorong();


  int kondisiMaju=1, par_ld, par_rd, par_r, par_l, par_f, dindingSaveZone1;
  dindingSaveZone1=0;
  while(dindingSaveZone1==0){
    par_ld=Paralax("leftDiagonal");
    par_rd=Paralax("rightDiagonal");
    par_r=Paralax("right");
    par_l=Paralax("left");
    par_f=Paralax("front");
    lcd.clear();

    lcd.setCursor(0,0); lcd.print("LD");lcd.print(par_ld); lcd.print(" RD");lcd.print(par_rd);lcd.print(" R");lcd.print(par_r);lcd.print(" L");lcd.print(par_l);
    lcd.setCursor(12,1); lcd.print("F");lcd.print(par_f);
    
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
      MajuKanan(50);
      MajuKananDorong();
      MajuKiri(50);
      MajuKiriDorong();

      kondisiMaju=1;
    }
  }

  compass.init();
  CompassCalibration(); 
  compass.read();
  InitAzimuth();
  Berdiri();
  int readResult=readCompass();
  lcd.setCursor(0,1);
  lcd.print(readResult);
  while(!(readResult >= min_range_south && readResult <= max_range_south))
  {
    Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
    compass.read();
    readResult=readCompass();
    lcd.setCursor(0,1);lcd.print(readResult); lcd.print("kiri5");
  }
  Berdiri();
}
