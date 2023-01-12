#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliares1.h"

// Acrescentada variavel controlo para repetir insercao se ao for inserido numero int
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, MAX_CARACTERES, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }
        if(tamanhoString > maximoCaracteres)
        {
            printf("Demasiados caracteres!\n");
        }
    }
    while (tamanhoString == 1 || tamanhoString > maximoCaracteres);

    if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
    {
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString-1] = '\0'; 	//Elimina o \n da string armazenada em vetor
    }

}

void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}

void gravaFicheiroBinario(void)
{
    FILE *ficheiroBin;
    int elementosEscritos;
    ficheiroBin = fopen("dados.dat", "wb");
    if(ficheiroBin == NULL)
    {
        printf("Erro ao salvar o ficheiro");
    }
    else
    {
        // elementosEscritos = fwrite(vetor[],sizeof(variavel))
    }
}


tipoData lerData(void)
{
    tipoData data;
    int maxDiasMes;
    char mensagemDataAno[] = "\nInsira o ano: ";
    char mensagemDataMes[] = "\nInsira o mes:";
    char mensagemDataDia[] = "\nInsira o dia:";

    data.ano = lerInteiro(mensagemDataAno,MIN_ANO, MAX_ANO);
    data.mes = lerInteiro(mensagemDataMes,1, 12);

    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    data.dia = lerInteiro(mensagemDataDia,1, maxDiasMes);

    return data;
}
int transformaData (tipoData data)
{
    int i, diasAno, diasMes, diasTotal;
    diasAno = 365 * (data.ano - MIN_ANO);
    for (i = MIN_ANO; i<= data.ano; i++)
    {
        if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))
        {
            diasAno++;
        }
    }
    diasMes = 0;
    for (i = 0; i < data.mes; i++)
    {
        switch(i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            diasMes += 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasMes += 30;
            break;
        case 2:
            if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
            {
                diasMes += 29;
            }
            else
            {
                diasMes += 28;
            }
            break;
        }
    }
    diasTotal = data.dia + diasAno + diasMes;
//    printf("\n\n %d \n\n", diasMes);
//    printf("\n\n %d \n\n", diasAno);
//    printf("\n\n %d \n\n", data.dia);

    return diasTotal;
}
int menuFicheiros()
{
    int opcaoFicheiros;
    printf("Por favor introduza uma opcao\n");
    printf("1 - Armazenar dados dos computadores\n");
    printf("2 - Ler dados dos computadores\n");
    printf("3 - Armazenar dados das requisicoes\n");
    printf("4 - Ler dados das requisicoes\n");
    printf("0 - Voltar ao menu anterior\n");
    printf("Opcao: ");

    scanf("%d",&opcaoFicheiros);
    limpaBufferStdin();
    return opcaoFicheiros;
}
