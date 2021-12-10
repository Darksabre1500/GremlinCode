#ifndef PIDClass_h
#define PIDClass_h

class PIDClass {
public:
  double PID(double error, double kP, double kI, double kD, double integral_threshold);
  double proportionalFinal;
  double integralFinal;
  double derivativeFinal;
  double finalSpeed;

private:
  double previous_error = 0;
  double error;
  double integral;
  double derivative;
};

#endif