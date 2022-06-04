#include <Pixy2.h>
#include <Servo.h>

#define ambil  0
#define letak  1

// This is the main Pixy object 
Pixy2 pixy;
Servo fire;

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");

  fire.attach(9);
  pixy.init();

  //Close the grip
  pixy.setServos(0, 0);
//  pixy.setLamp(0, 0);
  padam(200);
}

void loop()
{ 
  //grab blocks!
  pixy.ccc.getBlocks();
  
  //if there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    //object is detected
    Serial.println("Detected ");
    //check only one object every cycle
    //check x and y coordinates
    if(pixy.ccc.blocks[0].m_y < 60)
    {
      Serial.println("Move Slowly to Front");  
    }
    else
    {
      if(pixy.ccc.blocks[0].m_x >= 40 && pixy.ccc.blocks[0].m_x < 130)
      {
        Serial.println("Move Slowly to Left");  
      }
      else if(pixy.ccc.blocks[0].m_x >= 130 && pixy.ccc.blocks[0].m_x <= 180)
      {
         grip(ambil);
      }
      else
      {
        Serial.println("Move Slowly to Right");   
      }
    }
  } 
  //if there is no object detected
  else
  {
    Serial.println("Not Detected");
  }
  //remove delay if possible
  delay(1000);
}

void padam(int waktu){
  fire.write(150);
  delay(waktu);
  fire.write(10);
}

void grip(int aksi){
  //ambil
  if (aksi==0){
    Serial.println("Gripping...");
    pixy.setServos(500, 0);//turun buka
    delay(1000);
    pixy.setServos(500, 500);//jepit
    delay(1000);
    pixy.setServos(0, 500);//angkat jepit
    delay(1000); 
  }
  //letak
  else if (aksi == 1){
    Serial.println("Gripping...");
    pixy.setServos(500, 500);//turun jepit
    delay(1000);
    pixy.setServos(500, 0);//turun buka
    delay(1000);
    pixy.setServos(0, 0);//angkat buka
    delay(1000); 
  }
}
