void RintanganPuing2(){
  MundurAwal();//persiapan robot maju
  MundurKiri(50);
  MundurKiriDorong();
  MundurKanan(50);
  MundurKananDorong();


  int kondisiMundur=1, par_ld, par_rd, par_r, par_l, par_f, par_g, dindingRuang1;
  dindingRuang1=0;
  while(dindingRuang1==0){
    par_ld=Paralax("leftDiagonal");
    par_rd=Paralax("rightDiagonal");
    par_r=Paralax("right");
    par_l=Paralax("left");
    par_f=Paralax("front");
    par_g=Paralax("gripper");
    lcd.clear();

    lcd.setCursor(0,0); lcd.print("LD");lcd.print(par_ld); lcd.print(" RD");lcd.print(par_rd);lcd.print(" R");lcd.print(par_r);lcd.print(" L");lcd.print(par_l);
    lcd.setCursor(10,1); lcd.print("F");lcd.print(par_f); lcd.print(" G");lcd.print(par_g);

    
    if((par_ld>=22 && par_ld<30) || (par_l<=10 && par_l>0)){//robot terlalu ke kiri sehingga perlu memutar ke kanan
      if (kondisiMundur==1) Berdiri();
      lcd.setCursor(0,1); lcd.print("puing2");
      Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
      kondisiMundur=0;
      
    } else if((par_rd<30 && par_rd>=22) || (par_r<=10 && par_r>00)){//robot terlalu ke kanan sehingga perlu memutar ke kiri
      if (kondisiMundur==1) Berdiri();
      lcd.setCursor(0,1); lcd.print("puing2");
      Putar("kanan", 32, 30); //berputar sejauh 32 derajat 
      kondisiMundur=0;
      
    } else if((par_g<10 || par_g<40) && (par_l>=10 && par_l<30) && (par_r>=10 && par_r<30)){//robot menemukan simpangan kiri
      dindingRuang1=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk maju
      if (kondisiMundur==0) MundurAwal();

//      lcd.setCursor(10,0); lcd.print("maju");
      lcd.setCursor(0,1); lcd.print("puing2");
      MundurKiri(30);
      MundurKiriDorong();
      MundurKanan(30);
      MundurKananDorong();

      kondisiMundur=1;
    }
  }



  //Mempersiapkan untuk melakukan pemadaman dan penyelamatan
  compass.init();
  CompassCalibration(); 
  compass.read();
  InitAzimuth();
  Berdiri();
  int readResult=readCompass();
  lcd.setCursor(0,1);
  lcd.print(readResult);
  while(!(readResult >= min_range_north && readResult <= max_range_north))
  {
    Putar("kiri", 32, 30);//berputar sejauh 32 derajat 
    compass.read();
    readResult=readCompass();
    lcd.setCursor(0,1);lcd.print(readResult); lcd.print("kiri5");
  }
  Berdiri();
}
