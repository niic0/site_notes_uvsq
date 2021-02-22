#include <stdio.h>
#include "exo.h"
#include <stdlib.h>

void float_precision () {
  float a,b,c,d;
  a = 1e-8;
  b = a + 1.0;
  c = b - 1.0;
  d = (a + 1.0) - 1.0;
  if (c==a) printf("ok c=a\n"); else printf("pb c!=a\n");
  if (d==a) printf("ok d=a\n"); else printf("pb d!=a\n");
  if (c==d) printf("ok c=d\n"); else printf("pb c!=d\n");
}
