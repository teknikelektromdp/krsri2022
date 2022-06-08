//inisialisasi kompas
void CompassSetup(){
  compass.init();
  CompassCalibration();
  InitAzimuth();
}

//Get azimuth value
int readCompass()
{
  compass.read();
  return compass.getAzimuth(); 
}
//Calibrated value
void CompassCalibration()
{
  compass.setCalibration(0, 3072, -938, 743, -268, 133);  
}
void InitAzimuth()
{
  min_range_south = 268;
  max_range_south = 282;
  min_range_north = 85;
  max_range_north = 105;
  min_range_east = 205;
  max_range_east = 230 ;
  min_range_west = 0;
  max_range_west = 55;
}

//fungsi untuk memutar robot ke selatan
void AdjustRobotPositionSelatan()
{
  BacaSensor();
  LcdDisplay();

//  if(readResult> max_range_south || readResult<148) arahPutar="kiri";
//  else if(readResult< min_range_south && readResult>=148)arahPutar="kanan";
//  else arahPutar="kiri";

  while(!(kompasValue >= min_range_south && kompasValue <= max_range_south))
  {
    if(kompasValue> max_range_south || kompasValue<((min_range_north + max_range_north)/2)){
      Putar("kiri", 32, 30);
    }
    else if(kompasValue< min_range_south && kompasValue>=((min_range_north + max_range_north)/2)){
      Putar("kanan", 32, 30);
    }
    else{
      Putar("kiri", 32, 30);
    }
      
    BacaSensor();
    modeGerak="h";
    LcdDisplay();
  }
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
