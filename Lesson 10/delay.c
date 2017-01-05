#include "delay.h"

void delay(int volatile pause_cycles) { 
        while(pause_cycles > 0){
          --pause_cycles;
        }
}