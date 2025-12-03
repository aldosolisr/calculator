#include <stdio.h>
#include "ast_print.h"

static void indent(int n) {
    for (int i = 0; i < n; i++)
        printf("  "); // dos espacios por nivel
}

void print_ast_indented(const ast_node *node, int indent_level) {
    if (!node) {
        indent(indent_level);
        printf("(null)\n");
        return;
    }

    switch (node->type) {

    case AST_NUMBER:
        indent(indent_level);
        printf("NUMBER: %g\n", node->as.number);
        break;

    case AST_IDENTIFIER:
        indent(indent_level);
        printf("IDENT: %s\n", node->as.identifier);
        break;

    case AST_BINARY:
        indent(indent_level);
        printf("BINARY '%c'\n", node->as.binary.op);

        indent(indent_level);
        printf("├─LEFT:\n");
        print_ast_indented(node->as.binary.left, indent_level + 1);

        indent(indent_level);
        printf("└─RIGHT:\n");
        print_ast_indented(node->as.binary.right, indent_level + 1);
        break;

    case AST_ASSIGN:
        indent(indent_level);
        printf("ASSIGN '%s'\n", node->as.assign.id);

        indent(indent_level);
        printf("└─VALUE:\n");
        print_ast_indented(node->as.assign.value, indent_level + 1);
        break;

    case AST_EXIT:
        indent(indent_level);
        printf("EXIT()\n");
        break;

    default:
        indent(indent_level);
        printf("UNKNOWN NODE\n");
    }
}

void print_ast(const ast_node *node) {
    print_ast_indented(node, 0);
}

