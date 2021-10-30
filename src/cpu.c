#include <stdio.h>
#include <string.h>

#include "cpu.h"

void initialiseCPU(struct cpu *cpu) {
    fprintf(stdout, "Initialising CPU...\n");
    memset(cpu, 0, sizeof(struct cpu));
}