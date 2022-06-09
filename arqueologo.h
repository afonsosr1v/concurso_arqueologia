#ifndef ARQUEOLOGO_H_
#define ARQUEOLOGO_H_

/***************************
 *      TAD ARQUEOLOGO
 *     GUARDA AS INFORMACOES RELATIVAS
 *     A CADA ARQUEOLOGO
 **************************/

/* Tipo dp TAD arqueologo */
typedef struct _arqueologo * arqueologo;

/* protótipos das funções associadas a um arqueologo - TAD arqueologo */

/*******************************************
 criaArqueologo - Criação da instacia da estrutura aassociada a um arqueologo.
 Pârametros:
    nome - nome do arquelogo
Retorno: Apontador para a instância criada
pré-condições: strlen(nome)<=40
******************************************/
arqueologo criaArqueologo(char * nome);

/***********************
 apagaArqueologo - Liberta a memoria ocupada pela instancia da estrutura associada
 Parametros:
    a - arqueologo a apagar
Retorno:
Pré-condições: a != NULL
***************************/
void apagaArqueologo(arqueologo a);

/**********************
retornaNomeArqueologo - Retorna o Nome do Arqueologo
Parametros:
    a - arqueologo
Retorno: Nome do Arqueologo
Pre-condições: a != NULL
**********************/
char* retornaNomeArqueologo(arqueologo a);

/*********************
retornaPosCArqueologo - Retorna a ultima posição C do arqueologo
Parametros:
    a - arqueologo
Retorno: Ultima Posição C
Pre-Condições: a =! NULL
*************/
int retornaPosCArqueologo(arqueologo a);

/***********************
retornaPosLArqueologo - Retorna a ultima posição L do arqueologo
Parametros:
    a - arqueologo
Retorno: Ultima posição L
Pre-Condições: a =! NULL
**********************/
int retornaPosLArqueologo(arqueologo a);

/**********************
retornaMeritoArqueologo - Retorna o merito do arqueologo
Parametros:
    a - arqueologo
Retorno: merito do arqueologo
Pre-Condições: a =! NULL
*********************/
int retornaMeritoArqueologo(arqueologo a);

//RETORNA AS PENALIZAÇÕES  DO ARQUEOLOGO
int retornaPenalizacoesArqueologo(arqueologo a);

//RETORNA SE O ARQUEOLOG SE ENCONTRA OU NAO DESQUALIFICADO
int retornaDesqualificadoArqueologo(arqueologo a);

//DA OS VALORES DE L E C AO ARQUEOLOGO
void daPosArqueologo(arqueologo a, int posC, int posL);

//DA O MERITO AO ARQUEOLOGO
void daMeritoArqueologo(arqueologo a, int valor);

//DA AS PENALIZAÇÕES AO ARQUEOLOGO
void daPenalizacoesArqueologo(arqueologo a, int penal);

//MARCA O ARQUEOLOGO COMO DESQUALIFICADO
void daDesqualificadoArqueologo(arqueologo a, int desqual);

//DÁ AO ARQUEOLOGO (NA SEQUENCIA) O SEU MERITO, A PENALIZAÇÃO E AS SUAS COORDENADAS L E C
void daMeritoPenalizacaoArqueologo(sequencia s, int atual, int penalizacao, int merito, int linha, int coluna);

//RETORNA A ULTIMA COORDENADA L DO ARQUEOLOGO
int ultimoLArqueologo(sequencia s, int atual);

//RETORNA A ULTIMA COORDENADA C DO ARQUEOLOGO
int ultimoCArqueologo(sequencia s, int atual);

//RETORNA O MERITO DE UM ARQUEOLOGO i DA SEQUENCIA
int meritoArqueologo(sequencia s, int atual);

//RETORNA O NOME DE UM ARQUEOLOGO i DA SEQUENCIA
char * nomeArqueologoSequencia(sequencia s, int atual);

//RETORNA AS PENALIZACOES DE UM ARQUEOLOGO i DA SEQUENCIA
int penalizacaoArqueologoSequencia(sequencia s, int atual);

//INFORMA SE O ARQUEOLOGO i DA SEQUENCIA SE ENCONTRA OU NÃO DESQUALIFICADO
int retornaDesqualificadoArqueologoSequencia(sequencia s, int atual);

//DESQUALIFICA O ARQUEOLOGO i DA SEQUENCIA
void desqualificaArqueologoSequencia(sequencia s, int atual);

//ADICIONA UM ARQUEOLOGO NA ULTIMA POSICAO DA SEQUENCIA
int adicionaArqueologoSequencia(sequencia s, char * nomearqueologo, int numMembros);

#endif
