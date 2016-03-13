
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "LCD.h"
#include "LCD_char_jp.h"

#define CENTERED 1

const uint8_t line1[] PROGMEM = {
#if CENTERED
    ' ',' ',
#endif
    //i-san イーサン 
    CHAR_JP_I, CHAR_JP_PROLONG, CHAR_JP_SA, CHAR_JP_N,
    //(dot) ・
    CHAR_JP_DOT,
    //duranto デュラント 
    CHAR_JP_TE, CHAR_JP_NIGORI, CHAR_JP_Sm_YU, 
    CHAR_JP_RA, CHAR_JP_N, CHAR_JP_TO,
    ' ',
#if !CENTERED
    //no ノ (の)
    CHAR_JP_NO,
#endif
};

const uint8_t line2[] PROGMEM = {
#if CENTERED
    //no ノ (の)
    CHAR_JP_NO,
    ' ',
#endif
    //taimurain (timeline) タイムライン
    CHAR_JP_TA, CHAR_JP_I, CHAR_JP_MU,
    CHAR_JP_RA, CHAR_JP_I, CHAR_JP_N,
    ' ',
    //he ヘ
    CHAR_JP_HE,
    ' ',
    //youkoso ヨウコソ
    CHAR_JP_YO, CHAR_JP_U, CHAR_JP_KO, CHAR_JP_SO,
};

int main(void){

    lcd_init();
    //set the cursor to not blink
    lcd_send_cmd(LCD_CMD_DISP_CTRL | LCD_CMD_DISP_CTRL_DISP_ON);
    //send 1st line
    lcd_send_arr_P(&line1, sizeof(line1));
    //set cursor to beginning of the second line
    lcd_send_cmd(LCD_CMD_SET_DDRAM_ADDR | 0x40);
    //send 2nd line
    lcd_send_arr_P(&line2, sizeof(line2));

    while(1);

}
