#ifndef PARSER
#define PARSER
#include "token.h"
#include "ast.h"

// generates an ast
ast_node *parse_tokens(const token_vector *list);
void free_ast(ast_node *node);
#endif
