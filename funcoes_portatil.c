#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliares1.h"
#include "funcoes_portatil.h"

char mensagemNumeroIdentificacaoPortatil[] = "\nNumero de Identificacao";
char mensagemProcessadorPortatil[] = "\nProcessador: \n1-i3\n2-i5\n3-i7\n";
char mensagemRamPortatil[] = "RAM do portatil (em gigabytes)";
//char mensagemEstadoPortatil[] = "\nEstado do Portatil: \n1-Disponivel\n2-Indisponivel\n";
char mensagemLocalizacaoPortatil[] = "\nLocalizacao do portatil:\n1- Campus 1\n2- Campus 2\n3- Campus 5\n4- Residencias\n";
char mensagemValorPortatil[] = "Insira o valor do portatil(em euros)";
//char mensagemQuantidadeAvariasPortatil[] = "\nQuantidade de avarias";
//char mensagemQuantidadeRequisicoesPortatil[] = "\nQuantidade de requisicoes";



int quantidadePortateisRegistados,quantidadePortateisIndisponiveis;




void registarPortatil(tipoPortatil vetorPortateis[],int quantidadePortateisRegistados)
{
    int i, pos;
    pos = -1;
    printf("Insira agora os dados de registo do computador em causa:");



    do
    {
        vetorPortateis[quantidadePortateisRegistados].identificacao = lerInteiro(mensagemNumeroIdentificacaoPortatil,1,99999);
        pos = procurarPortatilPorIdentificacao(vetorPortateis, quantidadePortateisRegistados, vetorPortateis[quantidadePortateisRegistados].identificacao);
        if (pos !=-1)
        {
            printf("Esse computador ja se encontra registado");
        }
    }
    while(pos != -1);
    vetorPortateis[quantidadePortateisRegistados].processador = lerInteiro(mensagemProcessadorPortatil,1,3);
    vetorPortateis[quantidadePortateisRegistados].ram = menuRAM();
    vetorPortateis[quantidadePortateisRegistados].estadoPortatil = 1;
    vetorPortateis[quantidadePortateisRegistados].localizacaoPortatil = lerInteiro(mensagemLocalizacaoPortatil,1,4);
    vetorPortateis[quantidadePortateisRegistados].dataAquisicao = lerData();
    vetorPortateis[quantidadePortateisRegistados].valor = lerFloat(mensagemValorPortatil,1.0,999999.99);
    vetorPortateis[quantidadePortateisRegistados].quantidadeAvarias = 0;
    vetorPortateis[quantidadePortateisRegistados].quantidadeRequisicoes = 0;
    quantidadePortateisRegistados++;
//        if (quantidadePortateisRegistados!=0)
//        {
//
//
//            else
//            {
//
//                vetorPortateis[quantidadePortateisRegistados].processador = lerInteiro(mensagemProcessadorPortatil,1,3);
//                vetorPortateis[quantidadePortateisRegistados].ram = menuRAM();
//                vetorPortateis[quantidadePortateisRegistados].estadoPortatil = 1;
//                vetorPortateis[quantidadePortateisRegistados].localizacaoPortatil = lerInteiro(mensagemLocalizacaoPortatil,1,4);
//                vetorPortateis[quantidadePortateisRegistados].dataAquisicao = lerData();
//                vetorPortateis[quantidadePortateisRegistados].valor = lerFloat(mensagemValorPortatil,1.0,999999.99);
//                vetorPortateis[quantidadePortateisRegistados].quantidadeAvarias = 0;
//                vetorPortateis[quantidadePortateisRegistados].quantidadeRequisicoes = 0;
//                quantidadePortateisRegistados++;
//            }
//        }
//
//        else
//        {
//
//            vetorPortateis[quantidadePortateisRegistados].processador = lerInteiro(mensagemProcessadorPortatil,1,3);
//            vetorPortateis[quantidadePortateisRegistados].ram = menuRAM();
//            vetorPortateis[quantidadePortateisRegistados].estadoPortatil = 1;
//            vetorPortateis[quantidadePortateisRegistados].localizacaoPortatil = lerInteiro(mensagemLocalizacaoPortatil,1,4);
//            vetorPortateis[quantidadePortateisRegistados].dataAquisicao = lerData();
//            vetorPortateis[quantidadePortateisRegistados].valor = lerFloat(mensagemValorPortatil,1.0,999999.99);
//            vetorPortateis[quantidadePortateisRegistados].quantidadeAvarias = 0;
//            vetorPortateis[quantidadePortateisRegistados].quantidadeRequisicoes = 0;
//            quantidadePortateisRegistados++;
//        }

}
void mostrarInformacaoPortatilPorPosicao(tipoPortatil vetor[], int posicao)
{
    printf("----------------------------------------------------------------------------------\n");
    printf("O computador de id: %d possui os seguintes dados:\n",vetor[posicao].identificacao);
    switch(vetor[posicao].processador)
    {
    case 1:
        printf("Processador: i3\n");
        break;
    case 2:
        printf("Processador: i5\n");
        break;
    case 3:
        printf("Processador: i7\n");
        break;
    }
    printf("RAM: %d GB\n",vetor[posicao].ram);
    switch(vetor[posicao].estadoPortatil)
    {
    case 1:
        printf("Estado: disponivel\n");
        break;
    case 2:
        printf("Estado: indisponivel\n");
        break;
    case 3:
        printf("Estado: indisponivel\n");
        break;
    }
    switch(vetor[posicao].localizacaoPortatil)
    {
    case 1:
        printf("Localizacao: Campus1\n");
        break;
    case 2:
        printf("Localizacao: Campus2\n");
        break;
    case 3:
        printf("Localizacao: Campus5\n");
        break;
    case 4:
        printf("Localizacao: Residencias\n");
        break;
    }
    printf("Data de aquisicao: %d-%d-%d\n",vetor[posicao].dataAquisicao.dia,vetor[posicao].dataAquisicao.mes,vetor[posicao].dataAquisicao.ano);
    printf("Valor: %.2f\n",vetor[posicao].valor);
    printf("Quantidade de avarias: %d\n",vetor[posicao].quantidadeAvarias);
    printf("Quantidade de requisicoes: %d\n\n",vetor[posicao].quantidadeRequisicoes);
    printf("----------------------------------------------------------------------------------\n");


}

