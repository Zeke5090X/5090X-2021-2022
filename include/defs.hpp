#pragma once
//extern int lds;
//extern int rds;
extern int page;
extern int ap;
extern int intake_state;
extern int leftY;
extern int rightY;
extern int tank1act;
extern int tank2act;

extern pros::Motor l1;
extern pros::Motor l2;
extern pros::Motor l3;
extern pros::Motor r1;
extern pros::Motor r2;
extern pros::Motor r3;
extern pros::Motor fbar;
extern pros::Motor lift;
extern pros::Controller master;
extern pros::ADIDigitalOut gl;
extern pros::ADIDigitalOut clamp;

extern bool glstate;
extern bool cstate;
extern bool fbarcoast;
extern bool liftcoast;

extern void goallift();
extern void llemugui();
extern void intakes();
extern void leftdrive(int lds);
extern void rightdrive(int rds);
extern void drive(); 
extern void lvglgui();
extern void lvglstyle();
extern void lvglla();
extern void lvglra();
extern void lvglinfo();
//extern void lvglscreens();

extern pros::ADIMotor red;
extern pros::ADIMotor blue;
extern pros::ADIMotor green;

extern lv_style_t buttonStyleREL;
extern lv_style_t buttonStylePR;
extern lv_style_t matrixStyleBg;
extern lv_style_t matrixStyleBtnRel;
extern lv_style_t matrixStyleBtnPr;
extern lv_style_t matrixStyleBtnRelMain;
extern lv_style_t matrixStyleBtnPrMain;

//extern lv_obj_t * laLabel;
//extern lv_obj_t * raLabel;
extern lv_obj_t * infoscr;
extern lv_obj_t * lascrTabButton;
extern lv_obj_t * tv;
extern lv_obj_t * latab;
extern lv_obj_t * ratab;
extern lv_obj_t * infotab;
//static lv_res_t btn_click_action(lv_obj_t * btn);