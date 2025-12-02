#include <stdlib.h>
#ifndef TOKEN_H
#define TOKEN_H

/*  */
typedef enum {
  TOKEN_ADD,
  TOKEN_SUBS,
  TOKEN_LPAR,
  TOKEN_RPAR,
  TOKEN_DIV,
  TOKEN_MULT,
  TOKEN_EXP,
  TOKEN_IDEN,
  TOKEN_ASIGN,
  TOKEN_NUM,
  TOKEN_UNKNOWN
} token_type;

typedef struct {
  token_type type;
  char value[255];
} token_t;

typedef struct {
  token_t *data;
  size_t size;
  size_t capacity;
} token_vector;

void tokenize(char *source, token_vector *tokens);
void init_vector(token_vector *vector);
void push_back(token_vector *vector, token_t token);
void free_vector(token_vector *vector);
void print_tokens(token_vector *vector);

#endif
