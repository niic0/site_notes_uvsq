#include "verif.h"

typedef struct arbre {
  struct arbre* fg;  // fils gauche
  struct arbre* fd;  // fils droit
  TOKEN* token;
} ARBRE;


ARBRE* token_to_arbre(ARBRE *A, LISTE_TOKEN liste, size_t current);
