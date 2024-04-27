#include <string.h>
#include <arch/x64/instructions.h>
#include <gen/gen.h>
#include <stdlib.h>

int code_len = 0;

void BinAppend(unsigned char **p, BinInstruction *bin) {
  for (size_t i = 0; i < bin->len; i++) {
    *p = bin->code[i];
    printf("%lx", bin->code[i]);
    p++;
  }
}

unsigned char *Gen(Node *node) {
  unsigned char *bin = calloc(4096, sizeof(char));
  unsigned char *p = bin;

  while (node->next) {
    switch (node->kind) {
    // case NK_LABEL:
      // break;
    case NK_INSTR:
      if(strcmp(node->str, X64_INSTR_RET)) BinAppend(&p, X64InstrRet());
      code_len++;
      break;
    }
    node = node->next;
  }
  return bin;
}
