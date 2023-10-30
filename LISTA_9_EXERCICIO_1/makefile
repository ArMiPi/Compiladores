CC = g++
EXEC = l9e1
OBJS = string_utils.cpp \
       Automato.cpp \
	   Lexico.cpp LexicoException.cpp \
	   Sintatico.cpp SintaticoException.cpp 
FLAGS = -g -o

all:
	$(CC) $(OBJS) $(EXEC).cpp $(FLAGS) $(EXEC)

$(EXEC):
	$(CC) $(OBJS) $(EXEC).cpp $(FLAGS) $(EXEC)

teste:
	./$(EXEC) < input.txt > saida.txt

generate:
	./$(EXEC) < exerc_09_input.output/entrada_01.txt > saidas/saida01.txt
	./$(EXEC) < exerc_09_input.output/entrada_02.txt > saidas/saida02.txt
	./$(EXEC) < exerc_09_input.output/entrada_03.txt > saidas/saida03.txt
	./$(EXEC) < exerc_09_input.output/entrada_04.txt > saidas/saida04.txt
	./$(EXEC) < exerc_09_input.output/entrada_05.txt > saidas/saida05.txt
	./$(EXEC) < exerc_09_input.output/entrada_06.txt > saidas/saida06.txt

compare:
	diff exerc_09_input.output/saida_01.txt saidas/saida01.txt
	diff exerc_09_input.output/saida_02.txt saidas/saida02.txt
	diff exerc_09_input.output/saida_03.txt saidas/saida03.txt
	diff exerc_09_input.output/saida_04.txt saidas/saida04.txt
	diff exerc_09_input.output/saida_05.txt saidas/saida05.txt
	diff exerc_09_input.output/saida_06.txt saidas/saida06.txt

clear:
	rm $(EXEC)
