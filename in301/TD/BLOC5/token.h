struct token{
	float val;
	int type_token;
	char op;
	struct token * suiv;
	struct token * prec;
};

typedef struct token* TOKEN;

TOKEN token_ajouter_fin_liste (TOKEN t,float val);
void token_afficher (TOKEN t);
