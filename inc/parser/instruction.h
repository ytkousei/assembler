#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

typedef enum _InstructionTypes {
  IT_RET,
} InstructionTypes;

typedef struct _Instruction Instruction;

struct _Instruction {
  InstructionTypes type;
  char *values;
};

Instruction *CreateInstruction(char *instr_name, char *values);

#endif
