#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
triport WireExpansion = triport(PORT10);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor LFM = motor(PORT2, ratio18_1, true);
motor LBM = motor(PORT1, ratio18_1, true);
motor RFM = motor(PORT8, ratio18_1, false);
motor RBM = motor(PORT19, ratio18_1, false);
encoder EncoderL = encoder(Brain.ThreeWirePort.G);
encoder EncoderR = encoder(WireExpansion.C);
motor RingConveyor = motor(PORT20, ratio18_1, true);
digital_out FClampPiston = digital_out(WireExpansion.E);
digital_out BClampPiston = digital_out(Brain.ThreeWirePort.E);
encoder ArmEncoder = encoder(WireExpansion.A);
motor ArmMotorA = motor(PORT11, ratio36_1, false);
motor ArmMotorB = motor(PORT5, ratio36_1, true);
motor_group Arm = motor_group(ArmMotorA, ArmMotorB);
motor Flipper = motor(PORT6, ratio36_1, false);
distance Distance = distance(PORT3);
bumper Bumper = bumper(Brain.ThreeWirePort.A);

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