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

int flipperTask(){
  activateFlipper(90, 600, 1);
  return 0;
}

void autonomous(void) {

  activateFlipper(59, 600, 2);
  task flipper(flipperTask);
  GoTo(0, 50, 3);
  wait(0.25, seconds);
  activateFlipper(45, 600, 1.75);
  GoTo(0, 15, 3);
  activateFlipper(90, 600, 1);
  GoTo(0, -3, 3);
  /*TurnTo(0, 3);
  GoTo(13, -3, 3);
  activateFlipper(43, 600, 3);
  GoTo(0, -3, 2);
  moveRings(2, 120, fwd);*/

} 