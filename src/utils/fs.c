#include <stdio.h>
#include <string.h>
#include <utils/print.h>
#include <utils/fs.h>

char file_content[BUF_SIZE + 1];

void ReadFile(char *path) {
  FILE *fp = fopen(path, "r");
  if(fp == NULL) Error("error: opening %s file", path);

  memset(file_content, 0, sizeof(file_content));

  if(fread(file_content, sizeof(char), BUF_SIZE, fp)) {
    fclose(fp);
  } else {
    if(ferror(fp)) {
      Error("error reading %s", path);
    } else if(feof(fp)) {
      Error("EOF found");
    }
  }
}
