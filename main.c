#include <stdio.h>
#include "token.h"
#include <stdlib.h>

int main(int argc, char **argv){
	char buffer[255];

  token_vector tokens;
  init_vector(&tokens);

	// while is text in stdin
	while(fgets(buffer, sizeof(buffer), stdin)){
    tokenize(buffer, &tokens);
    print_tokens(&tokens);
	}

  free_vector(&tokens);

	return EXIT_SUCCESS;
}
