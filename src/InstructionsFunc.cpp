#include "InstructionsFunc.h"
#include "Interpreter.h"

Interpreter *interpreter = new Interpreter();
/** @brief ...
// @param Frame *currentFrame ponteiro para o frame atual
@return void
*/
void nop(Frame *curr_frame){
    curr_frame->pc++;
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
void get_field(Frame *curr_frame){
  u1 byte1 = curr_frame->method_code.code[curr_frame->pc++];
  u1 byte2 = curr_frame->method_code.code[curr_frame->pc++];

  u2 index = (byte1<<8) | byte2;

  CpInfo field_ref = curr_frame->constant_pool_reference[index - 1];
  CpInfo nameAndType = curr_frame->constant_pool_reference[field_ref.FieldRef.name_and_type_index - 1];

  std::string class_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(curr_frame->constant_pool_reference, field_ref.FieldRef.class_index - 1);
  std::string field_name = curr_frame->constant_pool_reference->get_utf8_constant_pool(curr_frame->constant_pool_reference, nameAndType.NameAndType.name_index - 1);

  curr_frame->operand_stack.pop();

  // currentFrame->pushOperand(classVariable);
}
