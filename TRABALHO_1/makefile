CC = g++
EXEC = portugol
OBJS = string_utils.cpp \
       Automato.cpp \
	   Lexico.cpp LexicoException.cpp \
	   Sintatico.cpp SintaticoException.cpp 
FLAGS = -std=c++23 -g -o

all:
	$(CC) $(OBJS) $(EXEC).cpp $(FLAGS) $(EXEC)

$(EXEC):
	$(CC) $(OBJS) $(EXEC).cpp $(FLAGS) $(EXEC)

clear:
	rm $(EXEC)
