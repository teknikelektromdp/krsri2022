#include <QMC5883LCompass.h>

QMC5883LCompass compass;

int min_range_south, max_range_south, min_range_north, max_range_north, min_range_east, max_range_east, min_range_west, max_range_west;
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
  min_range_north = 0;
  max_range_north = 0;
  min_range_east = 0;
  max_range_east = 0;
  min_range_west = 0;
  min_range_west = 0;
}
void adjustRobotPosition()
{
  while(!(readCompass() >= min_range_south && readCompass() <= max_range_south))
  {
    compass.read();
    Serial.println(readCompass());  
  }
  delay(1000);
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
