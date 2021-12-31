#ifndef Direction_Control_h
#define Direction_Control_h
#include "PID.h"

class RotationController{
private:
  double targetAngle = 0;
  double lSpeed = 0;
  double rSpeed = 0;
  
public:
  RotationController(){}
  RotationController(double targetAngle){
    this->targetAngle = targetAngle;
  }

  void setAngle(double angle){
    targetAngle = angle;
  }

  void updateSpeed(double PID);

  double getLPow(){
    return lSpeed;
  }
  double getRPow(){
    return rSpeed;
  }
};

class DriveController{
private:
  bool turning;
  bool forward;
  
  double lSpeed = 0;
  double rSpeed = 0;
  double targetX;
  double targetY;

  RotationController rot;
  PIDClass RPID;
  PIDClass TPID;


public:
 
  DriveController(double targetX, double targetY, PIDClass &PID1, PIDClass &PID2);
  DriveController(double targetX, double targetY, PIDClass &PID1, PIDClass &PID2, bool forward);

  void updateSpeed();

  double getLPow(){
    return lSpeed;
  }
  double getRPow(){
    return rSpeed;
  }
};

#endif