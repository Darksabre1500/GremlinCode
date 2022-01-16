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
extern motor RingConveyor;
extern triport WireExpansion;
extern digital_out FClampPiston;
extern digital_out BClampPiston;
extern encoder ArmEncoder;
extern motor_group Arm;
extern motor Flipper;
extern distance Distance;
extern bumper Bumper;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );