/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Caleb Beversdorf                                          */
/*    Created:      Mon Feb 22 2021                                           */
/*    Description:  X-Drive Bot Code                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*------------------------------Controller Scheme-------------------------------

  - Left Joystick Up Down = Analog vertical movement
  - Left Joystick Left Right = Analog strafe movement
  - Right Joystick Left Right = Analog turn movement
  
------------------------------------------------------------------------------*/

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// LFM                  motor         1               
// LBM                  motor         2               
// RFM                  motor         9               
// RBM                  motor         19              
// EncoderL             encoder       C, D            
// EncoderR             encoder       A, B            
// EncoderS             encoder       E, F            
// LArm                 motor         3               
// RArm                 motor         8               
// Flipper              motor         10              
// RingCatcher          motor         13              
// FlipperAngle         potentiometer G            
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;
PIDClass PIDcontrol;
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

}

// Main will set up the competition functions and callbacks.
int main() {

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  Competition.bStopAllTasksBetweenModes = false;
  Competition.bStopTasksBetweenModes = false;  

  // Background Processes
  Brain.Screen.clearScreen();
  task temps(tempuatureDisplay);
  task brainTB(brainDebug);
  task controllerTB(controllerDebug);
  task timeout(timeoutClock);
  task odom(odomRuntime);
  task terminal(TerminalDebug);


  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
