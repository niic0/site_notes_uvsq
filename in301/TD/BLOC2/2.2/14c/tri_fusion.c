#include <stdio.h>
#include <stdlib.h>
#include "tabint.h"

void fusionner (int *t, int deb, int mil, int fin){
  int *temp, i, i1,i2; //2 variables pour comparer les 2 tableaux
  i = 0;
  i1 = deb;
  i2 = mil+1;

  temp = malloc ((fin-deb+1)*sizeof(int));

  //On compare les 2 tableaux et on les met la valeur la plus petites dans tmp
  while ((i1 <= mil) && (i2 <= fin)) {
    if (t[i1] < t[i2]) {
      temp[i] = t[i1]; i1++;
    }
    else {
      temp[i] = t[i2]; i2++;
    }
    i++;
  }

  while (i1<=mil) { // Pour finir de recopier le tableau 1
		temp[i] = t[i1];
		i1++;
		i++;
	}
	while (i2<=fin) { // Pour finir de recopier le tableau 2
		temp[i] = t[i2];
		i2++;
		i++;
	}

  for (i=deb ; i<=fin ; i++) {
		t[i] = temp[i-deb];
	}

  free(temp);
}

void tf (int *t, int deb, int fin) {
  if (fin == deb) return;
  int mil = (deb+fin)/2;

  tf(t,deb,mil);
  tf(t,mil+1,fin);
  fusionner(t, deb, mil, fin);
}

void tri_fusion (TABINT T) {
  tf (T.val,0,T.N-1);
}

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	TABINT T = gen_alea_tabint(N,100);

	printf("Avant tri\n");
	aff_tabint(T);

	if (verif_si_tableau_croissant(T)) printf("Tableau trié\n\n");
	else printf("Tableau non trié\n\n");

	tri_fusion(T);

	printf("Après tri bulle\n");
	aff_tabint(T);

	if (verif_si_tableau_croissant(T)) printf("Tableau trié\n");
	else printf("Tableau non trié\n");


	exit(0);
}
