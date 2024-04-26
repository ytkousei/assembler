#include <stdarg.h>
#include <stdlib.h>
#include <parser/instruction.h>

Instruction *CreateInstruction(char *instr_name, char *values) {
  Instruction *instr = malloc(sizeof(Instruction));
  instr->instr_name = instr_name;
  instr->values = values;

  return instr;
}
