
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
				NBECH++;
			}
			NBCOMP++;
		}
	}
}

struct stat stat_moy (int N, int Nbfois) {
	struct stat stats;
	TABINT T;

	for (int i=0 ; i<Nbfois ; i++) {
		T = gen_alea_tabint(N, 100);
		tri_bulle(T);
	}

	stats.nb_moy_ech = NBECH/Nbfois;
	stats.nb_moy_comp = NBCOMP/Nbfois;
	stats.N = N;

	return stats;
}

void creat_fic_test (){


}


int main() {
	struct stat stats;
	FILE *F;
	F = fopen("test_tri_bulle.data","w");

	int N = 10000*1.2;
	int Nbfois = 1000;

	while (N >=10) {
		stats = stat_moy(N,Nbfois);
		fprintf(F,"%d %f %f\n",N, stats.nb_moy_comp, stats.nb_moy_ech );
		N = N/10;
	}

	exit(0);
}
