void RintanganPuing1(){
  MajuAwal();//persiapan robot maju
  MajuKanan(50);
  MajuKananDorong();
  MajuKiri(50);
  MajuKiriDorong();


  int kondisiMaju=1, par_ld, par_rd, par_r, par_l, par_f, dinding2;
  dinding2=0;
  while(dinding2==0){
    par_ld=Paralax("leftDiagonal");
    par_rd=Paralax("rightDiagonal");
    par_r=Paralax("right");
    par_l=Paralax("left");
    par_f=Paralax("front");
    lcd.clear();

    lcd.setCursor(0,0); lcd.print("LD");lcd.print(par_ld); lcd.print(" RD");lcd.print(par_rd);
    lcd.setCursor(8,0); lcd.print("R");
    lcd.setCursor(9,0); lcd.print(par_r);
    lcd.setCursor(11,0); lcd.print("L");
    lcd.setCursor(12,0); lcd.print(par_l);
    lcd.setCursor(12,1); lcd.print(par_f);
    
    if((par_ld<=13 && par_ld>0) || (par_l<=10 && par_l>0)){
      if (kondisiMaju==1) Berdiri();
//      lcd.setCursor(10,0); lcd.print("kanan");
      Putar("kanan", 50); 
      kondisiMaju=0;
      
    } else if((par_rd<=13 && par_rd>0) || (par_r<=10 && par_r>0)){
      if (kondisiMaju==1) Berdiri();
//      lcd.setCursor(10,1); lcd.print("kiri");
      Putar("kiri", 50); 
      kondisiMaju=0;
      
    } else if((par_l==0 || par_l>40) && (par_f<=20 && par_f>0)){//robot menemukan simpangan kiri
      dinding2=1;//lanjut ke rintangan berikutnya 
      
    } else{
      if (kondisiMaju==0) MajuAwal();

//      lcd.setCursor(10,0); lcd.print("maju");
//      lcd.setCursor(10,1); lcd.print("maju");
      MajuKanan(50);
      MajuKananDorong();
      MajuKiri(50);
      MajuKiriDorong();

      kondisiMaju=1;
    }
  }

  //memutar robot ke arah utara/rintangan naik-turun
  Berdiri();
  int readResult=readCompass();
  lcd.setCursor(0,1);
  lcd.print(readResult);
  while(!(readResult >= 142 && readResult <= 154))
  {
    Putar("kiri2", 30);
    compass.read();
    readResult=readCompass();
    lcd.setCursor(0,1);lcd.print(readResult); lcd.print("kiri");
  }
  lcd.setCursor(3,1);lcd.print("maju");
}
