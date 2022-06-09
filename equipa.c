#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "iterador.h"
#include "dicionario.h"
#include "sequencia.h"

#include "arqueologo.h"
#include "equipa.h"

struct _equipa{
    char nome[40]; //nome da equipa
    int numMembros; //numero de membros da equipa
    sequencia arqueologos; //sequencia com todos os arqueologos pertencentes à equipa
    int pontuacao; //pontuação da equipa
    int proximoMove; //qual a posição da sequencia que joga a seguir
    int membrosValidos; //quantos membros da equipa não estão desqualificados
    int iEstrela; //qual a posição na sequencia da estrela da equipa
};

equipa criaEquipa(char * nome, int numMembros){
    equipa e;
    e = (equipa)malloc(sizeof(struct _equipa));
    if (e==NULL) return NULL;
    strcpy(e->nome, nome);
    e->numMembros = numMembros;
    e->arqueologos = criaSequencia(numMembros);
    e->pontuacao = 0;
    e->proximoMove = 0;
    e->membrosValidos = numMembros;
    e->iEstrela = 0;

    return e;
}

void daPontuacao(equipa e, int valor){
    e->pontuacao = e->pontuacao + valor;
}

char* retornaNomeEquipa(equipa e){
    return e->nome;
}

int retornaNumMembrosEquipa(equipa e){
    return e->numMembros;
}

int retornaPontuacaoEquipa(equipa e){
    return e->pontuacao;
}

void estrelaEquipa(dicionario d, char * nomeEquipa){
    equipa e = elementoDicionario(d, nomeEquipa);
    if(e->membrosValidos==0){
        printf("Equipa invalida\n");
    }
    else{
        char nomeEstrela[40];
        int i;
        int maiorValor = 0;
        int penalizacoesEstrela = 0;
        int iTemp = 0;
        
        for(i=0; i<e->numMembros; i++){
            if(retornaDesqualificadoArqueologoSequencia(e->arqueologos, iTemp) == 1){
                iTemp++;
                strcpy(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, iTemp));
                maiorValor = meritoArqueologo(e->arqueologos, iTemp);
                penalizacoesEstrela = penalizacaoArqueologoSequencia(e->arqueologos, iTemp);
            }
            if(retornaDesqualificadoArqueologoSequencia(e->arqueologos, i) == 0){
                if(meritoArqueologo(e->arqueologos, i) > maiorValor){
                    strcpy(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, i));
                    maiorValor = meritoArqueologo(e->arqueologos, i);
                    penalizacoesEstrela = penalizacaoArqueologoSequencia(e->arqueologos, i);
                    iTemp = i;
                }
                else if(meritoArqueologo(e->arqueologos, i) == maiorValor){
                    if(penalizacaoArqueologoSequencia(e->arqueologos, i) < penalizacoesEstrela){
                        strcpy(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, i));
                        maiorValor = meritoArqueologo(e->arqueologos, i);
                        penalizacoesEstrela = penalizacaoArqueologoSequencia(e->arqueologos, i);
                        iTemp = i;
                    }
                    else if(penalizacaoArqueologoSequencia(e->arqueologos, i) == penalizacoesEstrela){
                        if(strcmp(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, i))>0){
                            strcpy(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, i));
                            maiorValor = meritoArqueologo(e->arqueologos, i);
                            penalizacoesEstrela = penalizacaoArqueologoSequencia(e->arqueologos, i);
                            iTemp = i;
                        }
                        else if(strcmp(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, i))<0){
                            strcpy(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, iTemp));
                            penalizacoesEstrela = penalizacaoArqueologoSequencia(e->arqueologos, iTemp);
                        }

                    }
                    else if(penalizacaoArqueologoSequencia(e->arqueologos, i) > penalizacoesEstrela){
                        strcpy(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, iTemp));
                        maiorValor = meritoArqueologo(e->arqueologos, iTemp);
                        penalizacoesEstrela = penalizacaoArqueologoSequencia(e->arqueologos, iTemp);
                    }
                }
                else if(meritoArqueologo(e->arqueologos, i) < maiorValor){
                    strcpy(nomeEstrela, nomeArqueologoSequencia(e->arqueologos, iTemp));
                    maiorValor = meritoArqueologo(e->arqueologos, iTemp);
                    penalizacoesEstrela = penalizacaoArqueologoSequencia(e->arqueologos, iTemp);
                }
            }
        }
        
        printf("Estrela de %s: %s\n", nomeEquipa, nomeEstrela);
        e->iEstrela = iTemp;
    }
}

void daMeritoPenalizacaoEquipa(dicionario d, int penalizacao, int merito, int linha, int coluna, char * nomeEquipa){
    equipa e = elementoDicionario(d, nomeEquipa);
    daMeritoPenalizacaoArqueologo(e->arqueologos, e->proximoMove, penalizacao, merito, linha, coluna);
    e->pontuacao = e->pontuacao + merito - penalizacao;
    e->proximoMove++;
    if(e->proximoMove==e->numMembros){
        e->proximoMove=0;
    }
}

int deslocamentoLAnteriorEquipa(dicionario d, char * nomeEquipa){
    equipa e = elementoDicionario(d, nomeEquipa);
    return ultimoLArqueologo(e->arqueologos, e->proximoMove);
}

