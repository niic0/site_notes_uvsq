#include <stdio.h>
#include <stdlib.h>

void compadeux (){
  int i = -1;
  printf("Taille entier : %ld\n",sizeof(int));
  printf("Valeur -1 (int) avec d : %d\n",i);
  printf("Valeur -1 (int) avec u : %u\n",i);
  short int l = -1;
  printf("Taille de -1 (short int) avec hd : %hd\n", l);
  printf("Taille de -1 (short int) avec hu : %hu\n", l);
}
