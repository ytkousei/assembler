#include <stdarg.h>
#include <stdio.h>
#include <utils/print.h>
#include <ass.h>
#include <stdlib.h>

void Error(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);

  exit(1);
}

void Help() {
  printf("Usage: gcc [options] file\n");
  printf("Options\n");
  printf("  --help\n");
  printf("  --version\n");
}

void Version() {
  printf("ass %s\n", ASS_VERSION);
}