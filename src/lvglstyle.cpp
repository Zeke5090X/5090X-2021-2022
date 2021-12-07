#include "main.h"
//at some point we might want to use the rgb values for the lights 
void lvglstyle(){
    lv_style_t buttonStyleREL; //relesed style
    lv_style_t buttonStylePR; //pressed style

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

    lv_style_t matrixStyleBg;
    lv_style_copy(&matrixStyleBg, &lv_style_plain);
    matrixStyleBg.body.main_color = LV_COLOR_MAKE(100, 100, 100);
    matrixStyleBg.body.grad_color = LV_COLOR_MAKE(50, 50, 50);
    matrixStyleBg.body.padding.hor = 0;
    matrixStyleBg.body.padding.ver = 0;
    matrixStyleBg.body.padding.inner = 0;

    lv_style_t matrixStyleBtnRel;
    lv_style_copy(&matrixStyleBtnRel, &lv_style_btn_rel);
    matrixStyleBtnRel.body.main_color = LV_COLOR_MAKE(250, 0, 0);//this might look hidiously ugly
    matrixStyleBtnRel.body.grad_color = LV_COLOR_MAKE(0, 0, 250);//if so change the gradient to a blood red or black
    matrixStyleBtnRel.body.border.color = LV_COLOR_MAKE(115, 0, 0);
    matrixStyleBtnRel.body.border.width = 1;
    matrixStyleBtnRel.body.border.opa = LV_OPA_50;
    matrixStyleBtnRel.body.radius = 0;

    lv_style_t matrixStyleBtnPr;
    lv_style_copy(&matrixStyleBtnPr, &matrixStyleBtnRel);
    matrixStyleBtnPr.body.main_color = LV_COLOR_MAKE(125, 0, 0);
    matrixStyleBtnPr.body.grad_color = LV_COLOR_MAKE(0, 0, 125);

    lv_style_t matrixStyleBtnRelMain;
    lv_style_copy(&matrixStyleBtnRelMain, &matrixStyleBtnRel);
    matrixStyleBtnRelMain.body.main_color = LV_COLOR_MAKE(100, 100, 100);
    matrixStyleBtnRelMain.body.grad_color = LV_COLOR_MAKE(50, 50, 50);
    
    lv_style_t matrixStyleBtnPrMain;
    lv_style_copy(&matrixStyleBtnPrMain, &matrixStyleBtnRelMain);
    matrixStyleBtnPrMain.body.main_color = LV_COLOR_MAKE(50, 50, 50);
    matrixStyleBtnPrMain.body.grad_color = LV_COLOR_MAKE(25, 25, 25);    
    

    //more styles will be added as needed
}