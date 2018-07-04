/** @file Interpreter.h
 *  @brief ...
 *  @bug No know bugs.
 */
#ifndef JVM_CPP_INTERPRETER_H
#define JVM_CPP_INTERPRETER_H

#include "JavaClass.h"
#include "AttributeInfo.h"
#include "Frame.h"


/**
 * @brief ...
 **/
class Interpreter {
public:
  void execute(JavaClass);
  void load_class(JavaClass**, JavaClass);
  void load_class_var(ClassInstance *class_instance);
};

#endif
