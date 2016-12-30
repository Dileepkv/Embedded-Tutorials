#include "lm4f120h5qr.h"

#define LED_RED (1u << 1) //this defines the bit value associated with red for the LED data register 0x02u
#define LED_BLUE (1u << 2) //0x04u
#define LED_GREEN (1u << 3) //0x08u

int main(){
    SYSCTL_RCGCGPIO_R |= (1u << 5) ; //turn on bit 5 of 0x400FE608 register to wake up GPIO LED memory 
    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN) ; //turn on bits 1-3 of 0x40025400 for pin direction
    GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN) ; //turn on bits 1-3 of 0x4002551c to set pins as data output 

    GPIO_PORTF_DATA_BITS_R[LED_GREEN] = LED_GREEN ; //use the generic GPIO port F pointer-array and pick out the Ggreen bit: then set to green value    
    while(1){
      GPIO_PORTF_DATA_BITS_R[LED_RED] = LED_RED ; //use the generic GPIO port F pointer-array and pick out the first red bit: then set to red value
        int volatile counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        GPIO_PORTF_DATA_BITS_R[LED_RED] =  //call up the red pointer-array red bit and simple set to 0 - or off.
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
    }
    return 0;
}
