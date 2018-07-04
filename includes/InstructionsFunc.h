#ifndef INSTRUCTIONS_FUNC_H
#define INSTRUCTIONS_FUNC_H

#include "Frame.h"

void nop(Frame *curr_frame);
void get_field(Frame *curr_frame);
void aaload(Frame *curr_frame);
void aconst_null(Frame*);

#endif
