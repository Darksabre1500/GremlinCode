#include "vex.h"

 //This function moves the bot to the specified coordinates. The bot will always start at 0, 0 on startup. 
//If it times out, it will move on to the next function even if it still hasn't finished. 
//Units are in inches and seconds respectivley.
void GoTo(double target_X, double target_Y, double timeout, bool facingFront)
{
  TimeoutClock timer;
  PIDClass RPID(3);
  PIDClass TPID(16);
  DriveController drive(target_X, target_Y, RPID, TPID, facingFront);

  while(std::abs(target_Y-odom.getY()) > 1 || std::abs(target_X-odom.getX()) > 1)
  {
    drive.updateSpeed();

    LFM.spin(fwd, drive.getLPow(), rpm);
    LBM.spin(fwd, drive.getLPow(), rpm);
    RFM.spin(fwd, drive.getRPow(), rpm);
    RBM.spin(fwd, drive.getRPow(), rpm);

    if (timer.getTime() > timeout)
      break;

    wait(5, msec);
  }
  LFM.stop(brake);
  RFM.stop(brake);
  LBM.stop(brake);
  RBM.stop(brake);
}

//This function turns the bot to the specified angle. The bot will start at 90 Degrees on startup.
//It will always take the shortest route to the target angle.
//Units are in Degrees and Seconds.
void TurnTo(double target_angle, double timeout)
{
  TimeoutClock timer;
  PIDClass RPID(3);
  RotationController Rot(target_angle);
  while(std::abs(target_angle - odom.getAngle(DEGREES)) > 3)
  {
    RPID.PID(angleDiff(odom.getAngle(DEGREES), target_angle, DEGREES));
    Rot.updateSpeed(RPID.getPow());
    
    LFM.spin(fwd, Rot.getLPow(), rpm);
    LBM.spin(fwd, Rot.getLPow(), rpm);
    RFM.spin(fwd, Rot.getRPow(), rpm);
    RBM.spin(fwd, Rot.getRPow(), rpm);

    if (timer.getTime() > timeout)
      break;

    wait(10, msec);
  }
  LFM.stop(brake);
  RFM.stop(brake);
  LBM.stop(brake);
  RBM.stop(brake);
  
}

//This function moves the arm up and down. The arm degree will reset to zero every time the function is called.
//Positive moves the arm up, Negative moves it down.
//If waitForRelease is set to false, the function will start moving the arm and then move on to the next function while still moving the arm.
//Units are in Degrees.
void moveArm ( double rot, bool waitForRelease){
  LArm.resetRotation();
  RArm.resetRotation();

  if (waitForRelease){
    LArm.startRotateTo(rot, deg, 200, rpm);
    RArm.rotateTo(rot, deg, 200, rpm);
  }
  else{
    LArm.startRotateTo(rot, deg, 200, rpm);
    RArm.startRotateTo(rot, deg, 200, rpm);
  }
}

void moveRings(double time, double speed, directionType dir){
  RingCatcher.spin(dir, speed, rpm);
  wait(time * 1000, msec);
  RingCatcher.stop(brake);
}

 