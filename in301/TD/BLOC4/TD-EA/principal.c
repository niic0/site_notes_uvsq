#include <stdio.h>
#include "ea.h"

int main () {
  EA e,e1,e2,e3;

  e1 = ea_creer_valeur(6);
  e2 = ea_creer_valeur(7);
  e = ea_creer_operation('+',e1,e2);
  e1 = ea_creer_valeur(5);
  e2 = ea_creer_operation('-',e1,e);

  e1 = ea_creer_valeur(3);
  e2 = ea_creer_valeur(4);
  e = ea_creer_operation('-',e1,e3);

  e1 = ea_creer_operation('*',e, e2)

  e = ea_creer_valeur(8);
  e1 = ea_creer_valeur(9);
  e2 = ea_creer_operation('-',);

  printf("%f\n",ea_evaluer(e));


  return 0;
}
