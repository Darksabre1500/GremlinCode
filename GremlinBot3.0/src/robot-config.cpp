#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
triport WireExpansion = triport(PORT18);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor LFM = motor(PORT1, ratio18_1, false);
motor LBM = motor(PORT2, ratio18_1, true);
motor RFM = motor(PORT9, ratio18_1, true);
motor RBM = motor(PORT19, ratio18_1, false);
encoder EncoderL = encoder(Brain.ThreeWirePort.C);
encoder EncoderR = encoder(Brain.ThreeWirePort.A);
motor RingConveyor = motor(PORT13, ratio18_1, true);
digital_out FClampPiston = digital_out(WireExpansion.A);
digital_out BClampPiston = digital_out(WireExpansion.B);
encoder ArmEncoder = encoder(WireExpansion.C);
motor ArmMotorA = motor(PORT3, ratio36_1, false);
motor ArmMotorB = motor(PORT4, ratio36_1, true);
motor_group Arm = motor_group(ArmMotorA, ArmMotorB);
motor Flipper = motor(PORT5, ratio18_1, false);
distance Distance = distance(PORT6);
bumper Bumper = bumper(WireExpansion.E);

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