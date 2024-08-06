#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo Nodo;
typedef struct ListaEncadeada ListaEncadeada;

// Função para criar uma nova lista encadeada
ListaEncadeada* criarLista();

// Função para destruir a lista encadeada
void destruirLista(ListaEncadeada* lista);

// Função para adicionar um elemento no início da lista
void adicionarInicio(ListaEncadeada* lista, int valor);

// Função para adicionar um elemento no final da lista
void adicionarFim(ListaEncadeada* lista, int valor);

// Função para remover um elemento do início da lista
void removerInicio(ListaEncadeada* lista);

// Função para obter um elemento da lista por índice
int obterElemento(ListaEncadeada* lista, int indice);

// Função para verificar se a lista está vazia
int estaVazia(ListaEncadeada* lista);

// Função para obter o tamanho da lista
int obterTamanho(ListaEncadeada* lista);


