#include <cstring>
#include <cstdio>
#include "cpuOpCodes.h"

#include "CPU.h"

CPU::CPU() {
    for(int i = 0; i < sizeof(memory); i++)
    {
        memory[i] = 0;
    }
    
    registerA = 0;
    registerB = 0;
    registerC = 0;
    registerD = 0;
    registerE = 0;
    registerH = 0;
    registerL = 0;
    
    sp = 0;
    pc = 0;
    
    C  = false;
    AC = false;
    S  = false;
    Z  = false;
    P  = false;
    
    HLT = false;
}

void CPU::loadProgram(unsigned char *program, int size)
{
    memcpy(memory,program,size);
}

void CPU::run()
{
    while(!HLT)
    {
        pc += executeOperation();
    }
    printf("Halting the system...\n");
}

int CPU::executeOperation()
{
    int readBytes = 1;    
    uint8_t opCode = memory[pc];
    
    switch(opCode)
    {
        case NOP:
            break;
        case LXIB:
            registerB = memory[pc+2];
            registerC = memory[pc+1];
            readBytes+=2;
            break;
        case 0x02: unimplementedInstruction(); break;
        case 0x03: unimplementedInstruction(); break;
        case 0x04: unimplementedInstruction(); break;
        case DCRB:
        {
            uint8_t result = registerB - 1;
            Z = (result == 0);
            S = ((result & 0x80) == 0x80);
            P = parity(result);
            registerB = result;    
        }
        break;
        case MVIB:
            registerB = memory[pc+1];
            readBytes+=1;
            break;
        case 0x07: unimplementedInstruction(); break;
        case 0x08: unimplementedInstruction(); break;
        case DADB:
        {
            uint32_t result = ((registerB << 8) | registerC) + ((registerH << 8) | registerL);
            C = (result > 0xFFFF);
            registerH = (result & 0xFF00) >> 8;
            registerL = result & 0xFF;
        }
            break;
        case 0x0A: unimplementedInstruction(); break;
        case 0x0B: unimplementedInstruction(); break;
        case 0x0C: unimplementedInstruction(); break;
        case DCRC: unimplementedInstruction(); break;
        case MVIC:
            registerC = memory[pc+1];
            readBytes+=1;
            break;
        case 0x0F: unimplementedInstruction(); break;
        
        case 0x10: unimplementedInstruction(); break;
        case LXID:
            registerD = memory[pc+2];
            registerE = memory[pc+1];
            readBytes +=2;
            break;
        case 0x12: unimplementedInstruction(); break;
        case INXD:
            registerE++;
            if(registerE == 0)
            {
                registerD++;
            }
            break;
        case 0x14: unimplementedInstruction(); break;
        case 0x15: unimplementedInstruction(); break;
        case 0x16: unimplementedInstruction(); break;
        case 0x17: unimplementedInstruction(); break;
        case 0x18: unimplementedInstruction(); break;
        case DADD: 
        {
            uint32_t result = ((registerD << 8) | registerE) + ((registerH << 8) | registerL);
            C = (result > 0xFFFF);
            registerH = (result & 0xFF00) >> 8;
            registerL = result & 0xFF;
        }
            break;
        case LDAXD:
            registerA = memory[(registerD << 8) | registerE];
            break;
        case 0x1B: unimplementedInstruction(); break;
        case 0x1C: unimplementedInstruction(); break;
        case 0x1D: unimplementedInstruction(); break;
        case 0x1E: unimplementedInstruction(); break;
        case 0x1F: unimplementedInstruction(); break;
        
        case 0x20: unimplementedInstruction(); break;
        case LXIH:
            registerH = memory[pc+2];
            registerL = memory[pc+1];
            readBytes +=2;
            break;
        case 0x22: unimplementedInstruction(); break;
        case INXH:
            registerL++;
            if(registerL == 0)
            {
                registerH++;
            }
            break;
        case 0x24: unimplementedInstruction(); break;
        case 0x25: unimplementedInstruction(); break;
        case MVIH:
            registerH = memory[pc+1];
            readBytes+=1;
            break;
        case 0x27: unimplementedInstruction(); break;
        case 0x28: unimplementedInstruction(); break;
        case DADH:
        {
            uint32_t result = ((registerH << 8) | registerL) + ((registerH << 8) | registerL);
            C = (result > 0xFFFF);
            registerH = (result & 0xFF00) >> 8;
            registerL = result & 0xFF;
        }  
            break;
        case 0x2A: unimplementedInstruction(); break;
        case 0x2B: unimplementedInstruction(); break;
        case 0x2C: unimplementedInstruction(); break;
        case 0x2D: unimplementedInstruction(); break;
        case 0x2E: unimplementedInstruction(); break;
        case 0x2F: unimplementedInstruction(); break;
        
        case 0x30: unimplementedInstruction(); break;
        case LXISP:
            sp = (memory[pc+2] << 8) | memory[pc+1];
            readBytes +=2;
            break;
        case 0x32: unimplementedInstruction(); break;
        case 0x33: unimplementedInstruction(); break;
        case 0x34: unimplementedInstruction(); break;
        case 0x35: unimplementedInstruction(); break;
        case MVIM:
            memory[registerH << 8 | registerL] = memory[pc+1];
            readBytes+=1;
            break;
        case 0x37: unimplementedInstruction(); break;
        case 0x38: unimplementedInstruction(); break;
        case 0x39: unimplementedInstruction(); break;
        case 0x3A: unimplementedInstruction(); break;
        case 0x3B: unimplementedInstruction(); break;
        case 0x3C: unimplementedInstruction(); break;
        case 0x3D: unimplementedInstruction(); break;
        case 0x3E: unimplementedInstruction(); break;
        case 0x3F: unimplementedInstruction(); break;
        
        case 0x40: unimplementedInstruction(); break;
        case 0x41: unimplementedInstruction(); break;
        case 0x42: unimplementedInstruction(); break;
        case 0x43: unimplementedInstruction(); break;
        case 0x44: unimplementedInstruction(); break;
        case 0x45: unimplementedInstruction(); break;
        case 0x46: unimplementedInstruction(); break;
        case 0x47: unimplementedInstruction(); break;
        case 0x48: unimplementedInstruction(); break;
        case 0x49: unimplementedInstruction(); break;
        case 0x4A: unimplementedInstruction(); break;
        case 0x4B: unimplementedInstruction(); break;
        case 0x4C: unimplementedInstruction(); break;
        case 0x4D: unimplementedInstruction(); break;
        case 0x4E: unimplementedInstruction(); break;
        case 0x4F: unimplementedInstruction(); break;
        
        case 0x50: unimplementedInstruction(); break;
        case 0x51: unimplementedInstruction(); break;
        case 0x52: unimplementedInstruction(); break;
        case 0x53: unimplementedInstruction(); break;
        case 0x54: unimplementedInstruction(); break;
        case 0x55: unimplementedInstruction(); break;
        case 0x56: unimplementedInstruction(); break;
        case 0x57: unimplementedInstruction(); break;
        case 0x58: unimplementedInstruction(); break;
        case 0x59: unimplementedInstruction(); break;
        case 0x5A: unimplementedInstruction(); break;
        case 0x5B: unimplementedInstruction(); break;
        case 0x5C: unimplementedInstruction(); break;
        case 0x5D: unimplementedInstruction(); break;
        case 0x5E: unimplementedInstruction(); break;
        case 0x5F: unimplementedInstruction(); break;
        
        case 0x60: unimplementedInstruction(); break;
        case 0x61: unimplementedInstruction(); break;
        case 0x62: unimplementedInstruction(); break;
        case 0x63: unimplementedInstruction(); break;
        case 0x64: unimplementedInstruction(); break;
        case 0x65: unimplementedInstruction(); break;
        case 0x66: unimplementedInstruction(); break;
        case 0x67: unimplementedInstruction(); break;
        case 0x68: unimplementedInstruction(); break;
        case 0x69: unimplementedInstruction(); break;
        case 0x6A: unimplementedInstruction(); break;
        case 0x6B: unimplementedInstruction(); break;
        case 0x6C: unimplementedInstruction(); break;
        case 0x6D: unimplementedInstruction(); break;
        case 0x6E: unimplementedInstruction(); break;
        case MOVLA: 
            registerL = registerA;
            break;
        case 0x70: unimplementedInstruction(); break;
        case 0x71: unimplementedInstruction(); break;
        case 0x72: unimplementedInstruction(); break;
        case 0x73: unimplementedInstruction(); break;
        case 0x74: unimplementedInstruction(); break;
        case 0x75: unimplementedInstruction(); break;
        case 0x76: unimplementedInstruction(); break;
        case MOVMA:
            memory[(registerH << 8) | registerL] = registerA;
            break;
        case 0x78: unimplementedInstruction(); break;
        case 0x79: unimplementedInstruction(); break;
        case 0x7A: unimplementedInstruction(); break;
        case 0x7B: unimplementedInstruction(); break;
        case MOVAH:
            registerA = registerH;
            break;
        case 0x7D: unimplementedInstruction(); break;
        case 0x7E: unimplementedInstruction(); break;
        case 0x7F: unimplementedInstruction(); break;
        
        case 0x80: unimplementedInstruction(); break;
        case 0x81: unimplementedInstruction(); break;
        case 0x82: unimplementedInstruction(); break;
        case 0x83: unimplementedInstruction(); break;
        case 0x84: unimplementedInstruction(); break;
        case 0x85: unimplementedInstruction(); break;
        case 0x86: unimplementedInstruction(); break;
        case 0x87: unimplementedInstruction(); break;
        case 0x88: unimplementedInstruction(); break;
        case 0x89: unimplementedInstruction(); break;
        case 0x8A: unimplementedInstruction(); break;
        case 0x8B: unimplementedInstruction(); break;
        case 0x8C: unimplementedInstruction(); break;
        case 0x8D: unimplementedInstruction(); break;
        case 0x8E: unimplementedInstruction(); break;
        case 0x8F: unimplementedInstruction(); break;
        
        case 0x90: unimplementedInstruction(); break;
        case 0x91: unimplementedInstruction(); break;
        case 0x92: unimplementedInstruction(); break;
        case 0x93: unimplementedInstruction(); break;
        case 0x94: unimplementedInstruction(); break;
        case 0x95: unimplementedInstruction(); break;
        case 0x96: unimplementedInstruction(); break;
        case 0x97: unimplementedInstruction(); break;
        case 0x98: unimplementedInstruction(); break;
        case 0x99: unimplementedInstruction(); break;
        case 0x9A: unimplementedInstruction(); break;
        case 0x9B: unimplementedInstruction(); break;
        case 0x9C: unimplementedInstruction(); break;
        case 0x9D: unimplementedInstruction(); break;
        case 0x9E: unimplementedInstruction(); break;
        case 0x9F: unimplementedInstruction(); break;
       
        case 0xA0: unimplementedInstruction(); break;
        case 0xA1: unimplementedInstruction(); break;
        case 0xA2: unimplementedInstruction(); break;
        case 0xA3: unimplementedInstruction(); break;
        case 0xA4: unimplementedInstruction(); break;
        case 0xA5: unimplementedInstruction(); break;
        case 0xA6: unimplementedInstruction(); break;
        case 0xA7: unimplementedInstruction(); break;
        case 0xA8: unimplementedInstruction(); break;
        case 0xA9: unimplementedInstruction(); break;
        case 0xAA: unimplementedInstruction(); break;
        case 0xAB: unimplementedInstruction(); break;
        case 0xAC: unimplementedInstruction(); break;
        case 0xAD: unimplementedInstruction(); break;
        case 0xAE: unimplementedInstruction(); break;
        case 0xAF: unimplementedInstruction(); break;
        
        case 0xB0: unimplementedInstruction(); break;
        case 0xB1: unimplementedInstruction(); break;
        case 0xB2: unimplementedInstruction(); break;
        case 0xB3: unimplementedInstruction(); break;
        case 0xB4: unimplementedInstruction(); break;
        case 0xB5: unimplementedInstruction(); break;
        case 0xB6: unimplementedInstruction(); break;
        case 0xB7: unimplementedInstruction(); break;
        case 0xB8: unimplementedInstruction(); break;
        case 0xB9: unimplementedInstruction(); break;
        case 0xBA: unimplementedInstruction(); break;
        case 0xBB: unimplementedInstruction(); break;
        case 0xBC: unimplementedInstruction(); break;
        case 0xBD: unimplementedInstruction(); break;
        case 0xBE: unimplementedInstruction(); break;
        case 0xBF: unimplementedInstruction(); break;
        
        case 0xC0: unimplementedInstruction(); break;
        case POPB:
            registerB = memory[sp+1];
            registerC = memory[sp];
            sp+=2;
            break;
        case JNZ:
            if(!Z)
            {
                pc = (memory[pc+2] << 8) | memory[pc+1];
                readBytes = 0;
            }
            else
                readBytes+=2;
            break;
        case JMP:
            pc = (memory[pc+2] << 8) | memory[pc+1];
            readBytes = 0;
            break;
        case 0xC4: unimplementedInstruction(); break;
        case PUSHB:
            memory[sp-1] = registerB;
            memory[sp-2] = registerC;
            sp-=2;
            break;
        case 0xC6: unimplementedInstruction(); break;
        case 0xC7: unimplementedInstruction(); break;
        case 0xC8: unimplementedInstruction(); break;
        case RET:
            pc = (memory[sp+1] << 8) | memory[sp];
            sp+=2;
            readBytes = 0;
            break;    
        case 0xCA: unimplementedInstruction(); break;
        case 0xCB: unimplementedInstruction(); break;
        case 0xCC: unimplementedInstruction(); break;
        case CALL:
            memory[sp-1] = (pc+3 >> 8);
            memory[sp-2] = (pc+3) & 0xFF;
            sp-=2;
            pc = (memory[pc+2] << 8) | memory[pc+1];
            readBytes = 0;
            break;
        case 0xCE: unimplementedInstruction(); break;
        case 0xCF: unimplementedInstruction(); break;
        
        case 0xD0: unimplementedInstruction(); break;
        case POPD:
            registerD = memory[sp+1];
            registerE = memory[sp];
            sp+=2;
            break;
        case 0xD2: unimplementedInstruction(); break;
        case OUT:
            //PENDIENTE DE SABER COMO FUNCIONA I/0
            readBytes+=1;
            break;
        case 0xD4: unimplementedInstruction(); break;
        case PUSHD:
            memory[sp-1] = registerD;
            memory[sp-2] = registerE;
            sp-=2;
            break;
        case 0xD6: unimplementedInstruction(); break;
        case 0xD7: unimplementedInstruction(); break;
        case 0xD8: unimplementedInstruction(); break;
        case 0xD9: unimplementedInstruction(); break;
        case 0xDA: unimplementedInstruction(); break;
        case 0xDB: unimplementedInstruction(); break;
        case 0xDC: unimplementedInstruction(); break;
        case 0xDD: unimplementedInstruction(); break;
        case 0xDE: unimplementedInstruction(); break;
        case 0xDF: unimplementedInstruction(); break;
        
        case 0xE0: unimplementedInstruction(); break;
        case POPH:
            registerH = memory[sp+1];
            registerL = memory[sp];
            sp+=2;
            break;
        case 0xE2: unimplementedInstruction(); break;
        case 0xE3: unimplementedInstruction(); break;
        case 0xE4: unimplementedInstruction(); break;
        case PUSHH:
            memory[sp-1] = registerH;
            memory[sp-2] = registerL;
            sp-=2;
            break;
        case 0xE6: unimplementedInstruction(); break;
        case 0xE7: unimplementedInstruction(); break;
        case 0xE8: unimplementedInstruction(); break;
        case 0xE9: unimplementedInstruction(); break;
        case 0xEA: unimplementedInstruction(); break;
        case XCHG:
        {
            uint8_t temp1 = registerD;
            uint8_t temp2 = registerE;
            registerD = registerH;
            registerE = registerL;
            registerH = temp1;
            registerL = temp2;
        }
            break;
        case 0xEC: unimplementedInstruction(); break;
        case 0xED: unimplementedInstruction(); break;
        case 0xEE: unimplementedInstruction(); break;
        case 0xEF: unimplementedInstruction(); break;
        
        case 0xF0: unimplementedInstruction(); break;
        case 0xF1: unimplementedInstruction(); break;
        case 0xF2: unimplementedInstruction(); break;
        case 0xF3: unimplementedInstruction(); break;
        case 0xF4: unimplementedInstruction(); break;
        case 0xF5: unimplementedInstruction(); break;
        case 0xF6: unimplementedInstruction(); break;
        case 0xF7: unimplementedInstruction(); break;
        case 0xF8: unimplementedInstruction(); break;
        case 0xF9: unimplementedInstruction(); break;
        case 0xFA: unimplementedInstruction(); break;
        case 0xFB: unimplementedInstruction(); break;
        case 0xFC: unimplementedInstruction(); break;
        case 0xFD: unimplementedInstruction(); break;
        case CPI:
        {
            uint8_t result = registerA - memory[pc+1];
            Z = (result == 0);
            S = ((result & 0x80) == 0x80);
            P = parity(result);
            C = (registerA < memory[pc+1]);
        }
            readBytes+=1;
            break;
        case 0xFF: unimplementedInstruction(); break;
    }
    
    return readBytes;
}

void CPU::unimplementedInstruction()
{
    printf("UNIMPLEMENTED INSTRUCTION\n");
    printf("Code: %02hhX\n", memory[pc]);
    HLT = true;
}

int CPU::parity(uint8_t value)
{
    int number = 0;
    
    for(int i = 0; i < 8; i++)
    {
        if(value%2)
            number++;
        
        value = value >> 1;
    }
    return (number%2 == 0);
}
