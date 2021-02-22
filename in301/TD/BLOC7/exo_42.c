#include <stdio.h>
#include <stdlib.h>

void compadeuxv2 (){
  int cmt;
  int tmp = 0;

  for (cmt=1 ; cmt<=300 ; cmt++) {
    tmp++;
    if (tmp%11 == 0) printf("\n");
    printf("%5d",cmt);
  }
  printf("\n");
}
