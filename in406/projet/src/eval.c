#include "affichage.h"

#define IMP(a,b) (!a||b)
#define EQU(a,b) ((a&&b)||(!a&&!b))

/*
  ////////////////////////////////////////////////

  usage: ./a.out <expression>\n
           operateurs: '+'   = OU
                       '.'   = ET
                       '=>'  = implique
                       '<=>' = equivaut
                       'NON' = unaire
            priorités: '(', ')'
           constantes: '0', '1'
              exemple: ./a.out (1=>(NON (1+0).1))

  NB bash: - parentheses : \( \)
           - superieur/inferieur : \< \>

  VALEURS DE RETOUR :
  1 : erreur d'allocation
  2 : erreur d'input ; l'expression contient des tokens indefinies
  3 : erreur d'expression ; l'expression est incorrecte
  4 : erreur du programme

  /////////////////////////////////////////////////
*/


int arbre_to_int(ARBRE *A);                // fonction permettant de calculer l'expression booleenne de l'arbre
int token_to_int(enum token_value token);  // fonction permettant de traduire un token de type constant en entier
void free_all(LISTE_TOKEN liste, ARBRE* A);// libere la liste de token et l'arbre



/*  
 * PROGRAMME PRINCIPAL
 */
int main (int argc, char** argv){
  if(argc == 1){ usage(); exit(2); }

  LISTE_TOKEN liste = string_to_token(argv);
  ARBRE* A = malloc(sizeof(ARBRE));
  if(A == NULL) exit(1);

  if(!verif_expression(liste)) puts("l'expression est acceptee");
  else exit(3);

  A = token_to_arbre(A, liste, 0);

  /* AFFICHAGE GRAPHIQUE DE L'ARBRE (a decommenter) */
  structure(A,0);

  int res = arbre_to_int(A);
  if(res == -1) exit(4);                   // erreur du programme

  free_all(liste, A);

  printf("resultat : %d\n\n", res);
  return 0;
}


/*
 * RETOUR   : renvoie le resultat du calcul de l'expression booleenne traduit par l'arbre.
 *            renvoie -1 si l'operation
 * ARGUMENT : ARBRE A contenant l'expression booleenne
*/
int arbre_to_int(ARBRE *A) {
  if(A->token->type == CONST) return token_to_int(A->token->value);

  // resultat(A->fg) (op) resultat(A->fd)
  switch(A->token->value){
    case OU : return arbre_to_int(A->fg) || arbre_to_int(A->fd);
    case ET : return arbre_to_int(A->fg) && arbre_to_int(A->fd);
    case IMP: return IMP(arbre_to_int(A->fg), arbre_to_int(A->fd));
    case EQU: return EQU(arbre_to_int(A->fg), arbre_to_int(A->fd));
    case NON: return !arbre_to_int(A->fd);
    default:
      fprintf(stderr,"[ERR] probleme a arbr_to_int, la value n'est pas un OP");
      exit(4);
  }

  return -1;
}


/*
 * RETOUR   : retourne la valeur entiere du token CONST pris en argument
 *            si la valeur n'est pas de type CONST, on sort du programme
 * ARGUMENT : la valeur du token de type CONST
 */
int token_to_int(enum token_value token){
  int ret;

  switch(token)
    {
      case ZERO : ret = 0; break;
      case UN   : ret = 1; break;
      default :
        fprintf(stderr,"[ERR] le token pris dans arbre_to_int n'est pas une valeur booleennne\n");
        exit(4);   // erreur venant du programme
    }
  return ret;
}

/*
 * libere recurssivement la memoire de l'abre
*/
void free_arbre(ARBRE* A){
  if(A) free(A);
  else{
    free_arbre(A->fd);
    free_arbre(A->fg);
  }
}
/*
 * libere la memoire de la liste de token
 * ARGUMENT : token a free
*/
void free_all(LISTE_TOKEN liste, ARBRE* A){
  for(int i=0; liste.tokens[i]; i++)
    free(liste.tokens[i]);
  free_arbre(A);
}
