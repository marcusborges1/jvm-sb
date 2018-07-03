/** @file Frame.h
 *  @brief ...
 *  @bug No know bugs.
 */
#ifndef JVM_CPP_FRAME_H
#define JVM_CPP_FRAME_H

#include "JavaClass.h"
#include "AttributeInfo.h"
#include "stack"

/**
 * @brief ...
 **/

class Frame {
  public:
    Frame();
    Frame(MethodInfo*, CpInfo*);
    u4* local_variables_array;
    std::stack<u4> operand_stack;
    CpInfo* constant_pool_reference;

    Frame* caller;
    MethodInfo* method;
    u4 pc;
    CodeAttribute code;
    void execute_frame();
};


#endif
