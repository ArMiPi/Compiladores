CC = gcc
EXECUTAVEL = l7e1

all:
	flex $(EXECUTAVEL).l
	$(CC) lex.yy.c -o $(EXECUTAVEL)

exec:
	./$(EXECUTAVEL) < input.txt > ss.txt

clear:
	rm *c
	rm $(EXECUTAVEL)