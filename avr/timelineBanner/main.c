
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "LCD.h"
#include "LCD_char_jp.h"

const uint8_t line1[] PROGMEM = {
    //i-san イーサン 
    CHAR_JP_I, CHAR_JP_PROLONG, CHAR_JP_SA, CHAR_JP_N,
    //(dot) ・
    CHAR_JP_DOT,
    //duranto デュラント 
    CHAR_JP_TE, CHAR_JP_NIGORI, CHAR_JP_Sm_YU, 
    CHAR_JP_RA, CHAR_JP_N, CHAR_JP_TO,
    ' ',
    //no ノ (の)
    CHAR_JP_NO,
};

int main(void){

    lcd_init();
    lcd_send_arr_P(&line1, sizeof(line1));

    while(1);

}
