#include "vex.h"

void RotationController::updateSpeed(){
  int dir = -1;

  RPID.PID(angleDiff(odom.getAngle(DEGREES), targetAngle, DEGREES));

  if(sin(degToRadians(targetAngle) - odom.getAngle(RADIANS)) < 0)
    dir = 1;

  lSpeed = dir * RPID.getPow();
  rSpeed = -dir * RPID.getPow();
}

void DriveController::updateSpeed(){
  TPID.PID(vectorLength(targetX, targetY));
  if (forward)
    speed = TPID.getPow();
  else 
    speed = -TPID.getPow();
}

DriveController::DriveController(double targetX, double targetY, PIDClass &PID1){
  this->targetX = targetX;
  this->targetY = targetY;
  forward = true;
  TPID = PID1;
}

DriveController::DriveController(double targetX, double targetY, PIDClass &PID1, bool forward){
  this->targetX = targetX;
  this->targetY = targetY;
  this->forward = forward;
  TPID = PID1;
}

void straightDrive(int &initRPow, int &initLPow){
  PIDClass PID(0.125);

  if (EncoderL.rotation(deg) > EncoderR.rotation(deg)){
    PID.PID(EncoderL.rotation(deg) - EncoderR.rotation(deg), 0, 1);
    initLPow *= PID.getPow(); 
  }
  else if (EncoderL.rotation(deg) < EncoderR.rotation(deg)){
    PID.PID(EncoderR.rotation(deg) - EncoderL.rotation(deg), 0, 1);
    initRPow *= PID.getPow(); 
  }
}