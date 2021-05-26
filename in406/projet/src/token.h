#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum type {
  OP,
  PT,
  CONST,
};

enum token_value {
  OU, ET, IMP, EQU,   // IMP = implique ; EQU = equivaut
  NON,
  PT_O, PT_F,         // parenthese ouvrante et fermante
  UN, ZERO,
};


typedef struct token {
  enum type type;
  enum token_value value;
  struct token *next;
}TOKEN;

typedef struct liste_token {
  TOKEN **tokens;
  size_t size;
}LISTE_TOKEN;


LISTE_TOKEN string_to_token(char **string);
int init_liste(LISTE_TOKEN *liste);
int init_token(TOKEN **T);
