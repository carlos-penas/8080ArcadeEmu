#ifndef CPUOPCODES_H
#define CPUOPCODES_H

//Definition of the operation code for all of the CPU instructions

#define NOP     0x00    //No operation
#define LXIB    0x01    //Load inmediate value in register pair BC (B <- byte 3, C <- byte 2)
#define STAXB   0x02    //Move content of the accumulator to the memory location stored in register pair BC
#define INXB    0x03    //The content of register pair BC is incremented by one (No condition flags affected)
#define INRB    0x04    //The content of register B is incremented by one (All condition flags affected except CY)
#define DCRB    0x05    //The content of register B is decremented by one (All condition flags affected except CY)
#define MVIB    0x06    //The value  specified in byte 2 of the instruction is moved to register B
#define RLC     0x07    //The content of the accumulator is rotated left one bit (MSb goes to LSb and CY flag)
//      -       0x08
#define DADB    0x09    //The content of register pair BC is added to the content of register pair HL and stored in HL (CY flag affected)
#define LDAXB   0x0A    //The content of the memory location stored in register pair BC is moved to the accumulator
#define DCXB    0x0B    //The content of register pair BC is decremented by one (No condition flags affected)
#define INRC    0x0C    //The content of register C is incremented by one (All condition flags affected except CY)
#define DCRC    0x0D    //The content of register C is decremented by one (All condition flags affected except CY)
#define MVIC    0x0E    //The value specified in byte 2 of the instruction is moved to register C
#define RRC     0x0F    //The content of the accumulator is rotated right one bit (LSb goes to MSb and CY flag)
//      -       0x10    
#define LXID    0x11    //Load inmediate value in register pair DE (D <- byte 3, E <- byte 2)
#define STAXD   0x12    //Move content of the accumulator to the memory location stored in register pair DE
#define INXD    0x13    //The content of register pair DE is incremented by one (No condition flags affected)
#define INRD    0x14    //The content of register D is incremented by one (All condition flags affected except CY)
#define DCRD    0x15    //The content of register D is decremented by one (All condition flags affected except CY)
#define MVID    0x16    //The value specified in byte 2 of the instruction is moved to register D
#define RAL     0x17    //The content of the accumulator is rotated left one bit (MSb goes to CY flag and CY flag goes to LSb)
//      -       0x18
#define DADD    0x19    //The content of register pair DE is added to the content of register pair HL and stored in HL (CY flag affected)
#define LDAXD   0x1A    //The content of the memory location stored in register pair DE is moved to the accumulator
#define DCXD    0x1B    //The content of register pair DE is decremented by one (No condition flags affected)
#define INRE    0x1C    //The content of register E is incremented by one (All condition flags affected except CY)
#define DCRE    0x1D    //The content of register E is decremented by one (All condition flags affected except CY)
#define MVIE    0x1E    //The value specified in byte 2 of the instruction is moved to register E
#define RAR     0x1F    //The content of the accumulator is rotated right one bit (LSb goes to CY flag and CY flag goes to MSb)
//      -       0x20    
#define LXIH    0x21    //Load inmediate value in register pair HL (H <- Byte 3, L <- byte 2)
#define SHLD    0x22    //The content of register L is moved to the memory location specified, the content of register H is moved to that memory location + 1
#define INXH    0x23    //The content of register pair HL is incremented by one (No condition flags affected)
#define INRH    0x24    //The content of register H is incremented by one (All condition flags affected except CY)
#define DCRH    0x25    //The content of register H is decremented by one (All condition flags affected except CY)
#define MVIH    0x26    //The value specified in byte 2 of the instruction is moved to register H
#define DAA     0x27    // ???
//      -       0x28
#define DADH    0x29    //The content of register pair HL is added to register pair HL (itself), the result is stored in HL (only CY flag affected)
#define LHLD    0x2A    //The content of the memory location specified is moved to register L, the content of the next memory location is moved to register H
#define DCXH    0x2B    //The content of register pair HL is decremented by one (No condition flags affected except)
#define INRL    0x2C    //The content of register L is incremented by one (All condition flags affected except CY)
#define DCRL    0x2D    //The content of register L is decremented by one (All condition flags affected except CY)
#define MVIL    0x2E    //The value specified is moved to register L
#define CMA     0x2F    //The content of the accumulator is complemented (No flags affected)
//      -       0x30
#define LXISP   0x31    //Load the specified value into the stack pointer register SP (MSB <- Byte 3, LSB <- Byte2)
#define STA     0x32    //The content of the accumulator is moved to the memory location specified
#define INXSP   0x33    //The content of stack pointer register SP is incremented by one (No condition flags affected)
#define INRM    0x34    //The content of the memory location stored in register pair HL is incremented by one (All condition flags affected except CY)
#define DCRM    0x35    //The content of the memory location stored in register pair HL is decremented by one (All condition flags affected except CY)
#define MVIM    0x36    //The value specified is moved to the memory location stored in register pair HL
#define STC     0x37    //The carry flag CY  is set to one (No other flags affected)
//      -       0x38
#define DADSP   0x39    //The content of stack pointer register SP is added to register pair HL and stored in register pair HL (only CY flag affected)
#define LDA     0x3A    //The content of the memory location specified is moved to the accumulator A
#define DCXSP   0x3B    //The content of stack pointer register SP is decremented by one (No condition flags affected)
#define INRA    0x3C    //The content of the accumulator A is incremented by one (All condition flags affected except CY)
#define DCRA    0x3D    //The content of the accumulator A is decremented by one (All condition flags affected except CY)
#define MVIA    0x3E    //The value specified is moved to the accumulator A
#define CMC     0x3F    //The carry flag CY is complemented (No other flags affected)

