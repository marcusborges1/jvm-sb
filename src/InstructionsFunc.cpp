#include "InstructionsFunc.h"
#include "Interpreter.h"
#include "CpInfo.h"

Interpreter *interpreter = new Interpreter();

/** @brief Não faz nada, só incrementa pc.
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

  u1 index = curr_frame->method_code.code[curr_frame->pc];

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

/** @brief Coloca na pilha de operandos a variável da posição 0 do vetor de
 *          variáveis locais.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void aload_0(Frame *curr_frame) {
	// incrementa pc
	curr_frame->pc++;
	// coloca variável na pilha
	curr_frame->push_operand(curr_frame->local_variables_array.at(0));
}

/** @brief Guarda referência do object ou array do operando na variável local 1.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void astore_1(Frame *curr_frame) {
  curr_frame->pc++;
  Operand *op = curr_frame->pop_operand();
  curr_frame->local_variables_array.at(1) = op;
}

/** @brief ...
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void invokespecial(Frame *curr_frame) {
	//incrementa pc
	curr_frame->pc++;

	u2 index_method = curr_frame->method_code.code[curr_frame->pc];
	index_method = (index_method << 8) + curr_frame->method_code.code[
                                                          ++curr_frame->pc];

	CpInfo &ref_method = curr_frame->constant_pool_reference[index_method-1];
	CpInfo &name_and_type = curr_frame->constant_pool_reference[
                                      ref_method.MethodRef.name_and_type-1];

	std::string class_name = ref_method.get_utf8_constant_pool(
          curr_frame->constant_pool_reference, ref_method.MethodRef.index -1);
	std::string method_name = ref_method.get_utf8_constant_pool(
                                    curr_frame->constant_pool_reference,
                                    name_and_type.NameAndType.name_index - 1);
	std::string method_descriptor = ref_method.get_utf8_constant_pool(
                                curr_frame->constant_pool_reference,
                                name_and_type.NameAndType.descriptor_index -1);

  //incrementa pc
	curr_frame->pc++;
}

/** @brief ...
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_1(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 1;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra o valor NULL na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void aconst_null(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_EmptySpace;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_m1(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = -1;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_0(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 0;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_2(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 2;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_3(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 3;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_4(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 4;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief Empurra int na pilha de operandos
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void iconst_5(Frame* curr_frame) {
    Operand *op = (Operand*)malloc(sizeof(Operand));
    op->tag = CONSTANT_Integer;
    op->type_int = 5;
    curr_frame->push_operand(op);
    curr_frame->pc++;
}

/** @brief ...
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void getfield(Frame *curr_frame) {
  u1 byte1 = curr_frame->method_code.code[curr_frame->pc++];
  u1 byte2 = curr_frame->method_code.code[curr_frame->pc++];

  u2 index = (byte1<<8) | byte2;

  CpInfo field_ref = curr_frame->constant_pool_reference[index-1];
  CpInfo name_and_type = curr_frame->constant_pool_reference[
                                  field_ref.FieldRef.name_and_type_index-1];

  std::string class_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
        curr_frame->constant_pool_reference, field_ref.FieldRef.class_index-1);
  std::string field_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
    curr_frame->constant_pool_reference, name_and_type.NameAndType.name_index-1);

  curr_frame->operand_stack.pop();

  // curr_frame->pushOperand(classVariable);
}

/**
 * @brief Recebe um campo estático a partir de uma classe.
 * @param *curr_frame ponteiro para o frame atual
 * @return void
 */
void getstatic(Frame *curr_frame) {
    curr_frame->pc++;

    u2 index = curr_frame->method_code.code[curr_frame->pc++];
    index = (index << 8) + curr_frame->method_code.code[curr_frame->pc++];

    CpInfo &field_info = curr_frame->constant_pool_reference[index-1];
    CpInfo &name_and_type = curr_frame->constant_pool_reference[
                                  field_info.FieldRef.name_and_type_index-1];
    std::string class_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
      curr_frame->constant_pool_reference, field_info.FieldRef.class_index-1);

    if (class_name == "java/lang/System") {
        // se for a classe System (default java) não coloca na pilha
        return;
    }

    JavaClass class_info = get_class_info_and_load_not_exists(class_name);
    std::string var_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(
                                      class_info.constant_pool,
                                      name_and_type.NameAndType.name_index-1);

    Operand *static_field = get_static_field_of_class(class_name, var_name);

    curr_frame->push_operand(static_field);
}


// void fsub(Frame *curr_frame){
//   float f1, f2, f3;
//   u4 a1,a2,a3;
//
//   // Get First Argument
//   a2 = curr_frame->operand_stack.top();
//   curr_frame->operand_stack.pop();
//   // Get second Argument
//   a1 = curr_frame->operand_stack.top();
//   curr_frame->operand_stack.pop();
//   // convert u4 to float
//   memcpy(&f2, &a2, sizeof(f2));
//   memcpy(&f1, &a1, sizeof(f1));
//   f3 = f1 - f2;
//   // convert float to u4
//   memcpy(&a3, &f3, sizeof(a3));
//   curr_frame->operand_stack.push(a3);
//
//   curr_frame->pc++;
// }
//
