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

unsigned char X64InstrMov();
unsigned char X64InstrAdd();
unsigned char X64InstrSub();
unsigned char X64InstrMul();
unsigned char X64InstrDiv();
unsigned char X64InstrInc();
unsigned char X64InstrDec();
unsigned char X64InstrNeg();
unsigned char X64InstrCmp();
unsigned char X64InstrJmp();
unsigned char X64InstrAnd();
unsigned char X64InstrOr();
unsigned char X64InstrXor();
unsigned char X64InstrNot();
unsigned char X64InstrCall();
unsigned char X64InstrRet();

#endif
