#ifndef autonType_h
#define autonType_h

using namespace vex;
  enum coordType {ABSOLUTE, RELATIVE};
  void GoTo(double target_X, double target_Y, double timeout, coordType coordinates, bool facingFront = true);
  void GoToStraight(double target_X, double target_Y, double timeout, coordType coordinates, bool facingFront = true);
  void driveTill(directionType dir, double speed, double timeout);
  void driveTill(double speed, double timeout, double limitX, double limitY, coordType coordinates);
  void TurnTo(double target_angle, double timeout);
  void moveArm (double ArmPos, bool threaded);
  void moveRings(double time, directionType dir, bool threaded);


#endif