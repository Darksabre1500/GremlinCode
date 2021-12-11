#ifndef autonType_h
#define autonType_h

using namespace vex;
  enum armDirection {UP, DOWN};
  void GoTo(double target_X, double target_Y, double timeout, bool facingFront);
  void TurnTo(double target_angle, double timeout);
  void moveArm (double rot, bool waitForRelease);
  void moveRings(double time, double speed, directionType dir);


#endif