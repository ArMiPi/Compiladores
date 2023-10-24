CC = gcc
EXECUTAVEL = lexico

all:
	flex $(EXECUTAVEL).l
	$(CC) -o $(EXECUTAVEL) lex.yy.c

# [REMOVER]
exec:
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_01.c > ../Trabalho/script_teste_lexico/saidas/teste_01.txt
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_02.c > ../Trabalho/script_teste_lexico/saidas/teste_02.txt
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_03.c > ../Trabalho/script_teste_lexico/saidas/teste_03.txt
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_04.c > ../Trabalho/script_teste_lexico/saidas/teste_04.txt
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_05.c > ../Trabalho/script_teste_lexico/saidas/teste_05.txt	
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_06.c > ../Trabalho/script_teste_lexico/saidas/teste_06.txt	
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_07.c > ../Trabalho/script_teste_lexico/saidas/teste_07.txt	
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_08.c > ../Trabalho/script_teste_lexico/saidas/teste_08.txt	
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_09.c > ../Trabalho/script_teste_lexico/saidas/teste_09.txt	
	./$(EXECUTAVEL) < ../Trabalho/script_teste_lexico/testes/teste_10.c > ../Trabalho/script_teste_lexico/saidas/teste_10.txt	

# [REMOVER]	
compare:	
	diff ../Trabalho/script_teste_lexico/saidas/teste_01.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_01.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_02.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_02.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_03.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_03.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_04.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_04.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_05.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_05.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_06.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_06.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_07.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_07.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_08.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_08.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_09.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_09.c.txt
	diff ../Trabalho/script_teste_lexico/saidas/teste_10.txt ../Trabalho/script_teste_lexico/saidas_padrao/saida_teste_10.c.txt

# [REMOVER]
teste:
	./$(EXECUTAVEL) < teste.txt > ss.txt

clear:
	rm lex.yy.c
	rm $(EXECUTAVEL)