#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Pixy2.h>

int left_min, left_max, right_min, right_max, front_min, front_max;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// This is the main Pixy object 
Pixy2 pixy;

void initPixy()
{
  left_min = 40;
  left_max = 130;
  right_min = 145;
  right_max = 180;
  front_min = 60;
  front_max = 0;
  pixy.init();
}

void gripMovement(String movement)
{
  //pixy.setServos(lifter, gripper)
  //lcg = lift and close gripper 
  if(movement == "lcg")
  {
    pixy.setServos(0, 25);
  }
  //lift and open gripper
  else if(movement == "log")
  {
    pixy.setServos(0, 500);
  }
  //put and open gripper
  else if(movement == "pog")
  {
    pixy.setServos(700, 500);
  }
  //put and close gripper
  else
  {
    pixy.setServos(600, 25);
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  initPixy();
  gripMovement("lcg");
  //turn on the led
  pixy.setLamp(1, 0);
}

void loop()
{
  //grab blocks!
  pixy.ccc.getBlocks(); 
  //if there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    //object is detected
    //Serial.println("Detected ");
    //check only one object every cycle
    //check x and y coordinates
    if(pixy.ccc.blocks[0].m_y < front_min)
    {
      Serial.println("Move Slowly to Front");
      lcd.setCursor(0,0);
      lcd.print("Move to F");  
    }
    else
    {
      if(pixy.ccc.blocks[0].m_x >= left_min && pixy.ccc.blocks[0].m_x < left_max)
      {
        Serial.println("Move Slowly to Left");
        lcd.setCursor(0,0);
        lcd.print("Move to L");  
      }
      else if(pixy.ccc.blocks[0].m_x >= right_min && pixy.ccc.blocks[0].m_x <= right_max)
      {
        lcd.setCursor(0,0);
        lcd.print("Slowly to Front");
        gripMovement("pcg");
        delay(3000);
        gripMovement("lcg");
      }
      else
      {
        Serial.println("Move Slowly to Right");
        lcd.setCursor(0,0);
        lcd.print("Move to R");    
      }
    }
  } 
  //if there is no object detected
  else
  {
    Serial.println("Not Detected");
    lcd.print("Not Detected"); 
  }
  //remove delay if possible
  delay(1000);
  lcd.clear();
}
