#include "tableau.h"
#include <string.h>
#include <stdlib.h>

//associe à chaque caractere un indice dans le tableau des frequences
//les caractes possible sont les caracteres alphabetiques en minuscules et le caractere de fin de chaine '\0'
int indice(char c){
  int E;
  E = calloc(27,sizeof(int)); //aloue 27 éléments de la taille d'un int. calloc va permettre d'initialiser
                              //toutes les valeurs de E[] à 0
  E[(int)c]++;
  return E[(int)c];
}


//tri le tableau  selon la composante i
void tri_base_indice(Tableau t, int i){
  //a ecrire
}




//tri par base
void tri_base(Tableau t){
  int i;
  for(i=t.taille-1; i>=0; i--)
    tri_base_indice(t, i);
}




//tri le tableau entre indices deb et fin compris
void tri_rapide(Tableau t, int deb, int fin){
  char *pivot = t.tab[deb];
  int pos = deb;

  if (deb>=fin) return;

  for (int i=deb ; i<fin ; i++) {
    if (strcmp(t.tab[i],pivot) == -1) {
      t.tab[pos] = t.tab[i];
      pos++;
      t.tab[i] = t.tab[pos];
      t.tab[pos] = pivot;
    }
  }

  tri_rapide(t, deb, pos);
  tri_rapide(t, pos+1, fin);
}


//tri par comparaison en utilisant la fonction strcmp
void tri_cmp(Tableau t){
  tri_rapide(t, 0, t.n-1);
}
