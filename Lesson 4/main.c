int main(){
    *((unsigned int *)0x400FE608)= 0x20u ; /*turn on bit 5 of 0x400FE608 register to wake up GPIO LED memory*/ 
    
    return 0;
}
