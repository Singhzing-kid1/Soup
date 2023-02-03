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
motor_group driveTrain = motor_group(motorA2, motorA1, motorB2, motorB1);
controller Controller1 = controller(primary);
motor pickerUpperMotor = motor(PORT16, ratio6_1, false);
motor launcherMotor = motor(PORT17, ratio6_1, false);
motor_group launcher = motor_group(launcherMotor, pickerUpperMotor);

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
