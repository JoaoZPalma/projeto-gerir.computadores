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
char mensagemDevolucao[]="Por favor introduza o codigo respetivo a requisicao: \n";
char mensagemLocalDevolucao[] = "\nLocal de devolucao:\n1- Campus 1\n2- Campus 2\n3- Campus 5\n4- Residencias\n";
char mensagemRenovacao[] = "Por quanto tempo deseja prolongar a reserva (MAXIMO: 7 Dias)";
char mensagemCodigoRequisicao[] = "\nInsira o respetivo codigo da requisicao: ";

int main()
{
    int quantidadePortateisRegistados = 0;
    int quantidadeRequisicoes = 0;
    int quantidadePortateisIndisponiveis = 0;
    int quantidadeRequisicoesAtivas = 0;
    int repetir=0;
    tipoRequisicao *vetorRequisicoes;
    vetorRequisicoes = NULL;
    FILE *ficheiro;

    char codigo[MAX_CODIGO];

    int opcaoPrincipal, quantidadePortateisDisponiveis, opcaoRegisto, i, pos, idRequisicao, opcaoFicheiros, erro, duracao, posRequisicao, posPortatil, renovacao;
    tipoPortatil vetorPortateis[MAX_PORTATEIS];

    tipoData dataAtual, dataDevolucao;
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
        case 2: // Alterar localizacao de portatil
            pos = alterarLocalizacaoPortatil(vetorPortateis,quantidadePortateisRegistados);
            mostrarInformacaoPortatilPorPosicao(vetorPortateis,pos);
            break;
        case 3: //Procurar portatil
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
        case 4: //Fazer requisicao
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
                            printf("Memória insuficiente");
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
        case 5://Mostrar requisicoes
//           lerString(mensagemCodigo,codigo,MAX_CODIGO);
//           pos = procurarRequisicaoPorCodigo(vetorRequisicoes,quantidadeRequisicoes,codigo);
//            if (pos!=-1)
//            {
//                mostrarRequisicaoPorPosicao(vetorRequisicoes,quantidadeRequisicoes,pos);
//            }
            for(i=0; i<quantidadeRequisicoes; i++)
            {
                mostrarRequisicaoPorPosicao(vetorRequisicoes,quantidadeRequisicoes,i);
            }
            break;
        case 6:
            lerString(mensagemDevolucao,codigo,MAX_CODIGO);
            posRequisicao = procurarRequisicaoPorCodigo(vetorRequisicoes,quantidadeRequisicoes,codigo);
            if (posRequisicao!=-1)
            {
                do
                {
                    dataDevolucao = lerData();
                    duracao = calculaDuracao(dataDevolucao,vetorRequisicoes[posRequisicao].dataRequisicao);
                    if(duracao < 0)
                    {
                        printf("Por favor introduza uma data válida (maior que a data de requisicao)\n");
                    }
                }
                while (duracao < 0);
                vetorRequisicoes[posRequisicao].localDevolucao = lerInteiro(mensagemLocalDevolucao,1,4);
                vetorRequisicoes[posRequisicao].multa = (duracao - vetorRequisicoes[posRequisicao].prazoRequisicao)*10;
                vetorRequisicoes[posRequisicao].estadoRequisicao = 2;

                ficheiro = fopen("devolucoes.txt","a");
                if (ficheiro == NULL)
                {
                    printf ("Ficheiro não Existe!!");
                }
                else
                {
                    fprintf(ficheiro,"Codigo da requisicao: %s\n",vetorRequisicoes[posRequisicao].codigo);
                    fprintf(ficheiro,"Identificacao do portatil: %d\n",vetorRequisicoes[posRequisicao].identificacaoPortatil);
                    fprintf(ficheiro,"Nome do utente: %s\n",vetorRequisicoes[posRequisicao].nome);
                    switch(vetorRequisicoes[posRequisicao].tipoUtente)
                    {
                    case 1:
                        fprintf(ficheiro,"Tipo de utente: Estudante\n");
                        break;
                    case 2:
                        fprintf(ficheiro,"Tipo de utente: Docente\n");
                        break;
                    case 3:
                        fprintf(ficheiro,"Tipo de utente: Tecnico administrativo\n");
                        break;
                    }
                    fprintf(ficheiro,"Data de requisicao: %d/%d/%d\n",vetorRequisicoes[posRequisicao].dataRequisicao.dia,vetorRequisicoes[posRequisicao].dataRequisicao.mes,vetorRequisicoes[posRequisicao].dataRequisicao.ano);
                    fprintf(ficheiro,"Data de devolucao: %d/%d/%d\n",vetorRequisicoes[posRequisicao].dataDevolucao.dia,vetorRequisicoes[posRequisicao].dataDevolucao.mes,vetorRequisicoes[posRequisicao].dataDevolucao.ano);
                    fprintf(ficheiro,"Prazo da requisicao: %d\n",vetorRequisicoes[posRequisicao].prazoRequisicao);
                    switch(vetorRequisicoes[posRequisicao].localDevolucao)
                    {
                    case 1:
                        fprintf(ficheiro,"Local de devolucao: Campus 1\n");
                        break;
                    case 2:
                        fprintf(ficheiro,"Local de devolucao: Campus 2\n");
                        break;
                    case 3:
                        fprintf(ficheiro,"Local de devolucao: Campus 5\n");
                        break;
                    case 4:
                        fprintf(ficheiro,"Local de devolucao: Residencias\n");
                        break;
                    }
                    fprintf(ficheiro,"Estado da requisicao: Concluida\n");
                    fprintf(ficheiro,"Multa: %.2f\n",vetorRequisicoes[posRequisicao].multa);

                    posPortatil=procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,vetorRequisicoes[posRequisicao].identificacaoPortatil);

                    switch(vetorPortateis[posPortatil].processador)
                    {
                    case 1:
                        fprintf(ficheiro,"Processador: i3\n");
                        break;
                    case 2:
                        fprintf(ficheiro,"Processador: i5\n");
                        break;
                    case 3:
                        fprintf(ficheiro,"Processador: i7\n");
                        break;
                    }

                    switch(vetorPortateis[posPortatil].ram)
                    {
                    case 1:
                        fprintf(ficheiro,"RAM: 4\n");
                        break;
                    case 2:
                        fprintf(ficheiro,"RAM: 8\n");
                        break;
                    case 3:
                        fprintf(ficheiro,"RAM: 16\n");
                        break;
                    case 4:
                        fprintf(ficheiro,"RAM: 32\n");
                        break;
                    case 5:
                        fprintf(ficheiro,"RAM: 64\n");
                        break;
                    }
                    vetorPortateis[posPortatil].localizacaoPortatil=vetorRequisicoes[posRequisicao].localDevolucao;
                    erro = fclose(ficheiro);
                    if (erro != 0)
                    {
                        printf ("Erro %d no fecho ficheiro", erro);
                    }
                }
            }
            break;
        case 7: //Renovar requisicao portatil
            lerString(mensagemCodigoRequisicao,codigo,MAX_CODIGO);
            posRequisicao = procurarRequisicaoPorCodigo(vetorRequisicoes,quantidadeRequisicoes,codigo);
            if (posRequisicao!=-1 && vetorRequisicoes[pos].estadoRequisicao==1)
            {
                renovacao = lerInteiro(mensagemRenovacao,1,7);
                vetorRequisicoes[posRequisicao].prazoRequisicao += renovacao;
            }
            else
            {
                if (vetorRequisicoes[pos].estadoRequisicao!=1)
                {
                    printf("Impossivel renovar uma requisicao ja concluida!");
                }
                else{printf("Requisicao nao encontrada\n");}

            }
            break;
        case 8: //Ficheiros
            do
            {
                opcaoFicheiros = menuFicheiros();
                switch (opcaoFicheiros)
                {
                case 1:
                    ficheiro = fopen("portateis.dat", "wb");
                    if (ficheiro == NULL)
                    {
                        printf ("Ficheiro não Existe!!");
                    }
                    else
                    {
                        fwrite(&quantidadePortateisRegistados,sizeof(int),1,ficheiro);
                        fwrite(vetorPortateis,sizeof(tipoPortatil),quantidadePortateisRegistados,ficheiro);
                        erro = fclose(ficheiro);
                        if (erro != 0)
                        {
                            printf ("Erro %d no fecho ficheiro", erro);
                        }
                    }
                    break;
                case 2:
                    ficheiro = fopen("portateis.dat", "rb");
                    if (ficheiro == NULL)
                    {
                        printf ("Ficheiro não Existe!!");
                    }
                    else
                    {
                        fread(&quantidadePortateisRegistados,sizeof(int),1,ficheiro);
                        fread(vetorPortateis,sizeof(tipoPortatil),quantidadePortateisRegistados,ficheiro);
                        erro = fclose(ficheiro);
                        if (erro != 0)
                        {
                            printf ("Erro %d no fecho ficheiro", erro);
                        }
                    }
                    break;
                case 3:
                    ficheiro = fopen("requisicoes.dat", "wb");
                    if (ficheiro == NULL)
                    {
                        printf ("Ficheiro não Existe!!");
                    }
                    else
                    {
                        fwrite(&quantidadeRequisicoes,sizeof(int),1,ficheiro);
                        fwrite(vetorRequisicoes,sizeof(tipoRequisicao),quantidadeRequisicoes,ficheiro);
                        erro = fclose(ficheiro);
                        if (erro != 0)
                        {
                            printf ("Erro %d no fecho ficheiro", erro);
                        }
                    }
                    break;
                case 4:
                    ficheiro = fopen("requisicoes.dat", "rb");
                    if (ficheiro == NULL)
                    {
                        printf ("Ficheiro não Existe!!");
                    }
                    else
                    {
                        fread(&quantidadeRequisicoes,sizeof(int),1,ficheiro);
                        vetorRequisicoes = realloc(vetorRequisicoes,quantidadeRequisicoes*sizeof(tipoRequisicao));
                        if (vetorRequisicoes == NULL)
                        {
                            printf("Memória insuficiente");
                        }
                        fread(vetorRequisicoes,sizeof(tipoRequisicao),quantidadeRequisicoes,ficheiro);
                        erro = fclose(ficheiro);
                        if (erro != 0)
                        {
                            printf ("Erro %d no fecho ficheiro", erro);
                        }
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
            while(opcaoFicheiros != 0);
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
    printf("5 - Mostrar todas as requisicoes\n");

    printf("Opcao: ");


    scanf("%d",&opcao);
    limpaBufferStdin();
    return opcao;
}
