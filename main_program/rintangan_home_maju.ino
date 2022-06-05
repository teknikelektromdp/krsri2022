void RintanganHomeMaju() {
  //robot maju 
  MajuAwal();
  MajuKanan(30);
  MajuKananDorong();
  MajuKiri(30);
  MajuKiriDorong();

  int kondisiMaju=1, par_ld, par_rd, par_r, par_l, par_f, dinding1;
  dinding1=0;//flag yang menyimpan keadaan robot menemukan dinding di depan, nilai ini nantinya digunakan untuk keluar dari while
  while(dinding1==0){
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
//      lcd.setCursor(10,0); lcd.print("kanan");
      Putar("kanan", 30); 
      kondisiMaju=0;
      
    } else if((par_rd<=13 && par_rd>0) || (par_r<=10 && par_r>0)){//robot terlalu ke kanan sehingga perlu memutar ke kiri
      if (kondisiMaju==1) Berdiri();
//      lcd.setCursor(10,1); lcd.print("kiri");
      Putar("kiri", 30); 
      kondisiMaju=0;
      
    } else if((par_l==0 || par_l>40) && (par_f<=20 && par_f>0)){//robot menemukan simpangan kiri
      dinding1=1;//lanjut ke rintangan berikutnya

    } else{//robot lurus sehingga meneruskan untuk maju
      if (kondisiMaju==0) MajuAwal();

//      lcd.setCursor(10,0); lcd.print("maju");
//      lcd.setCursor(10,1); lcd.print("maju");
      MajuKanan(30);
      MajuKananDorong();
      MajuKiri(30);
      MajuKiriDorong();

      kondisiMaju=1;
    }
  }

  // posisi menghadap puing 1
  Berdiri();
  int readResult=readCompass();
  lcd.setCursor(0,1);
  lcd.print(readResult);
  while(!(readResult >= 197 && readResult <= 207))
  {
    Putar("kiri1", 30);
    compass.read();
    readResult=readCompass();
    lcd.setCursor(0,1);lcd.print(readResult); lcd.print("kiri");
  }
  lcd.setCursor(3,1);lcd.print("maju");
}
