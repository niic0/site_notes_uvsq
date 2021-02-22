#include <stdio.h>
#include <stdlib.h>

void compadeux2 () {
  for (int i=1 ; i<=300 ; i++){
    if (i%10==0) printf("\n");
    printf("%d",i);
  }
}
