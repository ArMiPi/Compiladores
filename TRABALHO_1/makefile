CC = g++
EXEC = portugol
OBJS = string_utils.cpp Automato.cpp Lexico.cpp
FLAGS = -g -o

all:
	$(CC) $(OBJS) $(EXEC).cpp $(FLAGS) $(EXEC)

$(EXEC):
	$(CC) $(OBJS) $(EXEC).cpp $(FLAGS) $(EXEC)

teste:
	./$(EXEC) < input.txt > saida.txt

clear:
	rm $(EXEC)
