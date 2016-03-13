
#include <avr/io.h>
#include <util/delay.h>

#include "LCD.h"
#include "LCD_char_jp.h"

int main(void){

    lcd_init();
    lcd_send_char('A');
    lcd_send_char('b');
    lcd_send_char('c');    
    lcd_send_char(CHAR_JP_TE);
    lcd_send_char(CHAR_JP_SU);
    lcd_send_char(CHAR_JP_TO);

    while(1);

}
