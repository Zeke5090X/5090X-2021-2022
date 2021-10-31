#include "main.h"
bool glstate = true;
bool cstate = true;
int tank1act = 0;
int tank2act = 0;
void goallift(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
        gl.set_value(true);
        tank1act++;
    }if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
		gl.set_value(false);
        tank1act++;
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
    master.print(0, 0, "Tank 1 %d", tank1act);
    master.print(1, 0, "Tank 2 %d", tank2act);
}