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
  /*GoToStraight(42, 8, 5, true);
  wait(0.25, sec);
  FClamp.set(false);
  wait(0.25, sec);
  moveArm(3, true);
  GoToStraight(30, 8, 5, false);*/

  //Setup Bot to the left of yellow goal

  GoToStraight(39.5, 8, 5, true);
  wait(0.4, sec);
  FClamp.set(false);
  wait(0.5, sec);
  moveArm(5, true);
  TurnTo(65, 3);
  wait(0.25, sec);
  GoToStraight(25, 7, 5, false);
  FClamp.set(true);
  GoToStraight(3, 7, 7, false);
  
  //GoToStraight(30, 8, 5, false);

} 