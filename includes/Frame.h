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
#include <map>

typedef struct Operand Operand;

 struct Operand {
   u1 tag; // CONSTANT_Integer, CONSTANT_Float, etc
   union{
     u4 type_bool;
     u4 type_byte;
     u4 type_char;
     u4 type_short;
     u4 type_int;
     u4 type_float;
     u8 type_long;
     u8 type_double;
     std::string* type_string;
   };
 };

 /** @brief Estrutura para instanciar a classe
  */
 typedef struct {
     // ponteiro com o nome da classe
     std::string *name_class;
     // ponteiro com informacoes da classe
     JavaClass info_class;
     // vetor com as referencias dos campos da classe
     std::map<std::string, Operand*> *fields_class;
 } ClassInstance;

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

    std::vector<Operand*> local_variables_array;
    std::stack<Operand*> operand_stack;
    CpInfo* constant_pool_reference;
    CodeAttribute* method_code;
    MethodInfo* method_info;
    u4 pc;

    void execute_frame();
    Operand* pop_operand();
    void push_operand(Operand* op);
    static void setup_instructions_func();
};

Operand* check_string_create_type(std::string string_tipo);

#endif
