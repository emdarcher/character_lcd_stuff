

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

    //make the Cursor return to the home postion (DDRAM address 0x00) 
    lcd_send_cmd(LCD_CMD_RET_HOME);
    //wait a little longer just to be cautious 
    _delay_ms(LCD_STARTUP_MS);
}

void lcd_send_cmd(uint8_t in_cmd){

    //set to cmd mode
    LCD_RS_PORT &= ~(1<<LCD_RS_BIT); 
  
    lcd_send_data(in_cmd); 

    //wait for command to finish
    _delay_us(LCD_CMD_WAIT_US);
}

void lcd_send_char(uint8_t in_ch){
    
    //set to character mode
    LCD_RS_PORT |= (1<<LCD_RS_BIT); 

    lcd_send_data(in_ch);

    //wait for command to finish
    _delay_us(LCD_CHAR_WAIT_US);
}
void lcd_send_arr_P(const uint8_t * in_arr_P, uint8_t size){
    //sends a set of characters in a PROGMEM array passed in `in_arr_P`
    uint8_t i;
    for(i=0;i<size;i++){
        lcd_send_char(pgm_read_byte(in_arr_P + i)); 
    }
}

void lcd_send_data(uint8_t in_data){
    
    //clear the data pins
    LCD_D_PORT = 0x00;
    //clear enable
    LCD_E_PORT &= ~(1<<LCD_E_BIT);

    //write data to data pins
    LCD_D_PORT = in_data;
    
    //set enable
    LCD_E_PORT |= (1<<LCD_E_BIT);
    //wait a bit
    _delay_us(1);
    //clear enable to read in the data
    LCD_E_PORT &= ~(1<<LCD_E_BIT);
    //now clear data pins
    LCD_D_PORT = 0x00;
}

void lcd_add_custom_char(const uint8_t * in_bmp_P, 
        uint8_t rows, uint8_t char_addr){
    //loads a custom character into the LCD's CGRAM line by line
    //with the amount of rows specified by rows, 8 or 10 depending on the LCD
    //the variable `char_addr` should be the address you want to be 
    //able to address that character with after loading it.
    //must be between 0x00 and 0x0F


    //send command to enter new custom character
    uint8_t line_data_start_addr = (uint8_t)(char_addr << 3) | 0x00;
    lcd_send_cmd(LCD_CMD_SET_CGRAM_ADDR | line_data_start_addr);
    //wait for command to finish
    _delay_us(LCD_CMD_WAIT_US);

    //set to data entry mode
    LCD_RS_PORT |= (1<<LCD_RS_BIT); 
    //wait for command to finish
    _delay_us(LCD_CMD_WAIT_US); 

    uint8_t i;
    for(i=0;i<rows;i++){
        lcd_send_data(pgm_read_byte(in_bmp_P + i));
        _delay_us(LCD_WRITE_WAIT_US);
    } 
     
}

