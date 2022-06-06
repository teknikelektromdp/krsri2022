#include <QMC5883LCompass.h>

QMC5883LCompass compass;

int min_range_south, max_range_south, min_range_north, max_range_north, min_range_east, max_range_east, min_range_west, max_range_west;
int calibrationData[3][2];
bool changed = false;
bool done = false;
int t = 0;
int c = 0;

//Get azimuth value
int readCompass()
{
  return compass.getAzimuth(); 
}
//Calibrated value
void compassCalibration()
{
//   compass.setCalibration(-891, 1147, -1741, 433, -177, 250);
  compass.setCalibration(0, 3072, -938, 743, -268, 133);
}
void initAzimuth()
{
  min_range_south = 253;
  max_range_south = 260;
  min_range_north = 0;
  max_range_north = 0;
  min_range_east = 0;
  max_range_east = 0;
  min_range_west = 0;
  min_range_west = 0;
}
void adjustRobotPosition()
{
  int readResult=readCompas();
  while(!(readResult >= min_range_south && readResult <= max_range_south))
  {
    compass.read();
    Serial.println(readResult);
    readResult=readCompas();  
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
void setup() {
  Serial.begin(9600);
  compass.init();
  compassCalibration(); 
  compass.read();
  initAzimuth();
  adjustRobotPosition();
}
void loop() {
  Serial.println("Main Program");
  delay(1000);
}
