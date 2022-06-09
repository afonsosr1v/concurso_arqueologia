#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "iterador.h"
#include "dicionario.h"
#include "sequencia.h"

#include "talhao.h"
#include "terreno.h"


struct _terreno{
    talhao ** matriz; //matriz dinamica com structs talhão
    int L, C; //numero de linhas e colunas da matriz
};

terreno criaTerreno(int linhas, int colunas) {
    terreno t = (terreno)malloc(sizeof(struct _terreno));
    if (t==NULL) return NULL;

    int i = 0;

    t->L = linhas;
    t->C = colunas;


    //tentativas sem sucesso de malloc talvez volte a tentar  //não voltei
    /*t->matriz = malloc(linhas+1 * sizeof(*t->matriz));
    for(i=0; i <= linhas+1; i++){
        t->matriz[i]=malloc(colunas+1*sizeof(t->matriz[0]));
    }*/

    

    /* t->matriz = (talhao **)malloc(sizeof(int*)*linhas+1);
        if(t->matriz==NULL) {
            return NULL;
        }
    
    for(i=0;i<=linhas+1;i++){
        t->matriz[i]=(talhao *)malloc(sizeof(int)*colunas+1);
        if(t->matriz[i]==NULL){
            return NULL;
        }
        printf("%d", i);
    } */

    t->matriz = (talhao**)malloc(sizeof(talhao)*linhas+1);
    for(i=0;i<=linhas;i++){
        t->matriz[i] = (talhao*)malloc(sizeof(talhao)*colunas+1);
    }
    

   i=0;
    int j=0;
    for(i=0;i<=linhas;i++){
        for(j=0;j<=colunas;j++){
            t->matriz[i][j]= criaTalhao(0);
            //printf("Criado Talhao [%d][%d]\n", i, j); //verificação
        }
    }

    return t;
}

void apagaTerreno(terreno t){
    free(t);
}

void daValorTalhaoTerreno(terreno t, int i, int j, int valor){
    //printf("a dar valor (%d) talhao[%d][%d]\n", valor, i, j); //verificação
    daValorTalhao(t->matriz[i][j], valor);
    //printf("foi dado o valor %d ao talhao[%d][%d]\n", valor, i, j); //verificação
    //printf("a passar ao proximo\n");
}

void riquezaTerreno(terreno t){
    //printf("entrou na riqueza terreno"); //verificação
    int i, j;
    int sum=0;
    //printf("Este terreno tem %d por %d talhoes\n", t->L, t->C);//verificação
    for(i=0; i<=t->L; i++){
        for (j=0; j<=t->C; j++){
            //printf("entrou no loop Linha: %d Coluna %d\n", i, j);//verificação
            sum = sum + retornaValorTalhao(t->matriz[i][j]);
            //printf("Valor no talhao: %d\n", retornaValorTalhao(t->matriz[i][j]));//verificação
        }
    }
    printf("Riqueza enterrada: %d\n", sum);
    //fflush(stdin);
}

void imprimeTerreno(terreno t){
    int i, j;

    int Linhas=t->L;
    int Colunas=t->C;
    //printf("Linhas:%d\nColunas:%d\n", Linhas, Colunas); //verificação
    i=1;
    j=1;
    for(i=1; i<=Linhas; i++){
        for(j=1; j<=Colunas; j++){
            if(retornaValorTalhao(t->matriz[i][j])==0){
                printf("-");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int escavacaoTerreno(terreno t, int linha, int coluna){
    //printf("O talhão[%d][%d] tem um merito de %d\n", linha, coluna,retornaValorTalhao(t->matriz[linha][coluna])); //verificação
    return retornaValorTalhao(t->matriz[linha][coluna]);
}

int numEscavacoesTerreno(terreno t, int linha, int coluna){
    //printf("a retornar numero de escavacões: %d\n", retornaEscavacoesTalhao(t->matriz[linha][coluna]));//verificação
    return retornaEscavacoesTalhao(t->matriz[linha][coluna]);
}

void zeraTalhaoTerreno(terreno t, int linha, int coluna){
    daValorTalhao(t->matriz[linha][coluna], 0);
    //printf("O Talhao[%d][%d] tem agora valor %d\n", linha, coluna, retornaValorTalhao(t->matriz[linha][coluna]));//verificação
    daEscavacoesTalhao(t->matriz[linha][coluna]);
}

int terrenoSair(terreno t){
    int i, j;
    int sum=0;
    //printf("Este terreno tem %d por %d talhoes\n", t->L, t->C);//verificação
    for(i=0; i<=t->L; i++){
        for (j=0; j<=t->C; j++){
            //printf("entrou no loop Linha: %d Coluna %d\n", i, j);//verificação
            sum = sum + retornaValorTalhao(t->matriz[i][j]);
            //printf("Valor no talhao: %d\n", retornaValorTalhao(t->matriz[i][j]));//verificação
        }
    }
    return sum;
}

void zeraTalhoesZero(terreno t){
    int i=0;

    for(i=0; i<=t->L;i++){
        daValorTalhao(t->matriz[i][0], 0);
    }
    i=0;
    for(i=0;i<=t->C;i++){
        daValorTalhao(t->matriz[0][i], 0);
    }
}

int retornaLterreno(terreno t){
    return t->L;
}

int retornaCterreno(terreno t){
    return t->C;
}

