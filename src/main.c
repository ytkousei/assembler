#include <stdio.h>
#include <elf.h>
#include <elf_file.h>
#include <tokenizer/tokenizer.h>

int main(int argc, char **argv) {
  Token *token = tokenizer("main:\n\tadd rax,128\n\tret");

  // while (token)
  // {
  //   printf("kind: %d, val: %d\n", token->kind, token->val),
  //   token = token->next;
  // }
}
