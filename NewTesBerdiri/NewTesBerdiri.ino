#include <Servo.h>

Servo servoa, servob, servoc, servod, servoe, servof, servog, servoh, servoi, servoj, servok, servol;




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
