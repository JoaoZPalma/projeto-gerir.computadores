#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "constantes1.h"
#include "funcoes_auxiliares1.h"

typedef struct
{
    int identificacaoPortatil, tipoUtente, prazoRequisicao, estadoRequisicao, localDevolucao;
    char codigo[10], nome[50];
    tipoData dataRequisicao, dataDevolucao;
    float multa;

}tipoRequisicao;

#endif
