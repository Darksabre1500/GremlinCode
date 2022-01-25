#include <math.h>
#include "General_Functions.h"

#ifndef odometryType_h
#define odometryType_h

//Updater for task
int odometry();

//Odometry method
class Odometry{
private:
  //Starting conditions
  const double Wl = 7;
  const double Wr = 1.625;
  const double startRot = degToRadians(90);
  const double startX = 0;
  const double startY = 0;

  //Program variables
  double prevL = 0;
  double prevR = 0;
  double botRot = 0;

  double globalX = startX;
  double globalY = startY;

  double angleDeg;
  double angleRad;
  double angleRadUnwrapped;

  public:

  void updateOdom();
  void updateAngle();

  double getX(){
    return globalX;
  }
  double getY(){
    return globalY;
  }
  double getAngle(angleType aType){
    if (aType == DEGREES)
      return angleDeg;
    else
      return angleRad;
  }
};

//Odom declaration
extern Odometry odom;

#endif