#include "main.h"

//int lds = 0;
//int rds = 0;
int right_y = 0;
int left_y = 0;
int right_y_f = 0;
int left_y_f = 0;
const float averages = 10.5;

// int right_y_c [averages] = { };
// int left_y_c [averages] = { };
int cycle = 0;
int n=0;
float real_left = 0;
float real_right = 0;

// void leftdrive(int lds){
//     l1.move_velocity(lds);
//     l2.move_velocity(lds);
//     l3.move_velocity(lds);
// }
// //groups together the left drive motors
// void rightdrive(int rds){
//     r1.move_velocity(rds);
//     r2.move_velocity(rds);
//     r3.move_velocity(rds);
// }
//groups together the right drive motors
//this doesnt work. will revisit

void drive(){
        right_y = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        left_y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

        if (right_y > real_right){
            real_right += (right_y - real_right)/averages;
        }
        else if (right_y < real_right){
            real_right -= (real_right - right_y)/averages;
        }

        if (left_y > real_left){
            real_left += (left_y - real_left)/averages;
        }
        else if (left_y < real_left){
            real_left -= (real_left - left_y)/averages;;
        }

        // right_y_c[cycle] = right_y;
        // left_y_c[cycle] = left_y;

        // for (n=0 ; n < averages ; ++n){
        //     right_y_f += right_y_c[cycle];
        //     left_y_f += left_y_c[cycle];
        // }
        // right_y_f = right_y_f / 5;
        // left_y_f = left_y_f / 5;

        if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
            l1.move_velocity(70);
		    l2.move_velocity(70);
		    l3.move_velocity(70);
		    r1.move_velocity(-70);
		    r2.move_velocity(-70);
		    r3.move_velocity(-70);
        }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
            l1.move_velocity(-70);
		    l2.move_velocity(-70);
		    l3.move_velocity(-70);
		    r1.move_velocity(70);
		    r2.move_velocity(70);
		    r3.move_velocity(70);
        }else{ 
            l1.move_voltage(-real_left*120);
	        l2.move_voltage(-real_left*120);
	        l3.move_voltage(-real_left*120);
	        r1.move_voltage(real_right*120);
	        r2.move_voltage(real_right*120);
	        r3.move_voltage(real_right*120);
   }
    // cycle = cycle++;
    // if(cycle == averages){
    //     cycle = 0;
    // }else{}

}