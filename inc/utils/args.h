#ifndef _ARGS_H
#define _ARGS_H

#include <utils/fs.h>
#include <arch/archs.h>

typedef struct _Args {
  char *input_path;
  char *output_path;
  Archs arch;
} Args;

Args *InitArgs(int argc, char **argv);

#endif