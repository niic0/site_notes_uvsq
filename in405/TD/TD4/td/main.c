#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "my_ls.h"

int main (int argc, char** argv) {
  struct stat *file = NULL;
  stat(argv[1], file);
  printf("%s",print_type(file));
  return 0;
}
