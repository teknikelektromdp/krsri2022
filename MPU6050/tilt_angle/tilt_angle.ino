#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

//get an approximate tilt angle from x axis of the accelerometer
float getTiltAngle()
{
  return mpu.getAngleX();  
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  //Start calculating the offset
  delay(1000);
  mpu.calcOffsets(true,true);
}

void loop() {
  mpu.update();
  Serial.println(getTiltAngle());
  
}