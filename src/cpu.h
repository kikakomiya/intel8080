#pragma once

#include <stdint.h>

// A lot of opcodes here are unnamed.
// This is until I understand their function and can name it appropriately.
enum opcodes {
    OP_NOP, // 0x00
    OP_Unnamed01, // 0x01
    OP_StoreAInMemoryLocationBC, // 0x02
    OP_IncrementBC, // 0x03
    OP_IncrementB, // 0x04
    OP_DecrementB, // 0x05
    OP_Unnamed06, // 0x06
    OP_Unnamed07, // 0x07
    OP_Pad1, // 0x08
    OP_AddBCToHL, // 0x09
    OP_LoadMemoryLocationBCIntoA, // 0x0A
    OP_DecrementBC, // 0x0B
    OP_IncrementC, // 0x0C
    OP_DecrementC, // 0x0D
    OP_Unnamed0E, // 0x0E
    OP_Unnamed0F, // 0x0F
    OP_Pad2, // 0x10
    OP_Unnamed11, // 0x11
    OP_StoreAInMemoryLocationDE, // 0x12
    OP_IncrementDE, // 0x13
    OP_IncrementD, // 0x14
    OP_DecrementD, // 0x15
    OP_Unnamed16, // 0x16
    OP_Unnamed17, // 0x17
    OP_Pad3, // 0x18
    OP_AddDEToHL, // 0x19
    OP_LoadMemoryLocationDEIntoA, // 0x1A
    OP_DecrementDE, // 0x1B
    OP_IncrementE, // 0x1C
    OP_DecrementE, // 0x1D
    OP_Unnamed1E, // 0x1E
    OP_Unnamed1F, // 0x1F
    OP_Pad4, // 0x20
    OP_Unnamed21, // 0x21
    OP_Unnamed22, // 0x22
    OP_IncrementHL, // 0x23
    OP_IncrementH, // 0x24
    OP_DecrementH, // 0x25
    OP_Unnamed26, // 0x26
    OP_Unnamed27, // 0x27
    OP_Pad5, // 0x28
    OP_AddHIToHL, // 0x29
    OP_Unnamed2A, // 0x2A
    OP_DecrementHL, // 0x2B
    OP_IncrementL, // 0x2C
    OP_DecrementL, // 0x2D
    OP_Unnamed2E, // 0x2E
    OP_Unnamed2F, // 0x2F
    OP_Pad6, // 0x30
    OP_Unnamed31, // 0x31
    OP_Unnamed32, // 0x32
    OP_IncrementSP, // 0x33
    OP_IncrementM, // 0x34
    OP_DecrementM, // 0x35
    OP_Unnamed36, // 0x36
    OP_SetCarry, // 0x37
    OP_Pad7, // 0x38
    OP_AddSPToHL, // 0x39
    OP_Unnamed3A, // 0x3A
    OP_DecrementSP, // 0x3B
    OP_IncrementA, // 0x3C
    OP_DecrementA, // 0x3D
    OP_Unnamed3E, // 0x3E
    OP_Unnamed3F, // 0x3F
    OP_CopyBToB, // 0x40
    OP_CopyCToB, // 0x41
    OP_CopyDToB, // 0x42
    OP_CopyEToB, // 0x43
    OP_CopyHToB, // 0x44
    OP_CopyLToB, // 0x45
    OP_CopyMToB, // 0x46
    OP_CopyAToB, // 0x47
    OP_CopyBToC, // 0x48
    OP_CopyCToC, // 0x49
    OP_CopyDToC, // 0x4A
    OP_CopyEToC, // 0x4B
    OP_CopyHToC, // 0x4C
    OP_CopyLToC, // 0x4D
    OP_CopyMToC, // 0x4E
    OP_CopyAToC, // 0x4F
    OP_CopyBToD, // 0x50
    OP_CopyCToD, // 0x51
    OP_CopyDToD, // 0x52
    OP_CopyEToD, // 0x53
    OP_CopyHToD, // 0x54
    OP_CopyLToD, // 0x55
    OP_CopyMToD, // Ox56
    OP_CopyAToD, // 0x57
    OP_CopyBToE, // 0x58
    OP_CopyCToE, // 0x59
    OP_CopyDToE, // 0x5A
    OP_CopyEToE, // 0x5B
    OP_CopyHToE, // 0x5C
    OP_CopyLToE, // 0x5D
    OP_CopyMToE, // 0x5E
    OP_CopyAToE, // 0x5F
    OP_CopyBToH, // 0x60
    OP_CopyCToH, // 0x61
    OP_CopyDToH, // 0x62
    OP_CopyEToH, // 0x63
    OP_CopyHToH, // 0x64
    OP_CopyLToH, // 0x65
    OP_CopyMToH, // 0x66
    OP_CopyAToH, // 0x67
    OP_CopyBToL, // 0x68
    OP_CopyCToL, // 0x69
    OP_CopyDToL, // 0x6A
    OP_CopyEToL, // 0x6B
    OP_CopyHToL, // 0x6C
    OP_CopyLToL, // 0x6D
    OP_CopyMToL, // 0x6E
    OP_CopyAToL, // 0x6F
    OP_CopyBToM, // 0x70
    OP_CopyCToM, // 0x71
    OP_CopyDToM, // 0x72
    OP_CopyEToM, // 0x73
    OP_CopyHToM, // 0x74
    OP_CopyLToM, // 0x75
    OP_Halt, // 0x76
    OP_CopyAToM, // 0x77
    OP_CopyBToA, // 0x78
    OP_CopyCToA, // 0x79
    OP_CopyDToA, // 0x7A
    OP_CopyEToA, // 0x7B
    OP_CopyHToA, // 0x7C
    OP_CopyLToA, // 0x7D
    OP_CopyMToA, // 0x7E
    OP_CopyAToA, // 0x7F
    OP_AddB, // 0x80
    OP_AddC, // 0x81
    OP_AddD, // 0x82
    OP_AddE, // 0x83
    OP_AddH, // 0x84
    OP_AddL, // 0x85
    OP_AddM, // 0x86
    OP_AddA, // 0x87
    OP_AdcB, // 0x88
    OP_AdcC, // 0x89
    OP_AdcD, // 0x8A
    OP_AdcE, // Ox8B
    OP_AdcH, // 0x8C
    OP_AdcL, // 0x8D
    OP_AdcM, // 0x8E
    OP_AdcA, // 0x8F
    OP_SubB, // 0x90
    OP_SubC, // 0x91
    OP_SubD, // 0x92
    OP_SubE, // 0x93
    OP_SubH, // 0x94
    OP_SubL, // 0x95
    OP_SubM, // 0x96
    OP_SubA, // 0x97
    OP_SbbB, // 0x98
    OP_SbbC, // 0x99
    OP_SbbD, // 0x9A
    OP_SbbE, // 0x9B
    OP_SbbH, // 0x9C
    OP_SbbL, // 0x9D
    OP_SbbM, // 0x9E
    OP_SbbA, // 0x9F
    OP_AAndB, // 0xA0
    OP_AAndC, // 0xA1
    OP_AAndD, // 0xA2
    OP_AAndE, // 0xA3
    OP_AAndH, // 0xA4
    OP_AAndL, // 0xA5
    OP_AAndM, // 0xA6
    OP_AAndA, // 0xA7
    OP_AXorB, // 0xA8
    OP_AXorC, // 0xA9
    OP_AXorD, // 0xAA
    OP_AXorE, // 0xAB
    OP_AXorH, // 0xAC
    OP_AXorL, // 0xAD
    OP_AXorM, // 0xAE
    OP_AXorA, // 0xAF
    OP_AOrB, // 0xB0
    OP_AOrC, // 0xB1
    OP_AOrD, // 0xB2
    OP_AOrE, // 0xB3
    OP_AOrH, // 0xB4
    OP_AOrL, // 0xB5
    OP_AOrM, // 0xB6
    OP_AOrA, // 0xB7
    OP_ACompareB, // 0xB8
    OP_ACompareC, // 0xB9
    OP_ACompareD, // 0xBA
    OP_ACompareE, // 0xBB
    OP_ACompareH, // 0xBC
    OP_ACompareL, // 0xBD
    OP_ACompareM, // 0xBE
    OP_ACompareA, // 0xBF
    OP_UnnamedC0, // 0xC0
    OP_UnnamedC1, // 0xC1
    OP_JumpIfNotZero, // 0xC2
    OP_Jump, // 0xC3
    OP_CallIfNotZero, // 0xC4
    OP_UnnamedC5, // 0xC5
    OP_UnnamedC6, // 0xC6
    OP_UnnamedC7, // 0xC7
    OP_ReturnIfZero, // 0xC8
    OP_Return, // 0xC9
    OP_JumpIfZero, // 0xCA
    OP_Pad8, // 0xCB
    OP_CallIfZero, // 0xCC
    OP_Call, // 0xCD
    OP_UnnamedCE, // 0xCE
    OP_UnnamedCF, // 0xCF
    OP_UnnamedD0, // 0xD0
    OP_UnnamedD1, // 0xD1
    OP_UnnamedD2, // 0xD2
    OP_UnnamedD3, // 0xD3
    OP_UnnamedD4, // 0xD4
    OP_UnnamedD5, // 0xD5
    OP_UnnamedD6, // 0xD6
    OP_UnnamedD7, // 0xD7
    OP_UnnamedD8, // 0xD8
    OP_Pad9, // 0xD9
    OP_UnnamedDA, // 0xDA
    OP_UnnamedDB, // 0xDB
    OP_UnnamedDC, // 0xDC
    OP_Pad10, // 0xDD
    OP_UnnamedDE, // 0xDE
    OP_UnnamedDF, // 0xDF
    OP_UnnamedE0, // 0xE0
    OP_PopHL, // 0xE1
    OP_UnnamedE2, // 0xE2
    OP_ExchangeHAndLWithSPAndSPPlusOne, // 0xE3
    OP_UnnamedE4, // 0xE4
    OP_PushHL, // 0xE5
    OP_UnnamedE6, // 0xE6
    OP_UnnamedE7, // 0xE7
    OP_UnnamedE8, // 0xE8
    OP_UnnamedE9, // 0xE9
    OP_UnnamedEA, // 0xEA
    OP_ExchangeHAndLWithDAndE, // 0xEB
    OP_UnnamedEC, // 0xEC
    OP_Pad11, // 0xED
    OP_UnnamedEE, // 0xEE
    OP_UnnamedEF, // 0xEF
    OP_UnnamedF0, // 0xF0
    OP_PopPSW, // 0xF1
    OP_UnnamedF2, // 0xF2
    OP_UnnamedF3, // 0xF3
    OP_UnnamedF4, // 0xF4
    OP_PushPSW, // 0xF5
    OP_UnnamedF6, // 0xF6
    OP_UnnamedF7, // 0xF7
    OP_UnnamedF8, // 0xF8
    OP_SetSPToHL, // 0xF9
    OP_UnnamedFA, // 0xFA
    OP_UnnamedFB, // 0xFB
    OP_UnnamedFC, // 0xFC
    OP_Pad12, // 0xFD
    OP_UnnamedFE, // 0xFE
    OP_UnnamedFF // 0xFF
};

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

struct instruction {
    uint16_t opcode;
};

void initialiseCPU(struct cpu* cpu);
