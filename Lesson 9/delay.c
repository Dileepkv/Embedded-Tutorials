void delay(int pause_cycles);

void delay(int pause_cycles) {
   int volatile counter = 0; 
        while(counter < pause_cycles){
          ++counter;
        }
}