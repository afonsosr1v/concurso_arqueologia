#ifndef TALHAO_H_
#define TALHAO_H_

/****************
 *      TAD
*      TALHÃO
****************/

typedef struct _talhao * talhao;

//cria um talhão
talhao criaTalhao(int valor);

//apaga um talhão
void apagaTalhao(talhao tl);

//da o valor a um talhão
void daValorTalhao(talhao tl, int valor);

//incrementa o numero de vezes que um talhão foi escavado
void daEscavacoesTalhao(talhao tl);

//retorna o valor do talhão
int retornaValorTalhao(talhao tl);

//retorna o numero de vezes que o talhão foi escavado
int retornaEscavacoesTalhao(talhao tl);

#endif