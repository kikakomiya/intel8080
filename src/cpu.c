#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "cpu.h"

void initialiseCPU(struct cpu *cpu) {
    fprintf(stdout, "Initialising CPU...\n");
    memset(cpu, 0, sizeof(struct cpu));
}

void executeInstruction(uint8_t opcode, struct cpu* cpu) {
    switch (opcode) {
        // NOP
        // No operation.
        // Page 3-38
        case 0x00:
            break;
        // LXI B, D16
        // Store next two bytes in RAM in register pair BC.
        // Page 3-35
        case 0x01:
            cpu->B = cpu->ram[cpu->pc+2];
            cpu->C = cpu->ram[cpu->pc+1];
            break;
        // STAX B
        // Store value in accumulator in memory location denoted by value of register pair BC.
        // Page 3-62
        case 0x02:
            cpu->ram[cpu->BC] = cpu->A;
            break;
        // INX B
        // Increment value of register pair BC.
        // Page 3-26
        case 0x03:
            cpu->BC += 1;
            break;
        // INR B
        // Increment value of register B.
        // Page 3-25
        case 0x04:
            cpu->B += 1;
            break;
        // DCR B
        // Decrement value of register B.
        // Page 3-20
        case 0x05:
            cpu->B -= 1;
            break;
        // MVI B, D8
        // Store next byte in RAM in register B.
        // Page 3-37
        case 0x06:
            cpu->B = cpu->ram[cpu->pc+1];
            break;
        // DAD B
        // Add value of register pair BC to register pair HL.
        // Page 3-20
        case 0x09: {
            uint32_t temp09 = (uint32_t)cpu->BC + (uint32_t)cpu->HL;
            cpu->HL = temp09 & 0xFFFF;
            if (temp09 > 0xFFFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // LDAX B
        // Store value in memory location denoted by value of register pair BC in accumulator.
        // Page 3-33
        case 0x0A:
            cpu->A = cpu->ram[cpu->BC];
            break;
        // DCX B
        // Decrement value of register pair BC.
        // Page 3-22
        case 0x0B:
            cpu->BC -= 1;
            break;
        // INR C
        // Increment value of register C.
        // Page 3-25
        case 0x0C:
            cpu->C += 1;
            break;
        // DCR C
        // Decrement value of register C.
        // Page 3-20
        case 0x0D:
            cpu->C -= 1;
            break;
        // MVI C, D8
        // Store next byte in RAM in register C.
        // Page 3-37
        case 0x0E:
            cpu->C = cpu->ram[cpu->pc+1];
            break;
        // LXI D, D16
        // Store next two bytes in RAM in register pair DE.
        // Page 3-35
        case 0x11:
            cpu->D = cpu->ram[cpu->pc+2];
            cpu->E = cpu->ram[cpu->pc+1];
            break;
        // STAX D
        // Store value in accumulator in memory location denoted by value of register pair DE.
        // Page 3-62
        case 0x12:
            cpu->ram[cpu->DE] = cpu->A;
            break;
        // INX D
        // Increment value of register pair DE.
        // Page 3-26
        case 0x13:
            cpu->DE += 1;
            break;
        // INR D
        // Increment value of register D.
        // Page 3-25
        case 0x14:
            cpu->D += 1;
            break;
        // DCR D
        // Decrement value of register D.
        // Page 3-20
        case 0x15:
            cpu->D -= 1;
            break;
        // MVI D, D8
        // Store next byte in RAM in register D.
        // Page 3-37
        case 0x16:
            cpu->D = cpu->ram[cpu->pc+1];
            break;
        // DAD D
        // Add value of register pair DE to register pair HL.
        // Page 3-20
        case 0x19: {
            uint32_t temp19 = (uint32_t)cpu->DE + (uint32_t)cpu->HL;
            cpu->HL = temp19 & 0xFFFF;
            if (temp19 > 0xFFFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // LDAX D
        // Store value in memory location denoted by value of register pair DE in accumulator.
        // Page 3-33
        case 0x1A:
            cpu->A = cpu->ram[cpu->DE];
            break;
        // DCX D
        // Decrement value of register pair DE.
        // Page 3-22
        case 0x1B:
            cpu->DE -= 1;
            break;
        // INR E
        // Increment value of register E.
        // Page 3-25
        case 0x1C:
            cpu->E += 1;
            break;
        // DCR E
        // Decrement value of register E.
        // Page 3-20
        case 0x1D:
            cpu->E -= 1;
            break;
        // MVI E, D8
        // Store next byte in RAM in register E.
        // Page 3-37
        case 0x1E:
            cpu->E = cpu->ram[cpu->pc+1];
            break;
        // LXI H, D16
        // Store next two bytes in RAM in register pair HL.
        // Page 3-35
        case 0x21:
            cpu->H = cpu->ram[cpu->pc+2];
            cpu->L = cpu->ram[cpu->pc+1];
            break;
        // INX H
        // Increment value of register pair HL.
        // Page 3-26
        case 0x23:
            cpu->HL += 1;
            break;
        // INR H
        // Increment value of register H.
        case 0x24:
        // Page 3-25
            cpu->H += 1;
            break;
        // DCR H
        // Decrement value of register H.
        // Page 3-20
        case 0x25:
            cpu->H -= 1;
            break;
        // MVI H, D8
        // Store next byte in RAM in register H.
        // Page 3-37
        case 0x26:
            cpu->H = cpu->ram[cpu->pc+1];
            break;
        // DAD H
        // Add value of register pair HL to register pair HL.
        // Page 3-20
        case 0x29: {
            uint32_t temp29 = (uint32_t)cpu->HL + (uint32_t)cpu->HL;
            cpu->HL = temp29 & 0xFFFF;
            if (temp29 > 0xFFFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // DCX H
        // Decrement value of register pair HL.
        // Page 3-22
        case 0x2B:
            cpu->HL -= 1;
            break;
        // INR L
        // Increment value of register L.
        // Page 3-25
        case 0x2C:
            cpu->L += 1;
            break;
        // DCR L
        // Decrement value of register L.
        // Page 3-20
        case 0x2D:
            cpu->L -= 1;
            break;
        // MVI L, D8
        // Store next byte in RAM in register L.
        // Page 3-37
        case 0x2E:
            cpu->L = cpu->ram[cpu->pc+1];
            break;
        // INX SP
        // Increment value of stack pointer.
        // Page 3-26
        case 0x33:
            cpu->sp += 1;
            break;
        // MVI M, D8
        // Store next byte in RAM in memory location denoted by value of register pair M.
        // Page 3-37
        case 0x36:
            cpu->ram[cpu->M] = cpu->ram[cpu->pc+1];
            break;
        // STC
        // Set carry flag.
        // Page 3-63
        case 0x37:
            cpu->flags.C = 1;
            break;
        // DAD SP
        // Add value of stack pointer to register pair HL.
        // Page 3-20
        case 0x39: {
            uint32_t temp39 = (uint32_t)cpu->sp + (uint32_t)cpu->HL;
            cpu->HL = temp39 & 0xFFFF;
            if (temp39 > 0xFFFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // DCX SP
        // Decrement value of stack pointer.
        // Page 3-22
        case 0x3B:
            cpu->sp -= 1;
            break;
        // INR A
        // Increment value of accumulator.
        // Page 3-25
        case 0x3C:
            cpu->A += 1;
            break;
        // DCR A
        // Decrement value of accumulator.
        // Page 3-20
        case 0x3D:
            cpu->A -= 1;
            break;
        // MVI A, D8
        // Store next byte in RAM in accumulator.
        // Page 3-37
        case 0x3E:
            cpu->A = cpu->ram[cpu->pc+1];
            break;
        // MOV B, B
        // Copy value of register B to register B.
        // Page 3-36
        case 0x40:
            cpu->B = cpu->B;
            break;
        // MOV B, C
        // Copy value of register C to register B.
        // Page 3-36
        case 0x41:
            cpu->B = cpu->C;
            break;
        // MOV B, D
        // Copy value of register D to register B.
        // Page 3-36
        case 0x42:
            cpu->B = cpu->D;
            break;
        // MOV B, E
        // Copy value of register E to register B.
        // Page 3-36
        case 0x43:
            cpu->B = cpu->E;
            break;
        // MOV B, H
        // Copy value of register H to register B.
        // Page 3-36
        case 0x44:
            cpu->B = cpu->H;
            break;
        // MOV B, L
        // Copy value of register L to register B.
        // Page 3-36
        case 0x45:
            cpu->B = cpu->L;
            break;
        // MOV B, M
        // Copy value in memory location denoted by register pair M to register B.
        // Page 3-36
        case 0x46:
            cpu->B = cpu->ram[cpu->M];
            break;
        // MOV B, A
        // Copy value of accumulator to register B.
        // Page 3-36
        case 0x47:
            cpu->B = cpu->A;
            break;
        // MOV C, B
        // Copy value of register B to register C.
        // Page 3-36
        case 0x48:
            cpu->C = cpu->B;
            break;
        // MOV C, C
        // Copy value of register C to register C.
        // Page 3-36
        case 0x49:
            cpu->C = cpu->C;
            break;
        // MOV C, D
        // Copy value of register D to register C.
        // Page 3-36
        case 0x4A:
            cpu->C = cpu->D;
            break;
        // MOV C, E
        // Copy value of register E to register C.
        // Page 3-36
        case 0x4B:
            cpu->C = cpu->E;
            break;
        // MOV C, H
        // Copy value of register H to register C.
        // Page 3-36
        case 0x4C:
            cpu->C = cpu->H;
            break;
        // MOV C, L
        // Copy value of register L to register C.
        // Page 3-36
        case 0x4D:
            cpu->C = cpu->L;
            break;
        // MOV C, M
        // Copy value in memory location denoted by value of register pair M to register C.
        // Page 3-36
        case 0x4E:
            cpu->C = cpu->ram[cpu->M];
            break;
        // MOV C, A
        // Copy value of accumulator to register C.
        // Page 3-36
        case 0x4F:
            cpu->C = cpu->A;
            break;
        // MOV D, B
        // Copy value of register B to register D.
        // Page 3-36
        case 0x50:
            cpu->D = cpu->B;
            break;
        // MOV D, C
        // Copy value of register C to register D.
        // Page 3-36
        case 0x51:
            cpu->D = cpu->C;
            break;
        // MOV D, D
        // Copy value of register D to register D.
        // Page 3-36
        case 0x52:
            cpu->D = cpu->D;
            break;
        // MOV D, E
        // Copy value of register E to register D.
        // Page 3-36
        case 0x53:
            cpu->D = cpu->E;
            break;
        // MOV D, H
        // Copy value of register H to register D.
        // Page 3-36
        case 0x54:
            cpu->D = cpu->H;
            break;
        // MOV D, L
        // Copy value of register L to register D.
        // Page 3-36
        case 0x55:
            cpu->D = cpu->L;
            break;
        // MOV D, M
        // Copy value in memory location denoted by value of register paid M to register D.
        // Page 3-36
        case 0x56:
            cpu->D = cpu->ram[cpu->M];
            break;
        // MOV D, A
        // Copy value of accumulator to register D.
        // Page 3-36
        case 0x57:
            cpu->D = cpu->A;
            break;
        // MOV E, B
        // Copy value of register B to register E.
        // Page 3-36
        case 0x58:
            cpu->E = cpu->B;
            break;
        // MOV E, C
        // Copy value of register C to register E.
        // Page 3-36
        case 0x59:
            cpu->E = cpu->C;
            break;
        // MOV E, D
        // Copy value of register D to register E.
        // Page 3-36
        case 0x5A:
            cpu->E = cpu->D;
            break;
        // MOV E, E
        // Copy value of register E to register E.
        // Page 3-36
        case 0x5B:
            cpu->E = cpu->E;
            break;
        // MOV E, H
        // Copy value of register H to register E.
        // Page 3-36
        case 0x5C:
            cpu->E = cpu->H;
            break;
        // MOV E, L
        // Copy value of register L to register E.
        // Page 3-36
        case 0x5D:
            cpu->E = cpu->L;
            break;
        // MOV E, M
        // Copy value in memory location denoted by value of register pair M to register E.
        // Page 3-36
        case 0x5E:
            cpu->E = cpu->ram[cpu->M];
            break;
        // MOV E, A
        // Copy value in accumulator to register E.
        // Page 3-36
        case 0x5F:
            cpu->E = cpu->A;
            break;
        // MOV H, B
        // Copy value of register B to register H.
        // Page 3-36
        case 0x60:
            cpu->H = cpu->B;
            break;
        // MOV H, C
        // Copy value of register C to register H.
        // Page 3-36
        case 0x61:
            cpu->H = cpu->C;
            break;
        // MOV H, D
        // Copy value of register D to register H.
        // Page 3-36
        case 0x62:
            cpu->H = cpu->D;
            break;
        // MOV H, E
        // Copy value of register E to register H.
        // Page 3-36
        case 0x63:
            cpu->H = cpu->E;
            break;
        // MOV H, H
        // Copy value of register H to register H.
        // Page 3-36
        case 0x64:
            cpu->H = cpu->H;
            break;
        // MOV H, L
        // Copy value of register L to register H.
        // Page 3-36
        case 0x65:
            cpu->H = cpu->L;
            break;
        // MOV H, M
        // Copy value in memory location denoted by value of register pair M to register H.
        // Page 3-36
        case 0x66:
            cpu->H = cpu->ram[cpu->M];
            break;
        // MOV H, A
        // Copy value of accumulator to register H.
        // Page 3-36
        case 0x67:
            cpu->H = cpu->A;
            break;
        // MOV L, B
        // Copy value of register B to register L.
        // Page 3-36
        case 0x68:
            cpu->L = cpu->B;
            break;
        // MOV L, C
        // Copy value of register C to register L.
        // Page 3-36
        case 0x69:
            cpu->L = cpu->C;
            break;
        // MOV L, D
        // Copy value of register D to register L.
        // Page 3-36
        case 0x6A:
            cpu->L = cpu->D;
            break;
        // MOV L, E
        // Copy value of register E to register L.
        // Page 3-36
        case 0x6B:
            cpu->L = cpu->E;
            break;
        // MOV L, H
        // Copy value of register H to register L.
        // Page 3-36
        case 0x6C:
            cpu->L = cpu->H;
            break;
        // MOV L, L
        // Copy value of register L to register L.
        // Page 3-36
        case 0x6D:
            cpu->L = cpu->L;
            break;
        // MOV L, M
        // Copy value in memory location denoted by value of register pair M to register L.
        // Page 3-36
        case 0x6E:
            cpu->L = cpu->ram[cpu->M];
            break;
        // MOV L, A
        // Copy value of accumulator to register L.
        // Page 3-36
        case 0x6F:
            cpu->L = cpu->A;
            break;
        // MOV M, B
        // Copy value of register B to memory location denoted by value of register pair M.
        // Page 3-36
        case 0x70:
            cpu->ram[cpu->M] = cpu->B;
            break;
        // MOV M, C
        // Copy value of register C to memory location denoted by value of register pair M.
        // Page 3-36
        case 0x71:
            cpu->ram[cpu->M] = cpu->C;
            break;
        // MOV M, D
        // Copy value of register D to memory location denoted by value of register pair M.
        // Page 3-36
        case 0x72:
            cpu->ram[cpu->M] = cpu->D;
            break;
        // MOV M, E
        // Copy value of register E to memory location denoted by value of register pair M.
        // Page 3-36
        case 0x73:
            cpu->ram[cpu->M] = cpu->E;
            break;
        // MOV M, H
        // Copy value of register H to memory location denoted by value of register pair M.
        // Page 3-36
        case 0x74:
            cpu->ram[cpu->M] = cpu->H;
            break;
        // MOV M, L
        // Copy value of register L to memory location denoted by value of register pair M.
        // Page 3-36
        case 0x75:
            cpu->ram[cpu->M] = cpu->L;
            break;
        // MOV M, A
        // Copy value of accumulator to memory location denoted by value of register pair M.
        // Page 3-36
        case 0x77:
            cpu->ram[cpu->M] = cpu->A;
            break;
        // MOV A, B
        // Copy value of register B to accumulator.
        // Page 3-36
        case 0x78:
            cpu->A = cpu->B;
            break;
        // MOV A, C
        // Copy value of register C to accumulator.
        // Page 3-36
        case 0x79:
            cpu->A = cpu->C;
            break;
        // MOV A, D
        // Copy value of register D to accumulator.
        // Page 3-36
        case 0x7A:
            cpu->A = cpu->D;
            break;
        // MOV A, E
        // Copy value of register E to accumulator.
        // Page 3-36
        case 0x7B:
            cpu->A = cpu->E;
            break;
        // MOV A, H
        // Copy value of register H to accumulator.
        // Page 3-36
        case 0x7C:
            cpu->A = cpu->H;
            break;
        // MOV A, L
        // Copy value of register L to accumulator.
        // Page 3-36
        case 0x7D:
            cpu->A = cpu->L;
            break;
        // MOV A, M
        // Copy value in memory location denoted by value of register pair M to accumulator.
        // Page 3-36
        case 0x7E:
            cpu->A = cpu->ram[cpu->M];
            break;
        // MOV A, A
        // Copy value of accumulator to accumulator.
        // Page 3-36
        case 0x7F:
            cpu->A = cpu->A;
            break;
        // ADD B
        // Add value of register B to accumulator.
        // Page 3-4
        case 0x80: {
            uint16_t temp80 = (uint16_t)cpu->A + (uint16_t)cpu->B;
            cpu->A = temp80 & 0xFF;
            if (temp80 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADD C
        // Add value of register C to accumulator.
        // Page 3-4
        case 0x81: {
            uint16_t temp81 = (uint16_t)cpu->A + (uint16_t)cpu->C;
            cpu->A = temp81 & 0xFF;
            if (temp81 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADD D
        // Add value of register D to accumulator.
        // Page 3-4
        case 0x82: {
            uint16_t temp82 = (uint16_t)cpu->A + (uint16_t)cpu->D;
            cpu->A = temp82 & 0xFF;
            if (temp82 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADD E
        // Add value of register E to accumulator.
        // Page 3-4
        case 0x83: {
            uint16_t temp83 = (uint16_t)cpu->A + (uint16_t)cpu->E;
            cpu->A = temp83 & 0xFF;
            if (temp83 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADD H
        // Add value of register H to accumulator.
        // Page 3-4
        case 0x84: {
            uint16_t temp84 = (uint16_t)cpu->A + (uint16_t)cpu->H;
            cpu->A = temp84 & 0xFF;
            if (temp84 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADD L
        // Add value of register L to accumulator.
        // Page 3-4
        case 0x85: {
            uint16_t temp85 = (uint16_t)cpu->A + (uint16_t)cpu->L;
            cpu->A = temp85 & 0xFF;
            if (temp85 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADD M
        // Add value in RAM denoted by value of register pair M to accumulator.
        // Page 3-4
        case 0x86: {
            uint16_t temp86 = (uint16_t)cpu->A + (uint16_t)cpu->ram[cpu->M];
            cpu->A = temp86 & 0xFF;
            if (temp86 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADD A
        // Add value of accumulator to accumulator.
        // Page 3-4
        case 0x87: {
            uint16_t temp87 = (uint16_t)cpu->A + (uint16_t)cpu->A;
            cpu->A = temp87 & 0xFF;
            if (temp87 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADC B
        // Add value of register B and carry flag to accumulator.
        // Page 3-2
        case 0x88: {
            uint16_t temp88 = (uint16_t)cpu->A + (uint16_t)cpu->B + (uint16_t)cpu->flags.C;
            cpu->A = temp88 & 0xFF;
            if (temp88 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADC C
        // Add value of register C and carry flag to accumulator.
        // Page 3-2
        case 0x89: {
            uint16_t temp89 = (uint16_t)cpu->A + (uint16_t)cpu->C + (uint16_t)cpu->flags.C;
            cpu->A = temp89 & 0xFF;
            if (temp89 > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADC D
        // Add value of register D and carry flag to accumulator.
        // Page 3-2
        case 0x8A: {
            uint16_t temp8a = (uint16_t)cpu->A + (uint16_t)cpu->D + (uint16_t)cpu->flags.C;
            cpu->A = temp8a & 0xFF;
            if (temp8a > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADC E
        // Add value of register E and carry flag to accumulator.
        // Page 3-2
        case 0x8B: {
            uint16_t temp8b = (uint16_t)cpu->A + (uint16_t)cpu->E + (uint16_t)cpu->flags.C;
            cpu->A = temp8b & 0xFF;
            if (temp8b > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADC H
        // Add value of register H and carry flag to accumulator.
        // Page 3-2
        case 0x8C: {
            uint16_t temp8c = (uint16_t)cpu->A + (uint16_t)cpu->H + (uint16_t)cpu->flags.C;
            cpu->A = temp8c & 0xFF;
            if (temp8c > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADC L
        // Add value of register L and carry flag to accumulator.
        // Page 3-2
        case 0x8D: {
            uint16_t temp8d = (uint16_t)cpu->A + (uint16_t)cpu->L + (uint16_t)cpu->flags.C;
            cpu->A = temp8d & 0xFF;
            if (temp8d > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADC M
        // Add value in RAM denoted by value of register pair M and carry flag to accumulator.
        // Page 3-2
        case 0x8E: {
            uint16_t temp8e = (uint16_t)cpu->A + (uint16_t)cpu->ram[cpu->M] + (uint16_t)cpu->flags.C;
            cpu->A = temp8e & 0xFF;
            if (temp8e > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // ADC A
        // Add value of accumulator and carry flag to accumulator.
        // Page 3-2
        case 0x8F: {
            uint16_t temp8f = (uint16_t)cpu->A + (uint16_t)cpu->A + (uint16_t)cpu->flags.C;
            cpu->A = temp8f & 0xFF;
            if (temp8f > 0xFF) {
                cpu->flags.C = 1;
            }
            else {
                cpu->flags.C = 0;
            }
            break;
        }
        // SUB B
        // Subtract value of register B from accumulator to accumulator.
        // Page 3-63
        case 0x90:
            cpu->flags.C = cpu->B > cpu->A;
            cpu->A += ~cpu->B + 1;
            break;
        // SUB C
        // Subtract value of register C from accumulator to accumulator.
        // Page 3-63
        case 0x91:
            cpu->flags.C = cpu->C > cpu->A;
            cpu->A += ~cpu->C + 1;
            break;
        // SUB D
        // Subtract value of register D from accumulator to accumulator.
        // Page 3-63
        case 0x92:
            cpu->flags.C = cpu->D > cpu->A;
            cpu->A += ~cpu->D + 1;
            break;
        // SUB E
        // Subtract value of register E from accumulator to accumulator.
        // Page 3-63
        case 0x93:
            cpu->flags.C = cpu->E > cpu->A;
            cpu->A += ~cpu->E + 1;
            break;
        // SUB H
        // Subtract value of register H from accumulator to accumulator.
        // Page 3-63
        case 0x94:
            cpu->flags.C = cpu->H > cpu->A;
            cpu->A += ~cpu->H + 1;
            break;
        // SUB L
        // Subtract value of register L from accumulator to accumulator.
        // Page 3-63
        case 0x95:
            cpu->flags.C = cpu->L > cpu->A;
            cpu->A += ~cpu->L + 1;
            break;
        // SUB M
        // Subtract value in RAM denoted by value of register pair M from accumulator to accumulator.
        // Page 3-63
        case 0x96:
            cpu->flags.C = cpu->ram[cpu->M] > cpu->A;
            cpu->A += ~cpu->ram[cpu->M] + 1;
            break;
        // SUB A
        // Subtract value of accumulator from accumulator to accumulator.
        // Page 3-63
        case 0x97:
            cpu->flags.C = cpu->A > cpu->A;
            cpu->A += ~cpu->A + 1;
            break;
        // SBB B
        // Subtract value of register B with carry from accumulator to accumulator.
        // Page 3-56
        case 0x98:
            cpu->flags.C = (cpu->B + cpu->flags.C) > cpu->A;
            cpu->A += ~(cpu->B + cpu->flags.C) + 1;
            break;
        // SBB C
        // Subtract value of register C with carry from accumulator to accumulator.
        // Page 3-56
        case 0x99:
            cpu->flags.C = (cpu->C + cpu->flags.C) > cpu->A;
            cpu->A += ~(cpu->C + cpu->flags.C) + 1;
            break;
        // SBB D
        // Subtract value of register D with carry from accumulator to accumulator.
        // Page 3-56
        case 0x9A:
            cpu->flags.C = (cpu->D + cpu->flags.C) > cpu->A;
            cpu->A += ~(cpu->D + cpu->flags.C) + 1;
            break;
        // SBB E
        // Subtract value of register E with carry from accumulator to accumulator.
        // Page 3-56
        case 0x9B:
            cpu->flags.C = (cpu->E + cpu->flags.C) > cpu->A;
            cpu->A += ~(cpu->E + cpu->flags.C) + 1;
            break;
        // SBB H
        // Subtract value of register H with carry from accumulator to accumulator.
        // Page 3-56
        case 0x9C:
            cpu->flags.C = (cpu->H + cpu->flags.C) > cpu->A;
            cpu->A += ~(cpu->H + cpu->flags.C) + 1;
            break;
        // SBB L
        // Subtract value of register L with carry from accumulator to accumulator.
        // Page 3-56
        case 0x9D:
            cpu->flags.C = (cpu->L + cpu->flags.C) > cpu->A;
            cpu->A += ~(cpu->L + cpu->flags.C) + 1;
            break;
        // SBB M
        // Subtract value in RAM denoted by value of register pair M with carry from accumulator to accumulator.
        // Page 3-56
        case 0x9E:
            cpu->flags.C = (cpu->ram[cpu->M] + cpu->flags.C) > cpu->A;
            cpu->A += ~(cpu->ram[cpu->M] + cpu->flags.C) + 1;
            break;
        // SBB A
        // Subtract value of accumulator with carry from accumulator to accumulator.
        // Page 3-56
        case 0x9F:
            cpu->flags.C = (cpu->A + cpu->flags.C) > cpu->A;
            cpu->A += ~(cpu->A + cpu->flags.C) + 1;
            break;
        // ANA B
        // Store result of AND operation between value of accumulator and value of register B in accumulator.
        // Page 3-6
        case 0xA0:
            cpu->A &= cpu->B;
            break;
        // ANA C
        // Store result of AND operation between value of accumulator and value of register C in accumulator.
        // Page 3-6
        case 0xA1:
            cpu->A &= cpu->C;
            break;
        // ANA D
        // Store result of AND operation between value of accumulator and value of register D in accumulator.
        // Page 3-6
        case 0xA2:
            cpu->A &= cpu->D;
            break;
        // ANA E
        // Store result of AND operation between value of accumulator and value of register E in accumulator.
        // Page 3-6
        case 0xA3:
            cpu->A &= cpu->E;
            break;
        // ANA H
        // Store result of AND operation between value of accumulator and value of register H in accumulator.
        // Page 3-6
        case 0xA4:
            cpu->A &= cpu->H;
            break;
        // ANA L
        // Store result of AND operation between value of accumulator and value of register L in accumulator.
        // Page 3-6
        case 0xA5:
            cpu->A &= cpu->L;
            break;
        // ANA M
        // Store result of AND operation between value of accumulator and value in RAM denoted by value of register pair M in accumulator.
        // Page 3-6
        case 0xA6:
            cpu->A &= cpu->ram[cpu->M];
            break;
        // ANA A
        // Store result of AND operation between value of accumulator and value of accumulator in accumulator.
        // Page 3-6
        case 0xA7:
            cpu->A &= cpu->A;
            break;
        // XRA B
        // Store result of XOR operation between value of accumulator and value of register B in accumulator.
        // Page 3-66
        case 0xA8:
            cpu->A ^= cpu->B;
            break;
        // XRA C
        // Store result of XOR operation between value of accumulator and value of register C in accumulator.
        // Page 3-66
        case 0xA9:
            cpu->A ^= cpu->C;
            break;
        // XRA D
        // Store result of XOR operation between value of accumulator and value of register D in accumulator.
        // Page 3-66
        case 0xAA:
            cpu->A ^= cpu->D;
            break;
        // XRA E
        // Store result of XOR operation between value of accumulator and value of register E in accumulator.
        // Page 3-66
        case 0xAB:
            cpu->A ^= cpu->E;
            break;
        // XRA H
        // Store result of XOR operation between value of accumulator and value of register H in accumulator.
        // Page 3-66
        case 0xAC:
            cpu->A ^= cpu->H;
            break;
        // XRA L
        // Store result of XOR operation between value of accumulator and value of register L in accumulator.
        // Page 3-66
        case 0xAD:
            cpu->A ^= cpu->L;
            break;
        // XRA M
        // Store result of XOR operation between value of accumulator and value in RAM denoted by value of register pair M in accumulator.
        // Page 3-66
        case 0xAE:
            cpu->A ^= cpu->ram[cpu->M];
            break;
        // XRA A
        // Store result of XOR operation between value of accumulator and value of accumulator in accumulator.
        // Page 3-66
        case 0xAF:
            cpu->A ^= cpu->A;
            break;
        // ORA B
        // Store result of OR operation between value of accumulator and value of register B in accumulator.
        // Page 3-38
        case 0xB0:
            cpu->A |= cpu->B;
            break;
        // ORA C
        // Store result of OR operation between value of accumulator and value of register C in accumulator.
        // Page 3-38
        case 0xB1:
            cpu->A |= cpu->C;
            break;
        // ORA D
        // Store result of OR operation between value of accumulator and value of register D in accumulator.
        // Page 3-38
        case 0xB2:
            cpu->A |= cpu->D;
            break;
        // ORA E
        // Store result of OR operation between value of accumulator and value of register E in accumulator.
        // Page 3-38
        case 0xB3:
            cpu->A |= cpu->E;
            break;
        // ORA H
        // Store result of OR operation between value of accumulator and value of register H in accumulator.
        // Page 3-38
        case 0xB4:
            cpu->A |= cpu->H;
            break;
        // ORA L
        // Store result of OR operation between value of accumulator and value of register L in accumulator.
        // Page 3-38
        case 0xB5:
            cpu->A |= cpu->L;
            break;
        // ORA M
        // Store result of OR operation between value of accumulator and value in RAM denoted by value of register pair M in accumulator.
        // Page 3-38
        case 0xB6:
            cpu->A |= cpu->ram[cpu->M];
            break;
        // ORA A
        // Store result of OR operation between value of accumulator and value of accumulator in accumulator.
        // Page 3-38
        case 0xB7:
            cpu->A |= cpu->A;
            break;
        // POP B
        // Pop two bytes of data from stack and copy to register pair BC.
        // Page 3-42
        case 0xC1:
            cpu->B = cpu->ram[cpu->sp+1];
            cpu->C = cpu->ram[cpu->sp];
            cpu->sp += 2;
            break;
        // JNZ adr
        // Jumps to address of next two bytes.
        // Page 3-29
        case 0xC2:
            if (cpu->flags.C == 0) {
                // read next two bytes and set into PC
            }
            break;
        // PUSH B
        // Push value of register pair BC to next two bytes of stack.
        // Page 3-44
        case 0xC5:
            cpu->ram[cpu->sp-2] = cpu->C;
            cpu->ram[cpu->sp-1] = cpu->B;
            cpu->sp -= 2;
            break;
        // POP D
        // Pop two bytes of data from stack and copy to register pair DE.
        // Page 3-42
        case 0xD1:
            cpu->D = cpu->ram[cpu->sp+1];
            cpu->E = cpu->ram[cpu->sp];
            cpu->sp += 2;
            break;
        // PUSH D
        // Push value of register pair DE to next two bytes of stack.
        // Page 3-44
        case 0xD5:
            cpu->ram[cpu->sp-2] = cpu->E;
            cpu->ram[cpu->sp-1] = cpu->D;
            cpu->sp -= 2;
            break;
        // POP H
        // Pop two bytes of data from stack and copy to register pair HL.
        // Page 3-42
        case 0xE1:
            cpu->H = cpu->ram[cpu->sp+1];
            cpu->L = cpu->ram[cpu->sp];
            cpu->sp += 2;
            break;
        // XTHL
        // Exchange value of register H with value of the stack pointer, and value of register L with value of stack pointer plus one.
        // Page 3-69
        case 0xE3: {
            uint8_t e3temp1 = cpu->H;
            uint8_t e3temp2 = cpu->L;
            cpu->H = cpu->sp+1;
            cpu->L = cpu->sp;
            cpu->ram[cpu->sp] = e3temp2;
            cpu->ram[cpu->sp+1] = e3temp1;
            break;
        }
        // PUSH H
        // Push value of register pair HL to next two bytes of stack.
        // Page 3-44
        case 0xE5:
            cpu->ram[cpu->sp-2] = cpu->L;
            cpu->ram[cpu->sp-1] = cpu->H;
            cpu->sp -= 2;
            break;
        // ANI D8
        // Store result of AND operation between value of accumulator and next byte in accumulator, then unset carry and auxiliary carry flags.
        // Page 3-7
        case 0xE6:
            cpu->A &= cpu->ram[cpu->pc+1];
            cpu->flags.C = 0;
            cpu->flags.AC = 0;
            break;
        // XCHG
        // Exchange value of register H with value of register D, and value of register L with value of register E.
        // Page 3-65
        case 0xEB: {
            uint8_t ebtemp1 = cpu->H;
            uint8_t ebtemp2 = cpu->L;
            cpu->H = cpu->D;
            cpu->L = cpu->E;
            cpu->D = ebtemp1;
            cpu->E = ebtemp2;
            break;
        }
        // XRI D8
        // Store result of XOR operation between value of accumulator and next byte in accumulator, then unset carry and auxiliary carry flags.
        // Page 3-67
        case 0xEE:
            cpu->A ^= cpu->ram[cpu->pc+1];
            cpu->flags.C = 0;
            cpu->flags.AC = 0;
            break;
        // POP PSW
        // Pop two bytes of data from stack to flags and accumulator.
        // Page 3-42
        case 0xF1:
            cpu->PSW = cpu->ram[cpu->sp];
            cpu->A = cpu->ram[cpu->sp+1];
            cpu->sp += 2;
            break;
        // PUSH PSW
        // Push value of flags and accumulator to next two bytes of stack.
        // Page 3-44 
        case 0xF5:
            cpu->ram[cpu->sp-2] = cpu->PSW;
            cpu->ram[cpu->sp-1] = cpu->A;
            cpu->sp -= 2;
            break;
        // ORI D8
        // Store result of OR operation between value of accumulator and next byte in accumulator, then unset carry and auxiliary carry flags.
        // Page 3-40
        case 0xF6:
            cpu->A |= cpu->ram[cpu->pc+1];
            cpu->flags.C = 0;
            cpu->flags.AC = 0;
            break;
        // SPHL
        // Copy value of register pair HL to stack pointer.
        // Page 3-61
        case 0xF9:
            cpu->sp = cpu->HL;
            break;
        default:
            break;
    }
}
