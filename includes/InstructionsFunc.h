/** @file InstructionsFunc.h
 *  @brief ...
 */
#ifndef INSTRUCTIONS_FUNC_H
#define INSTRUCTIONS_FUNC_H

#include "Frame.h"

void nop(Frame *curr_frame);
void ldc(Frame *curr_frame);
void invokespecial(Frame *curr_frame);
void invokevirtual(Frame *curr_frame);
void astore_1(Frame *curr_frame);
void astore_2(Frame *curr_frame);
void astore_3(Frame *curr_frame);
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
void aload(Frame *curr_frame);
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
void dadd(Frame*);
void dsub(Frame*);
void dmul(Frame*);
void ddiv(Frame*);
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
void f2d(Frame *curr_frame);
void f2i(Frame *curr_frame);
void l2d(Frame *curr_frame);
void l2f(Frame *curr_frame);
void l2i(Frame *curr_frame);
void i2f(Frame *curr_frame);
void l2f(Frame *curr_frame);
void d2f(Frame *curr_frame);
void iadd(Frame *curr_frame);
void iand(Frame *curr_frame);
void d2f(Frame *curr_frame);
void d2l(Frame *curr_frame);
void d2i(Frame *curr_frame);
void ior(Frame *curr_frame);
void dup_x1(Frame *curr_frame);
void dup_x2(Frame *curr_frame);
void dup2(Frame *curr_frame);
void dup2_x1(Frame *curr_frame);
void dup2_x2(Frame *curr_frame);
void f2l(Frame *curr_frame);
void ladd(Frame *curr_frame);
void lsub(Frame *curr_frame);
void ldiv(Frame *curr_frame);
void laload(Frame *curr_frame);
void iaload(Frame *curr_frame);
void faload(Frame *curr_frame);
void daload(Frame *curr_frame);
void aaload(Frame *curr_frame);
void baload(Frame *curr_frame);
void caload(Frame *curr_frame);
void saload(Frame *curr_frame);

void lastore(Frame *curr_frame);
void fastore(Frame *curr_frame);
void dastore(Frame *curr_frame);
void aastore(Frame *curr_frame);
void bastore(Frame *curr_frame);
void castore(Frame *curr_frame);
void sastore(Frame *curr_frame);

void pop(Frame *curr_frame);
void pop2(Frame *curr_frame);

void astore(Frame *curr_frame);
void astore_0(Frame *curr_frame);

void if_icmpge(Frame*);
void ins_goto(Frame*);
void i2l(Frame*);
void i2d(Frame*);
void invokestatic(Frame *curr_frame);
void lreturn(Frame *curr_frame);
void new_obj(Frame *curr_frame);
void dup(Frame *curr_frame);

void putfield(Frame *curr_frame);

void ldc(Frame *curr_frame);
void ldc_w(Frame *curr_frame);
void ldc2_w(Frame *curr_frame);

void isub(Frame *curr_frame);
void invokeinterface(Frame *curr_frame);
void areturn(Frame *curr_frame);
void dreturn(Frame *curr_frame);
void freturn(Frame *curr_frame);
void ireturn(Frame *curr_frame);

void fadd(Frame *curr_frame);
void fsub(Frame *curr_frame);
void fdiv(Frame *curr_frame);
void fmul(Frame *curr_frame);
void frem(Frame *curr_frame);
void drem(Frame *curr_frame);
void fneg(Frame *curr_frame);
void lookupswitch(Frame *curr_frame);
void iconst_m1(Frame *curr_frame);

void if_icmpne(Frame *curr_frame);
void if_icmpeq(Frame *curr_frame);
void ifeq(Frame *curr_frame);
void ifne(Frame *curr_frame);
void iflt(Frame *curr_frame);
void ifge(Frame *curr_frame);
void ifgt(Frame *curr_frame);
void ifle(Frame *curr_frame);
void if_icmplt(Frame *curr_frame);
void if_icmpgt(Frame *curr_frame);
void if_icmple(Frame *curr_frame);
void if_acmpeq(Frame *curr_frame;
void if_acmpne(Frame *curr_frame);

void newarray(Frame*);
void iastore(Frame*);

void swap(Frame *curr_frame);
void imul(Frame *curr_frame);
void lmul(Frame *curr_frame);
void idiv(Frame *curr_frame);
void irem(Frame *curr_frame);
void lrem(Frame *curr_frame);
void ineg(Frame *curr_frame);
void lneg(Frame *curr_frame);
void dneg(Frame *curr_frame);
void ishl(Frame *curr_frame);
void lshl(Frame *curr_frame);
void ishr(Frame *curr_frame);
void lshr(Frame *curr_frame);
void iushr(Frame *curr_frame);
void lushr(Frame *curr_frame);
void land(Frame *curr_frame);
void lor(Frame *curr_frame);
void ixor(Frame *curr_frame);
void lxor(Frame *curr_frame);

void iinc(Frame *curr_frame);

void ret(Frame *curr_frame);

#endif
