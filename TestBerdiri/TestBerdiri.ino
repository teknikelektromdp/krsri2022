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
int angleToPulse(int ang) {
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX);
  return pulse;

}
void loop() {
  // put your main code here, to run repeatedly:
  Berdiri();
}

void Berdiri() {
  //Kaki Kiri Depan
  pwm.setPWM(1, 0, angleToPulse(90) ); //Pangkal 90
  pwm.setPWM(2, 0, angleToPulse(80) ); //Tengah 80
  pwm.setPWM(3, 0, angleToPulse(80) ); //Ujung 80

  //Kaki Kiri Belakang
  pwm.setPWM(4, 0, angleToPulse(33) ); //Pangkal33
  pwm.setPWM(5, 0, angleToPulse(40) ); //Tengah 40
  pwm.setPWM(6, 0, angleToPulse(50) ); //Ujung50

  //Kaki Kanan depan
  pwm.setPWM(8, 0, angleToPulse(80) ); //Pangkal 80
  pwm.setPWM(9, 0, angleToPulse(40) ); //Tengah 40
  pwm.setPWM(10, 0, angleToPulse(50) ); //Ujung 50
  
  //Kaki Kanan Belakang
  pwm.setPWM(12, 0, angleToPulse(60) ); //Pangkal 60
  pwm.setPWM(13, 0, angleToPulse(90) ); //Tengah 90
  pwm.setPWM(14, 0, angleToPulse(30) ); //Ujung 75
}
