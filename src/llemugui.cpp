#include "main.h"
//#include "robot.cpp"
void llemugui(){
    if(page == 0){
        pros::lcd::print(0, "Auton Preset = %d", ap); 
        pros::lcd::print(1,"");
        pros::lcd::print(2,"");
        pros::lcd::print(3,"");
        pros::lcd::print(4,"");
        pros::lcd::print(5,"");
        pros::lcd::print(6,"");
        pros::lcd::print(7,"");
    }else if(page == 1){
        
        pros::lcd::print(0, "l1 temp %d", l1.get_temperature());
		pros::lcd::print(1, "l2 temp %d", l2.get_temperature());
		pros::lcd::print(2, "l3 temp %d", l3.get_temperature());
		pros::lcd::print(3, "r1 temp %d", r1.get_temperature());
		pros::lcd::print(4, "r2 temp %d", r2.get_temperature());
		pros::lcd::print(5, "r3 temp %d", r3.get_temperature());
        pros::lcd::print(6,"");
        pros::lcd::print(7,"");
    }else if(page == 2){
        pros::lcd::print(0,"");
        pros::lcd::print(1,"");
        pros::lcd::print(2,"");
        pros::lcd::print(3, "sensor values go on this page");
        pros::lcd::print(4,"");
        pros::lcd::print(5,"");
        pros::lcd::print(6,"");
        pros::lcd::print(7,"");
    }else{ 
        pros::lcd::print(0,"you should not be able to read this");
    }
}