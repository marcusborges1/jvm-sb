#include "InstructionsFunc.h"
#include "CpInfo.h"


/** @brief ...
 * param *curr_frame ponteiro para o frame atual
 * @return void
 */
void nop(Frame *curr_frame){
  curr_frame->pc++;
}

/** @brief Coloca na pilha de operandos uma constante do tamanho de uma word.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void ldc(Frame *curr_frame) {
  Operand *op = (Operand*)malloc(sizeof(Operand));
  curr_frame->pc++;

  u1 index = curr_frame->method_code->code[curr_frame->pc];

  CpInfo &cpinfo = curr_frame->constant_pool_reference[index-1];
  op->tag = cpinfo.tag;
  switch (op->tag) {
    case CONSTANT_Integer:
        op->type_int = cpinfo.Integer.bytes;
        break;
    case CONSTANT_Float:
        op->type_float = cpinfo.Float.bytes;
        break;
    case CONSTANT_String: {
        std::string utf8_s = cpinfo.get_utf8_constant_pool(
                                          curr_frame->constant_pool_reference,
                                          cpinfo.String.bytes-1);
        op->type_string = new std::string(utf8_s); }
        break;
    default:
        // CONSTANT_Class
        // Constant_Method_Handle
        // Constant_Method_Ref
        break;
    }
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Guarda referência do object ou array do operando na variável local 1.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void astore_1(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *op = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(2) = op;
}
