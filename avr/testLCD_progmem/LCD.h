
#ifndef LCD_H
#define LCD_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>


#define LCD_D_DDR   DDRB
#define LCD_D_PORT  PORTB
#define LCD_RS_DDR  DDRD
#define LCD_RS_PORT PORTD
#define LCD_RS_BIT  PD5
#define LCD_E_DDR   DDRD
#define LCD_E_PORT  PORTD
#define LCD_E_BIT   PD6


#define LCD_STARTUP_MS  20
#define LCD_CMD_WAIT_US  50
#define LCD_CHAR_WAIT_US 50

//define the commands
#define LCD_CMD_CLR_DISP    0x01

#define LCD_CMD_RET_HOME    0x02

#define LCD_CMD_ENTRY_MODE_SEL  0x04
#define LCD_CMD_ENTRY_MODE_SET_INC  0x02
#define LCD_CMD_ENTRY_MODE_SET_DEC  0x00
#define LCD_CMD_ENTRY_MODE_SET_SHIFT    0x01

#define LCD_CMD_DISP_CTRL   0x08
#define LCD_CMD_DISP_CTRL_DISP_ON   0x04
#define LCD_CMD_DISP_CTRL_DISP_OFF  0x00
#define LCD_CMD_DISP_CTRL_UL_ON     0x02
#define LCD_CMD_DISP_CTRL_UL_OFF    0x00
#define LCD_CMD_DISP_CTRL_BLINK_ON  0x01
#define LCD_CMD_DISP_CTRL_BLINK_OFF 0x00

#define LCD_CMD_CUR_DISP_SHIFT      0x10
#define LCD_CMD_CUR_DISP_SHIFT_DISP_SHIFT   0x08
#define LCD_CMD_CUR_DISP_SHIFT_CUR_MOVE 0x00
#define LCD_CMD_CUR_DISP_SHIFT_RIGHT    0x04
#define LCD_CMD_CUR_DISP_SHIFT_LEFT     0x00

#define LCD_CMD_FUNC_SET    0x20
#define LCD_CMD_FUNC_SET_8BIT   0x10
#define LCD_CMD_FUNC_SET_4BIT   0x00
#define LCD_CMD_FUNC_SET_2LINE  0x08
#define LCD_CMD_FUNC_SET_1LINE  0x00
#define LCD_CMD_FUNC_SET_10FONT 0x04
#define LCD_CMD_FUNC_SET_7FONT  0x00

//you will have to OR the address with the cmd
//6bit addr
#define LCD_CMD_SET_CGRAM_ADDR  0x40
//7bit addr
#define LCD_CMD_SET_DDRAM_ADDR  0x80

void lcd_init(void);
void lcd_send_cmd(uint8_t in_cmd);
void lcd_send_char(uint8_t in_ch);
void lcd_send_arr_P(const uint8_t * in_arr_P, uint8_t size);


#endif
