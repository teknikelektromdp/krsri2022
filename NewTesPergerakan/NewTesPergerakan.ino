#include <Servo.h>

Servo servoa, servob, servoc, servod, servoe, servof, servog, servoh, servoi, servoj, servok, servol;

int a = 90;
int b = 90;
int c = 90;
int d = 90;
int e = 90;
int f = 90;
int g = 90;
int h = 90;
int i = 90;
int j = 90;
int k = 90;
int l = 90;
int repeat;
int rest = 1000;

void setup() {
  servoa.attach(2);
  servob.attach(3);
  servoc.attach(4);
  servod.attach(5);
  servoe.attach(6);
  servof.attach(7);
  servog.attach(8);
  servoh.attach(9);
  servoi.attach(10);
  servoj.attach(46);
  servok.attach(12);
  servol.attach(44);
  berdiri();
}

void loop() {
  delay(2000);
  trot();
  delay(1000);
}

void berdiri(){
  servoa.write(90);
  servob.write(90);
  servoc.write(90);
  
  servod.write(90);
  servoe.write(90);
  servof.write(90);
  
  servog.write(90);
  servoh.write(90);
  servoi.write(90);
  
  servoj.write(90);
  servok.write(90);
  servol.write(90);
}

void trot(){
  //step 1 left maju
  for(b=90, k=90; b>=70, k<=120; b--, k++){
    servob.write(b);
    servok.write(k);
    delay(10);
  }
  for(a=90, j=90; a>=80, j<=100; a--, j++){
    servoa.write(a);
    servoj.write(j);
    delay (10);
  }
  for(b=70, k=120; b<=90, k>=90; b++, k--){
    servob.write(b);
    servok.write(k);
    delay(10);
  }
  delay(rest);

  for(repeat=0; repeat<20; repeat++){
    //step 2 right maju + Left Mundur
  for(h=90, e=90; h<=110, e>=70; h++, e--){
    servoh.write(h);
    servoe.write(e);
    delay(10);
  }
  for(g=90, d=90, a=80, j=100; g<=95, d>=85, a<=110, j>=70; g++, d--, a++, j--){
    servog.write(g);
    servod.write(d);
    servoa.write(a);
    servoj.write(j);
    delay (10);
  }
  for(h=110, e=70; h>=90, e<=90; h--, e++){
    servoh.write(h);
    servoe.write(e);
    delay(10);
  }
  delay(rest);

  
  //step 3 right mundur + Left Maju
  for(b=90, k=90; b>=70, k<=110; b--, k++){
    servob.write(b);
    servok.write(k);
    delay(10);
  }
  for(g=95, d=85, a=110, j=70; g>=85, d<=95, a>=85, j<=95; g--, d++, a--, j++){
    servog.write(g);
    servod.write(d);
    servoa.write(a);
    servoj.write(j);
    delay (10);
  }
  for(b=70, k=110; b<=90, k>=90; b++, k--){
    servob.write(b);
    servok.write(k);
    delay(10);
  }
  delay(rest);
  }
  
  for(a=85, j=95, g=85, d=95; a<=90, j>=90, g<=90, d>=90; a++, j--, g++, d--){
    servoa.write(a);
    servoj.write(j);
    servog.write(g);
    servod.write(d);
    delay (10);
  }
  delay(5000);
}
//   //step 2 right mundur
//    for(h=130, e=125; h>=85, e>=65; h--, e--){
//    // 120 -> 85
//      servoh.write(h);
//      servoe.write(e);
//      delay(10);
//    }
//    for(g=115, d=60; g>=80, d<=100; g--, d++){
//    // 115 -> 140
//      servog.write(g);
//      servod.write(d);
//      delay (10);
//    }
//    for(h=85, e=65; h<=130, e<=125; h++, e++){
//    // 85 -> 120
//      servoh.write(h);
//      servoe.write(e);
//      delay(10);
//    }
//  //step 3 left mundur
//  for(b=50, k=75; b<=70, k<=90; b++, k++){
//    servob.write(b);
//    servok.write(k);
//    delay(10);
//  }
//  for(a=120, j=115; a<=130, j>=95; a++, j--){
//    servoa.write(a);
//    servoj.write(j);
//    delay (10);
//  }
//  for(b=70, k=90; b>=50, k>=75; b--, k--){
//    servob.write(b);
//    servok.write(k);
//    delay(10);
//  }
//    //step 4 right maju
//    for(h=130, e=125; h>=85, e>=65; h--, e--){
//    // 120 -> 85
//      servoh.write(h);
//      servoe.write(e);
//      delay(10);
//    }
//    for(g=80, d=100; g<=115, d>=60; g++, d--){
//    // 115 -> 140
//      servog.write(g);
//      servod.write(d);
//      delay (10);
//    }
//    for(h=85, e=65; h<=130, e<=125; h++, e++){
//    // 85 -> 120
//      servoh.write(h);
//      servoe.write(e);
//      delay(10);
//    }
