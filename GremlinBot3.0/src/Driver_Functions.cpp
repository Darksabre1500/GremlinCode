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

void movePistons(){
  if(Controller1.ButtonL1.pressing() && Clamp.timeSinceActive() >= 0.5)
    Clamp.open();
  else if (Controller1.ButtonL2.pressing() && Clamp.timeSinceActive() >= 0.5) 
    Clamp.close();

  if (Controller1.ButtonA.pressing() && BHook.timeSinceActive() >= 0.5) 
    BHook.open();
  else if (Controller1.ButtonB.pressing() && BHook.timeSinceActive() >= 0.5) 
    BHook.close();

  if (Controller1.ButtonX.pressing() && LHook.timeSinceActive() >= 0.5){
    LHook.open();
    RHook.open();
  } 
  else if (Controller1.ButtonY.pressing() && LHook.timeSinceActive() >= 0.5){
    LHook.close();
    RHook.close();
  }
}


void moveRings()
{
  if (Controller1.ButtonUp.pressing() || Controller2.ButtonUp.pressing()){
    RingCatcher.spin(fwd, 160, rpm);
  }
  else if (Controller1.ButtonDown.pressing() || Controller2.ButtonDown.pressing())
    RingCatcher.spin(reverse, 160, rpm);
  else 
    RingCatcher.stop(brake);
}

