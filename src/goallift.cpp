#include "main.h"
bool glstate = true;
bool cstate = true;
int tank1act = 0;
int tank2act = 0;
bool tared = false;
bool fbarcoast = false;
bool liftcoast = false;
void goallift(){
    int liftpos = lift.get_position();
    int fbarpos = fbar.get_position();
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
        gl.set_value(true);
        tank1act++;
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
		gl.set_value(false);
        tank1act++;
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
        if(tared == true || master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
            if(liftpos <= -1400 && master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == false){
                lift.move_velocity(0);
                printf("stop");
            }else{
                lift.move_velocity(-200);
            }
        }
        else{}
        }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        if(tared == true){
            if(liftpos >= 0  && master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == false){
                lift.move_velocity(0);
            }
            else{
                lift.move_velocity(200);
            }
        }
        else{
            lift.move_velocity(200);
        }
    }else{
        lift.move_velocity(0);
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
        lift.set_zero_position(0);
        tared = true;
        printf("tared is enabled");
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        fbar.move_velocity(-200);
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        fbar.move_velocity(200);
    }else{
        fbar.move_velocity(0);
    }
    if(fbarpos >= -35){
        //if(fbarcoast == true){
            fbar.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            //fbarcoast == false;
            printf("coast");
        //}
    }else if(fbarpos < -35){
        //if(fbarcoast == true){
            fbar.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            //fbarcoast == false;
            printf("brake");
        //}
    }else{
        fbar.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        printf("dynamic breaking broke");
    }
    //dynamic braking for the 4bar
    /*if(liftpos < 50){
        lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }else if(liftpos >= 50){
        lift.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }else{
        lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }*/
    //dynamic braking for the lift
    //master.print(0, 0, "Tank 1 %d", tank1act);
    //master.print(1, 0, "Tank 2 %d", tank2act);
}