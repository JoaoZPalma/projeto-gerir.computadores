#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "constantes1.h"

typedef struct
{
    int dia, mes, ano;
} tipoData;

typedef struct
{
    int identificacao, processador, ram, estadoPortatil, localizacaoPortatil, quantidadeAvarias, quantidadeRequisicoes, totalDiasRequisicao, diasAvariado, avaria;
    char designacao[15];
    tipoData dataAquisicao;
    float valor;
    tipoData dataAvaria;

} tipoAvaria;

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);
tipoData lerData(void);
int transformaData(tipoData data);
int menuFicheiros();

#endif // FUNCOES_AUXILIARES_H_INCLUDED
