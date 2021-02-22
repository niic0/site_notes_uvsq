#include "tableau.h"

//lit le fichier, et remplit les champs n et taille du tableau
Tableau nb_mot_fic(char* fic){
  char c;
  int est_mot = 0;
  Tableau t;
  FILE* f = fopen(fic, "r");
  
  if(f == NULL){
    fprintf(stderr, "Erreur ouverture fichier %s\n", fic);
    exit(EXIT_FAILURE);
  }

  t.n = 0;
  t.taille = 0;
  t.tab = NULL;
  
  while((c = fgetc(f)) != EOF){
    if(isalpha(c)){
      est_mot++;
    }
    else{
      if(est_mot){
	t.n++;
	if(est_mot > t.taille){
	  t.taille = est_mot;
	}
	est_mot = 0;
      }
    }
  }
  fclose(f);
  t.taille++; //on ajoute 1 pour stocker le caractere de fin de chaine
  return t;
}

//lit le fichier et retourne le tableau remplit des mots contenu dedans
Tableau init_tab_fic(char* fic){
  Tableau t;
  int i = 0;
  int j = 0;
  char c;
  FILE* f = fopen(fic, "r");
  int est_mot = 0;
  char* p;

  if(f == NULL){
    fprintf(stderr, "Erreur ouverture fichier %s\n", fic);
    exit(EXIT_FAILURE);
  }

  //allocation du tableau à 2 dimensions en une seule allocation
  t = nb_mot_fic(fic);
  t.tab = calloc(1,t.n*sizeof(char*)+t.n*t.taille);
  if(t.tab == NULL){
    fprintf(stderr, "Erreur allocation tableau\n");
    exit(EXIT_FAILURE);
  }
  p = (char*) (t.tab+t.n);
  for(i=0; i<t.n; i++)
    t.tab[i] = p + i*t.taille;

  i = 0;
  while((c = fgetc(f)) != EOF){
    if(isalpha(c)){
      t.tab[j][i] = tolower(c);//ecrit tout en minuscule
      t.tab[j][i+1] = '\0';
      i++;
      est_mot = 1;
    }
    else{
      if(est_mot){
	est_mot = 0;
	i = 0;
	j++;
      }
    }
  }
  fclose(f);
  
  return t;
}


void affiche_tab(Tableau t){
  int i;
  for(i=0; i<t.n; i++)
    printf("%s\n",t.tab[i]);
}



//retourne une copie du tableau
Tableau copy_tab(Tableau t){
  int i,j;
  char** tsauv = t.tab;
  char* p;

  //allocation memoire
  t.tab = calloc(1,t.n*sizeof(char*)+t.n*t.taille);
  if(t.tab == NULL){
    fprintf(stderr, "Erreur allocation tableau\n");
    exit(EXIT_FAILURE);
  }
  p = (char*) (t.tab+t.n);
  for(i=0; i<t.n; i++)
    t.tab[i] = p + i*t.taille;

  //recopie
  for(i=0; i<t.n; i++){
    for(j=0; j<t.taille; j++){
      t.tab[i][j] = tsauv[i][j];
    }
  }
  
  return t;
}


Tableau libere_tab(Tableau t){
  free(t.tab);
  t.tab = NULL;
  return t;
}
