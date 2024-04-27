#include <stdarg.h>
#include <stdlib.h>
#include <parser/instruction.h>
#include <utils/print.h>
#include <ctype.h>
#include <string.h>

char is_next = 1;

Param *CreateParam(Param *cur, ParamKind kind, int val) {
  if(!is_next) Error("Error: expected a ','\n");
  is_next = 0;
  Param *param = malloc(sizeof(Param));
  param->kind = kind;
  param->val = val;
  cur->next = param;
  return param;
}

char *InstructionToBin(char *str) {
  for (int i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }

  // if(strcmp(str, INSTR_MOV))
  // if(strcmp(str, INSTR_RET))

  Error("Error: %s is not instruction name\n", str);
}
