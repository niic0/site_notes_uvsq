#include <stdio.h>
#include <stdlib.h>

void afftailletype (){
  printf("Taille d'un char : %ld octets\n", sizeof(char));
  printf("Taille d'un unsigned char : %ld octets\n", sizeof(unsigned char));
  printf("-----------------------------\n");
  printf("Taille d'un int : %ld octets\n", sizeof(int));
  printf("Taille d'un unsigned int : %ld octets\n", sizeof(unsigned int));
  printf("Taille d'un short : %ld octets\n", sizeof(short));
  printf("Taille d'un short int : %ld octets\n", sizeof(short int));
  printf("Taille d'un long : %ld octets\n", sizeof(long));
  printf("Taille d'un long int : %ld octets\n", sizeof(long int));
}
