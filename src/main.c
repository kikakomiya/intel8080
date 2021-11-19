#include <stdio.h>

#include "cpu.h"

int main() {
    struct cpu cpu;
    initialiseCPU(&cpu);
    while (cpu.pc <= 65534) {
        fprintf(stdout, "PC: %d\n", cpu.pc);
        if (cpu.pc == 65534) {
            break;
        }
        cpu.pc += 2;
    }
    return 0;
}
