

#include <avr/io.h>
#include <util/delay.h>



int main(void){
    //set to output
    DDRD |= (1 << PD7);

    //basic delay then toggle loop
    while(1){
        PORTD ^= (1 << PD7);
        _delay_ms(500);        
    } 
    

}
