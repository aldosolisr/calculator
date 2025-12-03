all:
	gcc -o calculator main.c tokenizer.c parser.c ast_print.c

run: 
	./calculator
