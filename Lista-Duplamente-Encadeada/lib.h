#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo Nodo;
typedef struct ListaEncadeada ListaEncadeada;

ListaEncadeada* criarLista();

void adicionarInicio(ListaEncadeada* lista, int valor);

void adicionarFim(ListaEncadeada* lista, int valor);

void removerFim(ListaEncadeada* lista);

void arquivoInicio(ListaEncadeada * lista, FILE * file);

void arquivoFim(ListaEncadeada * lista, FILE * file);

void arquivoRemoverInicio(ListaEncadeada * lista);

void arquivoRemoverFim(ListaEncadeada * lista);

void mostrarLista(Nodo * aux);

void armazenarListaArquivo(Nodo * aux, FILE * file);

int obterElemento(ListaEncadeada* lista, int indice);

int estaVazia(ListaEncadeada* lista);

int obterTamanho(ListaEncadeada* lista);
