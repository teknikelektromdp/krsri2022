void MenujuRoom1(){
  compass.init();
  CompassCalibration(); 
  compass.read();
  InitAzimuth();

  Berdiri();
  int readResult=readCompass();
  lcd.setCursor(0,1);
  lcd.print(readResult);
  while(!(readResult >300))
  {
    Putar("kiri", 32, 30);
    compass.read();
    readResult=readCompass();
    lcd.setCursor(0,0);lcd.print(readResult); lcd.print("kiri3");
  }
  lcd.setCursor(3,1);lcd.print("maju");

  MajuAwal();
  MajuKanan(30);
  MajuKananDorong();
  MajuKiri(30);
  MajuKiriDorong();

  int kondisiMaju=1, par_ld, par_rd, par_r, par_l, par_f, simpang;
  simpang=0;//flag yang menyimpan keadaan robot menemukan simpang 4 di sekitar, nilai ini nantinya digunakan untuk keluar dari while
  while(simpang==0){
    par_ld=Paralax("leftDiagonal");
    par_rd=Paralax("rightDiagonal");
    par_r=Paralax("right");
    par_l=Paralax("left");
    par_f=Paralax("front");
    lcd.clear();

    lcd.setCursor(0,0); lcd.print("LD");lcd.print(par_ld); lcd.print(" RD");lcd.print(par_rd);lcd.print(" R");lcd.print(par_r);lcd.print(" L");lcd.print(par_l);
    lcd.setCursor(12,1); lcd.print("F");lcd.print(par_f);

    
    if((par_ld<=13 && par_ld>0) || (par_l<=10 && par_l>0)){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMaju==1) Berdiri();
      Putar("kanan", 32, 30); 
      lcd.setCursor(0,1); lcd.print("room1");
      kondisiMaju=0;
      
    } else if((par_rd<=13 && par_rd>0) || (par_r<=10 && par_r>0)){//robot terlalu ke kanan sehingga perlu memutar ke kiri
      if (kondisiMaju==1) Berdiri();
      lcd.setCursor(0,1); lcd.print("room1");
      Putar("kiri", 32, 30); 
      kondisiMaju=0;
      
    } else if((par_l==0 || par_l>40) && (par_r>=40 || par_r==0) && (par_f>=55 && par_f<=65)){//robot menemukan simpangan kiri
      simpang=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk maju
      if (kondisiMaju==0) MajuAwal();

      MajuKanan(30);
      MajuKananDorong();
      MajuKiri(30);
      MajuKiriDorong();

      lcd.setCursor(0,1); lcd.print("room1");
      kondisiMaju=1;
    }
  }


  Berdiri();
  lcd.setCursor(0,1);
  lcd.print(readResult);
  
  while(!(readResult >= min_range_north && readResult <= max_range_north))
  {
    Putar("kanan", 32, 30);
    compass.read();
    readResult=readCompass();
    lcd.setCursor(0,1);lcd.print(readResult); lcd.print("kanan1");
  }
}
