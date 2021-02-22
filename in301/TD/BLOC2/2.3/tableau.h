#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



struct Tableau{
  int n; //taille du tableau (nombre de mots)
  int taille; //taille max d'un mot du tableau
  char **tab; //tableau de char de dimension n*taille (complete par des '\0' la ou les mots ne couvrent pas taille caractères)
};

typedef struct Tableau Tableau;

//retourne une copie du tableau t
Tableau copy_tab(Tableau t);

//retourne un tableau avec les mots contenus dans le fichier fic (uniquement des caracteres alphabetiques et '\0')
Tableau init_tab_fic(char* fic);

//affiche les mots du tableau
void affiche_tab(Tableau t);

//libere la memoire
Tableau libere_tab(Tableau t);
