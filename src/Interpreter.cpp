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
  Interpreter *interpreter = new Interpreter();
  Instruction::setup_instructions(instructions);
  Frame::setup_instructions_func();

  JavaClass** class_array;

  interpreter->load_class(class_array, class_file);
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


void Interpreter::load_class(JavaClass** class_array, JavaClass class_file) {
    class_count++;
    //
    if (class_count == 1)
      class_array = (JavaClass**)malloc(sizeof(JavaClass*));
    else
      (JavaClass**)realloc(class_array, sizeof(JavaClass*)*class_count);

    class_array[class_count] = &class_file;
    return;
}
