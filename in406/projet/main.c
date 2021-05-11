#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int main (int argc, char** argv){
  if(argc == 1){
    usage();
    exit(2); // exit(2) = usage
  }

  liste_token liste;
  liste = string_to_token(argv);
  print_tokens(liste);
  return 0;
}
