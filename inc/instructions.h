#ifndef _INSTRUCTIONS_H
#define _INSTRUCTIONS_H

#define INSTR_MOV "mov"
#define INSTR_ADD "add"
#define INSTR_SUB "sub"
#define INSTR_MUL "mul"
#define INSTR_DIV "div"
#define INSTR_INC "inc"
#define INSTR_DEC "dec"
#define INSTR_NEG "neg"
#define INSTR_CMP "cmp"
#define INSTR_JMP "jmp"
#define INSTR_AND "and"
#define INSTR_OR "or"
#define INSTR_XOR "xor"
#define INSTR_NOT "not"
#define INSTR_CALL "call"
#define INSTR_RET "ret"

unsigned char instr_mov();
unsigned char instr_add();
unsigned char instr_sub();
unsigned char instr_mul();
unsigned char instr_div();
unsigned char instr_inc();
unsigned char instr_dec();
unsigned char instr_neg();
unsigned char instr_cmp();
unsigned char instr_jmp();
unsigned char instr_and();
unsigned char instr_or();
unsigned char instr_xor();
unsigned char instr_not();
unsigned char instr_call();
unsigned char instr_ret();

#endif
