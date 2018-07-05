#ifndef INSTRUCTIONS_FUNC_H
#define INSTRUCTIONS_FUNC_H

#include "Frame.h"

void nop(Frame *curr_frame);
void ldc(Frame *curr_frame);
void invokespecial(Frame *curr_frame);
void invokevirtual(Frame *curr_frame);
void astore_1(Frame *curr_frame);
void getstatic(Frame *curr_frame);
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
void void_return(Frame *curr_frame);
void iinc(Frame *curr_frame);
void iload(Frame *curr_frame);
void iload_0(Frame *curr_frame);
void iload_1(Frame *curr_frame);
void iload_2(Frame *curr_frame);
void iload_3(Frame *curr_frame);
void lconst_0(Frame*);
void lconst_1(Frame*);
void fconst_0(Frame*);
void fconst_1(Frame*);
void fconst_2(Frame*);
void dconst_0(Frame*);
void dconst_1(Frame*);
void bipush(Frame*);
void sipush(Frame*);
void lload_0(Frame*);
void lload_1(Frame*);
void lload_2(Frame*);
void lload_3(Frame*);
void fload_0(Frame*);
void fload_1(Frame*);
void fload_2(Frame*);
void fload_3(Frame*);
void lload(Frame*);
void dload(Frame*);
void dload_0(Frame*);
void dload_1(Frame*);
void dload_2(Frame*);
void dload_3(Frame*);
void dstore(Frame*);
void dstore_0(Frame*);
void dstore_1(Frame*);
void dstore_2(Frame*);
void dstore_3(Frame*);
void fstore(Frame*);
void fstore_0(Frame*);
void fstore_1(Frame*);
void fstore_2(Frame*);
void fstore_3(Frame*);
void lstore(Frame*);
void lstore_0(Frame*);
void lstore_1(Frame*);
void lstore_2(Frame*);
void lstore_3(Frame*);
void fload(Frame*);
void istore(Frame *curr_frame);
void istore_0(Frame *curr_frame);
void istore_1(Frame *curr_frame);
void istore_2(Frame *curr_frame);
void istore_3(Frame *curr_frame);


void if_icmpge(Frame*);
void ins_goto(Frame*);
void i2l(Frame*);


#endif
