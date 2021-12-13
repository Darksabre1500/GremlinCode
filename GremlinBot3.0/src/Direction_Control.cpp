#include "vex.h"

void RotationController::updateSpeed(double PID){
  int dir = -1;
  if(sin(degToRadians(targetAngle) - odom.getAngle(RADIANS)) < 0)
    dir = 1;
  lSpeed = dir * PID;
  rSpeed = -dir * PID;
}

void DriveController::updateSpeed(double TPID){
  double angle = odom.getAngle(RADIANS);

  if (!forward)
    angle = angleWrap(odom.getAngle(RADIANS) + M_PI, RADIANS);
  
  if (!turning){
    if (forward){  
      lSpeed = TPID;
      rSpeed = TPID;
    }
    else 
      lSpeed = -TPID;
      rSpeed = -TPID;
  }
  else{
    if(vectorRAngle(targetX, targetY) >= 3.0){
      RPID.PID(vectorRAngle(targetX, targetY));
      rot.updateSpeed(RPID.getPow());
      lSpeed = rot.getLPow();
      rSpeed = rot.getRPow();
    }
    else{
      turning = false;
      lSpeed = 0;
      rSpeed = 0;
    }
  }
}

  DriveController::DriveController(double targetX, double targetY, PIDClass &PID){
    this->targetX = targetX;
    this->targetY = targetY;
    forward = true;
    if (vectorRAngle(targetX, targetY) >= 3.0){
      turning = true;
      RPID = PID;
      rot.setAngle(vectorGAngle(targetX, targetY));
    }
  }

  DriveController::DriveController(double targetX, double targetY, PIDClass &PID, bool forward){
    this->targetX = targetX;
    this->targetY = targetY;
    this->forward = forward;
    if (vectorRAngle(targetX, targetY) >= 3.0){
      turning = true;
      RPID = PID;
      RotationController rot(vectorGAngle(targetX, targetY));
    }
  }