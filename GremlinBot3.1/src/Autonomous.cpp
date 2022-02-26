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
  ArmSet();
  GoToStraight(43, 10, 2, true);
  FClamp.set(false);
  wait(0.2, sec);
  //moveArm(2, true);
  GoToStraight(20, 5, 3, false);
  TurnTo(180, 5);
  wait(0.25, sec);
  GoToStraight(18, 7, 2.5, false);
  BClamp.set(true);
  wait(0.25, sec);
  GoToStraight(5, 7, 2.5, true);
  wait(0.25, sec);
  TurnTo(90, 5);
  wait(0.25, sec);
  GoToStraight(13, 7, 5, false);
  moveRings(3, fwd, false);
  //GoToStraight(30, 8, 5, false);

} 