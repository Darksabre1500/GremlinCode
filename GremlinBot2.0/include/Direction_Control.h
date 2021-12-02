#ifndef Direction_Control_h
#define Direction_Control_h

extern double Mfl;
extern double Mfr;
extern double Mbl;
extern double Mbr;

void Omni_Controller(double relativeAngle, double speed, double startAngle);
double Omni_Rotation(double targetAngle);

#endif