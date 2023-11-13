LEX=flex
YY=bison
CC=gcc
BIN = sintatico
L_SOURCE = lexico.l
Y_SOURCE = sintatico.y
CFLAGS = -std=c99 -I. -w

$(BIN): $(L_SOURCE) $(Y_SOURCE)
	$(LEX) $(L_SOURCE)
	$(YY) -d $(Y_SOURCE)
	$(CC) *.c $(CFLAGS) -o $(BIN)

# [REMOVER]
teste:
	./$(BIN) < ./testes/teste_01.c > saida.txt

# [REMOVER]	
exec:
	./$(BIN) < testes/teste_01.c > saidas/teste_01.txt
	./$(BIN) < testes/teste_02.c > saidas/teste_02.txt
	./$(BIN) < testes/teste_03.c > saidas/teste_03.txt
	./$(BIN) < testes/teste_04.c > saidas/teste_04.txt
	./$(BIN) < testes/teste_05.c > saidas/teste_05.txt	
	./$(BIN) < testes/teste_06.c > saidas/teste_06.txt	
	./$(BIN) < testes/teste_07.c > saidas/teste_07.txt	
	./$(BIN) < testes/teste_08.c > saidas/teste_08.txt	
	./$(BIN) < testes/teste_09.c > saidas/teste_09.txt	
	./$(BIN) < testes/teste_10.c > saidas/teste_10.txt	

# [REMOVER]	
compare:	
	diff saidas/teste_01.txt saidas_padrao/saida_teste_01.c.txt
	diff saidas/teste_02.txt saidas_padrao/saida_teste_02.c.txt
	diff saidas/teste_03.txt saidas_padrao/saida_teste_03.c.txt
	diff saidas/teste_04.txt saidas_padrao/saida_teste_04.c.txt
	diff saidas/teste_05.txt saidas_padrao/saida_teste_05.c.txt
	diff saidas/teste_06.txt saidas_padrao/saida_teste_06.c.txt
	diff saidas/teste_07.txt saidas_padrao/saida_teste_07.c.txt
	diff saidas/teste_08.txt saidas_padrao/saida_teste_08.c.txt
	diff saidas/teste_09.txt saidas_padrao/saida_teste_09.c.txt
	diff saidas/teste_10.txt saidas_padrao/saida_teste_10.c.txt

clear:
	rm $(BIN)
	rm lex.yy.c
	rm sintatico.tab.*
