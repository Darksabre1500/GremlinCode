#ifndef Direction_Control_h
#define Direction_Control_h

extern double Mfl;
extern double Mfr;
extern double Mbl;
extern double Mbr;
extern bool turning;

void Omni_Controller(double relativeAngle, double speed, double startAngle);
double rotation_Controller(double targetAngle, double speed);
double std_Controller(double target_X, double target_Y, double speed, bool forward);

#endif