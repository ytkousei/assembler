#include <stdio.h>
#include <stdarg.h>
#include <utils.h>
#include <stdlib.h>

#define BUF_SIZ 128

void Error(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);

  exit(1);
}
