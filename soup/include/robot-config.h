using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor motorA2;
extern motor motorA1;
extern motor motorB2;
extern motor motorB1;
extern controller Controller1;
extern motor pickerUpperMotor;
extern motor_group driveTrain;
extern int sensitivity;
extern int autonSpeed;
extern int slowBeltSpeed;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
