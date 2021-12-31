#ifndef General_Functions_h
#define General_Functions_h
#include "robot-config.h"
using namespace vex;

//Variables--------------------------------------------------------------------
enum angleType {RADIANS, DEGREES};

//Functions--------------------------------------------------------------------
int tempuatureDisplay();
int brainDebug();
int controllerDebug();
int TerminalDebug(); 
double inToRev(double centimetersTraveled, double wheelDiameter);
double inToDeg(double centimetersTraveled, double wheelDiameter);
double degToRev(double degreesTraveled);
double degToIn(double degreesTraveled, double wheelDiameter);
double highestEncoderValue(bool index);
double numCutoff(double num, double cutoff);
double degToRadians(double deg);
double radiansToDeg(double radian);
double angleDiff(double actual, double target, angleType aType);
double angleDiffDir(double actual, double target);
double angleWrap(double angle, angleType aType);

//Classes
class TimeoutClock
{
private:
  double initTime;

public:
  double getTime(){
    return (Brain.timer(msec) - initTime) / 1000.0;
  }

  void resetTime(){
    initTime = Brain.timer(msec);
  }

  TimeoutClock(){
    initTime = Brain.timer(msec);
  }
};

class Piston 
{
  private:
    bool opened = false;
    TimeoutClock nActiveTime;
    digital_out* port;

  public:
    void activate(){
      opened = !opened;
      port->set(opened);
      nActiveTime.resetTime();
    }

    void open(){
      if (!opened){
        opened = !opened;
        port->set(opened);
        nActiveTime.resetTime();
      }
    }

    void close(){
      if (opened){
        opened = !opened;
        port->set(opened);
        nActiveTime.resetTime();
      }
    }

    bool getState(){
      return opened;
    }

    double timeSinceActive(){
      return nActiveTime.getTime();
    }

    Piston(digital_out &pistonPort){
      port = &pistonPort;
      opened = false;
    }

    Piston(digital_out &pistonPort, bool startPos){
      port = &pistonPort;
      opened = startPos;
    }
};

//Class Objects
extern Piston Clamp;
extern Piston BHook;
extern Piston LHook;
extern Piston RHook;

#endif