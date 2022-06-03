#include <QMC5883LCompass.h>

QMC5883LCompass compass;

int min_range = 253, max_range = 260;
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
void setup() {
  Serial.begin(9600);
  compass.init();
  compassCalibration(); 
  compass.read();
  Serial.println(readCompass()); 
  while(!(readCompass() >= min_range && readCompass() <= max_range))
  {
    compass.read();
    Serial.println(readCompass());  
  }
  delay(5000);
}
void loop() {
  Serial.println("Main Program");
  delay(1000);
}