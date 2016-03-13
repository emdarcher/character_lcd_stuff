
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "LCD.h"
#include "LCD_char_jp.h"

const uint8_t line1[] PROGMEM = {'A', 'b', 'c', 
    CHAR_JP_TE, CHAR_JP_SU, CHAR_JP_TO};

int main(void){

    lcd_init();
    //lcd_send_char('A');
    //lcd_send_char('b');
    //lcd_send_char('c');    
    //lcd_send_char(CHAR_JP_TE);
    //lcd_send_char(CHAR_JP_SU);
    //lcd_send_char(CHAR_JP_TO);
    lcd_send_arr_P(&line1, sizeof(line1));

    while(1);

}
