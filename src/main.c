#include <stdio.h>
#include <elf_file.h>
#include <tokenizer/tokenizer.h>
#include <parser/parser.h>
#include <string.h>
#include <utils/print.h>
#include <utils/fs.h>
#include <utils/args.h>
#include <gen/gen.h>

int main(int argc, char **argv) {
  if (argc < 2) Error("Error: not enough arguments\n");

  Args *args = InitArgs(argc, argv);

  ReadFile(args->input_path);
  char code[BUF_SIZE + 1];
  strcpy(code, file_content);

  Token *token = Tokenize(code);
  Node *node = Parse(token);
  unsigned char *bin_code = Gen(node);
  // ElfFile ef = CreateElfFile(bin_code);
  // SaveElfFile(ef, args->output_path);
}
