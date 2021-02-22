#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char** argv) { //char** tableau de chaine de caractères
  float i;
  i = atof(argv[1])+ atof(argv[2]);
  printf("%f\n",i);
  return 0;
}
