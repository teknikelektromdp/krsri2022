//fungsi yang terkait display lcd
// baris 1 ==> left ; left diagonal ; front ; right diagonal; right ; gripper
// baris 2 ==> mode, kompas
void LcdDisplay(){ 
    lcd.setCursor(0,0);
    lcd.print(par_l); lcd.print(";"); lcd.print(par_ld); lcd.print(";"); lcd.print(par_f); lcd.print(";"); lcd.print(par_rd); lcd.print(";"); lcd.print(par_r); lcd.print(";    ");

    lcd.setCursor(0, 1);
    lcd.print(par_g); lcd.print(";"); lcd.print(par_b); lcd.print(";"); lcd.print(kompasValue); lcd.print(";"); lcd.print(modeGerak); lcd.print(";    ");
}


void BacaSensor(){
  par_ld=Paralax("leftDiagonal");
  par_rd=Paralax("rightDiagonal");
  par_r=Paralax("right");
  par_l=Paralax("left");
  par_f=Paralax("front");
  par_b=Paralax("behind");
  par_g=Paralax("gripper");
  kompasValue=readCompass();
}

void LcdSetup(){
  lcd.init();
  lcd.backlight();
  lcd.print("Start!");
}
