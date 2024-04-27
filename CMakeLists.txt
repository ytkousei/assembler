cmake_minimum_required(VERSION 3.13)
project(ass C)

set(
  SOURCES
  src/main.c
  src/utils/print.c
  src/utils/args.c
  src/utils/fs.c
  # src/elf_file.c
  src/tokenizer/token.c
  src/tokenizer/tokenizer.c
  src/parser/node.c
  src/parser/parser.c
  src/parser/instruction.c
  src/arch/archs.c
  src/arch/x64/instructions.c
  src/arch/x64/registers.c
)

add_executable(ass ${SOURCES})
include_directories(ass inc)