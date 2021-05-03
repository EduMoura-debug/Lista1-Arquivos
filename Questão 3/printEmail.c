#include <stdio.h>
#include <string.h>

struct Registro {
    int id_inscricao;
    char curso[20];
    char cpf[15];
    char dataNacimento[11];
    char sexo;
    char email[40];
    char opcaoQuadro;
};
typedef struct Registro Registro;


// Complexidade O(nlog(n))

int buscaBinaria(FILE *f, Registro reg)
{
    Registro e;
    fseek(f, 0, SEEK_END);
	rewind(f);
	
	int qt = fread(&e,sizeof(Registro),1,f);	
    while(qt>0)
	{   	
	
		if(strncmp(reg.cpf,e.cpf,15)==0)
		{   
            return 0;

		}
		qt = fread(&e,sizeof(Registro),1,f);
	}
    return -1;
}

int main(int argc, char**argv)
{
	FILE *arqA, *arqB;
	Registro e1, e2;
	int regA, regB, encontrado;
    
    if(argc != 3)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO A] [ARQUIVO B].\n", argv[0]);
		return 1;
	}
    arqA = fopen(argv[1],"r");
	if(!arqA)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}
	arqB = fopen(argv[2],"r");
	if(!arqB)
	{
		fclose(arqA);
		fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
		return 1;
	} 

	regA = fread(&e1,sizeof(Registro),1,arqA);
	while(regA > 0)
	{	
        encontrado = buscaBinaria(arqB, e1);
        if (encontrado == 0)
        {	
            printf("\n%s\n", e1.email);
        }
		regA = fread(&e1 ,sizeof(Registro),1,arqA);	
	}
	fclose(arqA);
	fclose(arqB);
}