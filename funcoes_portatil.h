#ifndef FUNCOES_PORTATIL_H_INCLUDED
#define FUNCOES_PORTATIL_H_INCLUDED

#include "funcoes_auxiliares1.h"

typedef struct
{
    int identificacao, processador, ram, estadoPortatil, localizacaoPortatil, quantidadeAvarias, quantidadeRequisicoes, totalDiasRequisicao;
    char designacao[15];
    tipoData dataAquisicao;
    float valor;
} tipoPortatil;

void registarPortatil(tipoPortatil vetor[],int quantidadeDeComputadoresRegistados);
void mostrarInformacaoPortatilPorPosicao(tipoPortatil vetor[], int posicao);
int menuRegistoPortatil();
int menuRAM();
int procurarPortatilPorIdentificacao(tipoPortatil vetor[],int quantidadePortateisRegistados, int numeroIdentificacao, int mostrarMensagem);
int alterarLocalizacaoPortatil(tipoPortatil vetor[], int quantidadePortateisRegistados);

#endif
