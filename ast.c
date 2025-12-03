#include "ast.h"
#include "token.h"
#include <string.h>


void free_ast(ast_node *node) {
  if (node == NULL) {
    return;
  }

  switch (node->type) {
  case AST_BINARY:
    free_ast(node->as.binary.left);
    free_ast(node->as.binary.right);
    break;

  case AST_ASSIGN:
    free_ast(node->as.assign.value);
    if (node->as.assign.id != NULL) {
      free(node->as.assign.id);
    }
    break;

  case AST_IDENTIFIER:
    if (node->as.identifier != NULL) {
      free(node->as.identifier);
    }
    break;

  case AST_EXIT:
    break;

  case AST_NUMBER:
    break;

  default:
    break;
  }

  free(node);
}

ast_node *new_number(double n) {
  ast_node *node = malloc(sizeof(ast_node));
  node->type = AST_NUMBER;
  node->as.number = n;
  return node;
}

ast_node *new_identifier(const char *name) {
  ast_node *node = malloc(sizeof(ast_node));
  node->type = AST_IDENTIFIER;
  node->as.identifier = strdup(name);
  return node;
}

ast_node *new_binary(char op, ast_node *left, ast_node *right) {
  ast_node *node = malloc(sizeof(ast_node));
  node->type = AST_BINARY;
  node->as.binary.op = op;
  node->as.binary.left = left;
  node->as.binary.right = right;
  return node;
}

ast_node *new_assign(const char *id, ast_node *value) {
  ast_node *node = malloc(sizeof(ast_node));
  node->type = AST_ASSIGN;
  node->as.assign.id = strdup(id);
  node->as.assign.value = value;
  return node;
}

ast_node *new_exit() {
  ast_node *node = malloc(sizeof(ast_node));
  node->type = AST_EXIT;
  return node;
}
