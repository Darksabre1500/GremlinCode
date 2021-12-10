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

int flipperTask2(){
  activateFlipper(89, 600, 2);
  return 0;
}

int flipperTask3(){
  while(globalY > 30){
    wait(25, msec);
  }
  activateFlipper(90, 600, 2);
  return 0;
}

int flipperTask4(){
  activateFlipper(51, 600, 1);
  return 0;
}

int flipperTask5(){
  double initSec = second;
  while(second - initSec < 0.75){
    activateFlipper(45, 200, 1);
  }
  
  return 0;
}

void autonomous(void) {

  activateFlipper(25, 600, 2);
  task flipper(flipperTask);
  GoTo(0, 48, 3, true);
  activateFlipper(45, 600, 1.75);
  task movingFlip(flipperTask3);
  GoTo(-11, -3, 3, true);
  TurnTo(0, 3);
  task flipper2(flipperTask2);
  GoTo2(17, 2, 200);
  activateFlipper(55, 600, 2);
  GoTo2(3, 2, -200);
  //task flipper4(flipperTask4);
  activateFlipper(51, 600, 3);
  moveRings(2, 120, fwd);

} 