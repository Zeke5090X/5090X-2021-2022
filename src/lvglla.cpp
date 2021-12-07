#include "main.h"
static lv_res_t lbtnm_action(lv_obj_t * btnm, const char *txt){
    int btnmNum = atoi(txt);
    switch (btnmNum) {
        case 1:
        ap = 1;
        break;
        case 2:
        ap = 2;
        break;
        case 3:
        ap = 3;
        break;
        case 4:
        ap = 4;
        break;
        case 5:
        ap = 5;
        break;
        case 6:
        ap = 6;
        break;
    }

    return LV_RES_OK;
}

static const char * lbtnm_map[] = {"L 1", "L 2", "L 3", "\n"
                            "L 4", "L 5", "L 6", ""};


void lvglla(){
    lv_obj_t * laMatrix = lv_btnm_create(lascr, NULL);
    lv_btnm_set_map(laMatrix, lbtnm_map);
    lv_obj_align(laMatrix, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);
    lv_btnm_set_action(laMatrix, lbtnm_action);
    lv_btnm_set_style(laMatrix, LV_BTNM_STYLE_BG, &matrixStyleBg);
    lv_btnm_set_style(laMatrix, LV_BTN_STYLE_REL, &matrixStyleBtnRel);
    lv_btnm_set_style(laMatrix, LV_BTN_STYLE_PR, &matrixStyleBtnPr);

}