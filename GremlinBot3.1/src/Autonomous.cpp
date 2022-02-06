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

  BClamp.set(true);
  wait(0.5, sec);
  moveRings(3, fwd, true);
  //GoToStraight(7, 8, 5, true);
  //wait(0.5, sec);
  TurnTo(0, 5);
  wait(0.5, sec);
  GoToStraight(110, 8, 5, true);
  wait(0.5, sec);
  TurnTo(225, 5);
  wait(0.5, sec);
  BClamp.set(false);
  wait(0.5, sec);
  GoToStraight(250, 8, 5, true);
  wait(0.5, sec);
  GoToStraight(5, 4, 5, false);
  TurnTo(160, 5);
  wait(0.5, sec);
  GoToStraight(200, 8, 5, false);

  //GoToStraight(30, 8, 5, false);

} 