#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliares1.h"
#include "funcoes_requisicao.h"
#include "funcoes_portatil.h"

char mensagemTipoUtente[] = "\nTipo de utente:\n1-Estudante\n2-Docente\n3-Tecnico Administrativo";
char mensagemPrazoRequisicao[] = "\nPor quantos dias deseja fazer a requisicao?:";
char mensagemCodigo[] = "\nInsira o respetivo codigo da requisicao: ";
char mensagemNome[] = "\nInsira o nome do Utente que pretende realizar a requisicao: ";


void requisitarPortatil(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes,tipoPortatil vetorPortateis[],int pos,tipoData dataAtual)
{
    tipoData dataDevolucao;
    vetorRequisicoes[quantidadeRequisicoes].dataRequisicao = dataAtual;
    int dataAquisicao = transformaData(vetorPortateis[pos].dataAquisicao);
    int dataRequisicao = transformaData(dataAtual);
    printf("%d/////%d",dataAquisicao,dataRequisicao);
//VERIFICAR SE ESTA DISPONIVEL
    if (dataAquisicao <= dataRequisicao)
    {
        lerString(mensagemCodigo,vetorRequisicoes[quantidadeRequisicoes].codigo,MAX_CODIGO);
        vetorRequisicoes[quantidadeRequisicoes].identificacaoPortatil = vetorPortateis[pos].identificacao;
        lerString(mensagemNome,vetorRequisicoes[quantidadeRequisicoes].nome,MAX_STRING);
        vetorRequisicoes[quantidadeRequisicoes].tipoUtente = lerInteiro(mensagemTipoUtente,1,3);
        vetorRequisicoes[quantidadeRequisicoes].prazoRequisicao = lerInteiro(mensagemPrazoRequisicao,1,30);
        vetorRequisicoes[quantidadeRequisicoes].dataDevolucao.ano = -1;
        vetorRequisicoes[quantidadeRequisicoes].dataDevolucao.mes = -1;
        vetorRequisicoes[quantidadeRequisicoes].dataDevolucao.dia = -1;
        vetorRequisicoes[quantidadeRequisicoes].estadoRequisicao = 1;
        vetorRequisicoes[quantidadeRequisicoes].localDevolucao = -1; //1- Ativa, 2- Concluida
        vetorRequisicoes[quantidadeRequisicoes].multa = 0;

        //      vetorRequisicoes[quantidadeRequisicoes].dataDevolucao =
//           vetorRequisicoes[quantidadeRequisicoes].
        //          vetorRequisicoes[quantidadeRequisicoes].
        //quantidadeRequisicoes++;
    }



}


int procurarRequisicaoPorCodigo(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes, char codigo[])
{
    int i,pos,testar;
//    if ((strcmp(vetorRequisicoes[]->codigo[MAX_CODIGO],codigo[MAX_CODIGO])==0))
//    {
//
//        // printf("Insira o numero de identificacao\n");
//        lerString(mensagemCodigo,codigo,MAX_CODIGO);
//    }
    if (quantidadeRequisicoes == 0)
    {
        printf("Nao existem requisicoes efetuadas\n");
    }
    else
    {
        for(i=0; i<quantidadeRequisicoes; i++)
        {
            testar = strcmp(codigo,vetorRequisicoes[i].codigo);
            //printf("%d",testar);

            if (testar==0)
            {
                pos = i;
                i = quantidadeRequisicoes;
            }
            else
            {
                printf("Nao foi possivel encontrar a requisicao com o codigo que disponibilizou\n\n");
                pos = -1;
            }
        }
    }
    //printf("%d",pos);
    return pos;
}

void mostrarRequisicaoPorPosicao(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes,int pos)
{
    printf("----------------------------------------------------------------------------------\n");
    printf("A requisicao de codigo: %s possui os seguintes dados:\n",vetorRequisicoes[pos].codigo);
    printf("O computador requisitado possui o id: %d\n",vetorRequisicoes[pos].identificacaoPortatil);
    printf("O nome do utente responsavel pela requisicao: %s\n",vetorRequisicoes[pos].nome);

    switch(vetorRequisicoes[pos].tipoUtente)
    {
    case 1:
        printf("Tipo de utente: Estudante\n");
        break;
    case 2:
        printf("Tipo de utente: Docente\n");
        break;
    case 3:
        printf("Tipo de utente: Tecnico administrativo\n");
        break;
    }
    printf("Data da requisicao : %d/%d/%d\n",vetorRequisicoes[pos].dataRequisicao.dia,vetorRequisicoes[pos].dataRequisicao.mes,vetorRequisicoes[pos].dataRequisicao.ano);
    printf("O prazo da requisicao (dias): %d\n",vetorRequisicoes[pos].prazoRequisicao);
    switch(vetorRequisicoes[pos].estadoRequisicao)
    {
    case 1:
        printf("Estado da requisicao: Ativa\n");
        break;
    case 2:
        printf("Estado da requisicao: Concluida\n");
        break;
    }
    switch(vetorRequisicoes[pos].localDevolucao)
    {
    case -1:
        printf("Local da devolucao: --------- \n");
        break;
    case 1:
        printf("Local da devolucao: Campus1\n");
        break;
    case 2:
        printf("Local da devolucao: Campus2\n");
        break;
    case 3:
        printf("Local da devolucao: Campus5\n");
        break;
    case 4:
        printf("Local da devolucao: Residencias\n");
        break;
    }
    if (vetorRequisicoes[pos].dataDevolucao.dia==-1)
    {
        printf("Data de devolucao: ----------\n");
    }
    else
    {
        printf("Data de devolucao: %d,%d,%d",vetorRequisicoes[pos].dataDevolucao.dia,vetorRequisicoes[pos].dataDevolucao.mes,vetorRequisicoes[pos].dataDevolucao.ano);
    }
    printf("----------------------------------------------------------------------------------\n");


}
int calculaDuracao(tipoData dataDevolucao, tipoData dataRequisicao)
{
    int diasDataDevolucao = transformaData(dataDevolucao);
    int diasDataRequisicao = transformaData(dataRequisicao);

    int duracao = diasDataDevolucao - diasDataRequisicao;

    return duracao;
}
