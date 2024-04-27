#include <arch/x64/instructions.h>
#include <stdlib.h>

BinInstruction *X64InstrMov() { }

BinInstruction *X64InstrAdd() { }

BinInstruction *X64InstrSub() { }

BinInstruction *X64InstrMul() { }

BinInstruction *X64InstrDiv() { }

BinInstruction *X64InstrInc() { }

BinInstruction *X64InstrDec() { }

BinInstruction *X64InstrNeg() { }

BinInstruction *X64InstrCmp() { }

BinInstruction *X64InstrJmp() { }

BinInstruction *X64InstrAnd() { }

BinInstruction *X64InstrOr() { }

BinInstruction *X64InstrXor() { }

BinInstruction *X64InstrNot() { }

BinInstruction *X64InstrCall() { }

BinInstruction *X64InstrRet() {
  unsigned char *code;
  BinInstruction *bin = CreateBinInstruction(&code, 1);
  code[0] = 0xc3;
  return bin;
}