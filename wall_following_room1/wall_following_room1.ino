// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define SONAR_NUM 6      // Number of sensors.
#define MAX_DISTANCE 60 // Maximum distance (in cm) to ping.
#define MAX_DISTANCE_FRONT 9 // Maximum distance (in cm) to ping.

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(2, 2, MAX_DISTANCE), //left
  NewPing(3, 3, MAX_DISTANCE), // left diagonal 
  NewPing(4, 4, MAX_DISTANCE_FRONT), // front
  NewPing(5, 5, MAX_DISTANCE), // right diagonal
  NewPing(6, 6, MAX_DISTANCE), // right
  NewPing(7, 7, MAX_DISTANCE) // gripper
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
  if(paralax("left") <= 8)
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
  if(paralax("right") <= 8)
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
void setup() 
{
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}
void loop() 
{ 
  delay(50);
  Serial.print("Front : ");
  Serial.println(paralax("front"));
  Serial.print("Left : ");
  Serial.println(paralax("left"));
  Serial.print("Right : ");
  Serial.println(paralax("right"));
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
  
  delay(1000);
}
