#include <stdio.h>
#include <string.h>
#include <utils/args.h>
#include <utils/print.h>
#include <stdlib.h>

Args *InitArgs(int argc, char **argv) {
  Args *args = malloc(sizeof(Args));
  args->output_path = "a.out";
  args->arch = AR_X64;

  char is_input_path = 0;
  char is_output_path = 0;
  char is_arch = 0;

  for(int i = 1; i < argc; i++) {
    if(strcmp(argv[i], "--help") == 0) {
      Help();
      exit(0);
    }

    if(strcmp(argv[i], "--version") == 0) {
      Version();
      exit(0);
    }

    if((strcmp(argv[i], "--arch") == 0 || strcmp(argv[i], "-a") == 0)) {
      if(is_arch) Error("Error: --arch option cannot be specified multiple times\n");
      if(!i >= argc) Error("Error: --arch is missing next argument\n");
      i++;
      FindArch(argv[i]);
      is_arch = 1;
      continue;
    }

    if((strcmp(argv[i], "--output") == 0 || strcmp(argv[i], "-o") == 0)) {
      if(is_output_path) Error("Error: Cannot specify multiple output files\n");
      if(!i >= argc) Error("Error: --output is missing next argument\n");
      i++;
      args->output_path = argv[i];
      is_output_path = 1;
      continue;
    }

    if(is_input_path) Error("Error: Cannot specify multiple input files\n");

    args->input_path = argv[i];
    is_input_path = 1;
  }

  return args;
}
