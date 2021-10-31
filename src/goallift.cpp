#include "main.h"
bool glstate = true;
bool cstate = true;
void goallift(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
        gl.set_value(true);
    }if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
		gl.set_value(false);
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        lift.move_velocity(-200);
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        lift.move_velocity(200);
    }else{
        lift.move_velocity(0);
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        fbar.move_velocity(-200);
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        fbar.move_velocity(200);
    }else{
        fbar.move_velocity(0);
        }
}