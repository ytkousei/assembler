#include <stdio.h>
#include <elf.h>
#include <elf_file.h>
#include <tokenizer/tokenizer.h>
#include <parser/parser.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
  Token *token = Tokenize("ret");
  //main:\n\tadd rax,128\n\t
  Node *node = Parse(token);

  // while (token)
  // {
  //   printf("kind: %d, val: %d\n", token->kind, token->val),
  //   token = token->next;
  // }
}
