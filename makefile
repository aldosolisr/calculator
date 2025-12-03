all:
	gcc -o calculator main.c tokenizer.c parser.c ast_print.c ast.c symbol_table.c eval.c -lm

run: 
	./calculator
