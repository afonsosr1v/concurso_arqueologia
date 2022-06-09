#ifndef CONCURSO_H_
#define CONCURSO_H_
/***************
 * TAD
 * CONCURSO
 * *************/
typedef struct _concurso * concurso;

//cria uma struct concurso
concurso criaConcurso(terreno t, int numEquipas);

//apaga uma struct concurso
void apagaConcurso(concurso c);

//executa o comando riqueza
void concursoRiqueza(char * entrada, concurso c);

//executa o comando terreno
void concursoTerreno(char * entrada, concurso c);

//executa o comando estrela
void concursoEstrela(char * entrada, concurso c);

//executa o comando escavacao
void concursoEscavacao(char * entrada, concurso c);

//cria uma equipa para adicionar ao concurso
void criaEquipaConcurso(concurso c, int posEquipaFicheiro);

//executa o comando equipa
void concursoEquipa(char * entrada, concurso c);

//executa o comando reforco
void concursoReforco(concurso c);

//executa o comando sair
void concursoSair(concurso c);

#endif