#include "lm4f120h5qr.h"
#include "delay.h"

#define LED_RED (1u << 1) //this defines the bit value associated with red for the LED data register 0x02u
#define LED_BLUE (1u << 2) //0x04u
#define LED_GREEN (1u << 3) //0x08u
#define WaitTime 500000u //define the time to wait between commands 
//do this here so the variable name does not need to be stored in memory while the code runs

unsigned fact(unsigned n) ;

int main(){
    unsigned volatile x;
    x= fact(0);
    x= 2u + 3u*fact(1u);
    (void)fact(5u);
  
  
  
    SYSCTL_RCGCGPIO_R |= (1u << 5) ; //turn on bit 5 of 0x400FE608 register to wake up GPIO LED clock access 
    SYSCTL_GPIOHBCTL_R |= (1u << 5) ; //convert processing mode to modern version AHB
    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN) ; //turn on bits 1-3 of 0x40025400 for pin direction
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN) ; //turn on bits 1-3 of 0x4002551c to set pins as data output 

    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED ;//turn red on to start
    while(1){        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN] = LED_GREEN ; //move to yellow    
        delay(WaitTime);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0; //move green by turning red off
        delay(WaitTime);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE ; //make cyan by turning blue on
        delay(WaitTime);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN] = 0 ; //move to blue by turning green off    
        delay(WaitTime);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED ; //move to purple by turning red on
        delay(WaitTime);
        
        GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = 0 ; //turn blue off leaving us at initial red
        delay(WaitTime);
        
    }
    return 0;
}

unsigned fact(unsigned n){
  // 0! = 1
  // n! = n*(n-1)! for all n>0
  
  unsigned foo[10]; //this variable it going to overload the stack to learn about it
  foo[n]=n;
  
  if(n==0u){
      return 1u;
  }else{
      return (foo[n])*fact(n-1);
  }
}
