#include <stdio.h>
#include <stdlib.h>

#include "constantes1.h"
#include "funcoes_auxiliares1.h"
#include "funcoes_portatil.h"
#include "funcoes_requisicao.h"

int menuPrincipal(int quantidadePortateisRegistados, int quantidadePortateisRequisicoes, int quantidadePortateisRequisicoesAtivas, int quantidadePortateisIndisponiveis);
char mensagemRepetir[]="Deseja repetir o procedimento?";
char mensagemPedirNumeroIdentificaoPortatil[] = "Insira o numero de identificao do portatil:\t";

int main()
{
    int quantidadePortateisRegistados = 0;
    int quantidadePortateisRequisicoes = 0;
    int quantidadePortateisIndisponiveis = 0;
    int quantidadePortateisRequisicoesAtivas = 0;
    int repetir=0;
    int numeroIdentificacao;

    int opcaoPrincipal, quantidadePortateisDisponiveis, opcaoRegisto, i, numeroIdentificao,pos;
    tipoPortatil vetorPortateis[MAX_PORTATEIS];

    do
    {



        opcaoPrincipal = menuPrincipal(quantidadePortateisRegistados, quantidadePortateisRequisicoes, quantidadePortateisRequisicoesAtivas, quantidadePortateisIndisponiveis);
        switch (opcaoPrincipal)
        {
        case 1: //Realizar requisição de 1 computador
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
            pos=-1;
            do{
                numeroIdentificacao = lerInteiro(mensagemPedirNumeroIdentificaoPortatil,1,99999);
                pos = procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados, numeroIdentificacao);
                if (pos != -1)
                {
                    mostrarInformacaoPortatilPorPosicao(vetorPortateis, pos);

                }
                else
                {
                    printf("Nao foi possivel encontrar esse portatil\n");
                    printf("Deseja tentar novamente? \n1- SIM\n2- NAO\n");
                    repetir = lerInteiro(mensagemRepetir,1,2);
                }
            }while((repetir==1) &&( pos==-1));
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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

    return 0;
}

int menuPrincipal(int quantidadePortateisRegistados, int quantidadePortateisRequisicoes, int quantidadePortateisRequisicoesAtivas, int quantidadePortateisIndisponiveis)
{

    int opcao, quantidadePortateisDisponiveis;//, quantidadePortateisDisponiveis,quantidadePortateisRegistados,quantidadePortateisRequisitados,quantidadePortateisAvariados;
    quantidadePortateisDisponiveis = quantidadePortateisRegistados-quantidadePortateisRequisicoesAtivas-quantidadePortateisIndisponiveis;
    printf("Quantidade de portateis existentes: %d\t\t Quantidade de requisicoes totais: %d\n", quantidadePortateisRegistados, quantidadePortateisRequisicoes);
    printf("Quantidade de portateis disponiveis: %d\t\t Quantidade de requisicoes ativas: %d\n", quantidadePortateisDisponiveis, quantidadePortateisRequisicoesAtivas);
    printf("1 - Registar computador\n");
    printf("2 - Procurar portatil por numero de identificao\n");

    scanf("%d",&opcao);
    limpaBufferStdin();
    return opcao;
}
