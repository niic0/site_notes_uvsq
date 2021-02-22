#include "tableau.h"
#include "chrono.h"
#include "tri.h"

int main(int argc, char** argv){
  Tableau t1, t2;

  if(argc != 2){
    fprintf(stderr, "Format attendu:\n%s fichier\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  t1 = init_tab_fic(argv[1]);
  t2 = copy_tab(t1);


  chrono_start();
  tri_base(t1);
  printf("Duree d'execution tri par base: %f millisecondes\n", 1000*chrono_lap());
  //affiche_tab(t1);
  t1 = libere_tab(t1);


  chrono_start();
  tri_cmp(t2);
  printf("Duree d'execution du tri par comparaison: %f millisecondes\n", 1000*chrono_lap());
  //affiche_tab(t2);
  t2 = libere_tab(t2);

  return EXIT_SUCCESS;
}
