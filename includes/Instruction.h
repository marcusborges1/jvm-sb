#ifndef JVM_CPP_INSTRUCTION_H
#define JVM_CPP_INSTRUCTION_H

#include <string>
#include "JavaClass.h"

class Instruction {
public:
    std::string name;
    u4 bytes;
    u4 constant_pool_flag;
    static void setup_instructions(Instruction*);
};

#endif
