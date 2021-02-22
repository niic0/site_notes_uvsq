#include <stdio.h>

void affbitsfloat (float F) {
  int bits = 0;
  unsigned int *x = (unsigned int *)&F;
  unsigned int n = *x;
  for (int i=1; i<=32 ; i++) {
    bits = ((n>>i) & 1);
    printf("%d",bits);
    if(i == 1) printf(" | ");
    if(i == 9) printf(" | ");
  }
  printf("\n");
}