//Move
#define MOVBB   0x40    //The content of register B is moved to register B
#define MOVBC   0x41    //The content of register C is moved to register B
#define MOVBD   0x42    //The content of register D is moved to register B
#define MOVBE   0x43    //The content of register E is moved to register B
#define MOVBH   0x44    //The content of register H is moved to register B
#define MOVBL   0x45    //The content of register L is moved to register B
#define MOVBM   0x46    //The content of the memory location stored in register pair HL is moved to register B
#define MOVBA   0x47    //The content of the accumulator A is moved to register B

//Move
#define MOVCB   0x48    //The content of register B is moved to register C
#define MOVCC   0x49    //The content of register C is moved to register C
#define MOVCD   0x4A    //The content of register D is moved to register C
#define MOVCE   0x4B    //The content of register E is moved to register C
#define MOVCH   0x4C    //The content of register H is moved to register C
#define MOVCL   0x4D    //The content of register L is moved to register C
#define MOVCM   0x4E    //The content of the memory location stored in register pair HL is moved to register C
#define MOVCA   0x4F    //The content of the accumulator A is moved to register C

//Move
#define MOVDB   0x50    //The content of register B is moved to register D
#define MOVDC   0x51    //The content of register C is moved to register D
#define MOVDD   0x52    //The content of register D is moved to register D
#define MOVDE   0x53    //The content of register E is moved to register D
#define MOVDH   0x54    //The content of register H is moved to register D
#define MOVDL   0x55    //The content of register L is moved to register D
#define MOVDM   0x56    //The content of the memory location stored in register pair HL is moved to register D
#define MOVDA   0x57    //The content of the accumulator A is moved to register D

//Move
#define MOVEB   0x58    //The content of register B is moved to register E
#define MOVEC   0x59    //The content of register C is moved to register E
#define MOVED   0x5A    //The content of register D is moved to register E
#define MOVEE   0x5B    //The content of register E is moved to register E
#define MOVEH   0x5C    //The content of register H is moved to register E
#define MOVEL   0x5D    //The content of register L is moved to register E
#define MOVEM   0x5E    //The content of the memory location stored in register pair HL is moved to register E
#define MOVEA   0x5F    //The content of the accumulator A is moved to register E

