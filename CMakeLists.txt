cmake_minimum_required(VERSION 3.13)
project(mas C)

set(
  SOURCES
  src/main.c
  src/elf_file.c
)

add_executable(mas ${SOURCES})
include_directories(mas inc)