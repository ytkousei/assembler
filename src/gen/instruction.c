#include <gen/instruction.h>

BinInstruction *CreateBinInstruction(unsigned char **code, int len) {
  *code = calloc(len, sizeof(char));
}
