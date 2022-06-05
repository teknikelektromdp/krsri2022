#define SONAR_NUM 6      // Number of sensors.
#define MAX_DISTANCE 60 // Maximum distance (in cm) to ping.
#define MAX_DISTANCE_FRONT 20 // Maximum distance (in cm) to ping.

//ultrasonic pins
const byte left = 24, leftDiagonal = 26, front = 27, rightDiagonal = 25, right = 23, gripper = 22;
const byte leftBoundary = 8, rightBoundary = 8;

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(left, left, MAX_DISTANCE), 
  NewPing(leftDiagonal, leftDiagonal, MAX_DISTANCE), 
  NewPing(front, front, MAX_DISTANCE_FRONT),
  NewPing(rightDiagonal, rightDiagonal, MAX_DISTANCE), 
  NewPing(right, right, MAX_DISTANCE),
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
  else
  {
    return sonar[5].ping_cm();
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
