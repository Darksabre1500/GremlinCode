using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern controller Controller2;
extern motor LFM;
extern motor LBM;
extern motor RFM;
extern motor RBM;
extern encoder EncoderL;
extern encoder EncoderR;
extern encoder EncoderS;
extern motor LArm;
extern motor RArm;
extern motor Flipper;
extern motor RingCatcher;
extern pot FlipperAngle;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );