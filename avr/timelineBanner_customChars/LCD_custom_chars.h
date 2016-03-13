

#ifndef LCD_CUSTOM_CHARS_H
#define LCD_CUSTOM_CHARS_H


//creating custom characters for a few hiragana

#define HIRAGANA_NO 0x00
const uint8_t custom_char_NO[] PROGMEM = {
    //の
    0b00000000,
    0b00001110,
    0b00010101,
    0b00010101,
    0b00010101,
    0b00011001,
    0b00000010,
    0b00000000,
};

#define HIRAGANA_YO 0x01
const uint8_t custom_char_YO[] PROGMEM = {
    //よ
    0b00000000,
    0b00000100,
    0b00000111,
    0b00000100,
    0b00001100,
    0b00010110,
    0b00011001,
    0b00000000,
};

#define HIRAGANA_U  0x02
const uint8_t custom_char_U[] PROGMEM = {
    //う
    0b00001110,
    0b00000000,
    0b00001110,
    0b00010001,
    0b00000001,
    0b00000001,
    0b00000110,
    0b00000000,
};

#define HIRAGANA_KO 0x03
const uint8_t custom_char_KO[] PROGMEM = {
    //こ
    0b00000000,
    0b00011111,
    0b00000001,
    0b00000000,
    0b00000000,
    0b00010000,
    0b00001111,
    0b00000000,
};

#define HIRAGANA_SO 0x04
const uint8_t custom_char_SO[] PROGMEM = {
    //そ
    0b00001001,
    0b00000110,
    0b00011111,
    0b00000100,
    0b00001000,
    0b00001000,
    0b00000110,
    0b00000000,
};

#endif
