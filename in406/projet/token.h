#include <stddef.h>

enum type {
  OP,
  PT,
  CONST,
};

enum token_value {
  OU,
  ET,
  IMP, // implique
  EQU, // equivaut
  NON,
  PT_O, // parenthèse ouvrante
  PT_F, // parenthèse fermante
  UN,
  ZERO,
};

typedef struct token {
  enum type type;
  enum token_value value;
  struct token *next;
}TOKEN;

typedef struct liste_token {
  TOKEN **tokens;
  size_t size;
}liste_token;

void usage();
void print_tokens(liste_token liste);
liste_token test(char** string);
liste_token string_to_token(char **string);
int verif_expression(char **string);
