#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "token.h"
#include "parser.h"
#include "ast_print.h"
#include "eval.h"
#include "symbol_table.h"

void handler(int sig){
    printf("\ninterrupt detected: press ctrl + d to exit ...\n");
}

int main(int argc, char **argv){
    char buffer[255];

    signal(SIGINT, handler);

    token_vector tokens;
    symbol_table table;      
    symbol_table_init(&table);

    printf("press ctrl + d to exit ...\n\n");

    // REPL
    while(fgets(buffer, sizeof(buffer), stdin)){
        init_vector(&tokens);
        tokenize(buffer, &tokens);

        ast_node *root = parse_tokens(&tokens);

        // print_ast_indented(root, 2);

        double result = eval_ast(root, &table);

        if (root && root->type != AST_ASSIGN && root->type != AST_EXIT)
            printf("= %g\n", result);

        free_ast(root);
        free_vector(&tokens);
    }

    symbol_table_free(&table);

    return EXIT_SUCCESS;
}

