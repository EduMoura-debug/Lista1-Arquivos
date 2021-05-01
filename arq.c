#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    FILE * f;

    f = fopen("candidatosB.dat", "w");
    if(f == NULL)
    {
       fprintf(stderr,"Arquivo %s não pode ser criado para escrita\n");
       return 1;
    }

    Registro e = { 1 , "bcc", "123.456.789-30", "21/08/2000", 'M', "1email@email.com", 'A'};
    fwrite (&e, sizeof(Registro), 1, f);

    Registro e1 = { 2 , "bcc", "123.456.789-31", "21/08/2000", 'M', "2email@email.com", 'A'};
    fwrite (&e1, sizeof(Registro), 1, f);

    Registro e2 = { 3 , "bcc", "123.456.789-32", "21/08/2000", 'M', "3email@email.com", 'A'};
    fwrite (&e2, sizeof(Registro), 1, f);

    Registro e3 = { 4 , "bcc", "123.456.789-33", "21/08/2000", 'M', "4email@email.com", 'A'};
    fwrite (&e3, sizeof(Registro), 1, f);

    Registro e4 = { 5 , "bcc", "123.456.789-14", "21/08/2000", 'M', "5email@email.com", 'A'};
    fwrite (&e4, sizeof(Registro), 1, f);
    
    Registro e5 = { 6 , "bcc", "123.456.789-35", "21/08/2000", 'M', "6email@email.com", 'A'};
    fwrite (&e5, sizeof(Registro), 1, f);

    Registro e6 = { 7 , "bcc", "123.456.789-36", "21/08/2000", 'M', "7email@email.com", 'A'};
    fwrite (&e6, sizeof(Registro), 1, f);

    Registro e7 = { 8 , "bcc", "123.456.789-37", "21/08/2000", 'M', "8email@email.com", 'A'};
    fwrite (&e7, sizeof(Registro), 1, f);

     Registro e8 = { 9 , "bcc", "123.456.789-18", "21/08/2000", 'M', "9email@email.com", 'A'};
    fwrite (&e8, sizeof(Registro), 1, f);
    
    Registro e9 = { 10 , "bcc", "123.456.789-39", "21/08/2000", 'M', "10email@email.com", 'A'};
    fwrite (&e9, sizeof(Registro), 1, f);

    Registro e10 = { 11 , "bcc", "123.456.789-40", "21/08/2000", 'M', "11email@email.com", 'A'};
    fwrite (&e10, sizeof(Registro), 1, f);

    Registro e11 = { 12 , "bcc", "123.456.789-42", "21/08/2000", 'M', "12email@email.com", 'A'};
    fwrite (&e11, sizeof(Registro), 1, f);

    Registro e12 = { 13 , "bcc", "123.456.789-23", "21/08/2000", 'M', "13email@email.com", 'A'};
    fwrite (&e12, sizeof(Registro), 1, f);
    
    Registro e13 = { 14 , "bcc", "123.456.789-44", "21/08/2000", 'M', "14email@email.com", 'A'};
    fwrite (&e13, sizeof(Registro), 1, f);

    Registro e14 = { 15 , "bcc", "123.456.789-45", "21/08/2000", 'M', "15email@email.com", 'A'};
    fwrite (&e14, sizeof(Registro), 1, f);

    Registro e15= { 16 , "bcc", "123.456.789-46", "21/08/2000", 'M', "16email@email.com", 'A'};
    fwrite (&e15, sizeof(Registro), 1, f);

     Registro e16 = { 17 , "bcc", "123.456.789-27", "21/08/2000", 'M', "17email@email.com", 'A'};
    fwrite (&e16, sizeof(Registro), 1, f);
    
    Registro e17 = { 18 , "bcc", "123.456.789-28", "21/08/2000", 'M', "18email@email.com", 'A'};
    fwrite (&e17, sizeof(Registro), 1, f);

    Registro e18 = { 19 , "bcc", "123.456.789-41", "21/08/2000", 'M', "19email@email.com", 'A'};
    fwrite (&e18, sizeof(Registro), 1, f);

    Registro e19 = { 20 , "bcc", "123.456.789-49", "21/08/2000", 'M', "20email@email.com", 'A'};
    fwrite (&e19, sizeof(Registro), 1, f);


    fclose(f);
    printf("\n\nArquivo Criado \n");

    return 0;
}