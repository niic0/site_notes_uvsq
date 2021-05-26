#include "affichage.h"



ARBRE* add_const(ARBRE *A, LISTE_TOKEN liste, size_t current);     // Ajoute une constante a l'arbre
ARBRE* add_op(ARBRE* A, LISTE_TOKEN liste, size_t current);        // Ajoute une operation a l'arbre (sauf op unaire)
ARBRE* add_sous_arbre(ARBRE *A, LISTE_TOKEN liste, size_t current);// En cas de parenthese, cree un sous arbre
size_t next_pt(LISTE_TOKEN liste, size_t current);                 // Positionne la tete de lecture de l'expression
                                                                   // apres les parentheses


/*
 * fonction recurssive permettant de representer un exerpression booleenne par un arbre
 * ARGUMENTS : - A       => l'arbre qui va etre rempli
 *             - liste   => la liste des tokens faites precedement
 *             - current => la tete de lecture de la liste
 * RETOUR    : l'arbre A contenant la liste de token
*/
ARBRE* token_to_arbre(ARBRE *A, LISTE_TOKEN liste, size_t current){
  if (A == NULL) exit(1);

  // on ne peut rencontrer une parenthese fermante que si on est entrain de creer un sous arbre
  if (liste.tokens[current]->value == PT_F) return A;

  // si on rencontre une parenthese
  if(liste.tokens[current]->type == CONST) A = add_const(A, liste, current);

  // si on rencontre un operateur
  else if (liste.tokens[current]->type == OP) A = add_op(A, liste, current);

  // si on rencontre une parenthese ouvrante
  else if (liste.tokens[current]->value == PT_O){
    A = add_sous_arbre(A, liste, current);
    current = next_pt(liste, current);
  }

  if (current+1 >= liste.size) return A;

  else A = token_to_arbre(A, liste, current+1);

  return A;
}


/*
 * fonction d'ajout d'une constante a un arbre
 * ARGUMENTS : - A       => l'arbre auquel il faut ajouter la constante
 *             - liste   => liste permettant d'avoir le token à ajouter
 *             - current => position dans la liste de la constante
*/
ARBRE* add_const(ARBRE *A, LISTE_TOKEN liste, size_t current){
    if (current == 0 || liste.tokens[current-1]->value == PT_O)
      A->token = liste.tokens[current];

    else if(A->fd == NULL){
      A->fd = malloc(sizeof(ARBRE));
      A->fd->token = liste.tokens[current];
    }

    // pour les constantes suivies d'un operateur unaire
    else if(A->fd->token->value == NON){
      A->fd->fd = malloc(sizeof(ARBRE));
      A->fd->fd->token = liste.tokens[current];
    }

  return A;
}


/*
 * fonction d'ajout d'une operation a un arbre sauf l'operation unaire
 * ARGUMENTS : - A       => l'arbre auquel il faut ajouter l'operation
 *             - liste   => liste permettant d'avoir le token à ajouter
 *             - current => position dans la liste de l'operation
*/
ARBRE* add_op(ARBRE* A, LISTE_TOKEN liste, size_t current){
  if(liste.tokens[current]->value == NON){
    if (current == 0 || liste.tokens[current-1]->value == PT_O)
      A->token = liste.tokens[current];

    else if(A->fd == NULL){
      A->fd = malloc(sizeof(ARBRE));
      A->fd->token = liste.tokens[current];
    }
  }

  else {
    ARBRE* buf = malloc(sizeof(ARBRE));
    buf->fg = A;
    buf->token = liste.tokens[current];
    A = buf;
  }

  return A;
}


/*
 * fonction gerant les parentheses et creant un sous arbre de ce qu'il y a entre les parenthese
 * pour l'arbre principal
 * ARGUMENTS : - A       => l'arbre auquel il faut ajouter le sous arbre
 *             - liste   => permet de garder la liste en memoire pour la renvoyer a la
 *                          fonction token_to_arbre
 *             - current => position de la tete de lecture de la liste
 * RETOUR    : renvoi le sous arbre cree a partir de ce qu'il y avait entre les parentheses
*/
ARBRE* add_sous_arbre(ARBRE *A, LISTE_TOKEN liste, size_t current){
  if(A->token == NULL) {
    return token_to_arbre(A, liste, current+1);
  }

  else if(A->fd == NULL) {
    A->fd = malloc(sizeof(ARBRE));
    A->fd = token_to_arbre(A->fd, liste, current+1);
  }

  else if(A->fd->token->value == NON){
    A->fd->fd = malloc(sizeof(ARBRE));
    A->fd->fd = token_to_arbre(A->fd->fd, liste, current+1);
  }
  return A;
}


/*
 * fonction permettant de positionner la tete de lecture apres les parentheses rencontrees dans
 * la liste de token. utilisation des piles
 * ARGUMENTS : - liste   => contient les token, permet a partir de current de connaitre la prochaine
 *                          parenthese qui ferme la parenthese positionnee a current dans la liste
 *             - current => position de la parenthese dans la liste
 * RETOUR    : position de la parenthese qui ferme la parenthese a la position current
*/
size_t next_pt(LISTE_TOKEN liste, size_t current){
  char* pile_PT = malloc(254*sizeof(char));
  pile_PT[strlen(pile_PT)] = '(';                // empile
  int i = current+1;

  while(strlen(pile_PT) != 0){                   // tant que la pile n'est pas vide
    if(liste.tokens[i]->value == PT_F)           // si parenthese fermante on depile
      pile_PT[strlen(pile_PT)-1] = 0;
    if(liste.tokens[i]->value == PT_O)           // si parenthese ouvrante on empile
      pile_PT[strlen(pile_PT)] = '(';
    i++;
  }

  free(pile_PT);
  return i-1;
}
