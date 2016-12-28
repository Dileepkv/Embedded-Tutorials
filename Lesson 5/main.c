#define RCGCGPIO (*((unsigned int *)0x400FE608U))

#define GPIOF_BASE 0x40025000U
#define GPIOF_DIRECTION (*((unsigned int *) (GPIOF_BASE + 0x400U)))
#define GPIOF_DEN (*((unsigned int *) (GPIOF_BASE + 0x51CU)))
#define GPIOF_COLORVALUE (*((unsigned int *) (GPIOF_BASE + 0x3FCU)))



int main(){
    RCGCGPIO = 0x20U ; /*turn on bit 5 of 0x400FE608 register to wake up GPIO LED memory*/ 
    GPIOF_DIRECTION = 0x0EU ; /*turn on bits 1-3 of 0x40025400 for pin direction*/
    GPIOF_DEN = 0x0EU ; /*turn on bits 1-3 of 0x4002551c to set pins as data output */
    
    while(1){
        GPIOF_COLORVALUE = 0x02U ; /*set the red bit for the LED on */
        int counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        GPIOF_COLORVALUE = 0x04U ; /*set the blue bit for the LED on */
        
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        GPIOF_COLORVALUE = 0x08U ; /*set the green bit for the LED on */
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
        GPIOF_COLORVALUE = 0x00U ; /*set the green bit for the LED off */
        counter = 0;
        while(counter < 1000000){
          ++counter;
        }
        
    }
    return 0;
}
