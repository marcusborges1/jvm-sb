/** @file Interpreter.h
 *  @brief ...
 *  @bug No know bugs.
 */
#ifndef JVM_CPP_INTERPRETER_H
#define JVM_CPP_INTERPRETER_H

#include "JavaClass.h"
#include "AttributeInfo.h"


//  struct MethodArea {
//   JavaClass** class_array;
//   int count;
// } ;


/**
 * @brief ...
 **/

 class Interpreter {
    public:
      void execute(JavaClass);
      void load_class(JavaClass**, JavaClass);
 };

#endif
