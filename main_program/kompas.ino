



//Get azimuth value
int readCompass()
{
  return compass.getAzimuth(); 
}
//Calibrated value
void compassCalibration()
{
  compass.setCalibration(-891, 1147, -1741, 433, -177, 250);  
}
void initAzimuth()
{
  min_range_south = 253;
  max_range_south = 260;
  min_range_north = 142;
  max_range_north = 154;
  min_range_east = 197;
  max_range_east = 207;
  min_range_west = 0;
  min_range_west = 0;
}
void adjustRobotPosition()
{
  int readResult=readCompass();
  String arahPutar;
  lcd.print(readResult);

  if(readResult> max_range_south || readResult<148) arahPutar="kiri";
  else if(readResult< min_range_south && readResult>=148)arahPutar="kanan";
  else arahPutar="kanan";

 
  while(!(readResult >= min_range_south && readResult <= max_range_south))
  {
    Putar(arahPutar, 30);
    compass.read();
    readResult=readCompass();
    lcd.setCursor(0,1);
    lcd.print(readResult);
  }
  delay(1000);
}
//Calibrating the compass
void calibration()
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
