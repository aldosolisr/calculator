#ifndef EVAL_H
#define EVAL_H

#include "ast.h"
#include "symbol_table.h"

double eval_ast(ast_node *node, symbol_table *table);

#endif

