#include "main.h"
/*
to do:
clean this up
*/
lv_style_t buttonStyleREL; //relesed style
lv_style_t buttonStylePR; //pressed style
lv_style_t matrixStyleBg; //matrix style
lv_style_t matrixStyleBtnRel; //matrix released style
lv_style_t matrixStyleBtnPr; //matrix pressed style
lv_style_t matrixStyleBtnRelMain; //generic matrix released style
lv_style_t matrixStyleBtnPrMain; //gereric matrix pressed style
lv_style_t tabStyleBG; //tab view background style
lv_style_t tabStyleBtnBG; //tab view button background style 
lv_style_t tabStyleBtnRel; //tab view button released style
lv_style_t tabStyleBtnPr; //you get the picture
lv_style_t tabStyleIndic; //indicator

//defined here so the compiler doesn't lose its shit

static lv_res_t lbtnm_action(lv_obj_t * btnm, const char *txt){
    int btnmNum = atoi(txt);
    printf("Button: %s released\n", txt);
    switch (btnmNum) {
        case 1:
        ap = 1;
        //lv_label_set_text(laLabel, "L1 loaded");
        //lv_label_set_text(raLabel, "L1 loaded");
        break;
        case 2:
        //lv_label_set_text(laLabel, "L2 loaded");
        //lv_label_set_text(raLabel, "L2 loaded");
        ap = 2;
        break;
        case 3:
        ap = 3;
        //lv_label_set_text(laLabel, "L3 loaded");
        //lv_label_set_text(raLabel, "L3 loaded");
        break;
        case 4:
        //lv_label_set_text(laLabel, "L4 loaded");
        //lv_label_set_text(raLabel, "L4 loaded");
        ap = 4;
        break;
        case 5:
        ap = 5;
        //lv_label_set_text(laLabel, "L5 loaded");
        //lv_label_set_text(raLabel, "L5 loaded");
        break;
        case 6:
        ap = 6;
        //lv_label_set_text(laLabel, "L1 loaded");
        //lv_label_set_text(raLabel, "L1 loaded");
        break;
        default:
        //lv_label_set_text(laLabel, "Nothing is loaded");
        //lv_label_set_text(raLabel, "Nothing is loaded");
        break;
    }
    printf("button is pressed");
    return LV_RES_OK;
}
// set text commands have been commented out because I couldn't find a way to fix scoping issues
// relevent info will be moved to the info tab

static const char * lbtnm_map[] = {"1L", "2L", "3L", "4L", "5L", "6L", ""};
//btn map for left auton matrix

