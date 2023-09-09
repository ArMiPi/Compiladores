CC = gcc
EXECUTAVEL = cstats

all:
	flex $(EXECUTAVEL).l
	$(CC) -o $(EXECUTAVEL) lex.yy.c -ll

clear:
	rm lex.yy.c
	rm $(EXECUTAVEL)