#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iterador.h"
#include "dicionario.h"
#include "sequencia.h"

#include "arqueologo.h"
#include "equipa.h"
#include "terreno.h"
#include "concurso.h"

void interpretador(concurso c){
 
    char entrada[50];
    char comando[50];
    
    do{
        scanf(" %[^\n]", entrada);
        sscanf(entrada, "%s", comando);
   
        
        if (strcmp(comando, "riqueza")==0){
            concursoRiqueza(entrada, c);
        }
        else if (strcmp(comando, "terreno")==0){
            concursoTerreno(entrada, c);
        }
        else if (strcmp(comando, "estrela")==0){
            concursoEstrela(entrada, c);
            
        }
        else if (strcmp(comando, "escavacao")==0){
            concursoEscavacao(entrada, c);
            
        }
        else if (strcmp(comando, "equipa")==0){
            concursoEquipa(entrada, c);
            
        }
        else if (strcmp(comando, "reforco")==0){
            concursoReforco(c);
            //fflush(stdin);
        }
        else if (strcmp(comando, "sair")==0){
        }
        else{
            printf("Comando invalido\n");
            
        }
       
        
    } while(strcmp(comando, "sair")!=0);
    concursoSair(c);
}

int main(){
    int L, C;
    int i, j;
    int valorTalhao;
    int numEquipas;
    int equipa;
    char entrada[100];

    fgets(entrada, 100, stdin);
    sscanf(entrada, " %d %d", &L, &C);

    terreno t = criaTerreno(L, C);
    if(t==NULL){return (10001);};



    for(i=1; i<=L; i++){
        for(j=1; j<=C; j++){
            if(scanf(" %d", &valorTalhao)!=1){return (999);}
            daValorTalhaoTerreno(t, i, j, valorTalhao);
        }
        j=1;
        
    }

    if(scanf("%d", &numEquipas)!=1){return(6969);}
   

    concurso c = criaConcurso(t, numEquipas);
    if(c==NULL){return (20002);}

    i=0;
    for(i=0; i<numEquipas; i++){
        if(scanf(" %d", &equipa)!=1){return (420);}
        criaEquipaConcurso(c, equipa);
    }
    interpretador(c);
}

    