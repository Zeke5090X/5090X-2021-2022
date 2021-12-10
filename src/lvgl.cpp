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
        printf("ap = 1");
        break;
        case 2:
        printf("ap = 2");
        ap = 2;
        break;
        case 3:
        ap = 3;
        printf("ap = 3");
        break;
        case 4:
        printf("ap = 4");
        ap = 4;
        break;
        case 5:
        ap = 5;
        printf("ap = 5");
        break;
        case 6:
        ap = 6;
        printf("ap = 6");
        break;
    }
    printf("button is pressed");
    return LV_RES_OK;
}

static const char * lbtnm_map[] = {"L 1", "L 2", "L 3", "L 4", "L 5", "L 6", ""};
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
    matrixStyleBtnRel.body.main_color = LV_COLOR_MAKE(250, 0, 0);//this might look hidiously ugly
    matrixStyleBtnRel.body.grad_color = LV_COLOR_MAKE(125, 0, 0);//if so change the gradient to a blood red or black
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
    lv_obj_align(laMatrix, NULL, LV_ALIGN_IN_TOP_MID, 0, -150);
    lv_btnm_set_action(laMatrix, lbtnm_action);
    lv_btnm_set_style(laMatrix, LV_BTNM_STYLE_BG, &matrixStyleBg);
    lv_btnm_set_style(laMatrix, LV_BTN_STYLE_REL, &matrixStyleBtnRel);
    lv_btnm_set_style(laMatrix, LV_BTN_STYLE_PR, &matrixStyleBtnPr);

    lv_obj_t * laLabel = lv_label_create(latab, NULL);
    lv_obj_align(laLabel, NULL, LV_ALIGN_CENTER, -100, 0);
    lv_label_set_text(laLabel, "Heres where you will say what's loaded");
}

static lv_res_t rbtnm_action(lv_obj_t * btnm, const char *txt){
    int btnmNum = atoi(txt);
    printf("Button: %s released\n", txt);
    switch (btnmNum) {
        case 1:
        ap = 7;
        printf("ap = 7");
        break;
        case 2:
        ap = 8;
        printf("ap = 8");
        break;
        case 3:
        ap = 9;
        printf("ap = 9");
        break;
        case 4:
        ap = 10;
        printf("ap = 10");
        break;
        case 5:
        ap = 11;
        printf("ap = 11");
        break;
        case 6:
        ap = 12;
        printf("ap = 12");
        break;
    }
    
    return LV_RES_OK;
}
static const char * rbtnm_map[] = {"R 1", "R 2", "R 3", "R 4", "R 5", "R 6", ""};
void lvglra(){
    lv_obj_t * raMatrix = lv_btnm_create(ratab, NULL);
    lv_btnm_set_map(raMatrix, rbtnm_map);
    lv_obj_align(raMatrix, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    lv_obj_set_size(raMatrix, 450, 100);
    lv_btnm_set_action(raMatrix, rbtnm_action);
    lv_btnm_set_style(raMatrix, LV_BTNM_STYLE_BG, &matrixStyleBg);
    lv_btnm_set_style(raMatrix, LV_BTN_STYLE_REL, &matrixStyleBtnRel);
    lv_btnm_set_style(raMatrix, LV_BTN_STYLE_PR, &matrixStyleBtnPr);

    lv_obj_t * raLabel = lv_label_create(latab, NULL);
    lv_obj_align(raLabel, NULL, LV_ALIGN_CENTER, 100, 0);
    lv_label_set_text(raLabel, "Heres where you will say what's loaded");

}

void lvglinfo(){
    //info tab stuff goes here
    //maybe put motor temps or sensor values here
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