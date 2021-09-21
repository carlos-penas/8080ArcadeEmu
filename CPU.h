#ifndef CPU_H
#define CPU_H
#include <stdint.h>

class CPU {
public:
    //Constructor
    CPU();
    
    void loadProgram(unsigned char *program, int size);
    
    void run();
    
    void executeOperation();
    
    
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
    int stackPointer;
    
    //Memory
    uint8_t memory[0x6000];
            
    
    //Flags
    bool CF;
    bool ZF;
    bool HLT;

};

#endif /* CPU_H */