//Move
#define MOVHB   0x60    //The content of register B is moved to register H
#define MOVHC   0x61    //The content of register C is moved to register H
#define MOVHD   0x62    //The content of register D is moved to register H
#define MOVHE   0x63    //The content of register E is moved to register H
#define MOVHH   0x64    //The content of register H is moved to register H
#define MOVHL   0x65    //The content of register L is moved to register H
#define MOVHM   0x66    //The content of the memory location stored in register pair HL is moved to register H
#define MOVHA   0x67    //The content of the accumulator A is moved to register H

//Move
#define MOVLB   0x68    //The content of register B is moved to register L
#define MOVLC   0x69    //The content of register C is moved to register L
#define MOVLD   0x6A    //The content of register D is moved to register L
#define MOVLE   0x6B    //The content of register E is moved to register L
#define MOVLH   0x6C    //The content of register H is moved to register L
#define MOVLL   0x6D    //The content of register L is moved to register L
#define MOVLM   0x6E    //The content of the memory location stored in register pair HL is moved to register L
#define MOVLA   0x6F    //The content of the accumulator A is moved to register L

//Move to address in HL
#define MOVMB   0x70    //The content of register B is moved to the memory location stored in register pair HL
#define MOVMC   0x71    //The content of register C is moved to the memory location stored in register pair HL
#define MOVMD   0x72    //The content of register D is moved to the memory location stored in register pair HL
#define MOVME   0x73    //The content of register E is moved to the memory location stored in register pair HL
#define MOVMH   0x74    //The content of register H is moved to the memory location stored in register pair HL
#define MOVML   0x75    //The content of register L is moved to the memory location stored in register pair HL

#define HLT     0x76    //The CPU is stopped. Register and flags stay the same.
#define MOVMA   0x77    //The content of the accumulator A is moved to the memory location stored in register pair HL

//Move
#define MOVAB   0x78    //The content of register B is moved to the accumulator A
#define MOVAC   0x79    //The content of register C is moved to the accumulator A
#define MOVAD   0x7A    //The content of register D is moved to the accumulator A
#define MOVAE   0x7B    //The content of register E is moved to the accumulator A
#define MOVAH   0x7C    //The content of register H is moved to the accumulator A
#define MOVAL   0x7D    //The content of register L is moved to the accumulator A
#define MOVAM   0x7E    //The content of the memory location stored in register pair HL is moved to the accumulator A
#define MOVAA   0x7F    //The content of the accumulator A is moved to the accumulator A

//Add
#define ADDB    0x80    //The content of register B is added to the accumulator A and stored in the accumulator
#define ADDC    0x81    //The content of register C is added to the accumulator A and stored in the accumulator
#define ADDD    0x82    //The content of register D is added to the accumulator A and stored in the accumulator
#define ADDE    0x83    //The content of register E is added to the accumulator A and stored in the accumulator
#define ADDH    0x84    //The content of register H is added to the accumulator A and stored in the accumulator
#define ADDL    0x85    //The content of register L is added to the accumulator A and stored in the accumulator
#define ADDM    0x86    //The content of the memory location stored in register pair HL is added to the accumulator A and stored in the accumulator
#define ADDA    0x87    //The content of the accumulator A is added to the accumulator A and stored in the accumulator

//Add with carry
#define ADCB    0x88    //The content of register B and the carry bit CY are added to the accumulator A and stored in the accumulator
#define ADCC    0x89    //The content of register C and the carry bit CY are added to the accumulator A and stored in the accumulator
#define ADCD    0x8A    //The content of register D and the carry bit CY are added to the accumulator A and stored in the accumulator
#define ADCE    0x8B    //The content of register E and the carry bit CY are added to the accumulator A and stored in the accumulator
#define ADCH    0x8C    //The content of register H and the carry bit CY are added to the accumulator A and stored in the accumulator
#define ADCL    0x8D    //The content of register L and the carry bit CY are added to the accumulator A and stored in the accumulator
#define ADCM    0x8E    //The content of the memory location stored in register pair HL and the carry bit CY are added to the accumulator A and stored in the accumulator.
#define ADCA    0x8F    //The content of the accumulator A and the carry bit CY are added to the accumulator A and stored in the accumulator

