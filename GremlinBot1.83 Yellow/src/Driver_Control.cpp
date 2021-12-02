#include "vex.h"

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  while (1) {
    //Gets the values of the joystick for each motor
      joystickValues();
    //Moves motors according to those values
      drive(); 
    //Moves Arm
      Arm(); 
    //Moves secondary arm
      moveFlipper();
      moveRings();
  }
}