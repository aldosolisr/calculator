#ifndef AST
#define AST

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

ast_node *new_exit();
ast_node *new_assign(const char *id, ast_node *value);
ast_node *new_binary(char op, ast_node *left, ast_node *right);
ast_node *new_identifier(const char *name);
ast_node *new_number(double n);
void free_ast(ast_node *node);

#endif