void lvglstyle(){
    lv_style_copy(&buttonStyleREL, &lv_style_plain);
    buttonStyleREL.body.main_color = LV_COLOR_MAKE(200, 10, 10);
    buttonStyleREL.body.grad_color = LV_COLOR_MAKE(100, 5, 5);
    buttonStyleREL.body.radius = 0;
    buttonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&buttonStylePR, &lv_style_plain);
    buttonStylePR.body.main_color = LV_COLOR_MAKE(150, 7, 7);
    buttonStylePR.body.grad_color = LV_COLOR_MAKE(50, 0, 0);
    buttonStylePR.body.radius = 0;
    buttonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

    lv_style_copy(&matrixStyleBg, &lv_style_plain);
    matrixStyleBg.body.main_color = LV_COLOR_MAKE(100, 100, 100);
    matrixStyleBg.body.grad_color = LV_COLOR_MAKE(50, 50, 50);
    matrixStyleBg.body.padding.hor = 0;
    matrixStyleBg.body.padding.ver = 0;
    matrixStyleBg.body.padding.inner = 0;

    lv_style_copy(&matrixStyleBtnRel, &lv_style_btn_rel);
    matrixStyleBtnRel.body.main_color = LV_COLOR_MAKE(250, 0, 0);
    matrixStyleBtnRel.body.grad_color = LV_COLOR_MAKE(125, 0, 0);
    matrixStyleBtnRel.body.border.color = LV_COLOR_MAKE(115, 0, 0);
    matrixStyleBtnRel.body.border.width = 1;
    matrixStyleBtnRel.body.border.opa = LV_OPA_50;
    matrixStyleBtnRel.body.radius = 0;

    lv_style_copy(&matrixStyleBtnPr, &matrixStyleBtnRel);
    matrixStyleBtnPr.body.main_color = LV_COLOR_MAKE(125, 0, 0);
    matrixStyleBtnPr.body.grad_color = LV_COLOR_MAKE(63, 0, 0);

    lv_style_copy(&matrixStyleBtnRelMain, &matrixStyleBtnRel);
    matrixStyleBtnRelMain.body.main_color = LV_COLOR_MAKE(100, 100, 100);
    matrixStyleBtnRelMain.body.grad_color = LV_COLOR_MAKE(50, 50, 50);
    
    lv_style_copy(&matrixStyleBtnPrMain, &matrixStyleBtnRelMain);
    matrixStyleBtnPrMain.body.main_color = LV_COLOR_MAKE(50, 50, 50);
    matrixStyleBtnPrMain.body.grad_color = LV_COLOR_MAKE(25, 25, 25);    
    
    lv_style_copy(&tabStyleBG, &lv_style_plain);
    tabStyleBG.body.main_color = LV_COLOR_BLACK;
    tabStyleBG.body.grad_color = LV_COLOR_BLACK;

    lv_style_copy(&tabStyleBtnBG, &tabStyleBG);
    tabStyleBG.body.main_color = LV_COLOR_MAKE(150, 0, 0);
    tabStyleBG.body.grad_color = LV_COLOR_MAKE(75, 0, 0);
    
    lv_style_copy(&tabStyleBtnRel, &tabStyleBG);
    tabStyleBtnRel.body.main_color = LV_COLOR_MAKE(200,0,0);

    lv_style_copy(&tabStyleBtnPr, &tabStyleBG);
    tabStyleBtnPr.body.main_color = LV_COLOR_MAKE(175, 0, 0);

    lv_style_copy(&tabStyleIndic, &lv_style_plain);
    tabStyleIndic.body.main_color = LV_COLOR_MAKE(200, 0, 0);
    tabStyleIndic.body.grad_color = LV_COLOR_MAKE(200, 0, 0);

    //more styles will be added as needed
}

void lvglla(){
    //lvglstyle();
    lv_obj_t * laMatrix = lv_btnm_create(latab, NULL);
    lv_btnm_set_map(laMatrix, lbtnm_map);
    lv_obj_align(laMatrix, NULL, LV_ALIGN_CENTER, -50, 0);
    lv_obj_set_size(laMatrix, 350, 75);
    lv_btnm_set_action(laMatrix, lbtnm_action);
    lv_btnm_set_style(laMatrix, LV_BTNM_STYLE_BG, &matrixStyleBg);
    lv_btnm_set_style(laMatrix, LV_BTN_STYLE_REL, &matrixStyleBtnRel);
    lv_btnm_set_style(laMatrix, LV_BTN_STYLE_PR, &matrixStyleBtnPr);

    lv_obj_t * laLabel = lv_label_create(latab, NULL);
    lv_obj_align(laLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 10, -10);
    lv_label_set_text(laLabel, "Heres where you will say what's loaded");
}

