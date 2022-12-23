#include <stdio.h>
#include <stdlib.h>

#include "constantes1.h"
#include "funcoes_auxiliares1.h"
#include "funcoes_portatil.h"
#include "funcoes_requisicao.h"

int menuPrincipal();

int main()
{
    int quantidadePortateisRegistados = 0;
    int quantidadePortateisRequisitados = 0;
    int quantidadePortateisAvariados = 0;
    int opcaoPrincipal, portateisDisponiveis, portateisRequisitados, opcaoRegisto, i, numeroIdentificao,pos;
    tipoPortatil vetorPortateis[MAX_PORTATEIS];

    do
    {
        portateisDisponiveis = quantidadePortateisRegistados-quantidadePortateisRequisitados-quantidadePortateisAvariados;


        opcaoPrincipal = menuPrincipal();
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
                    quantidadePortateisRegistados++;
                    break;
                case 2:
                    for(i = 0;i < quantidadePortateisRegistados; i++)
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
            printf("Insira o numero de identificacao do portatil:\t");
            scanf("%d", &numeroIdentificao);
            limpaBufferStdin();
            pos = procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,numeroIdentificao);
            if (pos != -1)
            {
                mostrarInformacaoPortatilPorPosicao(vetorPortateis, pos);

            }
            else
            {
                printf("Nao foi possivel encontrar esse portatil\n");
            }
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

int menuPrincipal()
{
    int opcao;
    printf("Quantidade de portateis existentes: %d\n", MAX_PORTATEIS);
    printf("Quantidade de portateis disponiveis: %d\n");
    printf("1 - Registar computador\n");
    printf("2 - Procurar portatil por numero de identificao\n");

    scanf("%d",&opcao);
    limpaBufferStdin();
    return opcao;
}
