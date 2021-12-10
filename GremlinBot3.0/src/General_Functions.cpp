#include "vex.h"

double second = 0;

//Background Tasks
  int tempuatureDisplay() {
    while(true) {
      Brain.Screen.clearLine(1);
      Brain.Screen.clearLine(2);
      Brain.Screen.clearLine(3);
      Brain.Screen.clearLine(4);
      Brain.Screen.clearLine(5);
      Brain.Screen.clearLine(6);
      Brain.Screen.clearLine(7);
      Brain.Screen.setCursor(1, 1);
      Brain.Screen.print("Left Front Motor Temp: %.2f%C", LFM.temperature(celsius));
      Brain.Screen.setCursor(2, 1);
      Brain.Screen.print("Right Front Motor Temp: %.2f%C", RFM.temperature(celsius));
      Brain.Screen.setCursor(3, 1);
      Brain.Screen.print("Left Back Motor Temp: %.2f%C", LBM.temperature(celsius));        
      Brain.Screen.setCursor(4, 1);
      Brain.Screen.print("Right Back Motor Temp: %.2f%C", RBM.temperature(celsius));
      Brain.Screen.setCursor(5, 1);
      Brain.Screen.print("Left Arm: %.2f%C", LArm.temperature(celsius));
      Brain.Screen.setCursor(6, 1);
      Brain.Screen.print("Right Arm: %.2f%C", RArm.temperature(celsius));
      Brain.Screen.setCursor(7, 1);
      Brain.Screen.print("Ring Motor: %.2f%C", RingCatcher.temperature(celsius));
      wait(5, sec);
    }
    return 0;
  }

  int brainDebug() {
    while(true){
      Brain.Screen.clearLine(8);
      Brain.Screen.clearLine(9);
      Brain.Screen.clearLine(10);
      Brain.Screen.clearLine(11);
      Brain.Screen.clearLine(12);
      Brain.Screen.setCursor(8, 1);
      Brain.Screen.print("EAngle: ");
      Brain.Screen.print("%.2f", angleDeg);
      Brain.Screen.setCursor(9, 1);
      Brain.Screen.print("Global X: ");
      Brain.Screen.print("%.2f", globalX);
      Brain.Screen.print(" | Global Y: ");
      Brain.Screen.print("%.2f", globalY);
      Brain.Screen.setCursor(10, 1);
      Brain.Screen.print("Encoder L Deg: ");
      Brain.Screen.print("%.2f", EncoderL.rotation(deg));
      Brain.Screen.setCursor(11, 1);
      Brain.Screen.print("Encoder R Deg: ");
      Brain.Screen.print("%.2f", EncoderR.rotation(deg));
      wait(100, msec);
    }
    return 0;
  }

  int controllerDebug(){
    while(true){
      if(LFM.temperature(celsius) >= 65 || RFM.temperature(celsius) >= 65 || LBM.temperature(celsius) >= 65 || RBM.temperature(celsius) >= 65) 
      {
        Controller1.Screen.clearLine(1);
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("Overheating");
      }  
      else if (LFM.temperature(celsius) >= 55 || RFM.temperature(celsius) >= 55 || LBM.temperature(celsius) >= 55 || RBM.temperature(celsius) >= 55) 
      {
        Controller1.Screen.clearLine(1);
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("Throttling");
      }
      wait(5, sec);
    }
    return 0;
  }

  int timeoutClock() {
    while(true) {
      wait(100, msec);
      second += 0.1;
    }
    return 0;
  }

  
  int TerminalDebug() 
  {
    std::cout << std::fixed << std::setprecision(2);

    while (true) {
      //std::cout << flipperAngle();
      std::cout << std::endl;
      wait(100, msec);
    }
    return 0;
  }

//  

//Conversions & Value Finders
  

  double inToRev(double inchesTraveled, double wheelDiameter){
    return inchesTraveled / (wheelDiameter * M_PI); 
  }

  double inToDeg(double inchesTraveled, double wheelDiameter){
    return (inchesTraveled / (wheelDiameter * M_PI)) * 360; 
  }

  double degToRev(double degreesTraveled) {
    return degreesTraveled / 360; 
  }

  double degToIn(double degreesTraveled, double wheelDiameter) {
    return (degreesTraveled / 360) * (wheelDiameter * M_PI); 
  }

  double numCutoff(double num, double cutoff){
    if (num > cutoff)
      num = cutoff;
    else if (num < -cutoff)
      num = -cutoff;
    return num;
  }

  double degToRadians(double deg)
  {
    return deg * M_PI/180;
  }

  double radiansToDeg(double radian)
  {
    return radian * 180/M_PI;
  }

  double numberDiff(double actual, double target)
  {
    return std::abs(target-actual);
  }

  double angleDiff(double actual, double target, angleType aType)
  {
    return 180 - std::abs(std::abs(actual - target) - 180);
  }

  double angleDiffDir(double actual, double target)
  {
    int dir = -1;
    if(sin(degToRadians(target) - angleRad) < 0)
      dir = 1;
    return dir * (180 - std::abs(std::abs(actual - target) - 180));
  }

  double angleWrap(double angle, angleType aType){
    double wrappedAngle = angle;
    if (aType == RADIANS)
    {  
      if (angle < 0)
        wrappedAngle += 2 * M_PI;
      else if (angle > 2 * M_PI) 
        wrappedAngle -= 2 * M_PI;
    }
    else if (aType == DEGREES) 
    {
      if (angle < 0)
        wrappedAngle += 360;
      else if (angle > 360) 
        wrappedAngle -= 360;
    }  
    return wrappedAngle;
  }
