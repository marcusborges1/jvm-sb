/** @file Instruction.h
 *  @brief ...
 */
#ifndef JVM_CPP_INSTRUCTION_H
#define JVM_CPP_INSTRUCTION_H

/** @cond */
#include <string>
/** @endcond */
#include "JavaClass.h"


/**
 * @brief ...
 **/
class Instruction {
public:
    std::string name;
    u4 bytes;
    u4 constant_pool_flag;
    static void setup_instructions(Instruction*);
};

#endif
