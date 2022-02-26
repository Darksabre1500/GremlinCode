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

  GoToStraight(2, 1, 1, false);
  wait(0.25, sec);
  BClamp.set(true);
  wait(0.5, sec);
  moveRings(3, fwd, true);
  TurnTo(0, 5);
  wait(0.5, sec);
  GoToStraight(95, 8, 5, true);
  wait(0.5, sec);
  TurnTo(225, 5);
  wait(0.5, sec);
  BClamp.set(false);
  wait(0.5, sec);
  GoToStraight(85, 8, 5, true);
  wait(0.5, sec);
  GoToStraight(8, 4, 5, false);
  TurnTo(140, 5);
  wait(0.5, sec);
  GoToStraight(55, 8, 5, false);

  /*FClamp.set(false);
  wait(0.5, sec);
  TurnTo(173, 5);
  wait(0.5, sec);
  GoToStraight(87, 8, 5, true);
  wait(0.5, sec);
  TurnTo(40, 5);
  wait(0.5, sec);
  FClamp.set(true);
  wait(0.5, sec);
  GoToStraight(85, 8, 5, true);
  wait(0.5, sec);
  GoToStraight(8, 4, 5, false);
  TurnTo(325, 5);
  wait(0.5, sec);
  GoToStraight(75, 8, 5, false);*/


} 