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
    ifstream file("/home/carlos/programming/8080ArcadeEmu/documentation/space_invaders/spaceInvaders.rom");
    
    unsigned char buffer[8192];
    
    file.read((char*)buffer,sizeof(buffer));
    unsigned int pointer = 0;
    
    while(pointer < sizeof(buffer))
    {
        printf("%04X   ", pointer);
        switch(buffer[pointer])
        {
            case NOP:
                printf("NOP\n");
                pointer++;
                break;
                
            case LXIB:
                printf("LXI     B, #$%02hhX%02hhX\n",buffer[pointer+2],buffer[pointer+1]);
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
                printf("MVI     B, #$%02hhX\n",buffer[pointer +1]);
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
                printf("MVI     C, #$%02hhX\n",buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RRC:
                printf("RRC\n");
                pointer++;
                break;
                
            case LXID:
                printf("LXI     D, #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
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
                printf("MVI     D, #$%02hhX\n", buffer[pointer+1]);
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
                printf("MVI     E, #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RAR:
                printf("RAR\n");
                pointer++;
                break;
                
            case LXIH:
                printf("LXI     H, #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case SHLD:
                printf("SHLD    #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
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
                printf("MVI     H, #$%02hhX\n", buffer[pointer+1]);
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
                printf("LHLD    ($%02hhX%02hhX)\n", buffer[pointer+2], buffer[pointer+1]);
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
                printf("MVI     L, #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case CMA:
                printf("CMA\n");
                pointer++;
                break;
                
            case LXISP:
                printf("LXI     SP, #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case STA:
                printf("STA     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
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
                printf("MVI     M, #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
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
                printf("LDA     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
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
                printf("MVI     A, #$%02hhX\n", buffer[pointer+1]);
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

            case SUBB:
                printf("SUB     B\n");
                pointer++;
                break;
                
            case SUBC:
                printf("SUB     C\n");
                pointer++;
                break;
                
            case SUBD:
                printf("SUB     D\n");
                pointer++;
                break;
                
            case SUBE:
                printf("SUB     E\n");
                pointer++;
                break;
                
            case SUBH:
                printf("SUB     H\n");
                pointer++;
                break;
                
            case SUBL:
                printf("SUB     L\n");
                pointer++;
                break;
                
            case SUBM:
                printf("SUB     M\n");
                pointer++;
                break;
                
            case SUBA:
                printf("SUB     A\n");
                pointer++;
                break;

            case SBBB:
                printf("SBB     B\n");
                pointer++;
                break;
                
            case SBBC:
                printf("SBB     C\n");
                pointer++;
                break;
                
            case SBBD:
                printf("SBB     D\n");
                pointer++;
                break;
                
            case SBBE:
                printf("SBB     E\n");
                pointer++;
                break;
                
            case SBBH:
                printf("SBB     H\n");
                pointer++;
                break;
                
            case SBBL:
                printf("SBB     L\n");
                pointer++;
                break;
                
            case SBBM:
                printf("SBB     M\n");
                pointer++;
                break;
                
            case SBBA:
                printf("SBB     A\n");
                pointer++;
                break;
            
            case ANAB:
                printf("ANA     B\n");
                pointer++;
                break;
                
            case ANAC:
                printf("ANA     C\n");
                pointer++;
                break;
                
            case ANAD:
                printf("ANA     D\n");
                pointer++;
                break;
                
            case ANAE:
                printf("ANA     E\n");
                pointer++;
                break;
                
            case ANAH:
                printf("ANA     H\n");
                pointer++;
                break;
                
            case ANAL:
                printf("ANA     L\n");
                pointer++;
                break;
                
            case ANAM:
                printf("ANA     M\n");
                pointer++;
                break;
                
            case ANAA:
                printf("ANA     A\n");
                pointer++;
                break;
                
            case XRAB:
                printf("XRA     B\n");
                pointer++;
                break;
                
            case XRAC:
                printf("XRA     C\n");
                pointer++;
                break;
                
            case XRAD:
                printf("XRA     D\n");
                pointer++;
                break;
                
            case XRAE:
                printf("XRA     E\n");
                pointer++;
                break;
                
            case XRAH:
                printf("XRA     H\n");
                pointer++;
                break;
                
            case XRAL:
                printf("XRA     L\n");
                pointer++;
                break;
                
            case XRAM:
                printf("XRA     M\n");
                pointer++;
                break;
                
            case XRAA:
                printf("XRA     A\n");
                pointer++;
                break;
                
            case ORAB:
                printf("ORA     B\n");
                pointer++;
                break;
                
            case ORAC:
                printf("ORA     C\n");
                pointer++;
                break;
                
            case ORAD:
                printf("ORA     D\n");
                pointer++;
                break;
                
            case ORAE:
                printf("ORA     E\n");
                pointer++;
                break;
                
            case ORAH:
                printf("ORA     H\n");
                pointer++;
                break;
                
            case ORAL:
                printf("ORA     L\n");
                pointer++;
                break;
                
            case ORAM:
                printf("ORA     M\n");
                pointer++;
                break;
                
            case ORAA:
                printf("ORA     A\n");
                pointer++;
                break;
                
            case CMPB:
                printf("CMP     B\n");
                pointer++;
                break;
                
            case CMPC:
                printf("CMP     C\n");
                pointer++;
                break;
                
            case CMPD:
                printf("CMP     D\n");
                pointer++;
                break;
                
            case CMPE:
                printf("CMP     E\n");
                pointer++;
                break;
                
            case CMPH:
                printf("CMP     H\n");
                pointer++;
                break;
                
            case CMPL:
                printf("CMP     L\n");
                pointer++;
                break;
                
            case CMPM:
                printf("CMP     M\n");
                pointer++;
                break;
                
            case CMPA:
                printf("CMP     A\n");
                pointer++;
                break;
                
            case RNZ:
                printf("RNZ\n");
                pointer++;
                break;
                
            case POPB:
                printf("POP     B\n");
                pointer++;
                break;
                
            case JNZ:
                printf("JNZ     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case JMP:
                printf("JMP     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case CNZ:
                printf("CNZ     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case PUSHB:
                printf("PUSH    B\n");
                pointer++;
                break;
                
            case ADI:
                printf("ADI     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RST0:
                printf("RST     0\n");
                pointer++;
                break;
                
            case RZ:
                printf("RZ\n");
                pointer++;
                break;
                
            case RET:
                printf("RET\n");
                pointer++;
                break;
                
            case JZ:
                printf("JZ      #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case CZ:
                printf("CZ      #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case CALL:
                printf("CALL    #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case ACI:
                printf("ACI     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RST1:
                printf("RST     1\n");
                pointer++;
                break;
                
            case RNC:
                printf("RNC\n");
                pointer++;
                break;
                
            case POPD:
                printf("POP     D\n");
                pointer++;
                break;
                
            case JNC:
                printf("JNC     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case OUT:
                printf("OUT     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case CNC:
                printf("CNC     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case PUSHD:
                printf("PUSH    D\n");
                pointer++;
                break;
                
            case SUI:
                printf("SUI     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RST2:
                printf("RST     2\n");
                pointer++;
                break;
                
            case RC:
                printf("RC\n");
                pointer++;
                break;
                
            case JC:
                printf("JC      #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case IN:
                printf("IN      #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case CC:
                printf("CC      #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case SBI:
                printf("SBI     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RST3:
                printf("RST     3\n");
                pointer++;
                break;
                
            case RPO:
                printf("RPO\n");
                pointer++;
                break;
                
            case POPH:
                printf("POP     H\n");
                pointer++;
                break;
                
            case JPO:
                printf("JPO     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case XTHL:
                printf("XTHL\n");
                pointer++;
                break;
                
            case CPO:
                printf("CPO     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case PUSHH:
                printf("PUSH    H\n");
                pointer++;
                break;
                
            case ANI:
                printf("ANI     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RST4:
                printf("RST     4\n");
                pointer++;
                break;
                
            case RPE:
                printf("RPE\n");
                pointer++;
                break;
                
            case PCHL:
                printf("PCHL\n");
                pointer++;
                break;
                
            case JPE:
                printf("JPE     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case XCHG:
                printf("XCHG\n");
                pointer++;
                break;
                
            case CPE:
                printf("CPE     #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case XRI:
                printf("XRI     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RST5:
                printf("RST     5\n");
                pointer++;
                break;
                
            case RP:
                printf("RP\n");
                pointer++;
                break;
                
            case POPPSW:
                printf("POP     PSW\n");
                pointer++;
                break;
                
            case JP:
                printf("JP      #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case DI:
                printf("DI\n");
                pointer++;
                break;
                
            case CP:
                printf("CP      #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case PUSHPSW:
                printf("PUSH    PSW\n");
                pointer++;
                break;
                
            case ORI:
                printf("ORI     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RST6:
                printf("RST     6\n");
                pointer++;
                break;
                
            case RM:
                printf("RM\n");
                pointer++;
                break;
                
            case SPHL:
                printf("SPHL\n");
                pointer++;
                break;
                
            case JM:
                printf("JM      #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case EI:
                printf("EI\n");
                pointer++;
                break;
                
            case CM:
                printf("CM      #$%02hhX%02hhX\n", buffer[pointer+2], buffer[pointer+1]);
                pointer+=3;
                break;
                
            case CPI:
                printf("CPI     #$%02hhX\n", buffer[pointer+1]);
                pointer+=2;
                break;
                
            case RST7:
                printf("RST     7\n");
                pointer++;
                break;
                
            default:
                printf("CODE %02hhX\n", buffer[pointer]);            
                pointer++;
                break;
        }
    }
}

