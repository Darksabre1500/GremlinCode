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
  wait(0.25, sec);
  moveRings(5, fwd, true);
  TurnTo(70, 1);
  wait(0.25, sec);
  GoToStraight(12, 6, 7, true);
  //moveArm(15, true);
  TurnTo(0, 2.75);
  wait(0.25, sec);
  //driveTill(22, 5);
  TurnTo(300, 2);
  wait(0.25, sec);
  GoToStraight(48, 4, 7, true);
  //driveTill(27, 100, 3);
  FClamp.set(false);
  wait(0.25, sec);
  //GoToStraight(30, 8, 5, false);

} 