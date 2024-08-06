#include "lib.h"

struct Nodo {
    int dados;
    Nodo* proximo;
    Nodo* anterior;
};

struct ListaEncadeada {
    Nodo* cabeca;
    int tamanho;
};

ListaEncadeada* criarLista() {
 	ListaEncadeada * lista = (ListaEncadeada*) malloc(sizeof(ListaEncadeada)) ;
	if(lista != NULL){
		lista->cabeca = NULL;
		lista->tamanho = 0;
	}
	return lista;
}

void destruirLista(ListaEncadeada* lista) {

   if(lista!= NULL){
   	Nodo *aux;
	while(lista->cabeca != NULL){
		aux = lista->cabeca;
   		lista->cabeca = lista->cabeca->proximo;
   		free(aux);
	}
	free(lista);
   }  
}

void adicionarInicio(ListaEncadeada* lista, int valor) {
    Nodo* no = (Nodo*) malloc (sizeof(Nodo));
    if(no != NULL){
    	no->dados = valor;
    	no->proximo = lista->cabeca;
    	lista->cabeca = no;
    	lista->tamanho++;
	}
}

void adicionarFim(ListaEncadeada* lista, int valor) {
   Nodo* no = (Nodo*) malloc(sizeof(Nodo));
   if(no !=NULL){
   		no->dados = valor;
   		no->proximo = NULL;
   		if(lista->cabeca == NULL)
   			lista->cabeca = no;
   		else{
   			Nodo *aux;
   			aux = lista->cabeca;
   			while(aux->proximo != NULL)
   				aux = aux->proximo;
   			aux->proximo = no;
		   }
   		lista->tamanho++;
   }
}

void removerInicio(ListaEncadeada* lista) {
 	if(lista->cabeca != NULL){
 		Nodo* aux = lista->cabeca;
 		lista->cabeca = lista->cabeca->proximo;
 		free(aux);
 		lista->tamanho--;
	 } 
}

int obterElemento(ListaEncadeada* lista, int indice) {
    if(indice<0 || indice >= lista->tamanho)
    	printf("Erro");
    else{
    	Nodo * aux = lista->cabeca;
    	for(int i = 0; i< indice; i++)
    		aux = aux->proximo;
    	return aux->dados;
	}
}


int estaVazia(ListaEncadeada* lista) {
    return lista->cabeca == NULL;
}

int obterTamanho(ListaEncadeada* lista) {
    return lista->tamanho;
}
