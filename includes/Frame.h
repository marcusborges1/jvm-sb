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

 #define type_bool 1
 #define type_byte 2
 #define type_char 3
 #define type_short 4
 #define type_int 5
 #define type_float 6
 #define type_long 7
 #define type_double 8
 #define type_string 9
 #define type_reference 10
 #define type_array 11


 struct Operand{
     u1 tag;
     u4 variable;
 };


class Frame {
  public:
    Frame(MethodInfo*, CpInfo*);

    CpInfo* constant_pool_reference;
    MethodInfo* method_info;
    CodeAttribute method_code;
    u4 pc;
    std::vector<u4> local_variables_array;

    std::stack<Operand> operand_stack;
    Frame* caller;
    void execute_frame();
    static void setup_instructions_func();
};

#endif
