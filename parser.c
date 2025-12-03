#include "parser.h"
#include <stdio.h>
#include <string.h>

static unsigned int pos;
static const token_vector *tokens;
static token_t current;


static void advance() {
  if (pos < tokens->size)
    current = tokens->data[pos++];
  else
    current = (token_t){.type = TOKEN_END};
}
token_t peek() {
  if (pos > tokens->size) {
    return (token_t){.type = TOKEN_END};
  }
  return tokens->data[pos];
}
static void expect(token_type expected) {
  if (current.type != expected) {
    fprintf(stderr, "Syntax Error: Expected '%s', but got %s\n",
            get_token_symbol(expected), current.value);
  }
  advance();
}

static ast_node *parse_addsub();
static ast_node *parse_operation();
static ast_node *parse_multdiv();
static ast_node *parse_parexp();

ast_node *parse_tokens(const token_vector *tokens_input) {
  tokens = tokens_input;
  pos = 0;
  advance();
  return parse_operation();
}

static ast_node *parse_operation() {
  // id = expr
  if (current.type == TOKEN_IDEN && peek().type == TOKEN_ASIGN) {
    char *id = strdup(current.value);
    advance();
    expect(TOKEN_ASIGN);
    ast_node *value = parse_addsub();
    return new_assign(id, value);
  }

  // exit()
  if (current.type == TOKEN_EXIT) {
    advance();
    return new_exit();
  }

  // pure expression
  return parse_addsub();
}

static ast_node *parse_addsub() {
  ast_node *left = parse_multdiv();

  while (current.type == TOKEN_ADD || current.type == TOKEN_SUBS) {
    char op = current.value[0];
    advance();
    ast_node *right = parse_multdiv();
    left = new_binary(op, left, right);
  }
  return left;
}

static ast_node *parse_multdiv() {
  ast_node *left = parse_parexp();

  while (current.type == TOKEN_DIV || current.type == TOKEN_MULT) {
    char op = current.value[0];
    advance();
    ast_node *right = parse_parexp();
    left = new_binary(op, left, right);
  }
  return left;
}

static ast_node *parse_parexp() {
  // ( <expr> )
  if (current.type == TOKEN_LPAR) {
    advance();
    ast_node *inside = parse_addsub();
    expect(TOKEN_RPAR);
    return inside;
  }

  // number
  if (current.type == TOKEN_NUM) {
    double n = atof(current.value);
    advance();

    // exponent
    if (current.type == TOKEN_EXP) {
      advance();
      ast_node *right = parse_parexp();
      return new_binary('^', new_number(n), right);
    }

    return new_number(n);
  }

  // identifier
  if (current.type == TOKEN_IDEN) {
    ast_node *id = new_identifier(current.value);
    advance();
    return id;
  }

  fprintf(stderr, "Syntax error: unexpected '%s'\n", current.value);
  return NULL;
}
