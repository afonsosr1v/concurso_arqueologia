#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "iterador.h"
#include "dicionario.h"
#include "sequencia.h"

#include "arqueologo.h"


struct _arqueologo{
    char nome[40];     //Nome do Arquelogo
    int posC;    //ultima posição C no terreno
    int posL; //ultima pos L no terreno
    int merito;         //mérito acumulado
    int penalizacoes; //penalizações do arqueologo
    int desqualificado; //se desqualificado=1 o arqueologo está desqualificado
};

arqueologo criaArqueologo(char * nome){
    arqueologo a;
    a = (arqueologo)malloc(sizeof(struct _arqueologo));
    if (a == NULL) return NULL;
    strcpy(a->nome, nome);
    a->posC = 0;
    a->posL = 0;
    a->merito = 0;
    a->penalizacoes = 0;
    a->desqualificado = 0;

    return a;
}

void apagaArqueologo(arqueologo a){
    free(a);
}

char* retornaNomeArqueologo(arqueologo a){
    return a->nome;
}

int retornaPosCArqueologo(arqueologo a){
    return a->posC;
}

int retornaPosLArqueologo(arqueologo a){
    return a->posL;
}

int retornaMeritoArqueologo(arqueologo a){
    return a->merito;
}

int retornaPenalizacoesArqueologo(arqueologo a){
    return a->penalizacoes;
}

int retornaDesqualificadoArqueologo(arqueologo a){
    return a->desqualificado;
}

void daPosArqueologo(arqueologo a, int posC, int posL){
    a->posC = posC;
    a->posL = posL;
}

void daMeritoArqueologo(arqueologo a, int valor){
    a->merito = a->merito + valor;
}

void daPenalizacoesArqueologo(arqueologo a, int penal){
    a->penalizacoes = a->penalizacoes + penal;
}

void daDesqualificadoArqueologo(arqueologo a, int desqual){
    a->desqualificado = desqual;
}

void daMeritoPenalizacaoArqueologo(sequencia s, int atual, int penalizacao, int merito, int linha, int coluna){
    arqueologo a = elementoPosSequencia(s, atual);
    a->merito = a->merito + merito - penalizacao;
    if(penalizacao > 0){
        a->penalizacoes++;
    }
    a->posC = coluna;
    a->posL = linha;
    //printf("%s foi para [%d][%d]\n", a->nome, a->posL, a->posC);
}

int ultimoLArqueologo(sequencia s, int atual){
    arqueologo a = elementoPosSequencia(s, atual);

    return a->posL;
}

int ultimoCArqueologo(sequencia s, int atual){
    arqueologo a = elementoPosSequencia(s, atual);

    return a->posC;
}

int meritoArqueologo(sequencia s, int atual){
    arqueologo a = elementoPosSequencia(s, atual);
    return a->merito;
}

char * nomeArqueologoSequencia(sequencia s, int atual){
    arqueologo a = elementoPosSequencia(s, atual);
    return a->nome;
}

int penalizacaoArqueologoSequencia(sequencia s, int atual){
    arqueologo a = elementoPosSequencia(s, atual);
    return a->penalizacoes;
}

void desqualificaArqueologoSequencia(sequencia s, int atual){
    arqueologo a = elementoPosSequencia(s, atual);
    a->desqualificado=1;
}

int retornaDesqualificadoArqueologoSequencia(sequencia s, int atual){
    arqueologo a = elementoPosSequencia(s, atual);
    return a->desqualificado;
}

int adicionaArqueologoSequencia(sequencia s, char * nomearqueologo, int numMembros){
    int i = 0;

    for(i=0; i<numMembros; i++){
        if(strcmp(nomearqueologo, nomeArqueologoSequencia(s, i))==0){
            printf("Arqueologo invalido\n");
            return 0;
        }
    }
    
    arqueologo a = criaArqueologo(nomearqueologo);
    adicionaPosSequencia(s, a, numMembros);
    return 1;
}