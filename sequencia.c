#include <stdlib.h>
#include "iterador.h"
#include "sequencia.h"

/* Estrutura de dados: sequencia implementada em vector */
struct _sequencia{
	void * * elems; // apontador para vector de enderecos de elementos
	int numElems;
	int capacidade; // capacidade corrente do vector
};


sequencia criaSequencia(int cap){
    sequencia s;

    s = (sequencia) malloc(sizeof(struct _sequencia));
    if(s==NULL) return NULL;

    s->elems = (void*) malloc(sizeof(void *)*cap);
    if(s->elems == NULL) {
        free(s);
        return NULL;
    }
    s->numElems = 0;
    s->capacidade = cap;

    return s;
}


void destroiSequencia (sequencia s ){
    free(s);
}


void destroiSeqElems(sequencia s, void (*destroi)(void *) ){

    for(int i = 0; i < s->numElems; i++) {
        destroi(s->elems[i]);
    }

    free(s->elems);
    free(s);
}


int vaziaSequencia(sequencia s){

    if(s->numElems == 0)
        return 1;
    else
        return 0;
}


int tamanhoSequencia(sequencia s){
	return s->numElems;
}


void * elementoPosSequencia(sequencia s, int i){
    return s->elems[i-1];
}


void adicionaPosSequencia(sequencia s, void * elem, int i){

        for(int num = s->numElems; num>=i; num--) {
            s->elems[num] = s->elems[num-1];
        }
        s->elems[i-1] = elem;
        s->numElems++;
}


void * removePosSequencia(sequencia s, int i){
    void* a;

    a = s->elems[i-1];

    for(; i < s->numElems; i++) {
        s->elems[i-1] = s->elems[i];
    }
    s->numElems--;
    return a;
}


iterador iteradorSequencia(sequencia s){
	//CUIDADO: DEVE DAR AO ITERADOR UMA COPIA DO VECTOR A PERCORRER
	iterador it;
	void* *aux = malloc(sizeof(void*)*(s->numElems));

	for(int i = 0; i < s->numElems; i++) {
        aux[i] = s->elems[i];
	}

	it = criaIterador(aux, s->numElems);

	return it;

}


