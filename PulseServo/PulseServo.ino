#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600

uint8_t servonum = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("3 Channel Servo Test");
  pwm.begin();
  pwm.setPWMFreq(60);
  delay (10);
}

void setServoPulse(uint8_t n, double pulse){
  double pulselength;
  pulselength = 1000000;
  pulselength /=60;
  Serial.print (pulselength); Serial.println(" us per period");
  pulselength /=4096;
  Serial.print (pulselength); Serial.println(" us per bit");
  pulse *= 1000000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n,0,pulse);
}

void loop(){
  servonum = 0;
  uint16_t posisi =0;
  Serial.println(posisi);
  uint16_t pulselen = posisi/180.0*450+150;
  Serial.println(pulselen);
  pwm.setPWM(1,0,pulselen);
  pwm.setPWM(2,0,pulselen);
  pwm.setPWM(3,0,pulselen);
  delay(500);
  delay(10000);
}
