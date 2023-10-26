CC = g++
EXEC = l9e1
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
