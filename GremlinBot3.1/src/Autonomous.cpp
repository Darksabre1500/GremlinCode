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

  FClamp.set(true);
  GoToStraight(46, 10, 5, true);
  FClamp.set(false);
  moveArm(3, true);
  GoToStraight(10, 10, 5, false);
  wait(0.25, sec);
  TurnTo(70, 1);
  wait(0.25, sec);
  GoToStraight(38, 7, 3, false);
  wait(0.25, sec);
  TurnTo(190, 3);
  /*wait(0.25, sec);
  GoToStraight(11, 4, 1.5, false);
  wait(0.25, sec);
  BClamp.set(true);
  moveRings(3, fwd, true);
  GoToStraight(7, 5, 2, true);*/

} 