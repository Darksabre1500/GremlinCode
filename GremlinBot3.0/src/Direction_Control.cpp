#include "vex.h"

bool turning = false;

//https://www.desmos.com/calculator/dadgckbr1z

double rotation_Controller(double targetAngle, double speed)
{
  double dir = -1;
  if(sin(degToRadians(targetAngle) - odom.getAngle(RADIANS)) < 0)
    dir = 1;
  return dir * speed;
}

double std_Controller(double target_X, double target_Y, double speed, bool forward) {
  double dir = 0;

  if (!forward)
    dir = M_PI;
  

  if(vectorRAngle(target_X, target_Y) > 2.0){
    turning = true;
    double targetAngle = angleWrap(vectorGAngle(target_X, target_Y) + dir, RADIANS);
    double rSpeed = PIDcontrol.PID(angleDiff(angleWrap(odom.getAngle(RADIANS) + dir, RADIANS), targetAngle, RADIANS), 3, 0, 0, 0);
    return rotation_Controller(targetAngle, rSpeed);
  }
  
  else { 
    turning = false;
    if (!forward)  
      return -speed;
    else 
      return speed;
  }
}