//Subtract
#define SUBB    0x90    //The content of register B is subracted from the accumulator A and stored in the accumulator
#define SUBC    0x91    //The content of register C is subracted from the accumulator A and stored in the accumulator
#define SUBD    0x92    //The content of register D is subracted from the accumulator A and stored in the accumulator
#define SUBE    0x93    //The content of register E is subracted from the accumulator A and stored in the accumulator
#define SUBH    0x94    //The content of register H is subracted from the accumulator A and stored in the accumulator
#define SUBL    0x95    //The content of register L is subracted from the accumulator A and stored in the accumulator
#define SUBM    0x96    //The content of the memory location stored in register pair HL is subracted from the accumulator A and stored in the accumulator
#define SUBA    0x97    //The content of the accumulator A is subracted from the accumulator A and stored in the accumulator

//Subtract with borrow
#define SBBB    0x98    //The content of register B and the carry bit CY are subracted from the accumulator A and stored in the accumulator
#define SBBC    0x99    //The content of register C and the carry bit CY are subracted from the accumulator A and stored in the accumulator
#define SBBD    0x9A    //The content of register D and the carry bit CY are subracted from the accumulator A and stored in the accumulator
#define SBBE    0x9B    //The content of register E and the carry bit CY are subracted from the accumulator A and stored in the accumulator
#define SBBH    0x9C    //The content of register H and the carry bit CY are subracted from the accumulator A and stored in the accumulator
#define SBBL    0x9D    //The content of register L and the carry bit CY are subracted from the accumulator A and stored in the accumulator
#define SBBM    0x9E    //The content of the memory location stored in register pair HL and the carry bit CY are subracted from the accumulator A and stored in the accumulator.
#define SBBA    0x9F    //The content of the accumulator A and the carry bit CY are subracted from the accumulator A and stored in the accumulator

//AND
#define ANAB    0xA0    //The content of register B is AND'd with the accumulator A and stored in the accumulator (CY flag is cleared)
#define ANAC    0xA1    //The content of register C is AND'd with the accumulator A and stored in the accumulator (CY flag is cleared)
#define ANAD    0xA2    //The content of register D is AND'd with the accumulator A and stored in the accumulator (CY flag is cleared)
#define ANAE    0xA3    //The content of register E is AND'd with the accumulator A and stored in the accumulator (CY flag is cleared)
#define ANAH    0xA4    //The content of register H is AND'd with the accumulator A and stored in the accumulator (CY flag is cleared)
#define ANAL    0xA5    //The content of register L is AND'd with the accumulator A and stored in the accumulator (CY flag is cleared)
#define ANAM    0xA6    //The content of the memory location stored in register pair HL is AND'd with the accumulator A and stored in the accumulator (CY flag is cleared)
#define ANAA    0xA7    //The content of the accumulator A is AND'd with the accumulator A and stored in the accumulator (CY flag is cleared)

//XOR
#define XRAB    0xA8    //The content of register B is XOR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define XRAC    0xA9    //The content of register C is XOR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define XRAD    0xAA    //The content of register D is XOR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define XRAE    0xAB    //The content of register E is XOR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define XRAH    0xAC    //The content of register H is XOR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define XRAL    0xAD    //The content of register L is XOR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define XRAM    0xAE    //The content of the memory location stored in register pair HL is XOR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define XRAA    0xAF    //The content of the accumulator A is XOR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)

//OR
#define ORAB    0xB0    //The content of register B is OR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define ORAC    0xB1    //The content of register C is OR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define ORAD    0xB2    //The content of register D is OR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define ORAE    0xB3    //The content of register E is OR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define ORAH    0xB4    //The content of register H is OR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define ORAL    0xB5    //The content of register L is OR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define ORAM    0xB6    //The content of the memory location stored in register pair HL is OR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)
#define ORAA    0xB7    //The content of the accumulator A is OR'd with the accumulator A and stored in the accumulator (CY flag and AC flag are cleared)

