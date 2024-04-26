cmake_minimum_required(VERSION 3.13)
project(mas C)

set(
  SOURCES
  src/main.c
  src/utils.c
  src/elf_file.c
  src/tokenizer/token.c
  src/tokenizer/tokenizer.c
  src/parser/node.c
  src/parser/parser.c
)

add_executable(mas ${SOURCES})
include_directories(mas inc)