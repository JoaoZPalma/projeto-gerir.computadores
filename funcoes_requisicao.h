#ifndef FUNCOES_REQUISICAO_H_INCLUDED
#define FUNCOES_REQUISICAO_H_INCLUDED

#include "constantes1.h"
#include "funcoes_auxiliares1.h"
#include "funcoes_portatil.h"

//char mensagemCodigo[] = "\nInsira o codigo respetivo a requisicao: ";


typedef struct
{
    int identificacaoPortatil, tipoUtente, prazoRequisicao, estadoRequisicao, localDevolucao;
    char codigo[10], nome[50];
    tipoData dataRequisicao, dataDevolucao;
    float multa;

}tipoRequisicao;

void requisitarPortatil(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes,tipoPortatil vetorPortateis[],int pos,tipoData dataAtual);
//tipoData calculaDataDevolucao(tipoData dataRequisicao, int prazoRequisicao);
int procurarRequisicaoPorCodigo(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes,char codigo[]);
void mostrarRequisicaoPorPosicao(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes,int pos);


#endif
