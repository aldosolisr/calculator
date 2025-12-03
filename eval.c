#include "eval.h"
#include "token.h"
#include <math.h>
#include <stdio.h>

double eval_ast(ast_node *node, symbol_table *table) {
    if (!node) return 0;

    switch (node->type) {

    case AST_NUMBER:
        return node->as.number;

    case AST_IDENTIFIER: {
        int found = 0;
        double val = symbol_table_get(table, node->as.identifier, &found);
        if (!found) {
            fprintf(stderr, "Error: variable '%s' not defined\n", node->as.identifier);
            return 0;
        }
        return val;
    }

    case AST_BINARY: {
        double left = eval_ast(node->as.binary.left, table);
        double right = eval_ast(node->as.binary.right, table);

        switch (node->as.binary.op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        case '^': return pow(left, right);
        default:
            fprintf(stderr, "Error: uknown operand\n");
            return 0;
        }
    }

    case AST_ASSIGN:
        symbol_table_set(table, node->as.assign.id, eval_ast(node->as.assign.value, table));
        return 0;

    case AST_EXIT:
        printf("Bye!\n");
        exit(0);
    }

    return 0;
}

