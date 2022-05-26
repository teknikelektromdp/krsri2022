#include <Servo.h>

Servo servoa, servob, servoc, servod, servoe, servof, servog, servoh, servoi, servoj, servok, servol;

int a = 130;
int b = 50;
int c = 60;
int d = 60;
int e = 125;
int f = 125;
int g = 115;
int h = 130;
int i = 140;
int j = 95;
int k = 75;
int l = 60;
int repeat;

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
  servoa.write(130);
  servob.write(50);
  servoc.write(60);
  
  servod.write(60);
  servoe.write(125);
  servof.write(125);
  
  servog.write(115);
  servoh.write(130);
  servoi.write(140);
  
  servoj.write(95);
  servok.write(75);
  servol.write(60);
}

void trot(){
  //step 1 left maju
  for(b=50, k=75; b<=70, k<=90; b++, k++){
    servob.write(b);
    servok.write(k);
    delay(10);
  }
  for(a=130, j=95; a>=120, j<=115; a--, j++){
    servoa.write(a);
    servoj.write(j);
    delay (10);
  }
  for(b=70, k=90; b>=50, k>=75; b--, k--){
    servob.write(b);
    servok.write(k);
    delay(10);
  }

  for(repeat=0; repeat<5; repeat++){
    //step 2 right maju + Left Mundur
  for(h=130, e=125; h>=120, e>=115; h--, e--){
  // 120 -> 85
    servoh.write(h);
    servoe.write(e);
    delay(10);
  }
  for(g=115, d=60, a=120, j=115; g<=125, d>=40, a<=130, j>=95; g++, d--, a++, j--){
  // 115 -> 140
    servog.write(g);
    servod.write(d);
    servoa.write(a);
    servoj.write(j);
    delay (10);
  }
  for(h=120, e=115; h<=130, e<=125; h++, e++){
  // 85 -> 120
    servoh.write(h);
    servoe.write(e);
    delay(10);
  }
  delay(1000);

  
  //step 3 right mundur + Left Maju
  for(b=50, k=75; b<=70, k<=90; b++, k++){
  // 120 -> 85
    servob.write(b);
    servok.write(k);
    delay(10);
  }
  for(g=125, d=40, a=130, j=95; g>=115, d<=60, a>=120, j<=115; g--, d++, a--, j++){
  // 115 -> 140
    servog.write(g);
    servod.write(d);
    servoa.write(a);
    servoj.write(j);
    delay (10);
  }
  for(b=70, k=90; b>=50, k>=75; b--, k--){
  // 85 -> 120
    servob.write(b);
    servok.write(k);
    delay(10);
  }
  delay(1000);
  }
  for(a=120, j=115; a<=130, j>=95; a++, j--){
    servoa.write(a);
    servoj.write(j);
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
