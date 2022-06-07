#define SONAR_NUM 7      // Number of sensors.
#define MAX_DISTANCE 80 // Maximum distance (in cm) to ping.
#define MAX_DISTANCE_FRONT 200 // Maximum distance (in cm) to ping.
#define MAX_DISTANCE_BEHIND 200 // Maximum distance (in cm) to ping.
//ultrasonic pins
const byte left = 24, leftDiagonal = 26, front = 27, rightDiagonal = 25, right = 23, gripper = 22, behind = 28;
const byte leftBoundary = 8, rightBoundary = 8;

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(left, left, MAX_DISTANCE), 
  NewPing(leftDiagonal, leftDiagonal, MAX_DISTANCE), 
  NewPing(front, front, MAX_DISTANCE_FRONT),
  NewPing(rightDiagonal, rightDiagonal, MAX_DISTANCE), 
  NewPing(right, right, MAX_DISTANCE),
  NewPing(behind, behind, MAX_DISTANCE_BEHIND),
  NewPing(gripper, gripper, MAX_DISTANCE) 
};


//Paralax distance value
int Paralax(String sensor)
{
  if(sensor == "left")
  {
    return sonar[0].ping_cm();
  }
  else if(sensor == "leftDiagonal")
  {
    return sonar[1].ping_cm();
  }
  else if(sensor == "front")
  {
    return sonar[2].ping_cm();
  }
  else if(sensor == "rightDiagonal")
  {
    return sonar[3].ping_cm();
  }
  else if(sensor == "right")
  {
    return sonar[4].ping_cm();
  }
  else if(sensor == "behind")
  {
    return sonar[5].ping_cm();
  }
  else
  {
    return sonar[6].ping_cm();
  }
}

//cek ada atau tidaknya jalan di sisi kiri robot
bool LeftIntersect()
{
  
  if(Paralax("left") == 0)
  {
      return true;
  }
  else
  {
    return false;
  }
}

//cek ada atau tidaknya jalan di sisi kanan robot
bool RightIntersect()
{
  
  if(Paralax("right") == 0)
  {
    return true;
  }
  else
  {
    return false; 
  }
}

//cek apakah sisi kiri robot terlalu dekat dengan dindig atau tidak
bool is_left_undefined()
{
  if(Paralax("left") <= leftBoundary)
  {
    if(Paralax("left") == 0)
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

//cek apakah sisi kanan robot terlalu dekat dengan dindig atau tidak
bool is_right_undefined()
{
  if(Paralax("right") <= rightBoundary)
  {
    if(Paralax("right") == 0)
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

//cek adanya dinding di depan robot
bool FrontWall()
{
  if(Paralax("front") == 0)
  {
    return false;
  }
  else
  {
    return true;  
  }
}

/**
   * Wall following
  
  void WallFollowing()
  {
    //cek persimpangan sebelah kiri dan kanan
    if(LeftIntersect() == true || RightIntersect() == true)
    {
      if(LeftIntersect() == true)
      {
        for(int i = 0; )
        PutarKiri();
      } 
      else
      {
        //cek apakah ada dinding di depan robot atau ridak
        if(is_front_wall() == true)
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
*/
