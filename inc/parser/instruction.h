#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include <arch/x64/instructions.h>

typedef enum _ParamKind {
  PK_NUM,
  PK_REG,
  PK_EOF,
} ParamKind;

typedef struct _Param Param;

struct _Param {
  Param *next;
  ParamKind kind;
  int val;
  char *str;
};

extern char is_next;

Param *CreateParam(Param *cur, ParamKind kind, int val);

char *InstructionToBin(char *str);

#endif
