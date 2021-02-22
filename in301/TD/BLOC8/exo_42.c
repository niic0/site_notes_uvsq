#include <stdio.h>
#include <stdlib.h>

void compadeuxv2 (){
  for (int cmt=1 ; cmt<=300 ; cmt++) {
    if (cmt%10 == 0) printf("\n");
    printf("%5d",cmt);
  }
  printf("\n");
}
