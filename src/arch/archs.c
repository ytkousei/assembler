#include <string.h>
#include <arch/archs.h>
#include <utils/print.h>

Archs FindArch(char *str) {
  if(strcmp(str, "x64") == 0) {
    return AR_X64;
  }

  Error("Error: %s is not architecture name\n", str);
}
