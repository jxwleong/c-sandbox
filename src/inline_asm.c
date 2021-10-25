// Copyright 2021 @jxwleong. All rights reserved.

#include <stdio.h>
#include <stdint.h>  // To use uint64_t

int main() {
    uint64_t  value;
    /*
        1. Move 0x10 to rbx
        2. Add 0x10 with value to rbx (0x10)
    */
    __asm__("movq $0x10, %rbx;"
            "add $0x10, %rbx;");
    __asm__("movq %%rbx, %0;" : "=r" (value) :);
    printf("0x%x", value);
    return 0;
}
