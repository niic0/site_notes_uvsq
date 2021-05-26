#include "verif.h"


                                                   // verification locale des tokens de type :
int verif_OP(LISTE_TOKEN liste, size_t i);         //   - operation
int verif_CONST(LISTE_TOKEN liste, size_t i);      //   - constante
int verif_NON(LISTE_TOKEN liste, size_t i);        //   - operateur unaire
int verif_PT_O_local(LISTE_TOKEN liste, size_t i); //   - parenthese ouvrante
int verif_PT_F_local(LISTE_TOKEN liste, size_t i); //   - parenthese fermante
int verif_PT(LISTE_TOKEN liste);                   // verifie que les parentheses se ferment



/*
 * Retourne 0 si l'expression est correcte, 1 sinon
*/
int verif_expression(LISTE_TOKEN liste){
  int ret = 0;

  if(verif_PT(liste)) ret = 1;


  for (size_t i=0; i<liste.size ; i++){
    if(ret){
       puts("[ERR] expression incorrecte");
       exit(3);                                 // exit(3) pour les expressions incorrectes
    }
    switch (liste.tokens[i]->type){

      case OP:                                  // OPERATION
        if ((liste.tokens[i]->value == NON)){   // si l'operateur est non, on verifie
          if(verif_NON(liste, i)) ret = 1;      // s'il respecte les confitions
        }
        else if(verif_OP(liste,i)) ret = 1;

      break;

      case CONST:                               // CONSTANTE
        if(verif_CONST(liste, i)) ret = 1;
        break;
      case PT:                                  // PARENTHESES
        break;
      default:
        ret = 1;
    }
  }

  return ret;
}


/*
 * RETOUR : 0 si la constante est entouree des bons éléments
 *          1 sinon
 */
int verif_PT(LISTE_TOKEN liste){
  char* pile_PT;                                     // pile contenant les parentheses
  pile_PT = malloc(MAX_SIZE_PILE*sizeof(char));

  for(size_t i=0; i<liste.size ; i++){

    if (liste.tokens[i]->value == PT_O){             // pour les parentheses ouvrantes
      if(verif_PT_O_local(liste, i)){                // verification locale
        puts("probleme de parenthese");
        return 1;
      }
      pile_PT[strlen(pile_PT)] = '(';                // empile
    }

    if (liste.tokens[i]->value == PT_F){             // pour les parentheses fermantes
      if(verif_PT_F_local(liste, i) || (pile_PT[strlen(pile_PT)-1] == 0)){
        puts("probleme de parenthese");
        return 1;
      }
      else pile_PT[strlen(pile_PT)-1] = 0;           // depile
    }
  }

  if (strlen(pile_PT) == 0){free(pile_PT);return 0;} // si la pile est vide
  else{ free(pile_PT); return 1;}                                     // si la pile n'est pas vide, il y a une erreur

  return 1;
}


/*
 * RETOUR : 0 si l'operateur est entouree des bons éléments
 *          1 sinon
 */
int verif_OP(LISTE_TOKEN liste, size_t i){
  int ret = 0;                                 // On part du principe que l'expression est correcte

  if ((i == 0) || (i+1 == liste.size)){        // si l'operateur commence ou termine l'expression et on revoie une erreur
    fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);
    return 1;
  }

  switch(liste.tokens[i-1]->type){
    case CONST: break;
    case PT:
      if      (liste.tokens[i-1]->value == PT_O) ret = 1;   // si la parenthese est ouvante
      else if (liste.tokens[i-1]->value == PT_F) ret = 0;   // si la parenthese est fermante
      break;

    default:
      ret = 1;
  }

  switch(liste.tokens[i+1]->type){
    case CONST: break;
    case PT:
      if      (liste.tokens[i+1]->value == PT_O) ret = 0;
      else if (liste.tokens[i+1]->value == PT_F) ret = 1;
      break;
    case OP:                                               // si c'est un operateur unaire
      if(liste.tokens[i+1]->value == NON)
        break;
      else ret = 1;
      break;
    default:
      ret = 1;
  }

  if(ret) fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);

  return ret;
}


/*
 * RETOUR : 0 si la constante est entoure des bons éléments
 *          1 sinon
 */
