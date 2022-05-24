#include <Servo.h>

Servo servoa, servob, servoc, servod, servoe, servof, servog, servoh, servoi, servoj, servok, servol;
//int a, b, c, d, e, f, g, h, i, j, k, l;

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
  servoa.write(130);
  servob.write(110);
  servoc.write(110);
  
  servod.write(60);
  servoe.write(65);
  servof.write(65);
  
  servog.write(115);
  servoh.write(70);
  servoi.write(130);
  
  servoj.write(95);
  servok.write(125);
  servol.write(110);
}
