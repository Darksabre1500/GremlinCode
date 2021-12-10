#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
triport WExp = triport(PORT18);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor LFM = motor(PORT1, ratio18_1, false);
motor LBM = motor(PORT2, ratio18_1, true);
motor RFM = motor(PORT9, ratio18_1, true);
motor RBM = motor(PORT19, ratio18_1, false);
encoder EncoderL = encoder(Brain.ThreeWirePort.C);
encoder EncoderR = encoder(Brain.ThreeWirePort.A);
motor LArm = motor(PORT3, ratio36_1, true);
motor RArm = motor(PORT8, ratio36_1, false);
motor RingCatcher = motor(PORT13, ratio18_1, true);
pot LArmRot = pot(Brain.ThreeWirePort.E);
pot RArmRot = pot(Brain.ThreeWirePort.F);
digital_out ClampPiston = digital_out(WExp.A);
digital_out BackClamp = digital_out(WExp.B);
digital_out LeftClamp = digital_out(WExp.C);
digital_out RightClamp = digital_out(WExp.D);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}