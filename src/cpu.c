#include <stdio.h>
#include <string.h>

#include "cpu.h"

void initialiseCPU(struct cpu *cpu) {
    fprintf(stdout, "Initialising CPU...\n");
    memset(cpu, 0, sizeof(struct cpu));
}

struct instruction decodeInstruction(uint16_t opcode) {
    struct instruction insn;
    switch (opcode) {
        case 0x00:
            insn.opcode = OP_NOP;
            break;
        case 0x01:
            break;
        case 0x02:
            break;
        case 0x03:
            insn.opcode = OP_IncrementBC;
            break;
        case 0x04:
            insn.opcode = OP_IncrementB;
            break;
        case 0x05:
            insn.opcode = OP_IncrementC;
            break;
        case 0x06:
            break;
        case 0x07:
            break;
        case 0x08:
            insn.opcode = OP_Pad1;
            break;
        case 0x09:
            insn.opcode = OP_AddBCToHL;
            break;
        case 0x0A:
            break;
        case 0x0B:
            insn.opcode = OP_DecrementBC;
            break;
        case 0x0C:
            insn.opcode = OP_IncrementC;
            break;
        case 0x0D:
            insn.opcode = OP_DecrementC;
            break;
        case 0x0E:
            break;
        case 0x0F:
            break;
        case 0x10:
            insn.opcode = OP_Pad2;
            break;
        case 0x11:
            break;
        case 0x12:
            break;
        case 0x13:
            insn.opcode = OP_IncrementDE;
            break;
        case 0x14:
            insn.opcode = OP_IncrementD;
            break;
        case 0x15:
            insn.opcode = OP_DecrementD;
            break;
        case 0x16:
            break;
        case 0x17:
            break;
        case 0x18:
            insn.opcode = OP_Pad3;
            break;
        case 0x19:
            insn.opcode = OP_AddDEToHL;
            break;
        case 0x1A:
            break;
        case 0x1B:
            insn.opcode = OP_DecrementDE;
            break;
        case 0x1C:
            insn.opcode = OP_IncrementE;
            break;
        case 0x1D:
            insn.opcode = OP_DecrementE;
            break;
        case 0x1E:
            break;
        case 0x1F:
            break;
        case 0x20:
            insn.opcode = OP_Pad4;
            break;
        case 0x21:
            break;
        case 0x22:
            break;
        case 0x23:
            insn.opcode = OP_IncrementHL;
            break;
        case 0x24:
            insn.opcode = OP_IncrementH;
            break;
        case 0x25:
            insn.opcode = OP_DecrementH;
            break;
        case 0x26:
            break;
        case 0x27:
            break;
        case 0x28:
            insn.opcode = OP_Pad5;
            break;
        case 0x29:
            insn.opcode = OP_AddHIToHL;
            break;
        case 0x2A:
            break;
        case 0x2B:
            insn.opcode = OP_DecrementHL;
            break;
        case 0x2C:
            insn.opcode = OP_IncrementL;
            break;
        case 0x2D:
            insn.opcode = OP_DecrementL;
            break;
        case 0x2E:
            break;
        case 0x2F:
            break;
        case 0x30:
            insn.opcode = OP_Pad6;
            break;
        case 0x31:
            break;
        case 0x32:
            break;
        case 0x33:
            insn.opcode = OP_IncrementSP;
            break;
        case 0x34:
            insn.opcode = OP_IncrementM;
            break;
        case 0x35:
            insn.opcode = OP_DecrementM;
            break;
        case 0x36:
            break;
        case 0x37:
            break;
        case 0x38:
            insn.opcode = OP_Pad7;
            break;
        case 0x39:
            insn.opcode = OP_AddSPToHL;
            break;
        case 0x3A:
            break;
        case 0x3B:
            insn.opcode = OP_DecrementSP;
            break;
        case 0x3C:
            insn.opcode = OP_IncrementA;
            break;
        case 0x3D:
            insn.opcode = OP_DecrementA;
            break;
        case 0x3E:
            break;
        case 0x3F:
            break;
        case 0x40:
            insn.opcode = OP_CopyBToB;
            break;
        case 0x41:
            insn.opcode = OP_CopyCToB;
            break;
        case 0x42:
            insn.opcode = OP_CopyDToB;
            break;
        case 0x43:
            insn.opcode = OP_CopyEToB;
            break;
        case 0x44:
            insn.opcode = OP_CopyHToB;
            break;
        case 0x45:
            insn.opcode = OP_CopyLToB;
            break;
        case 0x46:
            insn.opcode = OP_CopyMToB;
            break;
        case 0x47:
            insn.opcode = OP_CopyAToB;
            break;
        case 0x48:
            insn.opcode = OP_CopyBToC;
            break;
        case 0x49:
            insn.opcode = OP_CopyCToC;
            break;
        case 0x4A:
            insn.opcode = OP_CopyDToC;
            break;
        case 0x4B:
            insn.opcode = OP_CopyEToC;
            break;
        case 0x4C:
            insn.opcode = OP_CopyHToC;
            break;
        case 0x4D:
            insn.opcode = OP_CopyLToC;
            break;
        case 0x4E:
            insn.opcode = OP_CopyMToC;
            break;
        case 0x4F:
            insn.opcode = OP_CopyAToC;
            break;
        case 0x50:
            insn.opcode = OP_CopyBToD;
            break;
        case 0x51:
            insn.opcode = OP_CopyCToD;
            break;
        case 0x52:
            insn.opcode = OP_CopyDToD;
            break;
        case 0x53:
            insn.opcode = OP_CopyEToD;
            break;
        case 0x54:
            insn.opcode = OP_CopyHToD;
            break;
        case 0x55:
            insn.opcode = OP_CopyLToD;
            break;
        case 0x56:
            insn.opcode = OP_CopyMToD;
            break;
        case 0x57:
            insn.opcode = OP_CopyAToD;
            break;
        case 0x58:
            insn.opcode = OP_CopyBToE;
            break;
        case 0x59:
            insn.opcode = OP_CopyCToE;
            break;
        case 0x5A:
            insn.opcode = OP_CopyDToE;
            break;
        case 0x5B:
            insn.opcode = OP_CopyEToE;
            break;
        case 0x5C:
            insn.opcode = OP_CopyHToE;
            break;
        case 0x5D:
            insn.opcode = OP_CopyLToE;
            break;
        case 0x5E:
            insn.opcode = OP_CopyMToE;
            break;
        case 0x5F:
            insn.opcode = OP_CopyAToE;
            break;
        case 0x60:
            insn.opcode = OP_CopyBToH;
            break;
        case 0x61:
            insn.opcode = OP_CopyCToH;
            break;
        case 0x62:
            insn.opcode = OP_CopyDToH;
            break;
        case 0x63:
            insn.opcode = OP_CopyEToH;
            break;
        case 0x64:
            insn.opcode = OP_CopyHToH;
            break;
        case 0x65:
            insn.opcode = OP_CopyLToH;
            break;
        case 0x66:
            insn.opcode = OP_CopyMToH;
            break;
        case 0x67:
            insn.opcode = OP_CopyAToH;
            break;
        case 0x68:
            insn.opcode = OP_CopyBToL;
            break;
        case 0x69:
            insn.opcode = OP_CopyCToL;
            break;
        case 0x6A:
            insn.opcode = OP_CopyDToL;
            break;
        case 0x6B:
            insn.opcode = OP_CopyEToL;
            break;
        case 0x6C:
            insn.opcode = OP_CopyHToL;
            break;
        case 0x6D:
            insn.opcode = OP_CopyLToL;
            break;
        case 0x6E:
            insn.opcode = OP_CopyMToL;
            break;
        case 0x6F:
            insn.opcode = OP_CopyAToL;
            break;
        case 0x70:
            insn.opcode = OP_CopyBToM;
            break;
        case 0x71:
            insn.opcode = OP_CopyCToM;
            break;
        case 0x72:
            insn.opcode = OP_CopyDToM;
            break;
        case 0x73:
            insn.opcode = OP_CopyEToM;
            break;
        case 0x74:
            insn.opcode = OP_CopyHToM;
            break;
        case 0x75:
            insn.opcode = OP_CopyLToM;
            break;
        case 0x76:
            insn.opcode = OP_Halt;
            break;
        case 0x77:
            insn.opcode = OP_CopyAToM;
            break;
        case 0x78:
            insn.opcode = OP_CopyBToA;
            break;
        case 0x79:
            insn.opcode = OP_CopyCToA;
            break;
        case 0x7A:
            insn.opcode = OP_CopyDToA;
            break;
        case 0x7B:
            insn.opcode = OP_CopyEToA;
            break;
        case 0x7C:
            insn.opcode = OP_CopyHToA;
            break;
        case 0x7D:
            insn.opcode = OP_CopyLToA;
            break;
        case 0x7E:
            insn.opcode = OP_CopyMToA;
            break;
        case 0x7F:
            insn.opcode = OP_CopyAToA;
            break;
        case 0x80:
            insn.opcode = OP_AddB;
            break;
        case 0x81:
            insn.opcode = OP_AddC;
            break;
        case 0x82:
            insn.opcode = OP_AddD;
            break;
        case 0x83:
            insn.opcode = OP_AddE;
            break;
        case 0x84:
            insn.opcode = OP_AddH;
            break;
        case 0x85:
            insn.opcode = OP_AddL;
            break;
        case 0x86:
            insn.opcode = OP_AddM;
            break;
        case 0x87:
            insn.opcode = OP_AddA;
            break;
        case 0x88:
            insn.opcode = OP_AdcB;
            break;
        case 0x89:
            insn.opcode = OP_AdcC;
            break;
        case 0x8A:
            insn.opcode = OP_AdcD;
            break;
        case 0x8B:
            insn.opcode = OP_AdcE;
            break;
        case 0x8C:
            insn.opcode = OP_AdcH;
            break;
        case 0x8D:
            insn.opcode = OP_AdcL;
            break;
        case 0x8E:
            insn.opcode = OP_AdcM;
            break;
        case 0x8F:
            insn.opcode = OP_AdcA;
            break;
        case 0x90:
            insn.opcode = OP_SubB;
            break;
        case 0x91:
            insn.opcode = OP_SubC;
            break;
        case 0x92:
            insn.opcode = OP_SubD;
            break;
        case 0x93:
            insn.opcode = OP_SubE;
            break;
        case 0x94:
            insn.opcode = OP_SubH;
            break;
        case 0x95:
            insn.opcode = OP_SubL;
            break;
        case 0x96:
            insn.opcode = OP_SubM;
            break;
        case 0x97:
            insn.opcode = OP_SubA;
            break;
        case 0x98:
            insn.opcode = OP_SbbB;
            break;
        case 0x99:
            insn.opcode = OP_SbbC;
            break;
        case 0x9A:
            insn.opcode = OP_SbbD;
            break;
        case 0x9B:
            insn.opcode = OP_SbbE;
            break;
        case 0x9C:
            insn.opcode = OP_SbbH;
            break;
        case 0x9D:
            insn.opcode = OP_SbbL;
            break;
        case 0x9E:
            insn.opcode = OP_SbbM;
            break;
        case 0x9F:
            insn.opcode = OP_SbbA;
            break;
        case 0xA0:
            insn.opcode = OP_AAndB;
            break;
        case 0xA1:
            insn.opcode = OP_AAndC;
            break;
        case 0xA2:
            insn.opcode = OP_AAndD;
            break;
        case 0xA3:
            insn.opcode = OP_AAndE;
            break;
        case 0xA4:
            insn.opcode = OP_AAndH;
            break;
        case 0xA5:
            insn.opcode = OP_AAndL;
            break;
        case 0xA6:
            insn.opcode = OP_AAndM;
            break;
        case 0xA7:
            insn.opcode = OP_AAndA;
            break;
        case 0xA8:
            insn.opcode = OP_AXorB;
            break;
        case 0xA9:
            insn.opcode = OP_AXorC;
            break;
        case 0xAA:
            insn.opcode = OP_AXorD;
            break;
        case 0xAB:
            insn.opcode = OP_AXorE;
            break;
        case 0xAC:
            insn.opcode = OP_AXorH;
            break;
        case 0xAD:
            insn.opcode = OP_AXorL;
            break;
        case 0xAE:
            insn.opcode = OP_AXorM;
            break;
        case 0xAF:
            insn.opcode = OP_AXorA;
            break;
        case 0xB0:
            insn.opcode = OP_AOrB;
            break;
        case 0xB1:
            insn.opcode = OP_AOrC;
            break;
        case 0xB2:
            insn.opcode = OP_AOrD;
            break;
        case 0xB3:
            insn.opcode = OP_AOrE;
            break;
        case 0xB4:
            insn.opcode = OP_AOrH;
            break;
        case 0xB5:
            insn.opcode = OP_AOrL;
            break;
        case 0xB6:
            insn.opcode = OP_AOrM;
            break;
        case 0xB7:
            insn.opcode = OP_AOrA;
            break;
        case 0xB8:
            insn.opcode = OP_ACompareB;
            break;
        case 0xB9:
            insn.opcode = OP_ACompareC;
            break;
        case 0xBA:
            insn.opcode = OP_ACompareD;
            break;
        case 0xBB:
            insn.opcode = OP_ACompareE;
            break;
        case 0xBC:
            insn.opcode = OP_ACompareH;
            break;
        case 0xBD:
            insn.opcode = OP_ACompareL;
            break;
        case 0xBE:
            insn.opcode = OP_ACompareM;
            break;
        case 0xBF:
            insn.opcode = OP_ACompareA;
            break;
        case 0xC0:
            break;
        case 0xC1:
            break;
        case 0xC2:
            insn.opcode = OP_JumpIfNotZero;
            break;
        case 0xC3:
            insn.opcode = OP_Jump;
            break;
        case 0xC4:
            insn.opcode = OP_CallIfNotZero;
            break;
        case 0xC5:
            break;
        case 0xC6:
            break;
        case 0xC7:
            break;
        case 0xC8:
            insn.opcode = OP_ReturnIfZero;
            break;
        case 0xC9:
            insn.opcode = OP_Return;
            break;
        case 0xCA:
            insn.opcode = OP_JumpIfZero;
            break;
        case 0xCB:
            insn.opcode = OP_Pad8;
            break;
        case 0xCC:
            insn.opcode = OP_CallIfZero;
            break;
        case 0xCD:
            insn.opcode = OP_Call;
            break;
        case 0xCE:
            break;
        case 0xCF:
            break;
        case 0xD0:
            break;
        case 0xD1:
            break;
        case 0xD2:
            break;
        case 0xD3:
            break;
        case 0xD4:
            break;
        case 0xD5:
            break;
        case 0xD6:
            break;
        case 0xD7:
            break;
        case 0xD8:
            break;
        case 0xD9:
            insn.opcode = OP_Pad9;
            break;
        case 0xDA:
            break;
        case 0xDB:
            break;
        case 0xDC:
            break;
        case 0xDD:
            insn.opcode = OP_Pad10;
            break;
        case 0xDE:
            break;
        case 0xDF:
            break;
        case 0xE0:
            break;
        case 0xE1:
            break;
        case 0xE2:
            break;
        case 0xE3:
            break;
        case 0xE4:
            break;
        case 0xE5:
            break;
        case 0xE6:
            break;
        case 0xE7:
            break;
        case 0xE8:
            break;
        case 0xE9:
            break;
        case 0xEA:
            break;
        case 0xEB:
            break;
        case 0xEC:
            break;
        case 0xED:
            insn.opcode = OP_Pad11;
            break;
        case 0xEE:
            break;
        case 0xEF:
            break;
        case 0xF0:
            break;
        case 0xF1:
            break;
        case 0xF2:
            break;
        case 0xF3:
            break;
        case 0xF4:
            break;
        case 0xF5:
            break;
        case 0xF6:
            break;
        case 0xF7:
            break;
        case 0xF8:
            break;
        case 0xF9:
            insn.opcode = OP_SetSPToHL;
            break;
        case 0xFA:
            break;
        case 0xFB:
            break;
        case 0xFC:
            break;
        case 0xFD:
            insn.opcode = OP_Pad12;
            break;
        case 0xFE:
            break;
        case 0xFF:
            break;
    }
    return insn;
}

