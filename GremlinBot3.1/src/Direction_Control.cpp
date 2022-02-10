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

void str8Drive(double &initRPow, double &initLPow, bool fwd, double initLEnc, double initREnc){
  //Bigger this is, the slower the motor will go
  PIDClass PID(0.002);
  double edited;
  double LDiff = EncoderL.rotation(deg) - initLEnc;
  double RDiff = EncoderR.rotation(deg) - initREnc;
  PID.PID(std::abs(LDiff - RDiff), 0, 1);

  if (fwd){
    if (LDiff > RDiff){
      edited = initLPow * (1 - PID.getPow());
      std::cout << "InitL: " << initLPow << " PID: " << PID.getPow() << " Final: " << edited << std::endl;
      initLPow = edited;
    }
    else if (LDiff < RDiff){
      edited = initRPow * (1 - PID.getPow());
      std::cout << "InitR: " << initRPow << " PID: " << PID.getPow() << "Final: " << edited << std::endl;
      initRPow = edited;
    }
  }
  else {
    if (LDiff < RDiff){
      edited = initLPow * (1 - PID.getPow());
      std::cout << "InitL: " << initLPow << " PID: " << PID.getPow() << " Final: " << edited << std::endl;
      initLPow = edited;
    }
    else if (LDiff > RDiff){
      edited = initRPow * (1 - PID.getPow());
      std::cout << "InitR: " << initRPow << " PID: " << PID.getPow() << "Final: " << edited << std::endl;
      initRPow = edited;
    }
  }

}