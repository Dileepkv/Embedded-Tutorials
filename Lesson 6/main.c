#include "lm4f120h5qr.h"

int main(){
    SYSCTL_RCGCGPIO_R = 0x20U ; //turn on bit 5 of 0x400FE608 register to wake up GPIO LED memory 
    GPIO_PORTF_DIR_R = 0x0EU ; //turn on bits 1-3 of 0x40025400 for pin direction
    GPIO_PORTF_DEN_R = 0x0EU ; //turn on bits 1-3 of 0x4002551c to set pins as data output 
    GPIO_PORTF_DATA_R = 0x02U ; //set the red bit for the LED on
    
    unsigned int a=0x5a5a5a5a;
    unsigned int b=0xDEADBEEF;
    unsigned int c;
    
    c = a | b; //or
    c = a ^ b; //exclusive or
    c = a & b; //and
    c = ~b;   //NOT or compliment
    c = b >> 1; //right-shift
    c= b << 3; //left-shift
    
    
      
    GPIO_PORTF_DATA_R = 0x04U ; //turn blue on before loop 
    while(1){
        GPIO_PORTF_DATA_R = 0x02U ; //set the red bit for the LED on
        int volatile counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        GPIO_PORTF_DATA_R = 0x00U ; //set the bit for the LED off
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
    }
    return 0;
}
