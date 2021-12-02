#ifndef General_Functions_h
#define General_Functions_h

//#include "PIDClass.h"

//Variables--------------------------------------------------------------------
extern double second;
enum angleType {RADIANS, DEGREES};

//Functions--------------------------------------------------------------------
int tempuatureDisplay();
int brainDebug();
int controllerDebug();
int timeoutClock();
int TerminalDebug(); 
double inToRev(double centimetersTraveled, double wheelDiameter);
double inToDeg(double centimetersTraveled, double wheelDiameter);
double degToRev(double degreesTraveled);
double degToIn(double degreesTraveled, double wheelDiameter);
double highestEncoderValue(bool index);
double numCutoff(double num, double cutoff);
double degToRadians(double deg);
double radiansToDeg(double radian);
double angleDiff(double actual, double target);
double angleDiffDir(double actual, double target);
double angleWrap(double angle, angleType aType);

#endif