#include "lm4f120h5qr.h"

int main(){
    SYSCTL_RCGCGPIO_R = 0x20U ; /*turn on bit 5 of 0x400FE608 register to wake up GPIO LED memory*/ 
    GPIO_PORTF_DIR_R = 0x0EU ; /*turn on bits 1-3 of 0x40025400 for pin direction*/
    GPIO_PORTF_DEN_R = 0x0EU ; /*turn on bits 1-3 of 0x4002551c to set pins as data output */
    GPIO_PORTF_DATA_R = 0x02U ; /*set the red bit for the LED on */
       
    while(1){
        GPIO_PORTF_DATA_R = 0x02U ; /*set the red bit for the LED on */
        int volatile counter = 0;
        while(counter < 1000){
          ++counter;
        }
        
        GPIO_PORTF_DATA_R = 0x04U ; /*set the blue bit for the LED on */
        
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        GPIO_PORTF_DATA_R = 0x08U ; /*set the green bit for the LED on */
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        GPIO_PORTF_DATA_R = 0x00U ; /*set the green bit for the LED off */
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
    }
    return 0;
}
