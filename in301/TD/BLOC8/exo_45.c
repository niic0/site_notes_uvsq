#include <stdio.h>

void affbitschar (unsigned char C) {
  int bits = 0;
  for (int i=8 ; i>=0 ; i--) {
    bits = ((C>>i) & 1);
    printf("%d",bits);
  }
  printf("\n");
}
