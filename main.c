#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
//char mensagemCodigoRenovacao[] = "\nInsira o respetivo codigo da requisicao: ";
char mensagemAvaria[] = "Qual o tipo de avaria?\n 1 - Permanente\n 2 - Temporaria\n";



int main()
{
    int quantidadePortateisRegistados = 0;
    int quantidadeRequisicoes = 0;
    int quantidadePortateisIndisponiveis = 0;
    int quantidadeRequisicoesAtivas = 0;
    int quantidadeAvarias = 0;
    int repetir=0;
    int mostrarMensagem=1;
    tipoRequisicao *vetorRequisicoes;
    vetorRequisicoes = NULL;
    tipoAvaria *vetorAvarias;
    vetorAvarias = NULL;

    FILE *ficheiro;

    char codigo[MAX_CODIGO];

    int opcaoPrincipal, quantidadePortateisDisponiveis, opcaoRegisto, i, pos, idRequisicao, opcaoFicheiros, erro, duracao, posRequisicao, posPortatil, renovacao, idAvaria, opcaoAvaria;
    tipoPortatil vetorPortateis[MAX_PORTATEIS];

    tipoData dataAtual, dataDevolucao,dataReparacao;
    printf("Insira a data atual\n");
    dataAtual = lerData();
    do
    {



        opcaoPrincipal = menuPrincipal(quantidadePortateisRegistados, quantidadeRequisicoes, quantidadeRequisicoesAtivas, quantidadePortateisIndisponiveis);
        switch (opcaoPrincipal)
        {
        case 1: //Menu
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
                    if (quantidadePortateisRegistados==0)
                    {
                        printf("Nao existem portateis registados!\n");
                    }
                    for(i = 0; i < quantidadePortateisRegistados; i++)
                    {
                        mostrarInformacaoPortatilPorPosicao(vetorPortateis,i);
                    }
                    break;
                case 3: //Procurar portatil
                    pos=-1;
                    do
                    {
//                numeroIdentificacao = lerInteiro(mensagemPedirNumeroIdentificaoPortatil,1,99999);
//                pos = procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,numeroIdentificacao);
                        pos= procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,-1,1);
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
        case 3: //Fazer requisicao
            do
            {
                idRequisicao = lerInteiro(mensagemIdRequisicao, MIN_ID, MAX_ID);
                pos= procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,idRequisicao,1);
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
                        quantidadeRequisicoesAtivas++;

                    }
                    else if(vetorPortateis[pos].estadoPortatil==2)
                    {
                        printf("\nEsse computador encontra-se requisitado!\n");
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
    case 4://Mostrar requisicoes
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
        case 5: // DEVOLUCAO
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

                    posPortatil=procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,vetorRequisicoes[posRequisicao].identificacaoPortatil,1);

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
                    vetorPortateis[posPortatil].estadoPortatil=1;
                    quantidadeRequisicoesAtivas--;
                    erro = fclose(ficheiro);
                    if (erro != 0)
                    {
                        printf ("Erro %d no fecho ficheiro", erro);
                    }
                }
            }
            break;
        case 6: //Renovar requisicao portatil
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
//                else
//                {
//                    printf("Requisicao nao encontrada\n");
//                }

            }
            break;
        case 7://Registar avaria ou reparacao
            opcaoAvaria = menuAvarias();
            switch(opcaoAvaria)
            {
            case 1:
                idAvaria = lerInteiro(mensagemPedirNumeroIdentificaoPortatil,MIN_ID,MAX_ID);
                pos = procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,idAvaria,1);
                if(pos != -1)
                {
                    do
                    {
                        dataDevolucao = lerData();
                        duracao = calculaDuracao(dataDevolucao,vetorRequisicoes[posRequisicao].dataRequisicao);
                        if(duracao < 0)
                        {
                            printf("Por favor introduza uma data valida (maior que a data de requisicao)\n");
                        }
                    }
                    while (duracao < 0);
                    if (vetorPortateis[pos].estadoPortatil == 2)
                    {
                        for(i=0; i<quantidadeRequisicoes; i++)
                        {
                            if(vetorRequisicoes[i].estadoRequisicao == 1 && vetorRequisicoes[i].identificacaoPortatil==idAvaria)
                            {
                                vetorRequisicoes[i].localDevolucao = lerInteiro(mensagemLocalDevolucao,1,4);
                                vetorRequisicoes[i].multa = (duracao - vetorRequisicoes[i].prazoRequisicao)*10;
                                vetorRequisicoes[i].estadoRequisicao = 2;

                                ficheiro = fopen("devolucoes.txt","a");
                                if (ficheiro == NULL)
                                {
                                    printf ("Ficheiro não Existe!!");
                                }
                                else
                                {
                                    fprintf(ficheiro,"Codigo da requisicao: %s\n",vetorRequisicoes[i].codigo);
                                    fprintf(ficheiro,"Identificacao do portatil: %d\n",vetorRequisicoes[i].identificacaoPortatil);
                                    fprintf(ficheiro,"Nome do utente: %s\n",vetorRequisicoes[i].nome);
                                    switch(vetorRequisicoes[i].tipoUtente)
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
                                    fprintf(ficheiro,"Data de requisicao: %d/%d/%d\n",vetorRequisicoes[i].dataRequisicao.dia,vetorRequisicoes[i].dataRequisicao.mes,vetorRequisicoes[i].dataRequisicao.ano);
                                    fprintf(ficheiro,"Data de devolucao: %d/%d/%d\n",vetorRequisicoes[i].dataDevolucao.dia,vetorRequisicoes[i].dataDevolucao.mes,vetorRequisicoes[i].dataDevolucao.ano);
                                    fprintf(ficheiro,"Prazo da requisicao: %d\n",vetorRequisicoes[i].prazoRequisicao);
                                    switch(vetorRequisicoes[i].localDevolucao)
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
                                    fprintf(ficheiro,"Multa: %.2f\n",vetorRequisicoes[i].multa);

                                    posPortatil=procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,vetorRequisicoes[i].identificacaoPortatil,1);

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
                                    vetorPortateis[posPortatil].localizacaoPortatil=vetorRequisicoes[i].localDevolucao;
                                    erro = fclose(ficheiro);
                                    if (erro != 0)
                                    {
                                        printf ("Erro %d no fecho ficheiro", erro);
                                    }
                                }
                            }
                        }
                    }
                    vetorPortateis[pos].estadoPortatil = 3;
                    vetorPortateis[pos].quantidadeAvarias++;
                    vetorAvarias = realloc(vetorAvarias,(quantidadeAvarias+1)*sizeof(tipoAvaria));
                    if (vetorRequisicoes == NULL)
                    {
                        printf("Memória insuficiente");
                    }
                    vetorAvarias[quantidadeAvarias].dataAquisicao=vetorPortateis[pos].dataAquisicao;
                    strcpy(vetorAvarias[quantidadeAvarias].designacao,vetorPortateis[pos].designacao);
                    vetorAvarias[quantidadeAvarias].diasAvariado=-1;
                    vetorAvarias[quantidadeAvarias].estadoPortatil=vetorPortateis[pos].estadoPortatil;
                    vetorAvarias[quantidadeAvarias].identificacao=vetorPortateis[pos].identificacao;
                    vetorAvarias[quantidadeAvarias].localizacaoPortatil=vetorPortateis[pos].localizacaoPortatil;
                    vetorAvarias[quantidadeAvarias].processador=vetorPortateis[pos].processador;
                    vetorAvarias[quantidadeAvarias].quantidadeAvarias=vetorPortateis[pos].quantidadeAvarias;
                    vetorAvarias[quantidadeAvarias].quantidadeRequisicoes=vetorPortateis[pos].quantidadeRequisicoes;
                    vetorAvarias[quantidadeAvarias].ram=vetorPortateis[pos].ram;
                    vetorAvarias[quantidadeAvarias].totalDiasRequisicao=vetorPortateis[pos].totalDiasRequisicao;
                    vetorAvarias[quantidadeAvarias].valor=vetorPortateis[pos].valor;
                    vetorAvarias[quantidadeAvarias].dataAvaria=dataDevolucao;
                    vetorAvarias[quantidadeAvarias].avaria=lerInteiro(mensagemAvaria,1,2);
                    quantidadeAvarias++;
                    quantidadeRequisicoesAtivas--;
                }
                else
                {
                    printf("Portatil nao encontrado\n");
                }
                break;
            case 2:
                idAvaria = lerInteiro(mensagemPedirNumeroIdentificaoPortatil,MIN_ID,MAX_ID);
                pos = procurarPortatilPorIdentificacao(vetorPortateis,quantidadePortateisRegistados,idAvaria,1);
                if(pos != -1)
                {
                    if(vetorPortateis[pos].estadoPortatil != 3)
                    {
                        printf("Este portatil nao se encontra avariado\n");
                    }
                    else
                    {
                        for(i=0; i<quantidadeAvarias; i++)
                        {
                            if (vetorAvarias[i].identificacao==idAvaria && vetorAvarias[i].avaria==1)
                            {
                                printf("Este portatil tem uma avaria permanente\n");
                            }
                        }
                        do
                        {
                            dataReparacao=lerData();
                            for(i=0; i<quantidadeAvarias; i++)
                            {
                                if (vetorAvarias[i].identificacao==idAvaria && vetorAvarias[i].avaria==2)
                                {
                                    vetorAvarias[i].diasAvariado=transformaData(dataReparacao)-transformaData(dataDevolucao);
                                }
                            }
                            if(vetorAvarias[i].diasAvariado < 0)
                            {
                                printf("Por favor introduza uma data valida (maior que a data de devolucao/avaria)\n");
                            }
                        }
                        while (vetorAvarias[i].diasAvariado < 0);
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
            lerString(mensagemCodigoRequisicao,codigo,MAX_CODIGO);
            pos = procurarRequisicaoPorCodigo(vetorRequisicoes,quantidadeRequisicoes,codigo);
            if (pos!=-1)
            {
                mostrarRequisicaoPorPosicao(vetorRequisicoes,quantidadeRequisicoes,pos);
            }
            break;
        case 10:
            break;
        case 11:
            for(i=0; i<quantidadeAvarias; i++)
            {
                printf("----------------------------------------------------------------------------------\n");
                printf("O computador de id: %d possui os seguintes dados:\n",vetorAvarias[i].identificacao);
                switch(vetorAvarias[i].processador)
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
                printf("RAM: %d GB\n",vetorAvarias[i].ram);
                printf("Designacao: %s\n",vetorAvarias[i].designacao);
                switch(vetorAvarias[i].estadoPortatil)
                {
                case 1:
                    printf("Estado: disponivel\n");
                    break;
                case 2:
                    printf("Estado: requisitado\n");
                    break;
                case 3:
                    printf("Estado: avariado\n");
                    break;
                }
                switch(vetorAvarias[i].localizacaoPortatil)
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
                printf("Data de aquisicao: %d-%d-%d\n",vetorAvarias[i].dataAquisicao.dia,vetorAvarias[i].dataAquisicao.mes,vetorAvarias[i].dataAquisicao.ano);
                printf("Valor: %.2f\n",vetorAvarias[i].valor);
                printf("Quantidade de avarias: %d\n",vetorAvarias[i].quantidadeAvarias);
                printf("Quantidade de requisicoes: %d\n\n",vetorAvarias[i].quantidadeRequisicoes);
                printf("Data de avaria: %d-%d-%d\n",vetorAvarias[i].dataAvaria.dia,vetorAvarias[i].dataAvaria.mes,vetorAvarias[i].dataAvaria.ano);
                switch(vetorAvarias[i].avaria)
                {
                case 1:
                    printf("Tipo de avaria: Permanente\n");
                    break;
                case 2:
                    printf("Tipo de avaria: Temporaria\n");
                    break;
                    printf("Dias avariado: %d\n",vetorAvarias[i].diasAvariado);
                    printf("Total de dias requisitado: %d\n",vetorAvarias[i].totalDiasRequisicao);
                    printf("----------------------------------------------------------------------------------\n");
                }
            }
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
    printf(" 1 - Menu portateis\n");
    printf(" 2 - Alterar localizacao portatil\n");
    printf(" 3 - Requisitar portatil\n");
    printf(" 4 - Listar dados de requisicoes\n");
    printf(" 5 - Registar a devolucao de um portatil\n");
    printf(" 6 - Renovar a requisicao de um portatil\n");
    printf(" 7 - Registar a avaria ou reparacao portatil\n");
    printf(" 8 - Ficheiros fixes\n");
    printf(" 9 - Apresentar informacao de uma requisicao\n");
    printf("10 - Apresentar estatisticas\n");
    printf("11 - Apresentar avarias\n");
    printf("\n0 - Fechar programa!\n");
    printf("Opcao: ");


    scanf("%d",&opcao);
    limpaBufferStdin();
    return opcao;
}
