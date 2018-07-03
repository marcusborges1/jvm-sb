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

    std::cout << current_frame->method_code.code_length << std::endl;
    // enquanto frame não chegar ao final
    while(current_frame->pc < current_frame->method_code.code_length) {
      // coleta o primeiro opcode
      u1 op_code = current_frame->method_code.code[current_frame->pc];
      std::cout << instructions[op_code].name << std::endl;
      // execute_instruction(op_code);
      current_frame->pc++;
    }

    frame_stack.pop();
  }
  printf("=========================================\n");
  printf("======          JVM END           =======\n");
  printf("=========================================\n");
}
