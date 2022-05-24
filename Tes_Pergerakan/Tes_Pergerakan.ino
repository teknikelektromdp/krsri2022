#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50

uint8_t servonum = 0;

//Derajat untuk for()
unsigned int PKiD = 90;//Pangkal Kiri Depan. Forward Limit : 60. Backward Limit : 120.
unsigned int TKiD = 80;//Tengah Kiri Depan.
unsigned int UKiD = 80;//Ujung Kiri Depan. Out Limit : 40. In Limit : 100.

unsigned int PKiB = 33;//Pangkal Kiri Belakang. Forward Limit : 1. Backward Limit : 60.
unsigned int TKiB = 40;//Tengah Kiri Belakang.
unsigned int UKiB = 50;//Ujung Kiri Belakang. Out Limit : 80. In Limit : 20.

unsigned int PKaD = 80;//Pangkal Kanan Depan. Forward Limit : 100. Backward Limit : 30.
unsigned int TKaD = 40;//Tengah Kanan Depan.
unsigned int UKaD = 50;//Ujung Kanan Depan. Out Limit : 90/100. In Limit : 30.

unsigned int PKaB = 60;//Pangkal Kanan Belakang. Forward Limit : 100. Backward Limit : 40.
unsigned int TKaB = 90;//Tengah Kanan Belakang.
unsigned int UKaB = 75;//Ujung Kanan Belakang. Out Limit : 35. In Limit : 100.

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
  InitialState();
  delay(5000);
  Maju();
}

void InitialState() {
  //Kaki Kiri Depan
  pwm.setPWM(1, 0, angleToPulse(PKiD) ); //Pangkal
  pwm.setPWM(2, 0, angleToPulse(TKiD) ); //Tengah
  pwm.setPWM(3, 0, angleToPulse(UKiD) ); //Ujung
  
  //Kaki Kiri Belakang
  pwm.setPWM(4, 0, angleToPulse(PKiB) ); //Pangkal
  pwm.setPWM(5, 0, angleToPulse(TKiB) ); //Tengah
  pwm.setPWM(6, 0, angleToPulse(UKiB) ); //Ujung
  
  //Kaki Kanan depan
  pwm.setPWM(8, 0, angleToPulse(PKaD) ); //Pangkal
  pwm.setPWM(9, 0, angleToPulse(TKaD) ); //Tengah
  pwm.setPWM(10, 0, angleToPulse(UKaD) ); //Ujung
  
  //Kaki Kanan Belakang
  pwm.setPWM(12, 0, angleToPulse(PKaB) ); //Pangkal
  pwm.setPWM(13, 0, angleToPulse(TKaB) ); //Tengah
  pwm.setPWM(14, 0, angleToPulse(UKaB) ); //Ujung 
}

void Maju(){
  //Kaki Kiri Depan Maju
  for(UKiD; UKiD >= 50; UKiD--){//Ujung kaki keluar (80 ->50)
    pwm.setPWM(3, 0, angleToPulse(UKiD));//Ujung
  }
  for(PKiD; PKiD >= 70; PKiD--){//Pangkal kaki kedepan (90 ->70)
    pwm.setPWM(1, 0, angleToPulse(PKiD) ); //Pangkal
  }
  for(UKiD; UKiD <= 80; UKiD++){//Ujung kaki keluar (50 -> 80)
    pwm.setPWM(3, 0, angleToPulse(UKiD));//Ujung
  }
  
  pwm.setPWM(3, 0, angleToPulse(UKiD) ); //Ujung
  pwm.setPWM(1, 0, angleToPulse(PKiD) ); //Pangkal
  delay(5000);
  
  //Kaki Kanan Belakang Maju
  for(UKaB; UKaB >= 50; UKaB--){//Ujung kaki keluar (75 -> 50)
    pwm.setPWM(3, 0, angleToPulse(UKaB));//Ujung
  }
  for(PKaB; PKaB <= 100; PKaB++){//Pangkal kaki kedepan (60 -> 100)
    pwm.setPWM(1, 0, angleToPulse(PKaB) ); //Pangkal
  }
  for(UKaB; UKaB <= 75; UKaB++){//Ujung kaki keluar (50 -> 75)
    pwm.setPWM(3, 0, angleToPulse(UKaB));//Ujung
  }
  
   pwm.setPWM(1, 0, angleToPulse(PKaB) ); //Pangkal
   pwm.setPWM(3, 0, angleToPulse(UKaB));//Ujung
   delay (5000);

   //Kaki Kanan Depan Maju, Kaki Kiri Depan dan Kaki Kanan Belakang Mundur
   
}
