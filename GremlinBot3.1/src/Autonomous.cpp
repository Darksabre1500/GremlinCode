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

  ArmSet();
  FClamp.set(true);
  GoToStraight(46, 10, 2, true);
  FClamp.set(false);
  wait(0.125, sec);
  //moveArm(7, true);
  GoToStraight(15, 10, 2, false);
  wait(0.25, sec);
  TurnTo(66, 2);
  wait(0.25, sec);
  GoToStraight(32, 6, 3, false);
  wait(0.25, sec);
  TurnTo(185, 3);
  GoToStraight(17, 5, 3, false);
  BClamp.set(true);
  wait(0.25, sec);
  GoToStraight(10, 5, 3, true);
  moveRings(3, fwd, false);
  /*wait(0.25, sec);
  GoToStraight(11, 4, 1.5, false);
  wait(0.25, sec);
  BClamp.set(true);
  moveRings(3, fwd, true);
  GoToStraight(7, 5, 2, true);*/

} 