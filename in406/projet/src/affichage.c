#include "affichage.h"

/*
 * fonction affichant l'utilisation du programme
*/
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
 * permet a la fonction structure de mettre la bonne marge avant le token a afficher
*/
void padding ( char ch, int n ){
  int i;
  for (i=0; i<n; i++) putchar ( ch );
}
/*
 * Affiche l'arbre de fadon graphique dans le terminal
*/
void structure (ARBRE* root, int level ){
  if ( root == NULL ) {
    padding ( '\t', level );
    puts ( "~" );
  }

  else {
    structure ( root->fd, level + 1 );
    padding ( '\t', level );
    switch (root->token->value){
      case OU:   puts("+");   break;
      case ET:   puts(".");   break;
      case IMP:  puts("=>");  break;
      case EQU:  puts("<=>"); break;
      case NON:  puts("NON"); break;
      case UN:   puts("1");   break;
      case ZERO: puts("0");   break;
      default:
        puts("l'arbre contient des caracteres incorrecte");
        exit(3);
    }

    structure ( root->fg, level + 1 );
  }
}


/*
 * affichage les tokens des facon possibles :
 *   - avec la liste
 *   - avec l'attribut next des tokens
*/
void print_tokens(LISTE_TOKEN liste){
  printf("contenu de la liste : \n");
  for (int i=0; liste.tokens[i]; i++){
    switch (liste.tokens[i]->type)
      {
        case OP:    printf("tokens[%d] is OP\n",i);    break;
        case PT:    printf("tokens[%d] is PT\n",i);    break;
        case CONST: printf("tokens[%d] is CONST\n",i); break;
      }
  }

  printf("token->next->next... : \n");

  TOKEN *buf = liste.tokens[0];
  while(buf){
    switch(buf->type)
      {
        case OP:    printf("OP\n");    break;
        case PT:    printf("PT\n");    break;
        case CONST: printf("CONST\n"); break;
      }
    buf = buf->next;
  }
}

/*
 * affichage le token
*/
void print_token(TOKEN *T){
  switch (T->value)
    {
      case   OU: printf("is OU #+#\n");    break;
      case   ET: printf("is ET #.#\n");    break;
      case  IMP: printf("is IMP #=>#\n");  break;
      case  EQU: printf("is EQU #<=>#\n"); break;
      case  NON: printf("is NON #NON#\n"); break;
      case PT_O: printf("is PT_O  #(#\n"); break;
      case PT_F: printf("is PT_F #)#\n");  break;
      case ZERO: printf("is ZERO #0#\n");  break;
      case   UN: printf("is UN #1#\n");    break;
    }
}
