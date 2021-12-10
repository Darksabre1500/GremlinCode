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
extern motor LArm;
extern motor RArm;
extern motor RingCatcher;
extern pot LArmRot;
extern pot RArmRot;
extern triport WExp;
extern digital_out ClampPiston;
extern digital_out BackClamp;
extern digital_out LeftClamp;
extern digital_out RightClamp;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );