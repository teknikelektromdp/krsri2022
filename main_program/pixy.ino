void GripperPixy(){
  
  //grab blocks!
  pixy.ccc.getBlocks();
  
  //if there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    //object is detected
//    Serial.println("Detected ");
    lcd.setCursor(0,0);lcd.print("Detected");
    //check only one object every cycle
    //check x and y coordinates
    if(pixy.ccc.blocks[0].m_y < 60)
    {
      Serial.println("Move Slowly to Front");
    }
    else
    {
      if(pixy.ccc.blocks[0].m_x >= 40 && pixy.ccc.blocks[0].m_x < 130)
      {
        Serial.println("Move Slowly to Left");  
//        Putar("kiri", 10, 30);
//        lcd.clear());
//        lcd.setCursor(0,1); lcd.print("go left");
      }
      else if(pixy.ccc.blocks[0].m_x >= 130 && pixy.ccc.blocks[0].m_x <= 180)
      {
         Grip(ambil);
//         Putar("kiri", 32, 30);
      }
      else
      {
        Serial.println("Move Slowly to Right"); 
//        Putar("kanan", 10, 30);
//        lcd.clear();
//        lcd.setCursor(0,1);lcd.print("go right");
      }
    }
  } 
  //if there is no object detected
  else
  {
    Serial.println("Not Detected");
//    lcd.clear();
//    lcd.setCursor(0,0);lcd.print("Not Detected");
  }
  //remove delay if possible
  delay(1000);
}

void Padam(int waktu){
  fire.write(150);
  delay(waktu);
  fire.write(10);
}

void Grip(int aksi){
  //ambil
  if (aksi==0){
    Serial.println("Gripping...");
    pixy.setServos(500, 500);//turun buka
    delay(1000);
    pixy.setServos(500, 0);//jepit
    delay(1000);
    pixy.setServos(0, 0);//angkat jepit
    delay(1000); 
  }
  //letak
  else if (aksi == 1){
    Serial.println("Gripping...");
    pixy.setServos(500, 0);//turun jepit
    delay(1000);
    pixy.setServos(500, 500);//turun buka
    delay(1000);
    pixy.setServos(500, 500);//angkat buka
    delay(1000); 
  }
}
