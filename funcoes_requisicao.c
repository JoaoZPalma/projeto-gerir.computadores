#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliares1.h"
#include "funcoes_requisicao.h"
#include "funcoes_portatil.h"

char mensagemTipoUtente[] = "\nTipo de utente:\n1-Estudante\n2-Docente\n3-Tecnico Administrativo";

tipoRequisicao requisitarPortatil(tipoRequisicao vetorRequisicoes[],int quantidadeRequisicoes,tipoPortatil vetorPortateis[],int pos/**< , int numeroIdentificacao */)
{
        vetorRequisicoes[quantidadeRequisicoes].dataRequisicao = lerData();
        //dataAquisicao = transformaData(vetorPortateis[pos].dataAquisicao);
        //dataRequisicao = transformaData(vetorRequisicoes[quantidadeRequisicoes].dataRequisicao);
//VERIFICAR SE ESTA DISPONIVEL
        if (transformaData(vetorPortateis[pos].dataAquisicao) < transformaData(vetorRequisicoes[quantidadeRequisicoes].dataRequisicao))
        {
            vetorRequisicoes[quantidadeRequisicoes].identificacaoPortatil = vetorPortateis[pos].identificacao;
            vetorRequisicoes[quantidadeRequisicoes].tipoUtente = lerInteiro(mensagemTipoUtente,1,3);

        }

}
