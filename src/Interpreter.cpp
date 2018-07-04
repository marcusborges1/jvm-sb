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

/**
* @brief Função executar interpretação do arquivo .class
* @param JavaClass class_file
*/
void Interpreter::execute(JavaClass class_file) {
  Instruction instructions[256];
  Instruction::setup_instructions(instructions);
  Frame::setup_instructions_func();

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




void Interpreter::carrega_variavel_classe(InstanciaClasse *class_instance)
{
  class_instance->campos_class = new std::map<std::string,Operand*>();

    JavaClass *classe_carregada = class_instance->info_class;

    CpInfo &info_super_class = classe_carregada->constant_pool[classe_carregada->super_class - 1];

    std::string name_super_class = info_super_class->get_utf8_constant_pool(classe_carregada->constant_pool, info_super_class.Class.type_class_info - 1);
    do{
        name_super_class = info_super_class->get_utf8_constant_pool(classe_carregada->constant_pool, classe_carregada->super_class-1);
        for (int i = 0; i < classe_carregada->fields_count; i++) {
            FieldInfo &field_add = classe_carregada->fields[i];

            std::string name_field = info_super_class->get_utf8_constant_pool(classe_carregada->constant_pool, field_add.name_index - 1);
            std::string type_variable = info_super_class->get_utf8_constant_pool(classe_carregada->constant_pool, field_add.descriptor_index - 1);

            (*class_instance->campos_class)[name_field] = criaTipoAPartirString(tpVariavel);
        }
        if(name_super_class != "java/lang/Object" && name_super_class != ""){
            classe_carregada = this->getClassInfoAndLoadIfNotExists(name_super_class);
        }
    }while(name_super_class != "java/lang/Object");
}
}