//Comparison
#define CMPB    0xB8    //The content of register B is subtracted from the accumulator A. Accumulator remains unchanged (Z flag = 1 if A = B, CY flag = 1 if A < B)
#define CMPC    0xB9    //The content of register C is subtracted from the accumulator A. Accumulator remains unchanged (Z flag = 1 if A = B, CY flag = 1 if A < B)
#define CMPD    0xBA    //The content of register D is subtracted from the accumulator A. Accumulator remains unchanged (Z flag = 1 if A = B, CY flag = 1 if A < B)
#define CMPE    0xBB    //The content of register E is subtracted from the accumulator A. Accumulator remains unchanged (Z flag = 1 if A = B, CY flag = 1 if A < B)
#define CMPH    0xBC    //The content of register H is subtracted from the accumulator A. Accumulator remains unchanged (Z flag = 1 if A = B, CY flag = 1 if A < B)
#define CMPL    0xBD    //The content of register L is subtracted from the accumulator A. Accumulator remains unchanged (Z flag = 1 if A = B, CY flag = 1 if A < B)
#define CMPM    0xBE    //The content of the memory location stored in register pair HL is subtracted from the accumulator A. Accumulator remains unchanged (Z flag = 1 if A = B, CY flag = 1 if A < B)
#define CMPA    0xBF    //The content of the accumulator is subtracted from the accumulator A. Accumulator remains unchanged (Z flag = 1 if A = B, CY flag = 1 if A < B)

