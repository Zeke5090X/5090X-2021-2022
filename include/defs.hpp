#pragma once
//extern int lds;
//extern int rds;
extern int page;
extern int ap;
extern int intake_state;
extern int leftY;
extern int rightY;
extern int tank1act;
extern int left_y_f;
extern int right_y_f;

extern pros::Motor l1;
extern pros::Motor l2;
extern pros::Motor l3;
extern pros::Motor r1;
extern pros::Motor r2;
extern pros::Motor r3;
extern pros::Motor fbar;
extern pros::Motor intake;
extern pros::Rotation liftencoder;
extern pros::Controller master;
extern pros::ADIDigitalOut gl;
extern pros::ADIDigitalOut clamp;
extern bool glstate;
extern bool cstate;
extern bool intake_on;
extern bool intake_reversed;

extern void goallift();
extern void llemugui();
extern void intakes();
extern void leftdrive(int lds);
extern void rightdrive(int rds);
extern void drive(); 
extern pros::ADIMotor red;
extern pros::ADIMotor blue;
extern pros::ADIMotor green;