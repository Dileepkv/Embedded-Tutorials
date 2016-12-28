int main(){
    *((unsigned int *)0x400FE608U)= 0x20U ; /*turn on bit 5 of 0x400FE608 register to wake up GPIO LED memory*/ 
    *((unsigned int *)0x40025400U)= 0x0EU ; /*turn on bits 1-3 of 0x40025400 for pin direction*/
    *((unsigned int *)0x4002551CU)= 0x0EU ; /*turn on bits 1-3 of 0x4002551c to set pins as data output */
    
    while(1){
        *((unsigned int *)0x400253FCU)= 0x02U ; /*set the red bit for the LED on */
        int counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        *((unsigned int *)0x400253FCU)= 0x04U ; /*set the blue bit for the LED on */
        
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        *((unsigned int *)0x400253FCU)= 0x08U ; /*set the green bit for the LED on */
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        *((unsigned int *)0x400253FCU)= 0x00U ; /*set the green bit for the LED off */
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
    }
    return 0;
}