int menuRegistoPortatil()
{
    int opcaoRegistoPortatil;
    printf("Por favor introduza uma opcao\n");
    printf("1 - Registar computador\n");
    printf("2 - Listar computadores\n");
    printf("0 - Voltar ao menu anterior\n");
    printf("Opcao: ");

    scanf("%d",&opcaoRegistoPortatil);
    limpaBufferStdin();
    return opcaoRegistoPortatil;
}

int menuRAM()
{
    int opcaoRAM,quantidadeRAM;
    printf("Selecione a opcao de RAM do portatil(em gigabytes)\n");
    printf("1- 4GB\n");
    printf("2- 8GB\n");
    printf("3- 16GB\n");
    printf("4- 32GB\n");
    printf("5- 64GB\n");

    scanf("%d", &opcaoRAM);
    limpaBufferStdin();

    switch(opcaoRAM)
    {
    case 1:
        quantidadeRAM= 4;
        break;
    case 2:
        quantidadeRAM= 8;
        break;
    case 3:
        quantidadeRAM= 16;
        break;
    case 4:
        quantidadeRAM= 32;
        break;
    case 5:
        quantidadeRAM= 64;
        break;
    }
    return quantidadeRAM;

}

int procurarPortatilPorIdentificacao(tipoPortatil vetor[],int quantidadePortateisRegistados, int numeroIdentificacao)
{
    int i,pos;
    pos = -1;

    if (quantidadePortateisRegistados == 0)
    {
        printf("Nao existem portateis registados\n");
    }
    else
    {
        for(i=0; i<quantidadePortateisRegistados; i++)
        {

            if (numeroIdentificacao==vetor[i].identificacao)
            {
                pos = i;
                i = quantidadePortateisRegistados;
            }
        }
    }
    return pos;
}

void alterarLocalizacaoPortatil(tipoPortatil vetor[], int quantidadePortateisRegistados)
{
//   printf("");
//    procurarPortatilPorIdentificacao(tipoPortatil vetor[],int quantidadePortateisRegistados, int numeroIdentificacao)


}
