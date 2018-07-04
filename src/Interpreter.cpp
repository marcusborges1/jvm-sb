/** @file Interpreter.cpp
 *  @brief ...
 *  @bug No know bugs.
 */
#include "ClassFileReader.h"
#include "Interpreter.h"
#include "Instruction.h"
#include "MethodInfo.h"
#include "Frame.h"
#include "stack"


Frame* current_frame = NULL;
std::stack<Frame*> frame_stack;

/**
* @brief Função que executa a interpretação do arquivo .class.
* @param class_file informações do arquivo .class.
* @return void
*/
void Interpreter::execute(JavaClass class_file) {
  Instruction instructions[256];
  Instruction::setup_instructions(instructions);
  Frame::setup_instructions_func();
  load_class_memory(class_file);

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

/**
 * @brief Carrega classe para a memória.
 * @param *class_file informações do arquivo .class.
 * @return ClassInstance* ponteiro para instância de uma classe
 */
ClassInstance* Interpreter::load_class_memory(JavaClass class_file) {
    ClassInstance *c_instance = (ClassInstance*)malloc(
                                                        sizeof(ClassInstance));
    c_instance->info_class = class_file;
    std::string utf8_s = cpinfo->get_utf8_constant_pool(class_file.constant_pool,
                                                    class_file.this_class-1);
    c_instance->name_class = &utf8_s;
    loaded_classes.insert(
                (std::pair<std::string, ClassInstance*>(utf8_s, c_instance)));

    static_classes.insert(
                (std::pair<std::string, ClassInstance*>(utf8_s, c_instance)));
    load_class_var(c_instance);

    return c_instance;
}

/**
 * @brief Carrega variáveis com informações do .class.
 * @param *class_instance ponteiro para instância de uma classe
 * @return void
 */
void Interpreter::load_class_var(ClassInstance *class_instance) {
  class_instance->fields_class = new std::map<std::string, Operand*>();

  JavaClass current_class = class_instance->info_class;

  CpInfo &info_super_class = current_class.constant_pool[
                                              current_class.super_class-1];

  std::string name_super_class = info_super_class.get_utf8_constant_pool(
      current_class.constant_pool, info_super_class.Class.type_class_info-1);
  do {
      name_super_class = info_super_class.get_utf8_constant_pool(
                  current_class.constant_pool, current_class.super_class-1);
      for (int i = 0; i < current_class.fields_count; i++) {
          FieldInfo &field_add = current_class.fields[i];

          std::string name_field = info_super_class.get_utf8_constant_pool(
                      current_class.constant_pool, field_add.name_index-1);
          std::string type_variable = info_super_class.get_utf8_constant_pool(
                  current_class.constant_pool, field_add.descriptor_index-1);

          (*class_instance->fields_class)[
                      name_field] = check_string_create_type(type_variable);
      }
      if (name_super_class != "java/lang/Object" && name_super_class != "")
          current_class = get_class_info_and_load_not_exists(
                                                          name_super_class);
  } while (name_super_class != "java/lang/Object");
}

JavaClass Interpreter::get_class_info_and_load_not_exists(std::string c_path) {
    ClassInstance *c_instance = static_classes[c_path];
    ClassFileReader *reader = new ClassFileReader();

    if (c_instance == NULL){
        // verifica se a classe está no mesmo diretorio atual
        std::string filepath = current_path_folder+c_path+ ".class";
        JavaClass class_file = reader->read_class_file(filepath);
        c_instance = load_class_memory(class_file);
    }
    return c_instance->info_class;
}
