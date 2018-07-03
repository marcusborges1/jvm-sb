#include <Instruction.h>
#include <MethodInfo.h>
#include "Interpreter.h"

/**
* @brief Função executar interpretação do arquivo .class
* @param JavaClass class_file
*/
void Interpreter::execute(JavaClass class_file ) {
    Instruction instructions[256];
    Instruction::setup_instructions(instructions);

    MethodInfo *method = method->find_main(class_file);

    // Frame *frame = new Frame(methodInfo, classFile);
    // this->frameStack.push(frame);
    //
    // printf("=========================================\n");
    // printf("======    JAVA CONSOLE START      =======\n");
    // printf("=========================================\n");
    // while(!this->frameStack.empty()){
    //     this->frameStack.top()->executeFrame();
    // }
    // printf("=========================================\n");
    // printf("======     JAVA CONSOLE END       =======\n");
    // printf("=========================================\n");

}
