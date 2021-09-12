#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "cpuOpCodes.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main() {
    ifstream file("/home/carlos/programming/8080ArcadeEmu/documentation/invaders.h");
    
    unsigned char buffer[2048];
    int pointer;
    
    file.read((char*)buffer,sizeof(buffer));
    pointer = 0;
    
    while(pointer < sizeof(buffer))
    {
        switch(buffer[pointer])
        {
            case NOP:
                printf("NOP\n");
                pointer++;
                break;
                
            case LXIB:
                printf("LXI    B, #$%02X%02X\n",buffer[pointer+2],buffer[pointer+1]);
                pointer+=3;
                break;
                
            case STAXB:
                printf("STAX    B\n");
                pointer++;
                break;
                
            case INXB:
                printf("INX     B\n");
                pointer++;
                break;
            
            case INRB:
                printf("INR     B\n");
                pointer++;
                break;
                
            case DCRB:
                printf("DCR     B\n");
                pointer++;
                break;
            
            case MVIB:
                printf("MVI     B, #$%02X\n",buffer[pointer +1]);
                pointer+=2;
                break;
                
            case RLC:
                printf("RLC\n");
                pointer++;
                break;
                
            case DADB:
                printf("DAD     B\n");
                pointer++;
                break;
                
            case LDAXB:
                printf("LDAX    B\n");
                pointer++;
                break;
                
            case DCXB:
                printf("DCX     B\n");
                pointer++;
                break;
                
            case INRC:
                printf("INR     C\n");
                pointer++;
                break;
                
            case DCRC:
                printf("DCR     C\n");
                pointer++;
                break;
                
            case MVIC:
                printf("MVI     C, #$%02X\n",buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RRC:
                printf("RRC\n");
                pointer++;
                break;
                
            case LXID:
                printf("LXI     D, #$%02X%02X\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case STAXD:
                printf("STAX    D\n");
                pointer++;
                break;
                
            case INXD:
                printf("INX     D\n");
                pointer++;
                break;
                
            case INRD:
                printf("INR     D\n");
                pointer++;
                break;
                
            case DCRD:
                printf("DCR     D\n");
                pointer++;
                break;
                
            case MVID:
                printf("MVI     D, #$%02X", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RAL:
                printf("RAL\n");
                pointer++;
                break;
                
            case DADD:
                printf("DAD     D\n");
                pointer++;
                break;
                
            case LDAXD:
                printf("LDAX    D\n");
                pointer++;
                break;
                
            case DCXD:
                printf("DCX     D\n");
                pointer++;
                break;
                
            case INRE:
                printf("INR     E\n");
                pointer++;
                break;
                
            case DCRE:
                printf("DCR     E\n");
                pointer++;
                break;
                
            case MVIE:
                printf("MVI     E, #$%02X\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RAR:
                printf("RAR\n");
                pointer;
                break;
                
            case LXIH:
                printf("LXI     H, #$%02X%02X\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case SHLD:
                printf("SHLD    #$%02X%02X\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case INXH:
                printf("INX     H\n");
                pointer++;
                break;
                
            case INRH:
                printf("INR     H\n");
                pointer++;
                break;
                
            case DCRH:
                printf("DCR     H\n");
                pointer++;
                break;
                
            case MVIH:
                printf("MVI     H, #$%02X", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case DAA:
                printf("DAA\n");
                pointer++;
                break;
                
            case DADH:
                printf("DAD     H\n");
                pointer++;
                break;
                
            case LHLD:
                printf("LHLD    ($%02X%02X)", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
            
            case DCXH:
                printf("DCX     H\n");
                pointer++;
                break;
                
            case INRL:
                printf("INR     L\n");
                pointer++;
                break;
                
            case DCRL:
                printf("DCR     L\n");
                pointer++;
                break;
                
            case MVIL:
                printf("MVI     L, #$%02X\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case CMA:
                printf("CMA\n");
                pointer++;
                break;
                
            case LXISP:
                printf("LXI     SP, #$%02X%02X\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case STA:
                printf("STA     #$%02X%02X\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case INXSP:
                printf("INX     SP\n");
                pointer++;
                break;
                
            case INRM:
                printf("INR     M\n");
                pointer++;
                break;
                
            case DCRM:
                printf("DCR     M\n");
                pointer++;
                break;
                
            case MVIM:
                printf("MVI     M, #$%02X", buffer[pointer+1]);
                pointer++;
                break;
                
            case STC:
                printf("STC\n");
                pointer++;
                break;
                
            case DADSP:
                printf("DAD     SP\n");
                pointer++;
                break;
                
            case LDA:
                printf("LDA     ($%02X%02X)\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case DCXSP:
                printf("DCX     SP\n");
                pointer++;
                break;
                
            case INRA:
                printf("INR     A\n");
                pointer++;
                break;
                
            case DCRA:
                printf("DCR     A\n");
                pointer++;
                break;
                
            case MVIA:
                printf("MVI     A, #$%02X\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case CMC:
                printf("CMC\n");
                pointer++;
                break;
                
            case MOVBB:
                printf("MOV     B, B\n");
                pointer++;
                break;
                
            case MOVBC:
                printf("MOV     B, C\n");
                pointer++;
                break;
                
            case MOVBD:
                printf("MOV     B, D\n");
                pointer++;
                break;
                
            case MOVBE:
                printf("MOV     B, E\n");
                pointer++;
                break; 
                
            case MOVBH:
                printf("MOV     B, H\n");
                pointer++;
                break;
                
            case MOVBL:
                printf("MOV     B, L\n");
                pointer++;
                break;
                
            case MOVBM:
                printf("MOV     B, M\n");
                pointer++;
                break;
                
            case MOVBA:
                printf("MOV     B, A\n");
                pointer++;
                break;
                
            case MOVCB:
                printf("MOV     C, B\n");
                pointer++;
                break;
                
            case MOVCC:
                printf("MOV     C, C\n");
                pointer++;
                break;
                
            case MOVCD:
                printf("MOV     C, D\n");
                pointer++;
                break;
                
            case MOVCE:
                printf("MOV     C, E\n");
                pointer++;
                break; 
                
            case MOVCH:
                printf("MOV     C, H\n");
                pointer++;
                break;
                
            case MOVCL:
                printf("MOV     C, L\n");
                pointer++;
                break;
                
            case MOVCM:
                printf("MOV     C, M\n");
                pointer++;
                break;
                
            case MOVCA:
                printf("MOV     C, A\n");
                pointer++;
                break;
                
            case MOVDB:
                printf("MOV     D, B\n");
                pointer++;
                break;
                
            case MOVDC:
                printf("MOV     D, C\n");
                pointer++;
                break;
                
            case MOVDD:
                printf("MOV     D, D\n");
                pointer++;
                break;
                
            case MOVDE:
                printf("MOV     D, E\n");
                pointer++;
                break; 
                
            case MOVDH:
                printf("MOV     D, H\n");
                pointer++;
                break;
                
            case MOVDL:
                printf("MOV     D, L\n");
                pointer++;
                break;
                
            case MOVDM:
                printf("MOV     D, M\n");
                pointer++;
                break;
                
            case MOVDA:
                printf("MOV     D, A\n");
                pointer++;
                break;
            
            case MOVEB:
                printf("MOV     E, B\n");
                pointer++;
                break;
                
            case MOVEC:
                printf("MOV     E, C\n");
                pointer++;
                break;
                
            case MOVED:
                printf("MOV     E, D\n");
                pointer++;
                break;
                
            case MOVEE:
                printf("MOV     E, E\n");
                pointer++;
                break; 
                
            case MOVEH:
                printf("MOV     E, H\n");
                pointer++;
                break;
                
            case MOVEL:
                printf("MOV     E, L\n");
                pointer++;
                break;
                
            case MOVEM:
                printf("MOV     E, M\n");
                pointer++;
                break;
                
            case MOVEA:
                printf("MOV     E, A\n");
                pointer++;
                break;
                
            case MOVHB:
                printf("MOV     H, B\n");
                pointer++;
                break;
                
            case MOVHC:
                printf("MOV     H, C\n");
                pointer++;
                break;
                
            case MOVHD:
                printf("MOV     H, D\n");
                pointer++;
                break;
                
            case MOVHE:
                printf("MOV     H, E\n");
                pointer++;
                break; 
                
            case MOVHH:
                printf("MOV     H, H\n");
                pointer++;
                break;
                
            case MOVHL:
                printf("MOV     H, L\n");
                pointer++;
                break;
                
            case MOVHM:
                printf("MOV     H, M\n");
                pointer++;
                break;
                
            case MOVHA:
                printf("MOV     H, A\n");
                pointer++;
                break;
                
            case MOVLB:
                printf("MOV     L, B\n");
                pointer++;
                break;
                
            case MOVLC:
                printf("MOV     L, C\n");
                pointer++;
                break;
                
            case MOVLD:
                printf("MOV     L, D\n");
                pointer++;
                break;
                
            case MOVLE:
                printf("MOV     L, E\n");
                pointer++;
                break; 
                
            case MOVLH:
                printf("MOV     L, H\n");
                pointer++;
                break;
                
            case MOVLL:
                printf("MOV     L, L\n");
                pointer++;
                break;
                
            case MOVLM:
                printf("MOV     L, M\n");
                pointer++;
                break;
                
            case MOVLA:
                printf("MOV     L, A\n");
                pointer++;
                break;
                
            case MOVMB:
                printf("MOV     M, B\n");
                pointer++;
                break;
                
            case MOVMC:
                printf("MOV     M, C\n");
                pointer++;
                break;
                
            case MOVMD:
                printf("MOV     M, D\n");
                pointer++;
                break;
                
            case MOVME:
                printf("MOV     M, E\n");
                pointer++;
                break; 
                
            case MOVMH:
                printf("MOV     M, H\n");
                pointer++;
                break;
                
            case MOVML:
                printf("MOV     M, L\n");
                pointer++;
                break;
                
            case HLT:
                printf("HLT\n");
                pointer++;
                break;
 
            case MOVMA:
                printf("MOV     M, A\n");
                pointer++;
                break;
                
            case MOVAB:
                printf("MOV     A, B\n");
                pointer++;
                break;
                
            case MOVAC:
                printf("MOV     A, C\n");
                pointer++;
                break;
                
            case MOVAD:
                printf("MOV     A, D\n");
                pointer++;
                break;
                
            case MOVAE:
                printf("MOV     A, E\n");
                pointer++;
                break; 
                
            case MOVAH:
                printf("MOV     A, H\n");
                pointer++;
                break;
                
            case MOVAL:
                printf("MOV     A, L\n");
                pointer++;
                break;
                
            case MOVAM:
                printf("MOV     A, M\n");
                pointer++;
                break;
                
            case MOVAA:
                printf("MOV     A, A\n");
                pointer++;
                break;
                
            case ADDB:
                printf("ADD     B\n");
                pointer++;
                break;
                
            case ADDC:
                printf("ADD     C\n");
                pointer++;
                break;
                
            case ADDD:
                printf("ADD     D\n");
                pointer++;
                break;
                
            case ADDE:
                printf("ADD     E\n");
                pointer++;
                break;
                
            case ADDH:
                printf("ADD     H\n");
                pointer++;
                break;
                
            case ADDL:
                printf("ADD     L\n");
                pointer++;
                break;
                
            case ADDM:
                printf("ADD     M\n");
                pointer++;
                break;
                
            case ADDA:
                printf("ADD     A\n");
                pointer++;
                break;
                 
            case ADCB:
                printf("ADC     B\n");
                pointer++;
                break;
                
            case ADCC:
                printf("ADC     C\n");
                pointer++;
                break;
                
            case ADCD:
                printf("ADC     D\n");
                pointer++;
                break;
                
            case ADCE:
                printf("ADC     E\n");
                pointer++;
                break;
                
            case ADCH:
                printf("ADC     H\n");
                pointer++;
                break;
                
            case ADCL:
                printf("ADC     L\n");
                pointer++;
                break;
                
            case ADCM:
                printf("ADC     M\n");
                pointer++;
                break;
                
            case ADCA:
                printf("ADC     A\n");
                pointer++;
                break;
                
            //
            case SUBB:
                printf("SUB      B\n");
                pointer++;
                break;
                
            case SUBC:
                printf("SUB      C\n");
                pointer++;
                break;
                
            case SUBD:
                printf("SUB      D\n");
                pointer++;
                break;
                
            case SUBE:
                printf("SUB      E\n");
                pointer++;
                break;
                
            case SUBH:
                printf("SUB      H\n");
                pointer++;
                break;
                
            case SUBL:
                printf("SUB      L\n");
                pointer++;
                break;
                
            case SUBM:
                printf("SUB      M\n");
                pointer++;
                break;
                
            case SUBA:
                printf("SUB      A\n");
                pointer++;
                break;
            
            //
            case SBBB:
                printf("SBB      B\n");
                pointer++;
                break;
                
            case SBBC:
                printf("SBB      C\n");
                pointer++;
                break;
                
            case SBBD:
                printf("SBB      D\n");
                pointer++;
                break;
                
            case SBBE:
                printf("SBB      E\n");
                pointer++;
                break;
                
            case SBBH:
                printf("SBB      H\n");
                pointer++;
                break;
                
            case SBBL:
                printf("SBB      L\n");
                pointer++;
                break;
                
            case SBBM:
                printf("SBB      M\n");
                pointer++;
                break;
                
            case SBBA:
                printf("SBB      A\n");
                pointer++;
                break;
            
            
        }
    }
}

