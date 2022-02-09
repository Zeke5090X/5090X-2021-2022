#include "main.h"
bool glstate = true;
bool cstate = true;
int tank1act = 0;

void goallift(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
        glstate = !glstate;
        gl.set_value(glstate);
        tank1act++;
    }
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
		cstate = !cstate;
        clamp.set_value(cstate);
        tank1act++;
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        fbar.move_velocity(-200);
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        fbar.move_velocity(200);
    }else{
        fbar.move_velocity(0);
    }
<<<<<<< Updated upstream
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
=======

>>>>>>> Stashed changes
}