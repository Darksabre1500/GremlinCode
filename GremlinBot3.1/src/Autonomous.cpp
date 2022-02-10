#include "vex.h"

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

/*
Flipper Vals : -14 rev from purpendicular line start
1.25 for picking back up

*/

void autonomous(void) {

  //Setup Bot to the left of yellow goal
  ArmSet();
  GoToStraight(37, 8, 5, true);
  GoToStraight(5.5, 1, 2, true);
  wait(0.275, sec);
  FClamp.set(false);
  wait(0.25, sec);
  moveArm(3, true);
  GoToStraight(8, 3, 1.5, false);
  TurnTo(198, 2.5);
  wait(0.25, sec);
  GoToStraight(37, 2.85, 7, false);
  wait(0.25, sec);
  BClamp.set(true);
  wait(0.25, sec);
  GoToStraight(30, 4, 7, true);
  wait(0.25, sec);
  TurnTo(250, 2);
  wait(0.25, sec);
  GoToStraight(30, 4, 7, true);
  //driveTill(27, 100, 3);
  //GoToStraight(30, 8, 5, false);*/

} 