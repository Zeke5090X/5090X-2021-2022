#include "main.h"
static lv_res_t btn_click_action(lv_obj_t * btn){
    uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons

    if(id == 0){
        lv_scr_load(lascr);
    }else if(id == 1){
        lv_scr_load(rascr);
    }else if(id == 2){
        lv_scr_load(infoscr);
    }else{
        // more id statements will be added as needed
    }

    return LV_RES_OK;
}

void lvglscreens(){
    lv_obj_t * lascr = lv_obj_create(NULL, NULL);
    lv_obj_t * rascr = lv_obj_create(NULL, NULL);
    lv_obj_t * infoscr = lv_obj_create(NULL, NULL);
}

static const char * btn_map1[] = {"left autons", "right autons", "info", ""};

void lvglgui(){
    lv_obj_t * topMatrix = lv_btnm_create(lv_scr_act(), NULL);
    lv_btnm_set_map(topMatrix, btn_map1);
    lv_obj_align(topMatrix, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);
    lv_cb_set_action(topMatrix, btn_click_action);
    lv_btnm_set_style(topMatrix, LV_BTNM_STYLE_BG, &matrixStyleBg);
    lv_btnm_set_style(topMatrix, LV_BTN_STYLE_REL, &matrixStyleBtnRelMain);
    lv_btnm_set_style(topMatrix, LV_BTN_STYLE_PR, &matrixStyleBtnPrMain);

    lvglstyle();
    lvglla();
    lvglscreens();
}