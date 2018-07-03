/** @file Frame.h
 *  @brief ...
 *  @bug No know bugs.
 */
#ifndef JVM_CPP_FRAME_H
#define JVM_CPP_FRAME_H

#include "JavaClass.h"
#include "AttributeInfo.h"
#include <stack>
#include <vector>


/**
 * @brief O Frame armazena dados e resultados parciais, para executar
 *  ligação dinâmica,retornar valores para métodos e disparar exceções.
 *  Cada frame possui seu próprio array de variáveis locais, sua pilha de
 *  operandos e uma referência para o pool de constantes da classe do método
 *  corrente.
 **/
class Frame {
  public:
    Frame(MethodInfo*, CpInfo*);

    CpInfo* constant_pool_reference;
    MethodInfo* method_info;
    CodeAttribute method_code;
    u4 pc;
    std::vector<u4> local_variables_array;

    std::stack<u4> operand_stack;
    Frame* caller;
    void execute_frame();
    static void setup_instructions_func();
};

#endif
