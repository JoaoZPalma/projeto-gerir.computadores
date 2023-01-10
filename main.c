#include <stdio.h>
#include <stdlib.h>



#include "constantes1.h"
#include "funcoes_auxiliares1.h"
#include "funcoes_portatil.h"
#include "funcoes_requisicao.h"

int menuPrincipal(int quantidadePortateisRegistados, int quantidadeRequisicoes, int quantidadeRequisicoesAtivas, int quantidadePortateisIndisponiveis);
char mensagemRepetir[]="Deseja repetir o procedimento?";
char mensagemPedirNumeroIdentificaoPortatil[] = "Insira o numero de identificao do portatil:\t";
char mensagemIdRequisicao[]="Por favor introduza o id do portatil que quer requisitar\n";


int main()
{
    int quantidadePortateisRegistados = 0;
    int quantidadeRequisicoes = 0;
    int quantidadePortateisIndisponiveis = 0;
    int quantidadeRequisicoesAtivas = 0;
    int repetir=0;
    int *vetorRequisicoes;
    vetorRequisicoes = NULL;


    char mensagemCodigo[] = "\nInsira o codigo respetivo a requisicao: ";
    char codigo[MAX_CODIGO];

    int opcaoPrincipal, quantidadePortateisDisponiveis, opcaoRegisto, i, pos, idRequisicao;
    tipoPortatil vetorPortateis[MAX_PORTATEIS];

    tipoData dataAtual;
    printf("Insira a data atual\n");
    dataAtual = lerData();
    do
    {



        opcaoPrincipal = menuPrincipal(quantidadePortateisRegistados, quantidadeRequisicoes, quantidadeRequisicoesAtivas, quantidadePortateisIndisponiveis);
        switch (opcaoPrincipal)
        {
        case 1: //Realizar registo de 1 computador
            do
            {
                opcaoRegisto = menuRegistoPortatil();
                switch (opcaoRegisto)
                {
                case 1:
                    registarPortatil(vetorPortateis,quantidadePortateisRegistados);
                    if (vetorPortateis[quantidadePortateisRegistados].estadoPortatil==2)
                    {
                        quantidadePortateisIndisponiveis++;
                    }
                    quantidadePortateisRegistados++;
                    break;
                case 2:
                    for(i = 0; i < quantidadePortateisRegistados; i++)
                    {
                        mostrarInformacaoPortatilPorPosicao(vetorPortateis,i);
                    }
                    break;
                case 0:
                    printf("\nA voltar ao menu anterior\n\n");
                    break;
                default:
                    printf ("Opcao Invalida\n");
                    break;
                }
            }
            while(opcaoRegisto != 0);
            break;
        case 2:
            pos = alterarLocalizacaoPortatil(vetorPortateis,quantidadePortateisRegistados);
            mostrarInformacaoPortatilPorPosicao(vetorPortateis,pos);
            break;
        case 3:
            pos=-1;
            do
            {
//                numeroIdentificacao = lerInteiro(mensagemPedirNumeroIdentificaoPortatil,1,99999);
//                pos = procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,numeroIdentificacao);
                pos= procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,-1);
                if (pos != -1)
                {
                    mostrarInformacaoPortatilPorPosicao(vetorPortateis, pos);

                }
                else
                {
                    //printf("Nao foi possivel encontrar esse portatil\n");
                    printf("Deseja tentar novamente? \n1- SIM\n2- NAO\n");
                    repetir = lerInteiro(mensagemRepetir,1,2);
                }
            }
            while((repetir==1) &&( pos==-1));
            break;
        case 4:
            do
            {
                idRequisicao = lerInteiro(mensagemIdRequisicao, MIN_ID, MAX_ID);
                pos= procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,idRequisicao);
                if (pos != -1)
                {
                    mostrarInformacaoPortatilPorPosicao(vetorPortateis, pos);

                    if (vetorPortateis[pos].estadoPortatil==1)
                    {

                        vetorRequisicoes = realloc(vetorRequisicoes,(quantidadeRequisicoes+1)*sizeof(tipoRequisicao));
                        if (vetorRequisicoes == NULL)
                        {
                            printf("Mem�ria insuficiente");
                        }

                        requisitarPortatil(vetorRequisicoes,quantidadeRequisicoes,vetorPortateis,pos,dataAtual);
                        quantidadeRequisicoes++;

                    }
                }
                else
                {
                    printf("Deseja tentar novamente? \n1- SIM\n2- NAO\n");
                    repetir = lerInteiro(mensagemRepetir,1,2);
                }
            }
            while((repetir==1) &&( pos==-1));
            break;
        case 5:
 //           lerString(mensagemCodigo,codigo,MAX_CODIGO);
 //           pos = procurarRequisicaoPorCodigo(vetorRequisicoes,quantidadeRequisicoes,codigo);
//            if (pos!=-1)
//            {
//                mostrarRequisicaoPorPosicao(vetorRequisicoes,quantidadeRequisicoes,pos);
//            }
            for(i=0;i<quantidadeRequisicoes;i++)
            {
                mostrarRequisicaoPorPosicao(vetorRequisicoes,quantidadeRequisicoes,i);
            }
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 0:
            printf("A terminar programa!\n");
            break;
        default:
            printf ("Opcao Invalida\n");
            break;

        }

    }
    while(opcaoPrincipal != 0);
    free(vetorRequisicoes);
    return 0;
}

int menuPrincipal(int quantidadePortateisRegistados, int quantidadeRequisicoes, int quantidadeRequisicoesAtivas, int quantidadePortateisIndisponiveis)
{

    int opcao, quantidadePortateisDisponiveis;//, quantidadePortateisDisponiveis,quantidadePortateisRegistados,quantidadePortateisRequisitados,quantidadePortateisAvariados;
    quantidadePortateisDisponiveis = quantidadePortateisRegistados-quantidadeRequisicoesAtivas-quantidadePortateisIndisponiveis;
    printf("\nQuantidade de portateis existentes: %d\t\t Quantidade de requisicoes totais: %d\n", quantidadePortateisRegistados, quantidadeRequisicoes);
    printf("Quantidade de portateis disponiveis: %d\t\t Quantidade de requisicoes ativas: %d\n", quantidadePortateisDisponiveis, quantidadeRequisicoesAtivas);
    printf("1 - Registar computador\n");
    printf("2 - Alterar posicao portatil\n");
    printf("3 - Procurar portatil por numero de identificao\n");
    printf("4 - Realizar requisicao de portatil\n");

    printf("Opcao: ");


    scanf("%d",&opcao);
    limpaBufferStdin();
    return opcao;
}
