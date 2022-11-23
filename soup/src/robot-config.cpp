#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor motorA2 = motor(PORT12, ratio18_1, true);
motor motorA1 = motor(PORT14, ratio18_1, true);
motor motorB2 = motor(PORT13, ratio18_1, false);
motor motorB1 = motor(PORT11, ratio18_1, false);
controller Controller1 = controller(primary);
motor pickerUpperMotorA = motor(PORT16, ratio36_1, false);
motor pickerUpperMotorB = motor(PORT17, ratio36_1, true);
motor_group pickerUpper = motor_group(pickerUpperMotorA, pickerUpperMotorB);

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