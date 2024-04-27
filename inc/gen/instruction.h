#ifndef _GEN_INSTRUCTION_H
#define _GEN_INSTRUCTION_H

// #define DefineBinInstruction(len) 

typedef struct _BinInstruction BinInstruction;

struct _BinInstruction {
  unsigned char *code;
  int len;
};

BinInstruction *CreateBinInstruction(unsigned char **code, int len);

#endif
