#ifndef TFT_180_H
#define TFT_180_H
#include "COMMON.h"

#define Line 16

typedef enum
{
    WHITE    = (0xFFFF),                                                     // ??
    BLACK    = (0x0000),                                                     // ??
    BLUE     = (0x001F),                                                     // ??
    PURPLE   = (0xF81F),                                                     // ??
    PINK     = (0xFE19),                                                     // ??
    RED      = (0xF800),                                                     // ??
    MAGENTA  = (0xF81F),                                                     // ??
    GREEN    = (0x07E0),                                                     // ??
    CYAN     = (0x07FF),                                                     // ??
    YELLOW   = (0xFFE0),                                                     // ??
    BROWN    = (0xBC40),                                                     // ??
    GRAY     = (0x8430),                                                     // ??
}color_enum;

static uint16_t           tft180_pencolor     = YELLOW;
static uint16_t           tft180_bgcolor      = BLACK;
static uint8_t            tft180_x_max        = 160;
static uint8_t            tft180_y_max        = 128;

void tft180_init (void);
void tft180_clear_color (uint16_t tft180_bgcolor);
void tft180_show_string_color (uint8_t x, uint8_t y, const char dat[],uint16_t tft180_bgcolor,uint16_t tft180_pencolor);
void tft180_show_num_color (uint8_t x, uint8_t y, const float dat, uint8_t num, uint8_t pointnum,uint16_t tft180_bgcolor,uint16_t tft180_pencolor);
#define tft180_clear()                            (tft180_clear_color(tft180_bgcolor))
#define tft180_show_string(x,y,dat)                 (tft180_show_string_color((x),(y),(dat),tft180_bgcolor,tft180_pencolor))
#define tft180_show_float(x,y,dat,num,pointnum)       (tft180_show_num_color((x),(y),(dat),(num),(pointnum),tft180_bgcolor,tft180_pencolor))
#define tft180_show_int(x,y,dat,num)       (tft180_show_num_color((x),(y),(dat),(num),0,tft180_bgcolor,tft180_pencolor))

#endif