#define RNZ     0xC0    //If Z flag is not true, perform RET operation
#define POPB    0xC1    //The content of the memory location stored in stack pointer SP is moved to the register pair BC (B <- SP adress + 1, C <- SP adress). Stack pointer SP is incremented by 2
#define JNZ     0xC2    //If Z flag is not true, jump to the specified adress
#define JMP     0xC3    //Jump to the specified adress
#define CNZ     0xC4    //If Z flag is not true, perform CALL operation with specified data (Bytes 2 and 3)
#define PUSHB    0xC5   //The content of register pair BC is moved to the location stored on stack pointer SP - 2 and SP -1. Stack pointer SP is decremented by 2
#define ADI     0xC6    //The value specified is added to the accumulator A and stored in the accumulator
#define RST0    0xC7    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to adress 8*(NNN)   0?
#define RZ      0xC8    //If Z flag is true, perform RET operation
#define RET     0xC9    //The content of the memory location stored in the stack pointer SP and that location + 1 are moved to the program counter PC. Stack Pointer SP is incremented by two
#define JZ      0xCA    //If Z flag is true, jump to the specified adress
//      -       0xCB
#define CZ      0xCC    //If Z flag is not true, perform CALL operation with specified data (Bytes 2 and 3)
#define CALL    0xCD    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to the instruction specified.
#define ACI     0xCE    //The value specified and the CY flag are added to the accumulator A and stored in the accumulator
#define RST1    0xCF    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to adress 8*(NNN)  8?
#define RNC     0xD0    //If CY flag is not true, perform RET operation
#define POPD    0xD1    //The content of the memory location stored in stack pointer SP is moved to the register pair DE (D <- SP adress + 1, E <- SP adress). Stack pointer SP is incremented by 2
#define JNC     0xD2    //If CY flag is not true, jump to the specified adress
#define OUT     0xD3    //The content of the accumulator A is placed on the 8 bit bi-directional data bus for transmition to the specified port
#define CNC     0xD4    //If CY flag is not true, perform CALL operation with specified data (Bytes 2 and 3)
#define PUSHD    0xD5   //The content of register pair DE is moved to the location stored on stack pointer SP - 2 and SP -1. Stack pointer SP is decremented by 2
#define SUI     0xD6    //The specified value is subtracted from the accumulator A and stored in the accumulator
#define RST2    0xD7    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to adress 8*(NNN)  10?
#define RC      0xD8    //If CY flag is true, perform RET operation
//      -       0xD9
#define JC      0xDA    //If CY flag is true, jump to the specified adress
#define IN      0xDB    //The value on the 8 bit bi-directional data bus is placed on the accumulator A
#define CC      0xDC    //If CY flag is true, perform CALL operation with specified data (Bytes 2 and 3)
//      -       0xDD
#define SBI     0xDE    //The specified value and the CY flag are substracted from the accumulator A and stored in the accumulator
#define RST3    0xDF    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to adress 8*(NNN)  18?
#define RPO     0xE0    //If PO flag is true, perform RET operation
#define POPH    0xE1    //The content of the memory location stored in stack pointer SP is moved to the register pair HL (H <- SP adress + 1, L <- SP adress). Stack pointer SP is incremented by 2
#define JPO     0xE2    //If PO flag is true, jump to the specified adress
#define XTHL    0xE3    //The content of the register pair HL is exchanged with the content of the memory location stored in stack pointer SP and SP +1 (H <-> SP +1, L <-> SP)
#define CPO     0xE4    //If PO flag is true, perform CALL operation with specified data (Bytes 2 and 3)
#define PUSHH    0xE5   //The content of register pair HL is moved to the location stored on stack pointer SP - 2 and SP -1. Stack pointer SP is decremented by 2
#define ANI     0xE6    //The value specified is AND'd with the accumulator A and stored in the accumulator (CY and AC flags cleared)
#define RST4    0xE7    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to adress 8*(NNN)  20?
#define RPE     0xE8    //If PE flag is true, perform RET operation
#define PCHL    0xE9    //The contents of register pair HL are moved to the PC
#define JPE     0xEA    //If PE flag is true, jump to the specified adress
#define XCHG    0xEB    //The contens of register pair HL are exchanged with the contents of register pair DE
#define CPE     0xEC    //If PE flag is true, perform CALL operation with specified data (Bytes 2 and 3)
//      -       0xED
#define XRI     0xEE    //The value specified is XOR'd with the accumulator A and stored in the accumulator (CY and AC flags cleared)
#define RST5    0xEF    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to adress 8*(NNN)  28?
#define RP      0xF0    //If P flag is true, perform RET operation
#define POPPSW  0xF1    //The content of the memory location stored in stack pointer SP is moved to the flags. The content of that memory location + 1 is moved to the accumulator. Stack pointer SP is incremented by 2
#define JP      0xF2    //If P flag is true, jump to the specified adress
#define DI      0xF3    //The interrupt system is disabled after this instruction
#define CP      0xF4    //If P flag is true, perform CALL operation with specified data (Bytes 2 and 3)
#define PUSHPSW 0xF5    //The content of the accumulator A is moved to the memory location stored in stack pointer SP - 1. The value of all the flags is stored in the memory location stored in SP -2 . Stack pointer SP is decremented by 2
#define ORI     0xF6    //The value specified is OR'd with the accumulator A and stored in the accumulator (CY and AC flags cleared)
#define RST6    0xF7    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to adress 8*(NNN)  30?
#define RM      0xF8    //If M flag is true, perform RET operation
#define SPHL    0xF9    //The contents of register pair HL are moved to the stack pointer SP
#define JM      0xFA    //If M flag is true, jump to the specified adress
#define EI      0xFB    //The interrupt system is enabled after this instruction
#define CM      0xFC    //If M flag is true, perform CALL operation with specified data (Bytes 2 and 3)
//      -       0xFD
#define CPI     0xFE    //The specified value is subtracted from the accumulator A. If result = 0, Z flag is set. If result < 0, CY flag is set. It doesn't change the accumulator data, just compares.
#define RST7    0xFF    //The next instruction ADRESS is moved to the stack pointer SP - 2 and SP -1. Stack pointer SP is decremented y 2. Jump to adress 8*(NNN)  38?

#endif /* CPUOPCODES_H */

