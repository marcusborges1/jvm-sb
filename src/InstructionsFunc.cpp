#include "InstructionsFunc.h"


/** @brief ...
@param Frame *currentFrame ponteiro para o frame atual
@return void
*/
void nop(Frame *curr_frame){
    curr_frame->pc++;
}

void fsub(Frame *curr_frame){
  float f1, f2, f3;
  u4 a1,a2,a3;

  // Get First Argument
  a2 = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();
  // Get second Argument
  a1 = curr_frame->operand_stack.top();
  curr_frame->operand_stack.pop();
  // convert u4 to float
  memcpy(&f2, &a2, sizeof(f2));
  memcpy(&f1, &a1, sizeof(f1));
  f3 = f1 - f2;
  // convert float to u4
  memcpy(&a3, &f3, sizeof(a3));
  curr_frame->operand_stack.push(a3);

  curr_frame->pc++;
}

void getfield(Frame *curr_frame){
  
}
