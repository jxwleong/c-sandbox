#include <stdio.h>


int main(){
    long long value;
    /*
        1. Move 0x10 to ebx
        2. Add 0x10 with value to ebx (0x10)
    */
    __asm__("movl $0x10, %ebx;"
            "addl $0x10, %ebx;");
    __asm__("movl %%ebx, %0;" : "=r" (value) : );
    printf("0x%x", value);
    return 0;
}