#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iterador.h"
#include "dicionario.h"
#include "sequencia.h"

#include "arqueologo.h"
#include "equipa.h"
#include "talhao.h"
#include "terreno.h"
#include "concurso.h"

struct _concurso{
    terreno t; //struct terreno
    int numEquipas; //numero de equipas em jogo
    dicionario equipas; //dicionario que contem todas as equipas
};

concurso criaConcurso(terreno t, int numEquipas){
    concurso c = (concurso)malloc(sizeof(struct _concurso));
    if (c==NULL) return NULL;

    c->t = t;

    c->equipas = criaDicionario(numEquipas, 1);

    c->numEquipas = numEquipas;

    return c;
}

void apagaConcurso(concurso c){
    free(c);
}


void concursoRiqueza(char * entrada, concurso c){
    riquezaTerreno(c->t);
}

void concursoTerreno(char * entrada, concurso c){
    imprimeTerreno(c->t);
}

void concursoEstrela(char * entrada, concurso c){
    char comando[50];
    char nomeEquipa[50];
    sscanf(entrada, " %s %[^\n]s", comando, nomeEquipa);

    if(existeElemDicionario(c->equipas,nomeEquipa)==1){
        estrelaEquipa(c->equipas, nomeEquipa);
    }
    else {
        printf("Equipa invalida\n");
    }
}

void concursoEscavacao(char * entrada, concurso c){
    int linha, coluna;
    char comando[50];
    char nomeEquipa[50];
    int merito;
    int penalizacao;

    sscanf(entrada, " %s %d %d %[^\n]s", comando, &linha, &coluna, nomeEquipa);

    if(linha==0&&coluna==0){
        printf("Salto invalido\n");
    }
    else
    if(existeElemDicionario(c->equipas, nomeEquipa)!=1){
        printf("Equipa invalida\n");
    }
    else if(validadeEquipa(c->equipas, nomeEquipa)==0){
        printf("Equipa invalida\n");

    }
    else {
        verificacaoNext(c->equipas, nomeEquipa);

        int linhaatual = deslocamentoLAnteriorEquipa(c->equipas, nomeEquipa) + linha;
        int colunaatual = deslocamentoCAnteriorEquipa(c->equipas, nomeEquipa) + coluna;

        if((linhaatual<=0)||(colunaatual<=0)||(linhaatual>retornaLterreno(c->t))||(colunaatual>retornaCterreno(c->t))){
            if(desqualificaArqueologoEquipa(c->equipas, nomeEquipa)==0){
                c->numEquipas--;
            }
        }
        else {
            penalizacao = numEscavacoesTerreno(c->t, linhaatual, colunaatual)*10;
            merito = escavacaoTerreno(c->t, linhaatual, colunaatual);

            zeraTalhaoTerreno(c->t, linhaatual, colunaatual);

            daMeritoPenalizacaoEquipa(c->equipas, penalizacao, merito, linhaatual, colunaatual, nomeEquipa);
        }
        
    }
}

void criaEquipaConcurso(concurso c, int posEquipaFicheiro){
    int i, j; 
    FILE * fp = fopen("teams.txt", "r");
    int contaLinhas = 0;
    char leitura[100];
    char nomeEquipa[100];

    for(i=1;i<posEquipaFicheiro;i++){
        fscanf(fp, "%d\n", &contaLinhas);
        fscanf(fp, "%[^\n]\n", nomeEquipa);
        for(j=0; j<contaLinhas; j++){
            fscanf(fp, "%[^\n]\n", leitura);
        }
    }

    if(fscanf(fp, "%d\n", &contaLinhas)==-1){
        printf("Equipa inexistente\n");
    }
    else{
        sscanf(leitura, " %d", &contaLinhas);
        fscanf(fp, "%[^\n]\n", nomeEquipa);
        if(existeElemDicionario(c->equipas, nomeEquipa)==1){
            printf("Equipa invalida\n");
        }
        else {
        equipa e = criaEquipa(nomeEquipa, contaLinhas);
        j=0;
            for(j=0; j<contaLinhas; j++){

                fscanf(fp, "%[^\n]\n", leitura);
                daArqueologoEquipa(e, criaArqueologo(leitura), j);
            }
            adicionaElemDicionario(c->equipas, nomeEquipa, e);
        }
    }
    fclose(fp);
}

void concursoEquipa(char * entrada, concurso c){
    char comando[50];
    int posEquipa;
    sscanf(entrada, " %s %d", comando, &posEquipa);
    criaEquipaConcurso(c, posEquipa);
    c->numEquipas++;
}

void concursoSair(concurso c){
    if(c->numEquipas<=0){
        printf("Todas as equipas foram expulsas.\n");
    }
    else {
        if(terrenoSair(c->t)==0){
            printf("Todos os tesouros foram descobertos!\n");
        }
        else{
            printf("Ainda havia tesouros por descobrir...\n");
        }
    printf("classificacao\n");
    classificacaoEquipas(c->equipas, c->numEquipas);
    }
}

void concursoReforco(concurso c){
    char nomeEquipa[40];
    char nomeArqueologo[40];


    scanf("\n%[^\n]\n", nomeEquipa);
    scanf("%[^\n]\n", nomeArqueologo);

    //printf("%s\n", nomeEquipa);
    adicionaArqueologoEquipa(c->equipas, nomeEquipa, nomeArqueologo);
}
