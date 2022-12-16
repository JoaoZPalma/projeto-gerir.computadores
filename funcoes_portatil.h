#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "constantes1.h"
#include "funcoes_auxiliares1.h"

typedef struct
{
    int identificacao, processador, ram, estadoPortatil, localizacaoPortatil, quantidadeAvarias, quantidadeRequisicoes;
    char designacao[15];
    tipoData dataAquisicao;
    float valor;

}tipoPortatil;

#endif
