
#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>

void tri_bulle (TABINT T) {
	int i,j;

	for (i=T.N-1 ; i>0 ; i--) {
		for (j=0 ; j<i ; j++) {
			if (T.val[j] > T.val[j+1]){
				int tmp    = T.val[j];
				T.val[j]   = T.val[j+1];
				T.val[j+1] = tmp;
			}
		}
	}

}

int main(int argc, char *argv[]) {
	scanf("%d",*argv[1]);
	int N = *argv[1]; 
	TABINT T = gen_alea_tabint(N,100);

	printf("Avant tri\n");
	aff_tabint(T);

	if (verif_si_tableau_croissant(T)) printf("Tableau trié\n\n");
	else printf("Tableau non trié\n\n");

	tri_bulle(T);

	printf("Après tri bulle\n");
	aff_tabint(T);

	if (verif_si_tableau_croissant(T)) printf("Tableau trié\n");
	else printf("Tableau non trié\n");


	exit(0);
}
