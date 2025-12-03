#include <stdio.h>
#include "token.h"
#include "parser.h"
#include "ast_print.h"
#include <stdlib.h>
#include <signal.h>

void handler(int sig){
  printf("\ninterrupt detected: press ctrl + d to exit ...\n");
}

int main(int argc, char **argv){
	char buffer[255];

  // para no permitir terminar el programa y liberar memoria 
  // adecuadamente.
  signal(SIGINT, handler);

  token_vector tokens;

	// while is text in stdin
  printf("press ctrl + d to exit ...\n\n");
	while(fgets(buffer, sizeof(buffer), stdin)){
    init_vector(&tokens);
    tokenize(buffer, &tokens);
    print_tokens(&tokens);
    ast_node *root = parse_tokens(&tokens);
    print_ast_indented(root, 2);
    free_vector(&tokens);
	}


	return EXIT_SUCCESS;
}
