//Get azimuth value
int readCompass()
{
  return compass.getAzimuth(); 
}
//Calibrated value
void CompassCalibration()
{
  compass.setCalibration(0, 3072, -938, 743, -268, 133);  
}
void InitAzimuth()
{
  min_range_south = 300;
  max_range_south = 310;
  min_range_north = 70;
  max_range_north = 80;
  min_range_east = 245;
  max_range_east = 255;
  min_range_west = 10;
  min_range_west = 19;
}

//fungsi untuk memutar robot ke selatan
void AdjustRobotPositionSelatan()
{
  int readResult=readCompass();
//  String arahPutar;
  lcd.print(readResult);
  Serial.print(readResult);

//  if(readResult> max_range_south || readResult<148) arahPutar="kiri";
//  else if(readResult< min_range_south && readResult>=148)arahPutar="kanan";
//  else arahPutar="kiri";

 
  while(!(readResult >= min_range_south && readResult <= max_range_south))
  {
    if(readResult> max_range_south || readResult<((min_range_north + max_range_north)/2)){
      Putar("kiri", 32, 30);
    }
    else if(readResult< min_range_south && readResult>=148){
      Putar("kanan", 32, 30);
    }
    else{
      Putar("kiri", 32, 30);
      }
    
    compass.read();
    readResult=readCompass();
    lcd.clear();
    lcd.setCursor(0,0);lcd.print("home");
    lcd.setCursor(5,1);
    lcd.print(readResult);
//    Serial.println(readResult);
  }
//  delay(1000);
}


//Calibrating the compass
void Calibration()
{
  int x, y, z; 
  // Read compass values
  compass.read();
  // Return XYZ readings
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  changed = false;

  if(x < calibrationData[0][0]) {
    calibrationData[0][0] = x;
    changed = true;
  }
  if(x > calibrationData[0][1]) {
    calibrationData[0][1] = x;
    changed = true;
  }

  if(y < calibrationData[1][0]) {
    calibrationData[1][0] = y;
    changed = true;
  }
  if(y > calibrationData[1][1]) {
    calibrationData[1][1] = y;
    changed = true;
  }

  if(z < calibrationData[2][0]) {
    calibrationData[2][0] = z;
    changed = true;
  }
  if(z > calibrationData[2][1]) {
    calibrationData[2][1] = z;
    changed = true;
  }

  if (changed && !done) {
    Serial.println("CALIBRATING... Keep moving your sensor around.");
    c = millis();
  }
  t = millis();
  
  if ( (t - c > 5000) && !done) {
    done = true;
    Serial.println("DONE. Copy the line below and paste it into your projects sketch.);");
    Serial.println();
      
    Serial.print("compass.setCalibration(");
    Serial.print(calibrationData[0][0]);
    Serial.print(", ");
    Serial.print(calibrationData[0][1]);
    Serial.print(", ");
    Serial.print(calibrationData[1][0]);
    Serial.print(", ");
    Serial.print(calibrationData[1][1]);
    Serial.print(", ");
    Serial.print(calibrationData[2][0]);
    Serial.print(", ");
    Serial.print(calibrationData[2][1]);
    Serial.println(");");
  }  
}
//void setup() {
//  Serial.begin(9600);
//  compass.init();
//  compassCalibration(); 
//  compass.read();
//  initAzimuth();
//  adjustRobotPosition();
//}
//void loop() {
//  Serial.println("Main Program");
//  delay(1000);
//}
