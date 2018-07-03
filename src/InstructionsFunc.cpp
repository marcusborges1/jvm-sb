#include "InstructionsFunc.h"


/** @brief ...
@param Frame *currentFrame ponteiro para o frame atual
@return void
*/
void nop(Frame *curr_frame){
    curr_frame->pc++;
}
