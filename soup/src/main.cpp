// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motorA2              motor         12
// motorA1              motor         14
// motorB2              motor         13
// motorB1              motor         11
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;


// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void forwardBackward(double axis){
    if (axis >= globalSpeed){
        axis = globalSpeed;
    } else if (axis <= -globalSpeed){
        axis = -globalSpeed;
    } else {
        axis = axis;
    }
    motorA1.spin(forward, axis, percent);
    motorA2.spin(reverse, axis, percent);
    motorB1.spin(forward, axis, percent);
    motorB2.spin(reverse, axis, percent);
}

void strafe(double axis){
    if (axis >= globalSpeed){
        axis = globalSpeed;
    } else if (axis <= -globalSpeed){
        axis = -globalSpeed;
    } else {
        axis = axis;
    }
    motorA1.spin(forward, axis, percent);
    motorA2.spin(reverse, axis, percent);
    motorB1.spin(reverse, axis, percent);
    motorB2.spin(forward, axis, percent);
}

void pointTurn(double axis){
    if (axis >= globalSpeed){
        axis = globalSpeed;
    } else if (axis <= -globalSpeed){
        axis = -globalSpeed;
    } else {
        axis = axis;
    }
    motorA1.spin(reverse, axis, percent);
    motorA2.spin(reverse, axis, percent);
    motorB1.spin(forward, axis, percent);
    motorB2.spin(forward, axis, percent);
}

void movingPointTurnA(double axis1, double axis2){ // forward/backward left
    if (axis1 >= globalSpeed){
        axis1 = globalSpeed;
    } else if (axis1 <= -globalSpeed){
        axis1 = -globalSpeed;
    } else {
        axis1 = axis1;
    }

    if (axis2 >= globalSpeed){
        axis2 = globalSpeed;
    } else if (axis2 <= -globalSpeed){
        axis2 = -globalSpeed;
    } else {
        axis2 = axis2;
    }

    double avg = (axis1 + axis2)/2;
    double diff = avg/2;
    motorA1.spin(reverse, diff, percent);
    motorA2.spin(reverse, avg, percent);
    motorB1.spin(forward, avg, percent);
    motorB2.spin(forward, diff, percent);
}

void movingPointTurnB(double axis1, double axis2){ // forward/backward right
    if (axis1 >= globalSpeed){
        axis1 = globalSpeed;
    } else if (axis1 <= -globalSpeed){
        axis1 = -globalSpeed;
    } else {
        axis1 = axis1;
    }

    if (axis2 >= globalSpeed){
        axis2 = globalSpeed;
    } else if (axis2 <= -globalSpeed){
        axis2 = -globalSpeed;
    } else {
        axis2 = axis2;
    }

    double avg = (axis1 + axis2)/2;
    double diff = avg/2;
    motorA1.spin(reverse, avg, percent);
    motorA2.spin(reverse, diff, percent);
    motorB1.spin(forward, diff, percent);
    motorB2.spin(forward, avg, percent);
}

void roller(){
    launcher.spin(forward, 50, percent);
   // printf("R1 Pressed\n");
    wait(10, msec);
    }

void stopRoller(){
    launcher.stop();
   // printf("R1 Released\n");
    wait(10, msec);
    }

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

   // forwardBackward(autonSpeed);
   // wait(15, seconds);
   launcher.spin(forward, 50, percent);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop

  bool axis3Cond1;
  bool axis3Cond2;
  bool axis3Cond3;

  bool axis4Cond1;
  bool axis4Cond2;
  bool axis4Cond3;

  bool axis1Cond1;
  bool axis1Cond2;
  bool axis1Cond3;

  bool mixCond1;
  bool mixCond2;
  bool mixCond3;
  bool mixCond4;

  while (1) {
    double axis3 = Controller1.Axis3.position(); // put the values of the axises into variable's
    double axis4 = Controller1.Axis4.position();
    double axis1 = Controller1.Axis1.position();
    bool buttonL1 = Controller1.ButtonL1.pressing();
    bool buttonR1 = Controller1.ButtonR1.pressing();
    bool buttonR2 = Controller1.ButtonR2.pressing();

    axis3Cond1 = axis3 > sensitivity  ? true : false; // get possible Conditions for axis 3
    axis3Cond2 = axis3 < -(sensitivity)  ? true : false;
    axis3Cond3 = axis3 < sensitivity && axis3 > -(sensitivity) ? true : false;

    axis4Cond1 = axis4 > sensitivity  ? true : false; // get possible Conditions for axis 4
    axis4Cond2 = axis4 < -(sensitivity)  ? true : false;
    axis4Cond3 = axis4 < sensitivity && axis4 > -(sensitivity) ? true : false;

    axis1Cond1 = axis1 > sensitivity  ? true : false; // get possible Conditions for axis 1
    axis1Cond2 = axis1 < -(sensitivity) ? true : false;
    axis1Cond3 = axis1 == 0 ? true : false;

    mixCond1 = (axis3Cond1 && axis4Cond1) ? true : false;
    mixCond2 = (axis3Cond1 && axis4Cond2) ? true : false;
    mixCond3 = (axis3Cond2 && axis4Cond1) ? true : false;
    mixCond4 = (axis3Cond2 && axis4Cond2) ? true : false;

    Controller1.ButtonR1.pressed(roller);
    Controller1.ButtonR2.released(stopRoller);

    if (axis3Cond1 || axis3Cond2){
        forwardBackward(axis3);
    } else if (axis1Cond1 || axis1Cond2){
        pointTurn(axis1);
    } else {
        driveTrain.stop(coast);
    }

    wait(10, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
