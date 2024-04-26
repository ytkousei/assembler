#include <stdarg.h>
#include <stdlib.h>
#include <parser/instruction.h>
#include <utils.h>
#include <ctype.h>
#include <string.h>

char *InstructionToBin(char *str) {
  for (int i = 0; str[i]; i++) {
    str[i] = toupper(str[i]);
  }

  if(strcmp(str, INSTR_MOV))
  if(strcmp(str, INSTR_RET))

  Error("%s is not instruction name", str);
}
