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

  GoToStraight(44, 7, 2.5, false);
  wait(0.15, sec);
  BClamp.set(true);
  wait(0.15, sec);
  TurnTo(190, 2);
  //moveRings(3, fwd, true);
  wait(0.25, sec);
  GoToStraight(30, 2.5, 4, true);
  wait(0.25, sec);
  FClamp.set(false);
  //driveTill(22, 5);
  wait(0.15, sec);
  TurnTo(240, 2);
  GoToStraight(55, 4, 7, false);
  //driveTill(27, 100, 3);
  //GoToStraight(30, 8, 5, false);

} 