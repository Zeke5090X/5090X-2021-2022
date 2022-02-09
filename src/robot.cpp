#include "main.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor l1(1);
pros::Motor l2(2);
pros::Motor l3(3);
//left drive train motors
pros::Motor r1(17);
pros::Motor r2(18);
pros::Motor r3(19);
//right drive tain motors
pros::ADIDigitalOut gl(1, glstate);
//goal lift pneumatics 
pros::ADIDigitalOut clamp(2, cstate);
//clamp pneumatics
pros::Motor intake(4);

pros::Motor fbar(8);
pros::Rotation liftencoder(20);

pros::ADIMotor red(8);
pros::ADIMotor blue(6);
pros::ADIMotor green(7);