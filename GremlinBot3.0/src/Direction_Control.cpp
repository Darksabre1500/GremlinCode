#include "vex.h"

double Mfl;
double Mfr;
double Mbl;
double Mbr;

bool turning = false;

//https://www.desmos.com/calculator/dadgckbr1z

void Omni_Controller(double relativeAngle, double speed, double startAngle)
{
  //T finds Direction to move, R finds how much to prioritize rotation, and S finds speed
  double T = relativeAngle + startAngle;
  double R = 0;
  double S = speed/200;

  //Power of each diagonal
  double P1 = -cos(T + (M_PI/4));
  double P2 = sin(T + (M_PI/4));

  //Ratio for speed
  double Sr = std::max(std::abs(P1), std::abs(P2)) / S;

  //Motor power calculations
  Mfl = P2/Sr * (1-std::abs(R)) + R*S;
  Mfr = P1/Sr * (1-std::abs(R)) - R*S;
  Mbl = P1/Sr * (1-std::abs(R)) + R*S;
  Mbr = P2/Sr * (1-std::abs(R)) - R*S;

  //Scales power for motor rpm
  Mfl *= 200;
  Mfr *= 200;
  Mbl *= 200;
  Mbr *= 200;

}

double rotation_Controller(double targetAngle, double speed)
{
  double dir = -1;
  if(sin(degToRadians(targetAngle) - angleRad) < 0)
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
    double rSpeed = PIDcontrol.PID(angleDiff(angleWrap(angleRad + dir, RADIANS), targetAngle, RADIANS), 3, 0, 0, 0);
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