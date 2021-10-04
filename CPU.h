#ifndef CPU_H
#define CPU_H
#include <stdint.h>

class CPU {
public:
    //Constructor
    CPU();
    
    void loadProgram(unsigned char *program, int size);
    
    void run();    
    
private:
    //Program counter
    int pc;
    
    //Registers
    uint8_t registerA;
    uint8_t registerB;
    uint8_t registerC;
    uint8_t registerD;
    uint8_t registerE;
    uint8_t registerH;
    uint8_t registerL;
    
    //Stack Pointer
    int sp;
    
    //Memory
    uint8_t memory[0x6000];
            
    //Condition Bits
    bool C;    //Carry Bit
    bool AC;    //Auxiliary Carry Bit
    bool S;    //Sign Bit
    bool Z;    //Zero Bit
    bool P;    //Parity Bit
    
    bool HLT;   //Halt Flag
    
    bool interruptsEnabled;
    
    int executeOperation();
    
    void unimplementedInstruction();
    
    int parity(uint8_t value);

};

#endif /* CPU_H */

