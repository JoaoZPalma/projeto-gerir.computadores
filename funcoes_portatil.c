#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliares1.h"
#include "funcoes_portatil.h"

char mensagemNumeroIdentificacaoPortatil[] = "\nNumero de Identificacao";
char mensagemProcessadorPortatil[] = "\nProcessador: \n1-i3\n2-i5\n3-i7\n";
char mensagemRamPortatil[] = "RAM do portatil (em gigabytes)";
char mensagemEstadoPortatil[] = "\nEstado do Portatil: \n1-Disponivel\n2-Requisitado\n3-Avariado\n";
char mensagemLocalizacaoPortatil[] = "\nLocalizacao do portatil:\n1- Campus 1\n2- Campus 2\n3- Campus 5\n4- Residencias\n";
char mensagemValorPortatil[] = "Insira o valor do portatil(em euros)";
char mensagemQuantidadeAvariasPortatil[] = "\nQuantidade de avarias";
char mensagemQuantidadeRequisicoesPortatil[] = "\nQuantidade de requisicoes";

int quantidadePortateisRegistados;




void registarPortatil(tipoPortatil vetor[],int quantidadePortateisRegistados)
{
    printf("Insira agora os dados de registo do computador em causa:");
    vetor[quantidadePortateisRegistados].identificacao = lerInteiro(mensagemNumeroIdentificacaoPortatil,1,99999);
    vetor[quantidadePortateisRegistados].processador = lerInteiro(mensagemProcessadorPortatil,1,3);
    vetor[quantidadePortateisRegistados].ram = menuRAM();
    vetor[quantidadePortateisRegistados].estadoPortatil = lerInteiro(mensagemEstadoPortatil,1,3);
    vetor[quantidadePortateisRegistados].localizacaoPortatil = lerInteiro(mensagemLocalizacaoPortatil,1,4);
    vetor[quantidadePortateisRegistados].dataAquisicao = lerData();
    vetor[quantidadePortateisRegistados].valor = lerFloat(mensagemValorPortatil,1.0,999999.99);
    vetor[quantidadePortateisRegistados].quantidadeAvarias = lerInteiro(mensagemQuantidadeAvariasPortatil,0,9999);
    vetor[quantidadePortateisRegistados].quantidadeRequisicoes = lerInteiro(mensagemQuantidadeRequisicoesPortatil,0,9999);
    //quantidadeComputadoresRegistados++;

}

void mostrarInformacaoPortatilPorPosicao(tipoPortatil vetor[], int posicao)
{
    printf("----------------------------------------------------------------------------------\n");
    printf("O computador de id: %d possui os seguintes dados:\n",vetor[posicao].identificacao);
    printf("Processador: %d\n",vetor[posicao].processador);
    printf("RAM: %d\n",vetor[posicao].ram);
    printf("Estado: %d\n",vetor[posicao].estadoPortatil);
    printf("Localizacao: %d\n",vetor[posicao].localizacaoPortatil);
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
