#include <stdlib.h>
#include <string.h>

#include "iterador.h"
#include "dicionario.h"
#include "sequencia.h"

#include "talhao.h"

struct _talhao{
    int valor; //Valor do talhão
    int numEscavacoes; //Numero de vezes que um talhão foi escavado
};

talhao criaTalhao(int valor){
    talhao tl;
    tl = (talhao)malloc(sizeof(struct _talhao));
    if (tl == NULL) return NULL;
    tl->valor = valor;
    tl->numEscavacoes = 0;

    return tl;
};

void apagaTalhao(talhao tl){
    free(tl);
}

void daValorTalhao(talhao tl, int valor){
    tl->valor = valor;
}

void daEscavacoesTalhao(talhao tl){
    tl->numEscavacoes=tl->numEscavacoes+1;
}

int retornaValorTalhao(talhao tl){
    return tl->valor;
}

int retornaEscavacoesTalhao(talhao tl){
    return tl->numEscavacoes;
}
