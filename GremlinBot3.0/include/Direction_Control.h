#ifndef Direction_Control_h
#define Direction_Control_h

extern bool turning;

double rotation_Controller(double targetAngle, double speed);
double std_Controller(double target_X, double target_Y, double speed, bool forward);

#endif