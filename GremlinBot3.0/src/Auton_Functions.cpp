#include "vex.h"

/* //This function moves the bot to the specified coordinates. The bot will always start at 0, 0 on startup. 
//If it times out, it will move on to the next function even if it still hasn't finished. 
//Units are in inches and seconds respectivley.
void GoTo(double target_X, double target_Y, double timeout, bool facingFront)
{
  TimeoutClock timer;
  double speed = 0;
  double pow = 0;

  while(std::abs(target_Y-odom.getY()) > 1 || std::abs(target_X-odom.getX()) > 1)
  {
    speed = PIDcontrol.PID(vectorLength(target_X, target_Y), 16, 0, 0, 0);
    pow = std_Controller(target_X, target_Y, speed, facingFront);

    if (turning) {
      while(true){
        pow = std_Controller(target_X, target_Y, speed, facingFront);
        
        LFM.spin(fwd, pow, rpm);
        RFM.spin(fwd, -pow, rpm);
        LBM.spin(fwd, pow, rpm);
        RBM.spin(fwd, -pow, rpm);

        if (timer.getTime() > timeout)
          break;

        else if (turning == false) {
          LFM.stop(brake);
          RFM.stop(brake);
          LBM.stop(brake);
          RBM.stop(brake);
          wait(0.25, sec);
          break;
        }
        wait(10, msec);
      }
    }

    LFM.spin(fwd, pow, rpm);
    RFM.spin(fwd, pow, rpm);
    LBM.spin(fwd, pow, rpm);
    RBM.spin(fwd, pow, rpm);

    if (timer.getTime() > timeout)
      break;

    wait(10, msec);
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
  while(std::abs(target_angle - odom.getAngle(DEGREES)) > 3)
  {
    //std::cout << angleDiff(odom.getAngle(DEGREES), target_angle) << std::endl;
    double pow = rotation_Controller(target_angle, PIDcontrol.PID(angleDiff(odom.getAngle(DEGREES), target_angle, DEGREES), 3, 0, 0, 0));
    LFM.spin(fwd, pow, rpm);
    RFM.spin(fwd, -pow, rpm);
    LBM.spin(fwd, pow, rpm);
    RBM.spin(fwd, -pow, rpm);

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

 */