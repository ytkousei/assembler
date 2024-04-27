#ifndef _ARCHS_H
#define _ARCHS_H

typedef enum _Archs {
  // AR_X86,
  AR_X64,
} Archs;

Archs FindArch(char *str);

#endif
