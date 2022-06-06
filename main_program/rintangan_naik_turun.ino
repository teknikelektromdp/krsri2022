void NaikTurun(){
  int kondisiMaju=1, par_ld, par_rd, par_r, par_l, par_f, dinding3;

//  dinding3=0;//flag yang menyimpan keadaan robot menemukan dinding di depan, nilai ini nantinya digunakan untuk keluar dari while
//  while(dinding3==0){
    par_ld=Paralax("leftDiagonal");
    par_rd=Paralax("rightDiagonal");
    par_r=Paralax("right");
    par_l=Paralax("left");
    par_f=Paralax("front");
    lcd.clear();

    lcd.setCursor(0,0); lcd.print("LD");lcd.print(par_ld); lcd.print(" RD");lcd.print(par_rd);lcd.print(" R");lcd.print(par_r);lcd.print(" L");lcd.print(par_l);
    lcd.setCursor(12,1); lcd.print("F");lcd.print(par_f);

  int keluarNaikTurun = 0;

  BerdiriNaik();
  NaikMajuAwal();
  while(keluarNaikTurun==0){
    NaikMajuKanan();
    NaikMajuKananDorong();
    NaikMajuKiri();
    NaikMajuKiriDorong();
    lcd.setCursor(0,0); lcd.print("LD");lcd.print(par_ld); lcd.print(" RD");lcd.print(par_rd);lcd.print(" R");lcd.print(par_r);lcd.print(" L");lcd.print(par_l);
    lcd.setCursor(12,1); lcd.print("F");lcd.print(par_f);
    lcd.setCursor(0,1); lcd.print("naik");
    if ((par_f<45 && par_f>0) && (par_f >=40 || par_f == 0) && (par_r>40 && par_r==0)) keluarNaikTurun=1;
//    Berdiri();
//    MajuAwal();
//    while(Paralax("front")==0 || Paralax("front")>45){
//      MajuKanan(30);
//      MajuKananDorong();
//      MajuKiri(30);
//      MajuKiriDorong();
    }

}