void executeInstruction(struct instruction insn, struct cpu* cpu) {
    switch (insn.opcode) {
        case OP_NOP: // 0x00
            break;
        case OP_StoreNextTwoBytesInBC: // 0x01
            cpu->B = cpu->ram[cpu->pc+2];
            cpu->C = cpu->ram[cpu->pc+1];
            break;
        case OP_StoreAInMemoryLocationBC: // 0x02
            cpu->ram[cpu->BC] = cpu->A;
            break;
        case OP_IncrementBC: // 0x03
            cpu->BC += 1;
            break;
        case OP_IncrementB: // 0x04
            cpu->B += 1;
            break;
        case OP_DecrementB: // 0x05
            cpu->B -= 1;
            break;
        case OP_StoreNextByteInB: // 0x06
            cpu->B = cpu->ram[cpu->pc+1];
            break;
        case OP_Pad1: // 0x08
            break;
        case OP_AddBCToHL: // 0x09
            cpu->HL += cpu->BC;
            break;
        case OP_LoadMemoryLocationBCIntoA: // 0x0A
            cpu->A = cpu->ram[cpu->BC];
            break;
        case OP_DecrementBC: // 0x0B
            cpu->BC -= 1;
            break;
        case OP_IncrementC: // 0x0C
            cpu->C += 1;
            break;
        case OP_DecrementC: // 0x0D
            cpu->C -= 1;
            break;
        case OP_StoreNextByteInC: // 0x0E
            cpu->C = cpu->ram[cpu->pc+1];
            break;
        case OP_Pad2: // 0x10
            break;
        case OP_StoreNextTwoBytesInDE: // 0x11
            cpu->D = cpu->ram[cpu->pc+2];
            cpu->E = cpu->ram[cpu->pc+1];
            break;
        case OP_StoreAInMemoryLocationDE: // 0x12
            cpu->ram[cpu->DE] = cpu->A;
            break;
        case OP_IncrementDE: // 0x13
            cpu->DE += 1;
            break;
        case OP_IncrementD: // 0x14
            cpu->D += 1;
            break;
        case OP_DecrementD: // 0x15
            cpu->D -= 1;
            break;
        case OP_StoreNextByteInD: // 0x16
            cpu->D = cpu->ram[cpu->pc+1];
            break;
        case OP_Pad3: // 0x18
            break;
        case OP_AddDEToHL: // 0x19
            cpu->HL += cpu->DE;
            break;
        case OP_LoadMemoryLocationDEIntoA: // 0x1A
            cpu->A = cpu->ram[cpu->DE];
            break;
        case OP_DecrementDE: // 0x1B
            cpu->DE -= 1;
            break;
        case OP_IncrementE: // 0x1C
            cpu->E += 1;
            break;
        case OP_DecrementE: // 0x1D
            cpu->E -= 1;
            break;
        case OP_StoreNextByteInE: // 0x1E
            cpu->E = cpu->ram[cpu->pc+1];
            break;
        case OP_Pad4: // 0x20
            break;
        case OP_StoreNextTwoBytesInHL: // 0x21
            cpu->H = cpu->ram[cpu->pc+2];
            cpu->L = cpu->ram[cpu->pc+1];
            break;
        case OP_IncrementHL: // 0x23
            cpu->HL += 1;
            break;
        case OP_IncrementH: // 0x24
            cpu->H += 1;
            break;
        case OP_DecrementH: // 0x25
            cpu->H -= 1;
            break;
        case OP_StoreNextByteInH: // 0x26
            cpu->H = cpu->ram[cpu->pc+1];
            break;
        case OP_Pad5: // 0x28
            break;
        case OP_DecrementHL: // 0x2B
            cpu->HL -= 1;
            break;
        case OP_IncrementL: // 0x2C
            cpu->L += 1;
            break;
        case OP_DecrementL: // 0x2D
            cpu->L -= 1;
            break;
        case OP_StoreNextByteInL: // 0x2E
            cpu->L = cpu->ram[cpu->pc+1];
            break;
        case OP_Pad6: // 0x30
            break;
        case OP_IncrementSP: // 0x33
            cpu->sp += 1;
            break;
        case OP_StoreNextByteInM: // 0x36
            cpu->ram[cpu->M] = cpu->ram[cpu->pc+1];
            break;
        case OP_SetCarry: // 0x37
            cpu->flags.C = 1;
            break;
        case OP_Pad7: // 0x38
            break;
        case OP_AddSPToHL: // 0x39
            cpu->HL += cpu->sp;
            break;
        case OP_DecrementSP: // 0x3B
            cpu->sp -= 1;
            break;
        case OP_IncrementA: // 0x3C
            cpu->A += 1;
            break;
        case OP_DecrementA: // 0x3D
            cpu->A -= 1;
            break;
        case OP_StoreNextByteInA: // 0x3E
            cpu->A = cpu->ram[cpu->pc+1];
            break;
        case OP_CopyBToB: // 0x40
            cpu->B = cpu->B;
            break;
        case OP_CopyCToB: // 0x41
            cpu->B = cpu->C;
            break;
        case OP_CopyDToB: // 0x42
            cpu->B = cpu->D;
            break;
        case OP_CopyEToB: // 0x43
            cpu->B = cpu->E;
            break;
        case OP_CopyHToB: // 0x44
            cpu->B = cpu->H;
            break;
        case OP_CopyLToB: // 0x45
            cpu->B = cpu->L;
            break;
        case OP_CopyMToB: // 0x46
            cpu->B = cpu->ram[cpu->M];
            break;
        case OP_CopyAToB: // 0x47
            cpu->B = cpu->A;
            break;
        case OP_CopyBToC: // 0x48
            cpu->C = cpu->B;
            break;
        case OP_CopyCToC: // 0x49
            cpu->C = cpu->C;
            break;
        case OP_CopyDToC: // 0x4A
            cpu->C = cpu->D;
            break;
        case OP_CopyEToC: // 0x4B
            cpu->C = cpu->E;
            break;
        case OP_CopyHToC: // 0x4C
            cpu->C = cpu->H;
            break;
        case OP_CopyLToC: // 0x4D
            cpu->C = cpu->L;
            break;
        case OP_CopyMToC: // 0x4E
            cpu->C = cpu->ram[cpu->M];
            break;
        case OP_CopyAToC: // 0x4F
            cpu->C = cpu->A;
            break;
        case OP_CopyBToD: // 0x50
            cpu->D = cpu->B;
            break;
        case OP_CopyCToD: // 0x51
            cpu->D = cpu->C;
            break;
        case OP_CopyDToD: // 0x52
            cpu->D = cpu->D;
            break;
        case OP_CopyEToD: // 0x53
            cpu->D = cpu->E;
            break;
        case OP_CopyHToD: // 0x54
            cpu->D = cpu->H;
            break;
        case OP_CopyLToD: // 0x55
            cpu->D = cpu->L;
            break;
        case OP_CopyMToD: // 0x56
            cpu->D = cpu->ram[cpu->M];
            break;
        case OP_CopyAToD: // 0x57
            cpu->D = cpu->A;
            break;
        case OP_CopyBToE: // 0x58
            cpu->E = cpu->B;
            break;
        case OP_CopyCToE: // 0x59
            cpu->E = cpu->C;
            break;
        case OP_CopyDToE: // 0x5A
            cpu->E = cpu->D;
            break;
        case OP_CopyEToE: // 0x5B
            cpu->E = cpu->E;
            break;
        case OP_CopyHToE: // 0x5C
            cpu->E = cpu->H;
            break;
        case OP_CopyLToE: // 0x5D
            cpu->E = cpu->L;
            break;
        case OP_CopyMToE: // 0x5E
            cpu->E = cpu->ram[cpu->M];
            break;
        case OP_CopyAToE: // 0x5F
            cpu->E = cpu->A;
            break;
        case OP_CopyBToH: // 0x60
            cpu->H = cpu->B;
            break;
        case OP_CopyCToH: // 0x61
            cpu->H = cpu->C;
            break;
        case OP_CopyDToH: // 0x62
            cpu->H = cpu->D;
            break;
        case OP_CopyEToH: // 0x63
            cpu->H = cpu->E;
            break;
        case OP_CopyHToH: // 0x64
            cpu->H = cpu->H;
            break;
        case OP_CopyLToH: // 0x65
            cpu->H = cpu->L;
            break;
        case OP_CopyMToH: // 0x66
            cpu->H = cpu->ram[cpu->M];
            break;
        case OP_CopyAToH: // 0x67
            cpu->H = cpu->A;
            break;
        case OP_CopyBToL: // 0x68
            cpu->L = cpu->B;
            break;
        case OP_CopyCToL: // 0x69
            cpu->L = cpu->C;
            break;
        case OP_CopyDToL: // 0x6A
            cpu->L = cpu->D;
            break;
        case OP_CopyEToL: // 0x6B
            cpu->L = cpu->E;
            break;
        case OP_CopyHToL: // 0x6C
            cpu->L = cpu->H;
            break;
        case OP_CopyLToL: // 0x6D
            cpu->L = cpu->L;
            break;
        case OP_CopyMToL: // 0x6E
            cpu->L = cpu->ram[cpu->M];
            break;
        case OP_CopyAToL: // 0x6F
            cpu->L = cpu->A;
            break;
        case OP_CopyBToM: // 0x70
            cpu->ram[cpu->M] = cpu->B;
            break;
        case OP_CopyCToM: // 0x71
            cpu->ram[cpu->M] = cpu->C;
            break;
        case OP_CopyDToM: // 0x72
            cpu->ram[cpu->M] = cpu->D;
            break;
        case OP_CopyEToM: // 0x73
            cpu->ram[cpu->M] = cpu->E;
            break;
        case OP_CopyHToM: // 0x74
            cpu->ram[cpu->M] = cpu->H;
            break;
        case OP_CopyLToM: // 0x75
            cpu->ram[cpu->M] = cpu->L;
            break;
        case OP_CopyAToM: // 0x77
            cpu->ram[cpu->M] = cpu->A;
            break;
        case OP_CopyBToA: // 0x78
            cpu->A = cpu->B;
            break;
        case OP_CopyCToA: // 0x79
            cpu->A = cpu->C;
            break;
        case OP_CopyDToA: // 0x7A
            cpu->A = cpu->D;
            break;
        case OP_CopyEToA: // 0x7B
            cpu->A = cpu->E;
            break;
        case OP_CopyHToA: // 0x7C
            cpu->A = cpu->H;
            break;
        case OP_CopyLToA: // 0x7D
            cpu->A = cpu->L;
            break;
        case OP_CopyMToA: // 0x7E
            cpu->A = cpu->ram[cpu->M];
            break;
        case OP_CopyAToA: // 0x7F
            cpu->A = cpu->A;
            break;
        case OP_AddB: // 0x80
            cpu->A += cpu->B;
            break;
        case OP_AddC: // 0x81
            cpu->A += cpu->C;
            break;
        case OP_AddD: // 0x82
            cpu->A += cpu->D;
            break;
        case OP_AddE: // 0x83
            cpu->A += cpu->E;
            break;
        case OP_AddH: // 0x84
            cpu->A += cpu->H;
            break;
        case OP_AddL: // 0x85
            cpu->A += cpu->L;
            break;
        case OP_AddM: // 0x86
            cpu->A += cpu->ram[cpu->M];
            break;
        case OP_AddA: // 0x87
            cpu->A += cpu->A;
            break;
        case OP_SubB: // 0x90
            cpu->A -= cpu->B;
            break;
        case OP_SubC: // 0x91
            cpu->A -= cpu->C;
            break;
        case OP_SubD: // 0x92
            cpu->A -= cpu->D;
            break;
        case OP_SubE: // 0x93
            cpu->A -= cpu->E;
            break;
        case OP_SubH: // 0x94
            cpu->A -= cpu->H;
            break;
        case OP_SubL: // 0x95
            cpu->A -= cpu->L;
            break;
        case OP_SubM: // 0x96
            cpu->A -= cpu->ram[cpu->M];
            break;
        case OP_SubA: // 0x97
            cpu->A -= cpu->A;
            break;
        case OP_AAndB: // 0xA0
            cpu->A &= cpu->B;
            break;
        case OP_AAndC: // 0xA1
            cpu->A &= cpu->C;
            break;
        case OP_AAndD: // 0xA2
            cpu->A &= cpu->D;
            break;
        case OP_AAndE: // 0xA3
            cpu->A &= cpu->E;
            break;
        case OP_AAndH: // 0xA4
            cpu->A &= cpu->H;
            break;
        case OP_AAndL: // 0xA5
            cpu->A &= cpu->L;
            break;
        case OP_AAndM: // 0xA6
            cpu->A &= cpu->ram[cpu->M];
            break;
        case OP_AAndA: // 0xA7
            cpu->A &= cpu->A;
            break;
        case OP_AXorB: // 0xA8
            cpu->A ^= cpu->B;
            break;
        case OP_AXorC: // 0xA9
            cpu->A ^= cpu->C;
            break;
        case OP_AXorD: // 0xAA
            cpu->A ^= cpu->D;
            break;
        case OP_AXorE: // 0xAB
            cpu->A ^= cpu->E;
            break;
        case OP_AXorH: // 0xAC
            cpu->A ^= cpu->H;
            break;
        case OP_AXorL: // 0xAD
            cpu->A ^= cpu->L;
            break;
        case OP_AXorM: // 0xAE
            cpu->A ^= cpu->ram[cpu->M];
            break;
        case OP_AXorA: // 0xAF
            cpu->A ^= cpu->A;
            break;
        case OP_AOrB: // 0xB0
            cpu->A |= cpu->B;
            break;
        case OP_AOrC: // 0xB1
            cpu->A |= cpu->C;
            break;
        case OP_AOrD: // 0xB2
            cpu->A |= cpu->D;
            break;
        case OP_AOrE: // 0xB3
            cpu->A |= cpu->E;
            break;
        case OP_AOrH: // 0xB4
            cpu->A |= cpu->H;
            break;
        case OP_AOrL: // 0xB5
            cpu->A |= cpu->L;
            break;
        case OP_AOrM: // 0xB6
            cpu->A |= cpu->ram[cpu->M];
            break;
        case OP_AOrA: // 0xB7
            cpu->A |= cpu->A;
            break;
        case OP_Pad8: // 0xCB
            break;
        case OP_Pad9: // 0xD9
            break;
        case OP_Pad10: // 0xDD
            break;
        case OP_PopHL: // 0xE1
            cpu->H = cpu->ram[cpu->sp+1];
            cpu->L = cpu->ram[cpu->sp];
            cpu->sp += 2;
            break;
        case OP_ExchangeHAndLWithSPAndSPPlusOne: // 0xE3
            uint8_t e3temp1 = cpu->H;
            uint8_t e3temp2 = cpu->L;
            cpu->H = cpu->sp+1;
            cpu->L = cpu->sp;
            cpu->ram[cpu->sp] = e3temp2;
            cpu->ram[cpu->sp+1] = e3temp1;
            break;
        case OP_PushHL: // 0xE5
            cpu->ram[cpu->sp-2] = cpu->L;
            cpu->ram[cpu->sp-1] = cpu->H;
            cpu->sp -= 2;
            break;
        case OP_ExchangeHAndLWithDAndE: // 0xEB
            uint8_t ebtemp1 = cpu->H;
            uint8_t ebtemp2 = cpu->L;
            cpu->H = cpu->D;
            cpu->L = cpu->E;
            cpu->D = ebtemp1;
            cpu->E = ebtemp2;
            break;
        case OP_Pad11: // 0xED
            break;
        case OP_SetSPToHL: // 0xF9
            cpu->sp = cpu->HL;
            break;
        case OP_Pad12: // 0xFD
            break;
    }
}