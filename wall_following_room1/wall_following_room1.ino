#include <NewPing.h>

#define SONAR_NUM 6      // Number of sensors.
#define MAX_DISTANCE 60 // Maximum distance (in cm) to ping.
#define MAX_DISTANCE_FRONT 9 // Maximum distance (in cm) to ping.

//ultrasonic pins
const byte left = 24, ld = 26, front = 27, rd = 25, right = 23, gripper = 22;
const byte left_boundary = 8, right_boundary = 8;

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(left, left, MAX_DISTANCE), 
  NewPing(ld, ld, MAX_DISTANCE), 
  NewPing(front, front, MAX_DISTANCE_FRONT),
  NewPing(rd, rd, MAX_DISTANCE), 
  NewPing(right, right, MAX_DISTANCE),
  NewPing(gripper, gripper, MAX_DISTANCE) 
};

int paralax(String sensor)
{
  if(sensor == "left")
  {
    return sonar[0].ping_cm();
  }
  else if(sensor == "ld")
  {
    return sonar[1].ping_cm();
  }
  else if(sensor == "front")
  {
    return sonar[2].ping_cm();
  }
  else if(sensor == "rd")
  {
    return sonar[3].ping_cm();
  }
  else if(sensor == "right")
  {
    return sonar[4].ping_cm();
  }
  else
  {
    return sonar[5].ping_cm();
  }
}
bool is_left_intersection()
{
  
  if(paralax("left") == 0)
  {
      return true;
  }
  else
  {
    return false;
  }
}
bool is_right_intersection()
{
  
  if(paralax("right") == 0)
  {
    return true;
  }
  else
  {
    return false; 
  }
}
bool is_left_undefined()
{
  if(paralax("left") <= left_boundary)
  {
    if(paralax("left") == 0)
    {
      return false; 
    }
    else
    {
      return true;
    }
  }
  else
  {
    return false;  
  }
}
bool is_right_undefined()
{
  if(paralax("right") <= right_boundary)
  {
    if(paralax("right") == 0)
    {
      return false; 
    }
    else
    {
      return true;
    }
  }
  else
  {
    return false;  
  }
}
bool is_front_wall()
{
  if(paralax("front") == 0)
  {
    return false;
  }
  else
  {
    return true;  
  }
}
void wall_following()
{
  if(is_left_intersection() == true || is_right_intersection() == true)
  {
    if(is_left_intersection() == true)
    {
      Serial.println("Turn left");
    } 
    else
    {
      if(is_front_wall())
      {
        Serial.println("Turn right");
      }
      else
      {
        Serial.println("Go straight");  
      }  
    }
  }
  else
  {
    Serial.println("Follow the current line"); 
  } 
}
void setup() 
{
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}
void loop() 
{ 
  delay(50);
  wall_following();
  delay(1000);
}
