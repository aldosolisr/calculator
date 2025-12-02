#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	char buffer[255];

	// while is text in stdin
	while(fgets(buffer, sizeof(buffer), stdin)){
		buffer[strlen(buffer) - 1] = '\0';
		printf("%s\n", buffer);
	}

	return EXIT_SUCCESS;
}
