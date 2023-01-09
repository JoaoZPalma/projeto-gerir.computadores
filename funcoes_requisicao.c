#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliares1.h"
#include "funcoes_requisicao.h"
#include "funcoes_portatil.h"

char mensagemTipoUtente[] = "\nTipo de utente:\n1-Estudante\n2-Docente\n3-Tecnico Administrativo";
char mensagemPrazoRequisicao[] = "\nPor quantos dias deseja fazer a requisicao?:";
char mensagemCodigo[] = "\nInsira o codigo respetivo a requisicao: ";
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

    }



}


int procurarRequisicaoPorCodigo(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes, char codigo[])
{
    int i,pos;
    pos = -1;

    if (codigo==-1)
    {

        // printf("Insira o numero de identificacao\n");
        lerString(mensagemCodigo,codigo,MAX_CODIGO);
    }
    if (quantidadeRequisicoes == 0)
    {
        printf("Nao existem requisicoes efetuadas\n");
    }
    else
    {
        for(i=0; i<quantidadeRequisicoes; i++)
        {

            if (strcmp(codigo[MAX_CODIGO],vetorRequisicoes->codigo==0))
            {
                pos = i;
                i = quantidadeRequisicoes;
            }
            else
            {
                printf("Nao foi possivel encontrar a requisicao com o codigo que disponibilizou\n\n");
            }
        }
    }
    return pos;
}


//void devolucao(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes)
//{
//
//
//
//}


















//tipoData calculaDataDevolucao(tipoData dataRequisicao, int prazoRequisicao)
//{
//    tipoData dataDevolucao;
//    dataDevolucao.mes=dataRequisicao.mes;
//    dataDevolucao.ano=dataRequisicao.ano;
//    int diasMes,i;
//    for (i = 0; i < dataRequisicao.mes; i++)
//    {
//        switch(i)
//        {
//        case 1:
//        case 3:
//        case 5:
//        case 7:
//        case 8:
//        case 10:
//            diasMes = 31;
//            break;
//        case 4:
//        case 6:
//        case 9:
//        case 11:
//            diasMes = 30;
//            break;
//        case 2:
//            if ((dataRequisicao.ano % 400 == 0) || (dataRequisicao.ano % 4 == 0 && dataRequisicao.ano % 100 != 0))
//            {
//                diasMes = 29;
//            }
//            else
//            {
//                diasMes = 28;
//            }
//            break;
//        }
//    }
//    while (prazoRequisicao+dataRequisicao.dia>diasMes)
//    {
//    dataDevolucao.dia = prazoRequisicao+dataRequisicao.dia-diasMes;
//    dataDevolucao.mes++;
//    }
//
//printf("%d//%d//%d",dataDevolucao.dia,dataDevolucao.mes,dataDevolucao.ano);
//}
