#ifndef EQUIPA_H_
#define EQUIPA_H_

/*************************
 *      TAD
 *    Equipa
 * *********************/

typedef struct _equipa * equipa;

//cria uma struct equipa
equipa criaEquipa(char * nome, int numMembros);

//da um arqueologo à equipa
void daArqueologo(equipa e, arqueologo a);

//da pontuacao á equipa
void daPontuacao(equipa e, int valor);

//retorna o nome da equipa
char* retornaNomeEquipa(equipa e);

//retorna numero de membros de equipa
int retornaNumMembrosEquipa(equipa e);

//retorna a pontuação da equipa
int retornaPontuacaoEquipa(equipa e);

//define e imprime a estrela da equipa
void estrelaEquipa(dicionario d, char * nomeEquipa);

//dá o merito, penalização e coordenadas à equipa para esta passar ao arqueologo.
void daMeritoPenalizacaoEquipa(dicionario d, int penalizacao, int merito, int linha, int coluna, char * nomeEquipa);

//retorna a ultima coordenada L de uma equipa
int deslocamentoLAnteriorEquipa(dicionario d, char * nomeEquipa);

//retorna a ultima coordenada C de uma equipa
int deslocamentoCAnteriorEquipa(dicionario d, char * nomeEquipa);

//dá um arqueologo à sequencia de arqueologos da equipa
void daArqueologoEquipa(equipa e, arqueologo a, int pos);

//desquialifica um arqueologo da equipa
int desqualificaArqueologoEquipa(dicionario d, char * nomeEquipa);

//apaga a equipa e os seus membros
void apagaEquipaeMembros(equipa e);

//verificia se a equipa está apta para jogar ou não
int validadeEquipa(dicionario d, char * nomeEquipa);

//verifica se o proximo arqueologo está apto para jogar ou não
void verificacaoNext(dicionario d, char * nomeEquipa);

//salta à frente um arqueologo que não esteja apto para jogar
void daNext(dicionario d, char * nomeEquipa);

//adiciona um arqueologo dado no comando reforco à equipa
void adicionaArqueologoEquipa(dicionario d, char * equipa, char * arqueologo);

//faz a classificação das equipas
void classificacaoEquipas(dicionario d, int numEquipas);

//desqualifica uma equipa
int desqualificaEquipaDicionario(char * nomeEquipa, dicionario d);

#endif
