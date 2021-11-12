#include "main.h"
int page = 0;
int ap = 0;
int intake_state = 0;
/**
 * A callback function for LLEMU's center button.
 * Advances the gui by 1 page
 * 
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		page = page + 1;
		if(page==3){
			page = 0;
		}
	}
}
void on_left_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		ap = ap - 1;
	}
}
void on_right_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		ap = ap + 1;
	}
}
//call back functions for the left and right buttons
//cycles forward and back through auton presets
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	//pros::lcd::set_text(1, "Hello PROS User!");
	printf("initialize wasn't skipped");
	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn1_cb(on_center_button);
	pros::lcd::register_btn2_cb(on_right_button);
	lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	fbar.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	while (true) {
		drive();
		goallift();
		llemugui();
		
		pros::delay(20);
	}
}