

#include "LCD.h"


void lcd_init(void){
    //setup pins
    LCD_D_DDR |= 0xff;
    LCD_D_PORT = 0x00;

    //init RS
    LCD_RS_DDR |= (1<<LCD_RS_BIT);
    //set to 0
    LCD_RS_PORT &= ~(1<<LCD_RS_BIT); 

    //init E
    LCD_E_DDR |= (1<<LCD_E_BIT);
    //set to 0
    LCD_E_PORT &= ~(1<<LCD_E_BIT);

    //wait some time for the LCD to fully start up
    _delay_ms(LCD_STARTUP_MS); 

    //set display on with underline and blinking cursor
    lcd_send_cmd(LCD_CMD_DISP_CTRL
                    | LCD_CMD_DISP_CTRL_DISP_ON
                    | LCD_CMD_DISP_CTRL_UL_ON
                    | LCD_CMD_DISP_CTRL_BLINK_ON); 

    //set up the function of the display
    //for 8-bit interface, 2 lines, 5x7 font
    lcd_send_cmd(LCD_CMD_FUNC_SET
                    | LCD_CMD_FUNC_SET_8BIT
                    | LCD_CMD_FUNC_SET_2LINE
                    | LCD_CMD_FUNC_SET_2LINE);
    
    lcd_send_cmd(LCD_CMD_RET_HOME);
    
    _delay_ms(LCD_STARTUP_MS);
}
void lcd_send_cmd(uint8_t in_cmd){
    //clear the data pins
    LCD_D_PORT = 0x00;
    //clear enable
    LCD_E_PORT &= ~(1<<LCD_E_BIT);

    //set to cmd mode
    LCD_RS_PORT &= ~(1<<LCD_RS_BIT); 
   
    //write the cmd to the data pins
    LCD_D_PORT = in_cmd;

    //set enable
    LCD_E_PORT |= (1<<LCD_E_BIT);
    //wait a bit
    _delay_us(1);
    //clear enable to read in the data
    LCD_E_PORT &= ~(1<<LCD_E_BIT);
    //now clear data pins
    LCD_D_PORT = 0x00;

    //wait
    _delay_us(LCD_CMD_WAIT_US);
}
void lcd_send_char(uint8_t in_ch){
    //clear the data pins
    LCD_D_PORT = 0x00;
    //clear enable
    LCD_E_PORT &= ~(1<<LCD_E_BIT);
   
    //set to character mode
    LCD_RS_PORT |= (1<<LCD_RS_BIT); 

    //write the character to the data pins
    LCD_D_PORT = in_ch;

    //set enable
    LCD_E_PORT |= (1<<LCD_E_BIT);
    //wait a bit
    _delay_us(1);
    //clear enable to read in the data
    LCD_E_PORT &= ~(1<<LCD_E_BIT);
    //now clear data pins
    LCD_D_PORT = 0x00;


    //wait
    _delay_us(LCD_CHAR_WAIT_US);

}
void lcd_send_arr_P(const uint8_t * in_arr_P, uint8_t size){
    int i;
    for(i=0;i<size;i++){
        lcd_send_char(pgm_read_byte(in_arr_P + i)); 
    }
}

