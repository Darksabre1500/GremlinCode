#include "vex.h"

  int jValuesLFM;
  int jValuesRFM;
  int jValuesLBM;
  int jValuesRBM;

void joystickValues() {
  jValuesLFM = Controller1.Axis3.position() + Controller1.Axis4.position() + (Controller1.Axis1.position() * 0.8);
  jValuesRFM = Controller1.Axis3.position() - Controller1.Axis4.position() - (Controller1.Axis1.position() * 0.8);
  jValuesLBM = Controller1.Axis3.position() - Controller1.Axis4.position() + (Controller1.Axis1.position() * 0.8);
  jValuesRBM = Controller1.Axis3.position() + Controller1.Axis4.position() - (Controller1.Axis1.position() * 0.8);
  
  jValuesLFM = numCutoff(jValuesLFM, 100);
  jValuesLBM = numCutoff(jValuesLBM, 100);
  jValuesRFM = numCutoff(jValuesRFM, 100);
  jValuesRBM = numCutoff(jValuesRBM, 100);
}

void drive() {

  if (jValuesLFM != 0 || jValuesRFM != 0 || jValuesLBM != 0 || jValuesRBM != 0){
    LFM.spin(fwd, jValuesLFM, pct);
    RFM.spin(fwd, jValuesRFM, pct);
    LBM.spin(fwd, jValuesLBM, pct);
    RBM.spin(fwd, jValuesRBM, pct);
  }      
  else {
    LFM.stop(brake);
    RFM.stop(brake);
    LBM.stop(brake);
    RBM.stop(brake);
  }
} 

void Arm()
{
  if (Controller1.ButtonL1.pressing() || Controller2.ButtonL1.pressing())
  {
    LArm.spin(fwd, 100, pct);
    RArm.spin(fwd, 100, pct);
  }
  else if (Controller1.ButtonL2.pressing() || Controller2.ButtonL2.pressing())
  {
    LArm.spin(reverse, 100, pct);
    RArm.spin(reverse, 100, pct);
  }
  else
  {
    LArm.stop(brake);
    RArm.stop(brake);
  } 
}

void moveFlipper()
{
  int speed;  
  if (Controller1.ButtonA.pressing() || Controller2.ButtonA.pressing())
    speed = 200;
  else 
  speed = 600;

  if (Controller1.ButtonR1.pressing() || Controller2.ButtonR1.pressing())
    Flipper.spin(fwd, speed, rpm);
  else if (Controller1.ButtonR2.pressing() || Controller2.ButtonR2.pressing())
    Flipper.spin(reverse, speed, rpm);
  else 
    Flipper.stop(hold);
}

void moveRings()
{
  if (Controller1.ButtonUp.pressing() || Controller2.ButtonUp.pressing()){
    RingCatcher.spin(fwd, 120, rpm);
    std::cout << "Test";
  }
  else if (Controller1.ButtonDown.pressing() || Controller2.ButtonDown.pressing())
    RingCatcher.spin(reverse, 120, rpm);
  else 
    RingCatcher.stop(brake);
}

