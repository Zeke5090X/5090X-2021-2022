#include "main.h"
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor l1(1);
pros::Motor l2(2);
pros::Motor l3(3);
//left drive train motors
pros::Motor r1(4);
pros::Motor r2(5);
pros::Motor r3(6);
//right drive tain motors
pros::ADIDigitalOut gl(1, glstate);
//goal lift pneumatics 
pros::ADIDigitalOut clamp(2, cstate);
//clamp pneumatics
pros::Motor fbar(11);

pros::Motor lift(12);
pros::ADIMotor red(8);
pros::ADIMotor blue(6);
pros::ADIMotor green(7);