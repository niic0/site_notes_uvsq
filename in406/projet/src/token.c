#include "affichage.h"

#define MAX_SIZE 100

/*
 * ARGUMENT : liste_token a alloué
 * RETOUR : 0 pour succés, 1 sinon
*/
int init_liste(LISTE_TOKEN *liste){
  liste->tokens = malloc(MAX_SIZE*sizeof(TOKEN));
  if(liste->tokens == NULL){
    perror("malloc error for liste_token");
    return 1;
  }
  return 0;
}


/*
 * ARGUMENT : Token a allour
 * RETOUR : 0 pour succés, 1 sinon
*/
int init_token(TOKEN **T){
  *T = malloc(sizeof(TOKEN));
  if(*T == NULL){
    perror("malloc error for token");
    return 1;
  }
  return 0;
}


/*
 * Prend une chaine de caractere en argument et renvoie une liste de struct token
*/
LISTE_TOKEN string_to_token(char **string){

  LISTE_TOKEN liste;    // liste contenant tous les tokens, résultat à return
  if(init_liste(&liste))
    exit(1); // exit(1) = erreur d'allocation

  int i = 1;   // Pour commencer au arguments et pas au ./a.out
  int y = 0;   // Compteur générale pour la liste de
  int err = 0; // Variable indiquant une erreur sur l'input

  while(string[i]){ // Au cas où il y aurait un espace
    for(int k=0; k<(int)strlen(string[i]); k++){
      TOKEN *current;
      if(init_token(&current))
        exit(1);

      switch(string[i][k]){
        case '+': current->type = OP; current->value = OU; break;

        case '.': current->type = OP; current->value = ET; break;

        case '=':
          if(string[i][k+1] == '>'){
            current->type = OP; current->value = IMP;
            k++;
          }
          else err = 1;
          break;

        case '<':
          if(string[i][k+1] == '=' && string[i][k+2] == '>'){
            current->type = OP; current->value = EQU;
            k+=2;
          }
          else err = 1;
          break;

        case 'N':
          if(string[i][k+1] == 'O' && string[i][k+2] == 'N'){
            current->type = OP; current->value = NON;
            k+=2;
          }
          else err = 1;
          break;

        case '1': current->type = CONST; current->value = UN; break;
        case '0': current->type = CONST; current->value = ZERO; break;

        case '(': current->type = PT; current->value = PT_O; break;
        case ')': current->type = PT; current->value = PT_F; break;

        default: err = 1;
      }

      if(err){
          fprintf(stdout, "l'expression %c n'est pas reconnu\n", string[i][k]);
          usage();
          exit(2);
      }

      liste.tokens[y] = current;
      if(y>0) liste.tokens[y-1]->next = liste.tokens[y];
      y++;
    }

    i++;
    liste.size = y;

  }

  return liste;
}
