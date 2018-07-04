#ifndef INSTRUCTIONS_FUNC_H
#define INSTRUCTIONS_FUNC_H

#include "Frame.h"

void nop(Frame *curr_frame);
void ldc(Frame *curr_frame);
void invokespecial(Frame *curr_frame);
void invokevirtual(Frame *curr_frame);
void astore_1(Frame *curr_frame);
void getstatic(Frame *curr_frame);
void get_field(Frame *curr_frame);
void aaload(Frame *curr_frame);
void aconst_null(Frame *curr_frame);
void iconst_m1(Frame *curr_frame);
void iconst_0(Frame *curr_frame);
void iconst_1(Frame *curr_frame);
void iconst_2(Frame *curr_frame);
void iconst_3(Frame *curr_frame);
void iconst_4(Frame *curr_frame);
void iconst_5(Frame *curr_frame);
void getfield(Frame *curr_frame);
void aload_0(Frame *curr_frame);
void aload_1(Frame *curr_frame);
void aload_2(Frame *curr_frame);
void aload_3(Frame *curr_frame);

#endif
