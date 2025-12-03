#include "token.h"

#ifndef PARSER
#define PARSER

typedef enum {
  AST_NUMBER,
  AST_IDENTIFIER,
  AST_BINARY,
  AST_ASSIGN,
  AST_EXIT
} ast_type;

typedef struct ast_node {
  ast_type type;
  union {
    // number
    double number;
    // identifier
    char * identifier;
    // binary op + - * / ^
    struct{
      char op;
      struct ast_node *left;
      struct ast_node *right;
    } binary;
    // assign
    struct{
      char *id;
      struct ast_node *value;
    } assign;
  }as;
} ast_node;

// generates an ast
ast_node *parse_tokens(const token_vector *list);
#endif
