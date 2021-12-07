#include "main.h"

static lv_res_t rbtnm_action(lv_obj_t * btnm, const char *txt){
    int btnmNum = atoi(txt);
    switch (btnmNum) {
        case 1:
        ap = 7;
        break;
        case 2:
        ap = 8;
        break;
        case 3:
        ap = 9;
        break;
        case 4:
        ap = 10;
        break;
        case 5:
        ap = 11;
        break;
        case 6:
        ap = 12;
        break;
    }

    return LV_RES_OK;
}
static const char * rbtnm_map[] = {"R 1", "R 2", "R 3", "\n"
                            "R 4", "R 5", "R 6", ""};
void lvglra(){
    lv_obj_t * raMatrix = lv_btnm_create(rascr, NULL);
    lv_btnm_set_map(raMatrix, rbtnm_map);
    lv_obj_align(raMatrix, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
    lv_btnm_set_action(raMatrix, rbtnm_action);
    lv_btnm_set_style(raMatrix, LV_BTNM_STYLE_BG, &matrixStyleBg);
    lv_btnm_set_style(raMatrix, LV_BTN_STYLE_REL, &matrixStyleBtnRel);
    lv_btnm_set_style(raMatrix, LV_BTN_STYLE_PR, &matrixStyleBtnPr);
}