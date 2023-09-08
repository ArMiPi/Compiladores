CC = gcc
EXECUTAVEL = l7e3

all:
	flex $(EXECUTAVEL).l
	$(CC) lex.yy.c -o $(EXECUTAVEL)

exec:
	./$(EXECUTAVEL) < input.txt > ss.txt

clear:
	rm *c
	rm $(EXECUTAVEL)