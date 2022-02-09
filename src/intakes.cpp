#include "main.h"

bool intake_on = false;
bool intake_reversed = false;
bool activation_toggle = true;

void intakes(){
   if(liftencoder.get_position() >= 0.7){
	   intake_on = true;
   }else if(liftencoder.get_position() < 0.7){
	   intake_on = false;
   }else{
	   intake_on = false;
   }

   if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
	   activation_toggle = !activation_toggle;
   }
   if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
	   intake_reversed = true;
   }else{
	   intake_reversed = false;
   }

   if(intake_on == true && intake_reversed == false && activation_toggle == true){
	   intake.move_velocity(175);
   }else if(intake_on == true && intake_reversed == true && activation_toggle == true){
	   intake.move_velocity(-175);
   }else{
	   intake.move_velocity(0);
   }
   }