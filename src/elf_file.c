#include <elf_file.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <utils/print.h>

unsigned char *CreateElfHeader(unsigned char *code) {
  unsigned char *elf_header = calloc(64, sizeof(unsigned char));

  elf_header[0] = 0x7f;
  elf_header[1] = 'E';
  elf_header[2] = 'L';
  elf_header[3] = 'F';
  elf_header[4] = 0x02;
  elf_header[5] = 0x01;
  elf_header[6] = 0x01;
  elf_header[7] = 0x03;
  elf_header[8] = 0x00;
  elf_header[9] = 0x00;
  elf_header[10] = 0x00;
  elf_header[11] = 0x00;
  elf_header[12] = 0x00;
  elf_header[13] = 0x00;
  elf_header[14] = 0x00;
  elf_header[15] = 0x00; // END IDENT
  elf_header[16] = 0x02; // X64
  elf_header[17] = 0x00; // X64
  elf_header[18] = 0x3E; // AMD x86-64
  elf_header[19] = 0x00; // AMD x86-64
  elf_header[20] = 0x01; // elf version
  elf_header[21] = 0x00;
  elf_header[22] = 0x00;
  elf_header[23] = 0x00; // END elf version
  elf_header[24] = 0x40;
  elf_header[25] = 0x00;
  elf_header[26] = 0x78;
  elf_header[27] = 0x00;
  elf_header[28] = 0x00;
  elf_header[29] = 0x00;
  elf_header[30] = 0x00;
  elf_header[31] = 0x00;
  elf_header[32] = 0x40;
  elf_header[33] = 0x00;
  elf_header[34] = 0x00;
  elf_header[35] = 0x00;
  elf_header[36] = 0x00;
  elf_header[37] = 0x00;
  elf_header[38] = 0x00;
  elf_header[39] = 0x00; // END
  elf_header[40] = 0x00;
  elf_header[41] = 0x00;
  elf_header[42] = 0x00;
  elf_header[43] = 0x00;
  elf_header[44] = 0x00;
  elf_header[45] = 0x00;
  elf_header[46] = 0x00;
  elf_header[47] = 0x00; // END
  elf_header[48] = 0x00;
  elf_header[49] = 0x00;
  elf_header[50] = 0x00;
  elf_header[51] = 0x00; // END
  elf_header[52] = 0x00;
  elf_header[53] = 0x00; // END
  elf_header[54] = 0x38;
  elf_header[55] = 0x00; // END
  elf_header[56] = 0x01;
  elf_header[57] = 0x00; // END
  elf_header[58] = 0x00;
  elf_header[59] = 0x00; // END
  elf_header[60] = 0x00;
  elf_header[61] = 0x00; // END
  elf_header[62] = 0x00;
  elf_header[63] = 0x00; // END

  return elf_header;
}

unsigned char *CreateProgramHeader(unsigned char *code) {
  unsigned char *program_header = {
    0x01,
    0x00,
    0x00,
    0x00, // End
    0x05,
    0x00,
    0x00,
    0x00, // End
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00, // End
    0x40,
    0x00,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00, // End
    0x40,
    0x00,
    0x78,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00, // End
  };

  return program_header;
}

ElfFile CreateElfFile(unsigned char *code) {
  ElfFile file = {
    CreateElfHeader(code),
    CreateProgramHeader(code),
    code,
  };

  return file;
}

void SaveElfFile(ElfFile ef, char *path) {
  FILE *fp = fopen(path, "w+b");
  if(fp == NULL) Error("error: opening %s file", path);

  fwrite(ef.ehdr, sizeof(unsigned char), 64, fp);
  fwrite(ef.phdr, sizeof(unsigned char), 64, fp);

  fwrite(ef.code, sizeof(char), strlen(ef.code), fp);

  fclose(fp);
}
