#ifndef autonType_h
#define autonType_h

using namespace vex;
  enum armDirection {UP, DOWN};
  void GoTo(double target_X, double target_Y, double timeout, bool facingFront);
  void TurnTo(double target_angle, double timeout);
  void driveTill(directionType dir, double speed, double timeout);
  void moveArm (double ArmPos, bool threaded);
  void moveRings(double time, directionType dir, bool threaded);


#endif