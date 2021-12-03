#ifndef autonType_h
#define autonType_h

using namespace vex;
  enum armDirection {UP, DOWN};

  void CalibrateInertial(bool toggle);
  int odomRuntime();
  void GoTo(double target_X, double target_Y, double timeout);
  void GoTo2(double target_X, double timeout, int power);
  void TurnTo(double target_angle, double timeout);
  void moveArm (double rot, bool waitForRelease);
  void activateFlipper (double rot, double speed, double timeout);
  void moveFlipper (double time, double speed, directionType dir);
  void moveRings(double time, double speed, directionType dir);


#endif