#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// #####
// 1. Allocation, désallocation, génération aléatoire
//    et affichage de tableaux
// #####
TABINT alloue_tabint (int N) {
	TABINT T;
	T.N = N;
	T.val = malloc(N*sizeof(int));
	return T;
}

TABINT desalloue_tabint (TABINT T) {
	T.N = 0;
	free(T.val);
	T.val = NULL;
	return T;
}

TABINT gen_alea_tabint (int N, int K) {
	TABINT T;
	T = alloue_tabint(N);
	srand(getpid());

	for (int i=0 ; i<T.N ; i++) {
		T.val[i] = rand()%K;
	}

	return T;
}

TABINT sup_tabint (TABINT T) {
	return T;
}

void aff_tabint (TABINT T) {
	for (int i=0 ; i<T.N ; i++) {
		printf("%3d",T.val[i]);
	}
	printf("\n");
}

int verif_si_tableau_croissant (TABINT T) {
	for (int i=0 ;i<T.N ; i++) {
		if (T.val[i] > T.val[i+1]) return 0;
	}
	return 1;
}
