#include "token.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// helpers functions for having a dynamic array of vectors.
void init_vector(token_vector *vector) {
  vector->size = 0;
  vector->capacity = 4;
  vector->data = malloc(vector->capacity * sizeof(token_t));
}

void push_back(token_vector *vector, token_t token) {
  if (vector->size == vector->capacity) {
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity * sizeof(token_t));
  }
  // reminder size++ first evaluates then increments
  vector->data[vector->size].type = token.type;
  strcpy(vector->data[vector->size++].value, token.value);
}

void free_vector(token_vector *vector) { free(vector->data); }

void print_tokens(token_vector *vector) {
  for (int i = 0; i < vector->size; i++) {
    printf("TOKEN_TYPE %d\tVALUE: %s\n", vector->data[i].type,
           vector->data[i].value);
  }
}

// should pass the token_vector already initialized
void tokenize(char *source, token_vector *tokens) {

  int source_index = 0;

  // initializes the struct with ceroes
  token_t buffer = {0};

  while (source[source_index] != '\n') {
    if (isspace(source[source_index])) {
      ++source_index;
      continue;
    }
    if (isalpha(source[source_index])) {

      int value_index = 0;
      while (isalpha(source[source_index])) {
        buffer.value[value_index++] = source[source_index++];
      }
      buffer.value[value_index] = '\0';
      buffer.type = TOKEN_IDEN;

      push_back(tokens, buffer);
      continue;
    }
    if (isdigit(source[source_index])) {
      int value_index = 0;
      while (isdigit(source[source_index]) || source[source_index] == '.') {
        buffer.value[value_index++] = source[source_index++];
      }
      buffer.value[value_index] = '\0';
      buffer.type = TOKEN_NUM;
      push_back(tokens, buffer);
      continue;
    }
    // if is a reserved keyword
    switch (source[source_index++]) {
    case ')':
      buffer.type = TOKEN_RPAR;
      strcpy(buffer.value, ")");
      break;
    case '(':
      buffer.type = TOKEN_LPAR;
      strcpy(buffer.value, "(");
      break;
    case '+':
      buffer.type = TOKEN_ADD;
      strcpy(buffer.value, "+");
      break;
    case '-':
      buffer.type = TOKEN_SUBS;
      strcpy(buffer.value, "-");
      break;
    case '/':
      buffer.type = TOKEN_DIV;
      strcpy(buffer.value, "/");
      break;
    case '*':
      buffer.type = TOKEN_MULT;
      strcpy(buffer.value, "*");
      break;
    case '=':
      buffer.type = TOKEN_ASIGN;
      strcpy(buffer.value, "=");
      break;
    case '^':
      buffer.type = TOKEN_EXP;
      strcpy(buffer.value, "^");
      break;
    default:
      buffer.type = TOKEN_UNKNOWN;
    }
    push_back(tokens, buffer);
  }
}