int verif_CONST(LISTE_TOKEN liste, size_t i){
  int ret = 0;

  /* verification du token precedent */
  if(i!=0){                                              // liste.tokens[-1] n'existe pas
    switch (liste.tokens[i-1]->type) {
      case OP: break;
      case PT:
        if     (liste.tokens[i-1]->value == PT_O) ret = 0;
        else if(liste.tokens[i-1]->value == PT_F) ret = 1;
      break;

    default:
      ret = 1;
    }
  }


  if(ret){
    fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);
    return ret; // revient a retourner 1
  }


  /* verification du token suivant */
  if(i+1 != liste.size){
    switch (liste.tokens[i+1]->type) {
      case OP: break;
      case PT:
        if     (liste.tokens[i+1]->value == PT_O) ret = 1;
        else if(liste.tokens[i+1]->value == PT_F) ret = 0;
        break;

    default:
      ret = 1;
    }
  }

  if(ret) fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);

  return ret;
}


/*
 * Verifie a la fois l'operateur unaire et la parenthese ouvrante (condition identique)
 * RETOUR : 0 si la constante est entouree des bons éléments
 *          1 sinon
 */
int verif_NON(LISTE_TOKEN liste, size_t i){
  int ret = 0;

  /* verification du token precedent */
  if(i!=0){
    switch (liste.tokens[i-1]->type) {
      case OP: break;
      case PT:
        if     (liste.tokens[i-1]->value == PT_O) ret = 0;
        else if(liste.tokens[i-1]->value == PT_F) ret = 1;
      break;

      default:
        ret = 1;
    }
    if (ret){
      fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);
      return ret;
    }
  }

  /* verification du token suivant */
  if (i+1 != liste.size){                         // un operateur unaire ne peut finir une expression
    switch (liste.tokens[i+1]->type) {
      case CONST: break;
      case PT:
        if     (liste.tokens[i+1]->value == PT_O) ret = 0;
        else if(liste.tokens[i+1]->value == PT_F) ret = 1;
        break;
      default:
         ret = 1;
    }
  }
  else ret = 1;


  if(i==0 && (i+1==liste.size)) ret = 1;         // verification qu'il n'y ai pas que NON dans l'expression

  if (ret) fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);

  return ret;
}


/*
 * verifie localement si la parenthese ouvrante est valide
 * RETOUR : 1 si l'operation a reussi, 0 sinon
 */
int verif_PT_O_local(LISTE_TOKEN liste, size_t i){
  /* verification qu'il n'y ait pas que la parenthese dans l'expression et que
     la parenthese ouvrante n'est pas le dernier token de l'expression         */
  if((i==0 && (i+1==liste.size)) || (i+1 == liste.size)) return 1;

  int ret = 0;

  /* verification du token precedent */
  if(i!=0){
    switch (liste.tokens[i-1]->type) {
      case OP: break;
      case PT:
        if     (liste.tokens[i-1]->value == PT_O) ret = 0;
        else if(liste.tokens[i-1]->value == PT_F) ret = 1;
        break;

    default:
      ret = 1;
    }
    if (ret){
      fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);
      return ret;
    }
  }

  /* verification du token suivant */
  switch (liste.tokens[i+1]->type) {
    case OP:
      if(liste.tokens[i+1]->value != NON) ret = 1;
    case CONST: break;
    case PT:
      if     (liste.tokens[i+1]->value == PT_O) ret = 0;
      else if(liste.tokens[i+1]->value == PT_F) ret = 1;
      break;

    default:
      ret = 1;
  }

  if (ret) fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);

  return ret;
}


/*
 * verifie localement si la parenthese fermante est valide
 * RETOUR : 1 si l'operation a reussi, 0 sinon
 */
int verif_PT_F_local(LISTE_TOKEN liste, size_t i){
  if(i==0) return 1;

  int ret = 0;

  /* verification du token precedent */
  switch (liste.tokens[i-1]->type) {
    case CONST:
      break;
    case PT:
      if     (liste.tokens[i-1]->value == PT_O) ret = 1;
      else if(liste.tokens[i-1]->value == PT_F) ret = 0;
      break;

    default:
      ret = 1;
    }

    if (ret){
      fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);
      return ret;
    }


  /* verification du token suivant */
  if(i+1 != liste.size){                         // un operateur unaire ne peut finir une expression
    switch (liste.tokens[i+1]->type) {
    case OP:
      if(liste.tokens[i+1]->value == NON) ret = 1;
      break;
    case PT:
      if     (liste.tokens[i+1]->value == PT_O) ret = 1;
      else if(liste.tokens[i+1]->value == PT_F) ret = 0;
      break;
    default:
      ret = 1;
    }
  }


  if(i==0 && i+1==liste.size)                     // verification qu'il n'y ai pas que NON dans l'expression
    ret = 1;

  if (ret) fprintf(stdout, "/!\\ expression incorrecte a la position %zu\n", i+1);

  return ret;
}
