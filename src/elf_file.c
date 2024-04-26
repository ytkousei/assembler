#include <elf_file.h>

Elf64_Ehdr CreateElfHeader() {
  unsigned char e_ident[EI_NIDENT] = {
    ELFMAG0,
    ELFMAG1,
    ELFMAG2,
    ELFMAG3,
    ELFCLASS64,
    ELFDATA2LSB,
    0x01,
    ELFOSABI_LINUX,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
  };

  long long entry_point = 0x400078;

  Elf64_Ehdr header = {
    e_ident,
    ET_EXEC,
    EM_X86_64,
    0x01,
    entry_point,
    0x40,
    0x00,
    0x00,
    0x40,
    0x38,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
  };

  return header;
}