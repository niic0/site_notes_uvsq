#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"

#define MAX_SIZE 100

/*
 * argument : liste_token a alloué
 * return : 0 pour succés, 1 sinon
*/
int init_liste(liste_token *liste){
  liste->tokens = malloc(MAX_SIZE*sizeof(TOKEN));
  if(liste->tokens == NULL){
    perror("malloc error for liste_token");
    return 1;
  }
  return 0;
}

/*
 * argument : Token a alloué
 * return : 0 pour succés, 1 sinon
*/
int init_token(TOKEN **T){
  *T = malloc(sizeof(TOKEN));
  if(*T == NULL){
    perror("malloc error for token");
    return 1;
  }
  return 0;
}

void usage(){
  fprintf(stderr,
          "[ERR] usage: ./a.out <expression>\n"
          " operateurs: '+'   = OU\n"
          "             '.'   = ET\n"
          "             '=>'  = implique\n"
          "             '<=>' = equivaut\n"
          "             'NON' = unaire\n"
          "  priorités: '(', ')'\n"
          " constantes: '0', '1'\n"
          "    exemple: ./a.out (1=>(NON (1+0).1))\n\n"
          "NB bash: - parentheses : \\( \\) \n"
          "         - superieur/inferieur : \\< \\> \n");
}

/*
 * Retourne true si l'expression est correcte, false sinon
*/
int verif_expression(char **string){

  return 0;
}


liste_token string_to_token(char **string){

  liste_token liste;    // liste contenant tous les tokens, résultat à return
  if(init_liste(&liste))
    exit(1); // exit(1) = erreur d'allocation

  int i = 1; // Pour commencer au arguments et pas au ./a.out
  int y = 0; // Compteur générale pour la liste de 

  while(string[i]){ // Au cas où il y aurait un espace
    for(int k=0; k<(int)strlen(string[i]); k++){
      TOKEN *current;
      if(init_token(&current))
        exit(1);

      switch(string[i][k]){
      case '+':
        printf("%c\n", string[i][k]);
        current->type = OP; current->value = OU;
        break;
      case '.':
        printf("%c\n", string[i][k]);
        current->type = OP; current->value = ET;
        break;
      case '=':
        printf("%c%c\n",string[i][k],string[i][k+1]);
        if(string[i][k+1] == '>'){
          current->type = OP; current->value = IMP;
          k++;
        }
        else{
          puts("imp");
          usage();
          exit(2);
        }
        break;
      case '<':
        printf("%c%c%c\n",string[i][k],string[i][k+1],string[i][k+2]);
        if(string[i][k+1] == '=' && string[i][k+2] == '>'){
          current->type = OP; current->value = EQU;
          k+=2;
        }
        else{
          puts("non");
          usage();
          exit(2);
        }
        break;
      case 'N':
        printf("%c%c%c\n",string[i][k],string[i][k+1],string[i][k+2]);
        if(string[i][k+1] == 'O' && string[i][k+2] == 'N'){
          current->type = OP; current->value = NON;
          k+=2;
        }
        else{
          puts("non");
          usage();
          exit(2);
        }
        break;
      case '1':
        printf("%c\n", string[i][k]);
        current->type = CONST;current->value = UN;
        break;
      case '0':
        printf("%c\n", string[i][k]);
        current->type = CONST; current->value = ZERO;
        break;
      case '(':
        printf("%c\n", string[i][k]);
        current->type = PT; current->value = PT_O;
        break;
      case ')':
        printf("%c\n", string[i][k]);
        current->type = PT; current->type = PT_F;
        break;
      default:
        puts("default route");
        usage();
        exit(2);
      }

      liste.tokens[y] = current;
      if(y>0){
        liste.tokens[y-1]->next = liste.tokens[y];
      }
      y++;

    }
    i++;
    liste.size = y;
  }

  return liste;
}

void print_tokens(liste_token liste){
  printf("liste token : \n");
  for (int i=0; liste.tokens[i]; i++){
    switch (liste.tokens[i]->type)
      {
        case OP:
          printf("tokens[%d] is OP\n",i);
          break;
        case PT:
          printf("tokens[%d] is PT\n",i);
          break;
        case CONST:
          printf("tokens[%d] is CONST\n",i);
          break;
      }
  }
}