int deslocamentoCAnteriorEquipa(dicionario d, char * nomeEquipa){
    equipa e = elementoDicionario(d, nomeEquipa);
    return ultimoCArqueologo(e->arqueologos, e->proximoMove);
}

void daArqueologoEquipa(equipa e, arqueologo a, int pos){
    adicionaPosSequencia(e->arqueologos, a, pos);
}

int desqualificaArqueologoEquipa(dicionario d, char * nomeEquipa){
    equipa e = elementoDicionario(d, nomeEquipa);
    desqualificaArqueologoSequencia(e->arqueologos, e->proximoMove);
    e->proximoMove++;
    if(e->proximoMove==e->numMembros){
        e->proximoMove=0;
    }
    e->membrosValidos--;
    if (e->membrosValidos == 0) {
        printf("%s foi expulsa\n", nomeEquipa);
        return (0);
    }
    else {
        return (1);
    }
}

int validadeEquipa(dicionario d, char * nomeEquipa){
    equipa e = elementoDicionario(d, nomeEquipa);
    if(e->membrosValidos==0){
        return (0);
    }
    else {
        return (1);
    }
}

/*void apagaEquipaeMembros(equipa e){
    //destroiSeqElems(e->arqueologos, apagaArqueologo);
    destroiSequencia(e->arqueologos);
    free(e);
}*/

void verificacaoNext(dicionario d, char * nomeEquipa){
    equipa e = elementoDicionario(d, nomeEquipa);
    if(retornaDesqualificadoArqueologoSequencia(e->arqueologos, e->proximoMove)==1){
        e->proximoMove++;
        //printf("Proximo move incremetado");
        if(e->proximoMove>=e->numMembros){
        e->proximoMove=0;
        if(retornaDesqualificadoArqueologoSequencia(e->arqueologos, e->proximoMove)==1){
            e->proximoMove++;
        }
        }
    }
}

void daNext(dicionario d, char * nomeEquipa){
    equipa e = elementoDicionario(d, nomeEquipa);
    e->proximoMove++;
    if(e->proximoMove>=e->numMembros){
        e->proximoMove=0;
    }
}

void adicionaArqueologoEquipa(dicionario d, char * nomeequipa, char * arqueologo){

    if(existeElemDicionario(d, nomeequipa)==0){
        printf("Equipa invalida\n");
    }
    else{
        equipa e = elementoDicionario(d, nomeequipa);

        if(adicionaArqueologoSequencia(e->arqueologos, arqueologo, e->numMembros)==1){
            e->numMembros++;
            e->membrosValidos++;
        }
    }
}

void classificacaoEquipas(dicionario d, int numEquipas){
    int i = 0;
    equipa top = criaEquipa("zzz", 0);
    for(i=0;i<numEquipas;i++){
        iterador it = iteradorDicionario(d);
        equipa um = criaEquipa("um", 0);
        while (temSeguinteIterador(it)!=0){
            equipa dois = seguinteIterador(it);
            //printf("%d\n", dois->membrosValidos);
            if(dois->membrosValidos>0){
            if(um->numMembros==0){
                strcpy(um->nome, dois->nome);
                um->membrosValidos = dois->membrosValidos;
                um->numMembros = dois->numMembros;
                um->pontuacao = dois->pontuacao;
            }
            else{
                
                    if(dois->pontuacao>um->pontuacao){
                        strcpy(um->nome, dois->nome);
                        um->membrosValidos = dois->membrosValidos;
                        um->numMembros = dois->numMembros;
                        um->pontuacao = dois->pontuacao;
                    }
                    else if(dois->pontuacao==um->pontuacao){
                        if(dois->numMembros-dois->membrosValidos<um->numMembros-um->membrosValidos){
                            strcpy(um->nome, dois->nome);
                            um->membrosValidos = dois->membrosValidos;
                            um->numMembros = dois->numMembros;
                            um->pontuacao = dois->pontuacao;
                        }
                        if(dois->numMembros-dois->membrosValidos==um->numMembros-um->membrosValidos){
                            if(dois->membrosValidos<um->membrosValidos){
                                strcpy(um->nome, dois->nome);
                                um->membrosValidos = dois->membrosValidos;
                                um->numMembros = dois->numMembros;
                                um->pontuacao = dois->pontuacao;
                            }
                            else if(dois->membrosValidos == um->membrosValidos){
                                if(strcmp(dois->nome, um->nome)<0){
                                    strcpy(um->nome, dois->nome);
                                    um->membrosValidos = dois->membrosValidos;
                                    um->numMembros = dois->numMembros;
                                    um->pontuacao = dois->pontuacao;
                                }
                            }
                        }
                    }
                }
            }
        }
        strcpy(top->nome, um->nome);
        top->membrosValidos = um->membrosValidos;
        top->numMembros = um->numMembros;
        top->pontuacao = um->pontuacao;
        if(desqualificaEquipaDicionario(top->nome, d)==0){
            exit(0);
        }
        printf("%s: %d pts; %d descl.; %d com lic.\n", top->nome, top->pontuacao, top->numMembros-top->membrosValidos, top->membrosValidos);
        
    }
}

int desqualificaEquipaDicionario(char * nomeEquipa, dicionario d){
    equipa e = elementoDicionario(d, nomeEquipa);
    if(e==NULL){
        return (0);
    }
    else{
        e->membrosValidos=0;
        return (1);
    }
}
