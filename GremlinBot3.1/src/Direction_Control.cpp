#include "vex.h"

void RotationController::updateSpeed(double PID){
  int dir = -1;
  if(sin(degToRadians(targetAngle) - odom.getAngle(RADIANS)) < 0)
    dir = 1;
  lSpeed = dir * PID;
  rSpeed = -dir * PID;
}

void DriveController::updateSpeed(){
  if (!turning){
    TPID.PID(vectorLength(targetX, targetY));
    if (forward){  
      lSpeed = TPID.getPow();
      rSpeed = TPID.getPow();
    }
    else 
      lSpeed = -TPID.getPow();
      rSpeed = -TPID.getPow();
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
      LFM.stop(brake);
      RFM.stop(brake);
      LBM.stop(brake);
      RBM.stop(brake);
    }
  }
}

DriveController::DriveController(double targetX, double targetY, PIDClass &PID1, PIDClass &PID2){
  this->targetX = targetX;
  this->targetY = targetY;
  forward = true;
  if (vectorRAngle(targetX, targetY) >= 3.0){
    turning = true;
    RPID = PID1;
    TPID = PID2;
    rot.setAngle(vectorGAngle(targetX, targetY));
  }
}

DriveController::DriveController(double targetX, double targetY, PIDClass &PID1, PIDClass &PID2, bool forward){
  this->targetX = targetX;
  this->targetY = targetY;
  this->forward = forward;
  if (vectorRAngle(targetX, targetY) >= 3.0){
    turning = true;
    RPID = PID1;
    TPID = PID2;
    RotationController rot(vectorGAngle(targetX, targetY));
  }
}