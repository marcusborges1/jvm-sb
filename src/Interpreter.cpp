#include "MethodInfo.h"
#include "Instruction.h"
#include "Interpreter.h"
#include "Frame.h"
#include "stack"

/**
* @brief Função executar interpretação do arquivo .class
* @param JavaClass class_file
*/
void Interpreter::execute(JavaClass class_file ) {
    Instruction instructions[256];
    Instruction::setup_instructions(instructions);

    MethodInfo *method = method->find_main(class_file);
    std::stack<Frame*> frame_stack;

    Frame *frame = new Frame(method, class_file.constant_pool);
    Frame* current_frame = frame;
    frame_stack.push(frame);
    // this->frameStack.push(frame);
    //
      printf("=========================================\n");
      printf("======    JAVA CONSOLE START      =======\n");
      printf("=========================================\n");
      while(!(frame_stack.empty())){
        current_frame = frame_stack.top();
        printf("TEM COISA NO STACK\n");
        printf("EXECUTA\n");
        frame_stack.pop();
      }
      printf("=========================================\n");
      printf("======     JAVA CONSOLE END       =======\n");
      printf("=========================================\n");

}
