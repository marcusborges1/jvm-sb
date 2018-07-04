/** @file Interpreter.cpp
 *  @brief ...
 *  @bug No know bugs.
 */
#include "MethodInfo.h"
#include "Instruction.h"
#include "Interpreter.h"
#include "Frame.h"
#include "stack"


Frame* current_frame = NULL;
std::stack<Frame*> frame_stack;
int class_count = 0;

/**
* @brief Função executar interpretação do arquivo .class
* @param JavaClass class_file
*/
void Interpreter::execute(JavaClass class_file) {
  Instruction instructions[256];
  // Interpreter *interpreter = new Interpreter();
  Instruction::setup_instructions(instructions);
  Frame::setup_instructions_func();

  // JavaClass** class_array = (Java  Class**)malloc(sizeof(JavaClass*));
  // interpreter->load_class(class_array, class_file);

  MethodInfo *method = new MethodInfo();
  method->find_main(class_file);

  Frame *frame = new Frame(method, class_file.constant_pool);
  current_frame = frame;
  frame_stack.push(frame);

  printf("=========================================\n");
  printf("======         JVM START          =======\n");
  printf("=========================================\n");

  // se frame não estiver vazio
  while (!(frame_stack.empty())) {
    // coleta frame do topo (FIFO)
    current_frame = frame_stack.top();
    current_frame->execute_frame();
    frame_stack.pop();
  }
  printf("=========================================\n");
  printf("======          JVM END           =======\n");
  printf("=========================================\n");
}


// void Interpreter::load_class_var(ClassInstance *class_instance) {
//   class_instance->fields_class = new std::map<std::string,Operand*>();
//
//     JavaClass *loaded_class = class_instance->info_class;
//
//     CpInfo &info_super_class = loaded_class->constant_pool[
//                                                   loaded_class->super_class-1];
//
//     std::string name_super_class = info_super_class.get_utf8_constant_pool(
//         loaded_class->constant_pool, info_super_class.Class.type_class_info-1);
//     do {
//         name_super_class = info_super_class.get_utf8_constant_pool(
//                     loaded_class->constant_pool, loaded_class->super_class-1);
//         for (int i = 0; i < loaded_class->fields_count; i++) {
//             FieldInfo &field_add = loaded_class->fields[i];
//
//             std::string name_field = info_super_class.get_utf8_constant_pool(
//                         loaded_class->constant_pool, field_add.name_index-1);
//             std::string type_variable = info_super_class.get_utf8_constant_pool(
//                     loaded_class->constant_pool, field_add.descriptor_index-1);
//
//             (*class_instance->fields_class)[
//                         name_field] = check_string_create_type(type_variable);
//         }
//         // if (name_super_class != "java/lang/Object" && name_super_class != "") {
//             // loaded_class = this->getClassInfoAndLoadIfNotExists(name_super_class);
//         // }
//     } while(name_super_class != "java/lang/Object");
// }

// void Interpreter::load_class(JavaClass** class_array, JavaClass class_file) {
//     class_count++;
//     if (class_count != 1)
//       (JavaClass**)realloc(class_array, sizeof(JavaClass*)*class_count);
//
//     class_array[(class_count - 1)] = &class_file;
//     return;
// }
