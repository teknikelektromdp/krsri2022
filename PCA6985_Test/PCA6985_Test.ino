#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50

uint8_t servonum = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}
int angleToPulse(int ang){
  int pulse = map(ang,0,180,SERVOMIN, SERVOMAX);
  return pulse;
  
}
void loop() {
  // put your main code here, to run repeatedly:
pwm.setPWM(0, 0, angleToPulse(180) );
pwm.setPWM(1, 0, angleToPulse(180) );
delay (1000);
pwm.setPWM(0, 0, angleToPulse(0) );
pwm.setPWM(1, 0, angleToPulse(0) );
delay (1000);
}
