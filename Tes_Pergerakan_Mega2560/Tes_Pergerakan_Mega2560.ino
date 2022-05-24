#include <Servo.h>

Servo servoa, servob, servoc, servod, servoe, servof, servog, servoh, servoi, servoj, servok, servol;
int a = 130;
int b = 110;
int c = 110;

int d = 60;
int e = 70;
int f = 65;

int g = 115;
int h = 75;
int i = 90;

int j = 95;
int k = 125;
int l = 110;
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
}

void loop() {
  berdiri();
  delay(10000);
  jalan();
  berdiri();
}

void berdiri(){
  servoa.write(130);
  servob.write(110);
  servoc.write(110);
  
  servod.write(60);
  servoe.write(70);
  servof.write(65);
  
  servog.write(115);
  servoh.write(75);
  servoi.write(90);
  
  servoj.write(95);
  servok.write(125);
  servol.write(110);
}

void jalan(){
  //step 1
  for(c; c>=70; c--){
  // 110 -> 70
    servoc.write(c);
    delay(10);
  }
  for(a; a>=90; a--){
  // 130 -> 90
    servoa.write(a);
    delay (10);
  }
  for(c; c<=110; c++){
  // 70 -> 110
    servoc.write(c);
    delay(10);
  }
  delay(500);

  for(repeat=0; repeat < 3; repeat++){
    //step 2
    for(l; l>=70; l--){
    // 110 -> 70
    servol.write(l);
    delay(10);
    }
    for(j; j<=140; j++){
      // 95 -> 140
      servoj.write(j);
      delay (10);
    }
    for(l; l<=110; l++){
      // 70 -> 110
      servol.write(l);
      delay(10);
    }
    delay(500);
    
    //step 3
    for(i; i<=130; i++){
    // 90 -> 130
      servoi.write(i);
      delay(10);
    }
    for(g; g<=140; g++){
    // 115 -> 140
      servog.write(g);
      delay (10);
    }
    for(i; i>=90; i--){
    // 130 -> 90
      servoi.write(l);
      delay(10);
    }
    servoh.write(85);

    for(a; a<=160 ; a++ ){
    // 90 -> 160
      servoa.write(a);
      delay (10);
    }
    for(j; j>=45; j--){
      // 140 -> 45
      servoj.write(j);
      delay (10);
    }
    delay(500);

    //step 4
    for(f; f<=100; f++){
    // 65 -> 100
    servof.write(f);
    delay(10);
    }
    for(d; d>=20; d--){
    // 60 -> 20
      servod.write(d);
      delay (10);
    }
    for(f; f>=65; f--){
    // 100 -> 65
      servof.write(f);
      delay(10);
    }
    delay(500);

    //step 5
    for(c; c>=70; c--){
    // 110 -> 70
      servoc.write(c);
      delay(10);
    }
    for(a; a>=90; a--){
    // 130 -> 90
      servoa.write(a);
      delay (10);
    }
    for(c; c<=120; c++){
    // 70 -> 120
      servoc.write(c);
      delay(10);
    }
    
    for(g; g>=80 ; g--){
    // 140 -> 80
      servog.write(g);
      delay (10);
    }
    for(d; d<=100; d++){
    // 20 -> 100
      servod.write(d);
      delay (10);
    }
    delay(500);
  }
}
