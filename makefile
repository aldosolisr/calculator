all:
	gcc -o compiler main.c tokenizer.c

run: 
	./compiler
