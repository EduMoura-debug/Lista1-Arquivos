#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

// Complexidade O(n^2)

int main(int argc, char** argv)
{
    FILE *entrada, *saida;
	int qt;
	long tamanho, tamanho_saida;
	Registro e, eProx, eMaior;

	if(argc != 3)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO INICIAL] [ARQUIVO SAIDA].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"r");//rb+
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}
	fseek(entrada,0,SEEK_END);
	tamanho = ftell(entrada);
	rewind(entrada);

	saida = fopen(argv[2],"w");//wb
	if(!saida)
	{
		fclose(entrada);
		fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
		return 1;
	}

	qt = fread(&e,sizeof(Registro),1,entrada);
	fread(&eProx,sizeof(Registro),1,entrada);
	while(qt > 0)
	{
		if(feof(entrada))
		{
			break;
		}
		if(strncmp(e.cpf,eProx.cpf,15)==0)
		{
			if(e.id_inscricao > eProx.id_inscricao)
			{
				eMaior = e;
			}
			else
			{
				eMaior = eProx;
			}
			qt = fread(&eProx,sizeof(Registro),1,entrada);
			if(qt == 0){
				break;
			}
			if (strncmp(eMaior.cpf,eProx.cpf,15)==0)
			{
				while(strncmp(eMaior.cpf,eProx.cpf,15)==0)
				{
					if(eProx.id_inscricao > eMaior.id_inscricao)
					{
						eMaior = eProx;
					}
					qt = fread(&eProx,sizeof(Registro),1,entrada);
					if(qt == 0)
					{
						break;
					}
				}
			}
			e = eProx;
			fwrite(&eMaior,sizeof(Registro),1,saida);
		}
		else
		{
			fwrite(&e,sizeof(Registro),1,saida);
			e = eProx;
		}
		qt = fread(&eProx,sizeof(Registro),1,entrada);		
	}
	if(ftell(entrada) == tamanho)
	{
		fwrite(&e,sizeof(Registro),1,saida);
	}
	fseek(saida,0,SEEK_END);
	tamanho_saida = ftell(saida);
	printf("Tamanho do Arquivo inicial em registros: %ld\n", tamanho/sizeof(Registro));
	printf("Tamanho do Arquivo saida em registros: %ld\n", tamanho_saida/sizeof(Registro));

	fclose(entrada);
	fclose(saida);
	return 0;
}