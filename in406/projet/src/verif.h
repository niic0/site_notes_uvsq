#include "token.h"

#define MAX_SIZE_PILE 254

int verif_expression(LISTE_TOKEN liste);
int verif_OP(LISTE_TOKEN liste, size_t i);
int verif_CONST(LISTE_TOKEN liste, size_t i);
int verif_NON(LISTE_TOKEN liste, size_t i);
int verif_PT(LISTE_TOKEN liste);
