#ifndef AST_PRINT_H
#define AST_PRINT_H

#include "parser.h"   // aquí tienes tu definición del AST

void print_ast(const ast_node *node);
void print_ast_indented(const ast_node *node, int indent);

#endif

