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
    motorA1.spin(reverse, axis, percent);
    motorA2.spin(forward, axis, percent);
    motorB1.spin(reverse, axis, percent);
    motorB2.spin(forward, axis, percent);
}

void strafe(double axis){
    motorA1.spin(forward, axis, percent);
    motorA2.spin(reverse, axis, percent);
    motorB1.spin(reverse, axis, percent);
    motorB2.spin(forward, axis, percent);
}

void pointTurn(double axis){
    motorA1.spin(reverse, axis, percent);
    motorA2.spin(reverse, axis, percent);
    motorB1.spin(forward, axis, percent);
    motorB2.spin(forward, axis, percent);
}

void diagonalA  (double axis1, double axis2){
    motorA1.spin(forward, (axis1 + axis2)/2, percent);
    motorA2.spin(reverse, (axis1 + axis2)/2, percent);
}

void diagonalB(double axis1, double axis2){
    motorB1.spin(reverse, (axis1 + axis2)/2, percent);
    motorB2.spin(forward, (axis1 + axis2)/2, percent);
}

void movingPointTurnLeft(double axis1, double axis2){
    double speed = (axis1 + axis2)/2;
    motorA1.spin(reverse, speed/2, percent);
    motorB2.spin(forward, speed/2, percent);
    motorA2.spin(forward, speed, percent);
    motorB1.spin(reverse, speed, percent);
}

void movingPointTurnRight(double axis1, double axis2){
    double speed = (axis1 + axis2)/2;
    motorA1.spin(reverse, speed, percent);
    motorB2.spin(forward, speed, percent);
    motorA2.spin(forward, speed/2, percent);
    motorB1.spin(reverse, speed/2, percent);
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

    forwardBackward(autonSpeed);
    wait(10, seconds);
    strafe(autonSpeed);
    wait(5, seconds);
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

  bool axis2Cond1;
  bool axis2Cond2;
  bool axis2Cond3;

  bool axis1Cond1;
  bool axis1Cond2;
  bool axis1Cond3;

  bool mixCond1;
  bool mixCond2;
  bool mixCond3;
  bool mixCond4;
  bool mixCond5;
  bool mixCond6;
  bool mixCond7;
  bool mixCond8;

  while (1) {
    double axis3 = Controller1.Axis3.position(); // put the values of the axises into variable's
    double axis4 = Controller1.Axis4.position();
    double axis1 = Controller1.Axis1.position();
    double axis2 = Controller1.Axis2.position();

    axis3Cond1 = axis3 > sensitivity  ? true : false; // get possible Conditions for axis 3
    axis3Cond2 = axis3 < -(sensitivity)  ? true : false;
    axis3Cond3 = axis3 == 0 ? true : false;

    axis4Cond1 = axis4 > sensitivity  ? true : false; // get possible Conditions for axis 4
    axis4Cond2 = axis4 < -(sensitivity)  ? true : false;
    axis4Cond3 = axis4 == 0 ? true : false;

    axis2Cond1 = axis2 > sensitivity ? true : false; // get possible Conditions for axis 2
    axis2Cond2 = axis2 < -(sensitivity) ? true : false;
    axis2Cond3 = axis2 == 0 ? true : false;

    axis1Cond1 = axis1 > sensitivity  ? true : false; // get possible Conditions for axis 1
    axis1Cond2 = axis1 < -(sensitivity) ? true : false;
    axis1Cond3 = axis1 == 0 ? true : false;

    // diagonal conditions
    mixCond1 = (axis3Cond1 && axis1Cond1) && axis4Cond3 ? true : false;
    mixCond2 = (axis3Cond1 && axis1Cond2) && axis4Cond3 ? true : false;
    mixCond3 = (axis3Cond2 && axis1Cond1) && axis4Cond3 ? true : false;
    mixCond4 = (axis3Cond2 && axis1Cond2) && axis4Cond3 ? true : false;

    // moving point turn conditions
    mixCond5 = (axis3Cond1 && axis4Cond1) && axis1Cond3 ? true : false;
    mixCond6 = (axis3Cond1 && axis4Cond2) && axis1Cond3 ? true : false;
    mixCond7 = (axis3Cond2 && axis4Cond1) && axis1Cond3 ? true : false;
    mixCond8 = (axis3Cond2 && axis4Cond2) && axis1Cond3 ? true : false;

    Controller1.ButtonR1.pressing() ? pickerUpperMotor.spin(forward, 100, percent) : Controller1.ButtonR2.pressing() ? pickerUpperMotor.spin(forward, slowBeltSpeed, percent) : Controller1.ButtonL1.pressing() ? pickerUpperMotor.spin(reverse, 100, percent) : pickerUpperMotor.stop(coast);

    if ((axis3Cond1 || axis3Cond2) & axis4Cond3){
        forwardBackward(axis3);
    } else if ((axis4Cond1 || axis4Cond2) & axis3Cond3){
        pointTurn(axis4);
    } else if (axis1Cond1 || axis1Cond2){
        strafe(axis1);
    } else if(mixCond1 || mixCond2){
        diagonalA(axis3, axis4);
    } else if(mixCond3){
        diagonalB(axis3, -1*axis4);
    } else if(mixCond4){
        diagonalB(-1*axis3, axis4);
    } else if(mixCond5){
        movingPointTurnLeft(axis3, axis4);
    } else if(mixCond6){
        movingPointTurnRight(axis3, axis4);
    } else if(mixCond7){
        movingPointTurnLeft(-1*axis3, axis4);
    } else if(mixCond8){
        movingPointTurnRight(-1*axis3, axis4);
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
