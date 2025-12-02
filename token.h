#ifndef TOKEN_H
#define TOKEN_H  

/*  */
typedef enum{
	TOKEN_ADD, TOKEN_SUBS, TOKEN_LPAR, TOKEN_RPAR,
	TOKEN_DIV, TOKEN_MULT, TOKEN_EXP, TOKEN_SQRT,
	TOKEN_ID, TOKEN_ASIGN, TOKEN_NUM, TOKEN_UNKNOWN
}token_type;

typedef struct{
	token_type type;
	char value[255];
}token;

typedef struct token_list{
	token t;
	token_list *next;
	token_list *prev;
}token_list;

//TODO: CRUD 
void push_to_token_list(token t, const token_list *list);
token get_from_token_list(int index, const token_list *list);
token pop_token_list(int index, const token_list *list);

#endif
