#include <stdio.h>
#include <stdlib.h>

#include "funcoes_portatil.h"
#include "funcoes_auxiliares1.h"

int menuPrincipal();

int main()
{
    int quantidadePortateisRegistados = 0;
    int quantidadePortateisRequisitados = 0;
    int opcaoPrincipal,portateisDisponiveis,portateisRequisitados;
    tipoPortatil vetorPortateis[MAX_PORTATEIS];

    do
    {
    portateisDisponiveis = quantidadePortateisRegistados-quantidadePortateisRequisitados;


    opcaoPrincipal = menuPrincipal();
    switch (opcaoPrincipal)
    {
    case 1: //Realizar requisição de 1 computador
        registarPortatil(vetorPortateis,quantidadePortateisRegistados);
        mostrarInformacaoPortatilPorPosicao(vetorPortateis,quantidadePortateisRegistados);
        quantidadePortateisRegistados++;
        break;
    case 2:
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
    case 12:
        break;
    case 0:
        break;
    default:
         printf ("Opcao Invalida\n");

    }
    }while(opcaoPrincipal != '0');
}

int menuPrincipal()
{
    int opcao;
    printf("Quantidade de portateis existentes: %d\n", MAX_PORTATEIS);
    printf("Quantidade de portateis disponiveis: %d\n");
    printf("1 - Registar computador\n");

    scanf("%d",&opcao);
    return opcao;
}
