#ifndef _TFileh_
#define _TFileh_

//Mensagens de erro
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define ERROR -2

#define MAX 100

#include "TMat2D.h"
#include "TStackPontos.h"

MATRIZ* open_txt(char *nome);
int *converte_imagem(char *nome_texto, char *nome_binario);
MATRIZ* open_binario(char *nome);
int segment_file(char *nome_original, char *nome_resultado, int valor);
int componentes_conexos(char *img_segmentada, char *nome_resultado);
int labirinto(char *nome_labirinto, char *nome_resultado);
int salva_arquivo(MATRIZ *matriz, char *nome_arquivo);

#endif