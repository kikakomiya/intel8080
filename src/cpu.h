#pragma once

#include <stdint.h>

struct cpu {
    union {
        struct {
            uint8_t A;
            struct {
                uint8_t S: 1;
                uint8_t Z: 1;
                uint8_t _1: 1;
                uint8_t AC: 1;
                uint8_t _2: 1;
                uint8_t P: 1;
                uint8_t _3: 1;
                uint8_t C: 1;
            } flags;
        };
        uint16_t PSW;
    };
    union {
        struct {
            uint8_t B, C;
        };
        uint16_t BC;
    };
    union {
        struct {
            uint8_t D, E;
        };
        uint16_t DE;
    };
    union {
        struct {
            uint8_t H, L;
        };
        uint16_t HL, M;
    };
    uint16_t sp;
    uint16_t pc;
    uint8_t ram[65536];
};

void initialiseCPU(struct cpu* cpu);
