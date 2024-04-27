#ifndef _ELF_FILE_H
#define _ELF_FILE_H

#include <elf.h>

typedef struct _ElfFile {
  unsigned char *ehdr;
  unsigned char *phdr;
  char *code;
} ElfFile;

unsigned char *CreateElfHeader(unsigned char *code);
unsigned char *CreateProgramHeader(unsigned char *code);

ElfFile CreateElfFile(unsigned char *code);
void SaveElfFile(ElfFile ef, char *path);

#endif
