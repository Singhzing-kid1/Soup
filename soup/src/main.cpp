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
  while (1) {
    if (Controller1.Axis3.position() > 10 || Controller1.Axis3.position() < -10 && Controller1.Axis4.position() == 0) {      //Forward backward on axis 3
      motorA1.spin(reverse, Controller1.Axis3.position(), percent);
      motorA2.spin(forward, Controller1.Axis3.position(), percent);
      motorB1.spin(reverse, Controller1.Axis3.position(), percent);
      motorB2.spin(forward, Controller1.Axis3.position(), percent);
    } 
    else if (Controller1.Axis1.position() > 10 || Controller1.Axis1.position() < -10) { //Point turn left/right on axis 1
      motorA1.spin(reverse, Controller1.Axis1.position(), percent);
      motorA2.spin(reverse, Controller1.Axis1.position(), percent);
      motorB1.spin(forward, Controller1.Axis1.position(), percent);
      motorB2.spin(forward, Controller1.Axis1.position(), percent);
    } 
    else if (Controller1.Axis4.position() > 10 || Controller1.Axis4.position() < -10 && Controller1.Axis3.position() == 0) {  //Sideways right/left on axis 4
      motorA1.spin(forward, Controller1.Axis4.position(), percent);
      motorA2.spin(reverse, Controller1.Axis4.position(), percent);
      motorB1.spin(reverse, Controller1.Axis4.position(), percent);
      motorB2.spin(forward, Controller1.Axis4.position(), percent);
    } 
    else if (Controller1.Axis4.position() + Controller1.Axis3.position() > 10 || Controller1.Axis4.position() + Controller1.Axis3.position() < -10) {
      if (Controller1.Axis4.position() > 10 && Controller1.Axis3.position() > 10){
       motorB1.spin(reverse, (Controller1.Axis4.position()+Controller1.Axis3.position())/2, percent);
       motorB2.spin(reverse, (Controller1.Axis4.position()+Controller1.Axis3.position())/2, percent); 
      }
      else if (Controller1.Axis4.position() < -10 && Controller1.Axis3.position() < -10){
        motorA1.spin(reverse, (Controller1.Axis4.position()+Controller1.Axis3.position())/2, percent);
        motorA2.spin(reverse, (Controller1.Axis4.position()+Controller1.Axis3.position())/2, percent);
      }
      else if (Controller1.Axis4.position() > 10 && Controller1.Axis3.position() < -10){
        motorA1.spin(reverse, (Controller1.Axis4.position()+Controller1.Axis3.position())/2, percent);
        motorA2.spin(reverse, (Controller1.Axis4.position()+Controller1.Axis3.position())/2, percent);
      }
      else if (Controller1.Axis4.position() < -10 && Controller1.Axis3.position() > 10){
        motorB1.spin(reverse, (Controller1.Axis4.position()+Controller1.Axis3.position())/2, percent);
        motorB2.spin(reverse, (Controller1.Axis4.position()+Controller1.Axis3.position())/2, percent);
      }
    }
    else { //stops the motors
      motorA1.stop();
      motorA2.stop();
      motorB1.stop();
      motorB2.stop();
    }

    wait(20, msec); // Sleep the task for a short amount of time to
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
