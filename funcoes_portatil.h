//#ifndef FUNCOES_AUXILIARES_H_INCLUDED
//#define FUNCOES_AUXILIARES_H_INCLUDED

#ifndef FUNCOES_PORTATIL_H_INCLUDED
#define FUNCOES_PORTATIL_H_INCLUDED

#include "funcoes_auxiliares1.h"
//#include "constantes1.h"

typedef struct
{
    int identificacao, processador, ram, estadoPortatil, localizacaoPortatil, quantidadeAvarias, quantidadeRequisicoes, totalDiasRequisicao;
    char designacao[15];
    tipoData dataAquisicao;
    float valor;

}tipoPortatil;



void registarPortatil(tipoPortatil vetor[],int quantidadeDeComputadoresRegistados);
void mostrarInformacaoPortatilPorPosicao(tipoPortatil vetor[], int posicao);
int menuRegistoPortatil();
int menuRAM();
int procurarPortatilPorIdentificacao(tipoPortatil vetor[],int quantidadePortateisRegistados, int numeroIdentificacao);
void alterarLocalizacaoPortatil(tipoPortatil vetor[], int quantidadePortateisRegistados);


#endif
