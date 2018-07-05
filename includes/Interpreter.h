/** @file Interpreter.h
 *  @brief Declarações das funções do interpretador da JVM.
 *  @bug No know bugs.
 */
#ifndef JVM_CPP_INTERPRETER_H
#define JVM_CPP_INTERPRETER_H

#include "AttributeInfo.h"
#include "JavaClass.h"
#include "CpInfo.h"
#include "Frame.h"
#include <map>
#include <stack>
#include <string>


/**
 * @brief Interpretador da JVM.
 **/
class Interpreter {
public:
  std::string current_path_folder;

  void execute(JavaClass class_file);
};

ClassInstance* load_class_memory(JavaClass class_file);
void load_class_var(ClassInstance *class_instance);
JavaClass get_class_info_and_load_not_exists(std::string c_path);
Operand* get_static_field_of_class(std::string class_name,
                                    std::string field_name);
void push_frame(Frame *frame);
void pop_frame();
Frame* top_frame();
ClassInstance* get_static_class(std::string class_name);

#endif
