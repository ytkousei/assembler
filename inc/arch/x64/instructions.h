#ifndef _X64_INSTRUCTIONS_H
#define _X64_INSTRUCTIONS_H

#include <gen/instruction.h>

#define X64_INSTR_MOV "mov"
#define X64_INSTR_ADD "add"
#define X64_INSTR_SUB "sub"
#define X64_INSTR_MUL "mul"
#define X64_INSTR_DIV "div"
#define X64_INSTR_INC "inc"
#define X64_INSTR_DEC "dec"
#define X64_INSTR_NEG "neg"
#define X64_INSTR_CMP "cmp"
#define X64_INSTR_JMP "jmp"
#define X64_INSTR_AND "and"
#define X64_INSTR_OR "or"
#define X64_INSTR_XOR "xor"
#define X64_INSTR_NOT "not"
#define X64_INSTR_CALL "call"
#define X64_INSTR_RET "ret"

BinInstruction *X64InstrMov();
BinInstruction *X64InstrAdd();
BinInstruction *X64InstrSub();
BinInstruction *X64InstrMul();
BinInstruction *X64InstrDiv();
BinInstruction *X64InstrInc();
BinInstruction *X64InstrDec();
BinInstruction *X64InstrNeg();
BinInstruction *X64InstrCmp();
BinInstruction *X64InstrJmp();
BinInstruction *X64InstrAnd();
BinInstruction *X64InstrOr();
BinInstruction *X64InstrXor();
BinInstruction *X64InstrNot();
BinInstruction *X64InstrCall();
BinInstruction *X64InstrRet();

#endif
