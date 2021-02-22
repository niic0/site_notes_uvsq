#include <stdio.h>
#include <stdlib.h>

void affn(int n) {
  for (int i=-n; i<=n ;i++) printf("%4d",i);
  printf("\n");
}

void affnrec(int n) {
  int *i = malloc(n*sizeof(int));
  printf(i[n]);
  if (i[i[0]*-2] == -i[0]) {
      printf("\n");
      free (i);
      return;
  }
  affnrec(i+1);
}
