#include "vex.h"

//https://www.youtube.com/watch?v=3l7ZNJ21wMo

double vectorRAngle(double endX, double endY)
{
  //Finds X and Y difference from start to target
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();

  //Finds angle from 0 - 2pi of the vector from 0 (right on the x-axis)
  double vectorGlobalAngle = angleWrap(atan2(vectorY, vectorX), RADIANS);
  //Finds angle from 0 - 2pi of the bot angle from the vector angle
  double relativeAngle = angleWrap(vectorGlobalAngle - odom.getAngle(RADIANS), RADIANS);

  return relativeAngle;
}

double vectorGAngle(double endX, double endY)
{
  //Finds X and Y difference from start to target
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();

  //Finds angle from 0 - 2pi of the vector from 0 (right on the x-axis)
  double vectorGlobalAngle = angleWrap(atan2(vectorY, vectorX), RADIANS);

  return vectorGlobalAngle;
}


double vectorLength(double endX, double endY)
{
  //Finds X and Y difference from start to target
  double vectorX = endX-odom.getX();
  double vectorY = endY-odom.getY();
  
  //Finds length of the vector
  double vectorL = hypot(vectorX, vectorY);

  return vectorL;
}