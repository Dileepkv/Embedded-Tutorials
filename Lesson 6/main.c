#include "lm4f120h5qr.h"

#define LED_RED (1u << 1) //this defines the bit value associated with red for the LED data register 0x02u
#define LED_BLUE (1u << 2) //0x04u
#define LED_GREEN (1u << 3) //0x08u

int main(){
    SYSCTL_RCGCGPIO_R |= (1u << 5) ; //turn on bit 5 of 0x400FE608 register to wake up GPIO LED memory 
    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN) ; //turn on bits 1-3 of 0x40025400 for pin direction
    GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN) ; //turn on bits 1-3 of 0x4002551c to set pins as data output 

    GPIO_PORTF_DATA_R |= LED_BLUE ;  
    while(1){
        GPIO_PORTF_DATA_R |= LED_RED ; //or-equal sets whatever you are already superimposed with the value for red. Only valid with R/W registers
        int volatile counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        GPIO_PORTF_DATA_R &= ~LED_RED ; //Red off
        //&-equals-not compares the register with the opposite of red and preforms & and since not-red will alyways disagree with the relevent bits they will be turned off leaving the rest intace.
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
    }
    return 0;
}
