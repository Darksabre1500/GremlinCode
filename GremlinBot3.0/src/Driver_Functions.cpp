#include "vex.h"

void drive() {
  int rightPow = numCutoff(Controller1.Axis3.position(pct) - Controller1.Axis1.position(pct), 100); 
  int leftPow = numCutoff(Controller1.Axis3.position(pct) + Controller1.Axis1.position(pct), 100);

  if (Controller1.Axis3.position(pct) != 0 || Controller1.Axis1.position(pct) != 0){
    LFM.spin(fwd, leftPow, pct);
    RFM.spin(fwd, rightPow, pct);
    LBM.spin(fwd, leftPow, pct);
    RBM.spin(fwd, rightPow, pct);
  }      
  else {
    LFM.stop(brake);
    RFM.stop(brake);
    LBM.stop(brake);
    RBM.stop(brake);
  }
} 

void moveArm()
{
  if (Controller1.ButtonL1.pressing() || Controller2.ButtonL1.pressing())
    Arm.spin(fwd, 100, pct);
  else if (Controller1.ButtonL2.pressing() || Controller2.ButtonL2.pressing())
    Arm.spin(reverse, 100, pct);
  else
    Arm.stop(brake);
}

void movePistons(){
  if(Controller1.ButtonR1.pressing() && fClamp.timeSinceActive() >= 0.25)
    fClamp.open();
  else if (Controller1.ButtonR2.pressing() && fClamp.timeSinceActive() >= 0.25) 
    fClamp.close();

  if (Controller1.ButtonA.pressing() && bClamp.timeSinceActive() >= 0.25) 
    bClamp.open();
  else if (Controller1.ButtonB.pressing() && bClamp.timeSinceActive() >= 0.25) 
    bClamp.close();
}


void moveRings()
{
  if (Controller1.ButtonUp.pressing() || Controller2.ButtonUp.pressing()){
    RingConveyor.spin(fwd, 180, rpm);
  }
  else if (Controller1.ButtonDown.pressing() || Controller2.ButtonDown.pressing())
    RingConveyor.spin(reverse, 180, rpm);
  else 
    RingConveyor.stop(brake);
}

bool pressed;
bool interrupted;

void haptics(){
  if (Bumper.pressing() && pressed == false){
    Controller1.rumble(".");
    pressed = true;
    return;
  }
  else if (!Bumper.pressing() && pressed == true) {
    pressed = false;
  }

  if (Distance.objectDistance(inches) < 6.5 && interrupted == false){
    Controller1.rumble("..");
    interrupted = true;
  }
  else if (Distance.objectDistance(inches) > 6.5 && interrupted == true) {
    interrupted = true;
  }
}

