#include "main.h"

/*to do
fix speed stages
*/

//int lds = 0;
//int rds = 0;
int right_y = 0;
int left_y = 0;
void leftdrive(int lds){
    l1.move_velocity(lds);
    l2.move_velocity(lds);
    l3.move_velocity(lds);
}
//groups together the left drive motors
void rightdrive(int rds){
    r1.move_velocity(rds);
    r2.move_velocity(rds);
    r3.move_velocity(rds);
}
//groups together the right drive motors

void drive(){
   right_y = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
   left_y = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		l1.move(-left_y);
		l2.move(left_y);
		l3.move(-left_y);
		r1.move(right_y);
		r2.move(right_y);
		r3.move(-right_y);
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        l1.move_velocity(-70);
		l2.move_velocity(70);
		l3.move_velocity(-70);
		r1.move_velocity(70);
		r2.move_velocity(70);
		r3.move_velocity(-70);
    }if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        l1.move_velocity(70);
		l2.move_velocity(-70);
		l3.move_velocity(70);
		r1.move_velocity(-70);
		r2.move_velocity(-70);
		r3.move_velocity(70);
    }
    //doesn't work. will revisit
    //leftdrive(127);
    //rightdrive(127);
    //printf("%d", lds);
}
