#include "main.h"
bool glstate = true;
bool cstate = true;
int tank1act = 0;
int tank2act = 0;
bool tared = false;
void goallift(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
        gl.set_value(true);
        tank1act++;
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
		gl.set_value(false);
        tank1act++;
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
        if(tared = true){
            if(lift.get_position() == -665){
                lift.move_velocity(0);
            }else{
                lift.move_velocity(-200);
            }
        }
        else{}
        }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        if(tared = true){
            if(lift.get_position() == 0){
                lift.move_velocity(0);
            }else{
                lift.move_velocity(200);
            }
        }else{
            lift.move_velocity(200);
        }
    }else{
        lift.move_velocity(0);
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
        lift.tare_position();
        tared = false;
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        fbar.move_velocity(-200);
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        fbar.move_velocity(200);
    }else{
        fbar.move_velocity(0);
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
    
    }
    //master.print(0, 0, "Tank 1 %d", tank1act);
    //master.print(1, 0, "Tank 2 %d", tank2act);
}