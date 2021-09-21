#include <cstring>

#include "CPU.h"

CPU::CPU() {
    for(int i = 0; i < sizeof(memory); i++)
    {
        memory[i] = 0;
    }
}

void CPU::loadProgram(unsigned char *program, int size)
{
    memcpy(memory,program,size);
}

void CPU::run()
{
    while(!HLT)
    {
        
    }
}

void CPU::executeOperation()
{
    
}
