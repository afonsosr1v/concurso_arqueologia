#ifndef TERRENO_H_
#define TERRENO_H_

/************
 * TAD
 * TERRENO
 **********/


typedef struct _terreno * terreno;

//cria uma struct terreno
terreno criaTerreno(int linhas, int colunas);

//apaga a struct terreno
void apagaTerreno(terreno t);

//da o valor a passar ao talhao[i][j] do terrno
void daValorTalhaoTerreno(terreno t, int i, int j, int valor);

//soma o valor total dos talhoes do terreno
void riquezaTerreno(terreno t);

//imprime a matriz do terreno
void imprimeTerreno(terreno t);

//escava o talhao[linha][coluna] do terreno
int escavacaoTerreno(terreno t, int linha, int coluna);

//retorna o numero de escavacoes realizadas no talhao[linha][coluna]
int numEscavacoesTerreno(terreno t, int linha, int coluna);

//mete o talhao[linha][coluna] com o valor 0
void zeraTalhaoTerreno(terreno t, int linha, int coluna);

//verifica a riqueza do terreno durante a funcao sair
int terrenoSair(terreno t);

//limpa o terreno
void zeraTalhoesZero(terreno t);

//retorna o numero de linhas do terreno
int retornaLterreno(terreno t);

//retorna o numero de colunas do terreno
int retornaCterreno(terreno t);

#endif