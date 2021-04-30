
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <math.h>


int main(int argc, char** argv) {

    FILE *entrada;
	char *caracter;  

    int linha = 0;
    int novaPalavra = 0;
    int palavras = 0;
    int chars = 0;
    
	if(argc != 2)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [NOME DO ARQUIVO].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"r");
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

	 while (!feof(entrada)) {
          fread(caracter, 1, 1, entrada);
          chars++;
          if  ((*caracter!=' ') && (*caracter!='\n') && (!novaPalavra)) {
             novaPalavra = 1;
          }
          if  (((*caracter==' ') || (*caracter == '\n')) && (novaPalavra)) {
             novaPalavra = 0;
             palavras++;
          }
          if (*caracter=='\n') {
             linha++;
             }
   
   }   
    printf("\nNumero de palavras = %d\n", palavras);       
    printf("\nNumero de caracteres = %d\n", chars);
    printf("\nNumero de linhas = %d\n", linha+1);
	fclose(entrada);
	return 0;
}