static lv_res_t rbtnm_action(lv_obj_t * btnm, const char *txt){
    int btnmNum = atoi(txt);
    printf("Button: %s released\n", txt);
    switch (btnmNum) {
        case 1:
        ap = 7;
        //lv_label_set_text(laLabel, "R1 loaded");
        //lv_label_set_text(raLabel, "R1 loaded");
        break;
        case 2:
        ap = 8;
        //lv_label_set_text(laLabel, "R2 loaded");
        //lv_label_set_text(raLabel, "R2 loaded");
        break;
        case 3:
        ap = 9;
        //lv_label_set_text(laLabel, "R3 loaded");
        //lv_label_set_text(raLabel, "R3 loaded");
        break;
        case 4:
        ap = 10;
        //lv_label_set_text(laLabel, "R4 loaded");
        //lv_label_set_text(raLabel, "R4 loaded");
        break;
        case 5:
        ap = 11;
        //lv_label_set_text(laLabel, "R5 loaded");
        //lv_label_set_text(raLabel, "R5 loaded");
        break;
        case 6:
        ap = 12;
        //lv_label_set_text(laLabel, "R6 loaded");
        //lv_label_set_text(raLabel, "R6 loaded");
        break;
    }
    
    return LV_RES_OK;
}
static const char * rbtnm_map[] = {"1R", "2R", "3R", "4R", "5R", "6R", ""};
void lvglra(){
    lv_obj_t * raMatrix = lv_btnm_create(ratab, NULL);
    lv_btnm_set_map(raMatrix, rbtnm_map);
    lv_obj_align(raMatrix, NULL, LV_ALIGN_CENTER, -50, 0);
    lv_obj_set_size(raMatrix, 350, 75);
    lv_btnm_set_action(raMatrix, rbtnm_action);
    lv_btnm_set_style(raMatrix, LV_BTNM_STYLE_BG, &matrixStyleBg);
    lv_btnm_set_style(raMatrix, LV_BTN_STYLE_REL, &matrixStyleBtnRel);
    lv_btnm_set_style(raMatrix, LV_BTN_STYLE_PR, &matrixStyleBtnPr);

    lv_obj_t * raLabel = lv_label_create(ratab, NULL);
    lv_obj_align(raLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 10, -10);
    lv_label_set_text(raLabel, "Heres where you will say what's loaded");

    switch (ap){
		case 1:
		lv_label_set_text(raLabel, "L1 loaded");
		break;
		case 2:
		lv_label_set_text(raLabel, "L2 loaded");
		break;
		case 3: 
		lv_label_set_text(raLabel, "L3 loaded");
		break;
		case 4:
		lv_label_set_text(raLabel, "L4 loaded");
		break;
		case 5:
		lv_label_set_text(raLabel, "L5 loaded");
		break;
		case 6:
        lv_label_set_text(raLabel, "L6 loaded");
		break;
        case 7:
        lv_label_set_text(raLabel, "R1 loaded");
        break;
        case 8:
        lv_label_set_text(raLabel, "R2 loaded");
        break;
        case 9:
        lv_label_set_text(raLabel, "R3 loaded");
        break;
        case 10:
        lv_label_set_text(raLabel, "R4 loaded");
        break;
        case 11:
        lv_label_set_text(raLabel, "R5 loaded");
        break;
        case 12:
        lv_label_set_text(raLabel, "R6 loaded");
        break;
}
}
void lvglinfo(){
    /*lv_obj_t * auLable = lv_label_create(infotab, NULL);
    lv_obj_align(auLable, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 0);
    lv_label_set_text(auLable, "Auton %d Loaded", ap);*/
}

lv_obj_t * tv;
lv_obj_t * latab;
lv_obj_t * ratab;
lv_obj_t * infotab;
//pre defining 

void lvglgui(){
    tv = lv_tabview_create(lv_scr_act(), NULL);
    latab = lv_tabview_add_tab(tv, "Left Auton");
    ratab = lv_tabview_add_tab(tv, "Right Auton");
    infotab = lv_tabview_add_tab(tv, "Info");
    //creating the tabview and tabs

    lv_tabview_set_style(tv, LV_TABVIEW_STYLE_BG, &tabStyleBG);
    lv_tabview_set_style(tv, LV_TABVIEW_STYLE_INDIC, &tabStyleIndic);
    lv_tabview_set_style(tv, LV_TABVIEW_STYLE_BTN_BG, &tabStyleBtnBG);
    //lv_tabview_set_style(tv, LV_TABVIEW_STYLE_BTN_REL, &tabStyleBtnRel);
    //lv_tabview_set_style(tv, LV_TABVIEW_STYLE_BTN_PR, &tabStyleBtnPr);
    //setting the style of the tabview

    lvglstyle();
    lvglla();
    lvglra();
    //functions are called here for organisational purposes 
}