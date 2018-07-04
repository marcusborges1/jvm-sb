#ifndef INSTRUCTIONS_FUNC_H
#define INSTRUCTIONS_FUNC_H

#include "Frame.h"

void nop(Frame *curr_frame);
void get_field(Frame *curr_frame);
void aaload(Frame *curr_frame);
void aconst_null(Frame*);
void iconst_m1(Frame*);
void iconst_0(Frame*);
void iconst_1(Frame*);
void iconst_2(Frame*);
void iconst_3(Frame*);
void iconst_4(Frame*);
void iconst_5(Frame*);
#endif
