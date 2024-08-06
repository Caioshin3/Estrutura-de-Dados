#include "lib.h"

struct Nodo{
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

void adicionarInicio(ListaEncadeada* lista, int valor) {
    Nodo* no = (Nodo*) malloc (sizeof(Nodo));
    if(no != NULL){
    	no->dados = valor;
    	no->proximo = lista->cabeca;
    	no->anterior = NULL;
    	if(lista->cabeca != NULL){
         lista->cabeca->anterior = no;
    	}
    	lista->cabeca = no;
    	lista->tamanho++;
	}
}

void adicionarFim(ListaEncadeada* lista, int valor) {
   Nodo* no = (Nodo*) malloc(sizeof(Nodo));
   if(no != NULL){
   		no->dados = valor;
   		no->proximo = NULL;
   		no->anterior = NULL;
   		if(lista->cabeca == NULL){
   			lista->cabeca = no;
   		}
   		else{
   			Nodo *aux;
   			aux = lista->cabeca;
   			while(aux->proximo != NULL){
   				aux = aux->proximo;
   			}
   			    aux->proximo = no;
   			    no->anterior = aux;
		   }
   		lista->tamanho++;
   }
}

void removerInicio(ListaEncadeada* lista) {
 	if(lista->cabeca != NULL){
 		Nodo* aux = lista->cabeca;
 		lista->cabeca = lista->cabeca->proximo;
 		lista->cabeca->anterior = NULL;
 		free(aux);
 		lista->tamanho--;
	 } 
}

void removerFim(ListaEncadeada* lista) {
   if(lista->cabeca != NULL){
 		Nodo* aux = lista->cabeca;
 		while(aux->proximo != NULL){
     	  aux = aux->proximo; 
 		}
 		Nodo* aux2 = aux->anterior;
 		aux2->proximo = NULL;
 		free(aux);
 		lista->tamanho--;
	 }
}

void arquivoInicio(ListaEncadeada * lista, FILE * file){
  char temp [100];
  for(int i = 0; i<5; i++){
     fgets(temp, sizeof(temp), file);
     int valor = 0;
     sscanf(temp, "%d", &valor);
      adicionarInicio(lista,valor);
      if(i<4){
      printf("No %d foi adicionado no inicio da lista\n",valor);
      }if(i==4){
      printf("No %d foi adicionado no inicio da lista\n\n",valor);
      }
    }
}

void arquivoFim(ListaEncadeada * lista, FILE * file){
  char temp [100];
  for(int i = 0; i<5; i++){
     fgets(temp, sizeof(temp), file);
     int valor = 0;
     sscanf(temp, "%d", &valor);
      adicionarFim(lista,valor);
      if(i<4){
      printf("No %d foi adicionado no final da lista\n",valor);
      }if(i==4){
      printf("No %d foi adicionado no final da lista\n\n",valor);
      } 
    }
}

void arquivoRemoverInicio(ListaEncadeada * lista){
  for(int i = 0; i<2; ++i){
      printf("No %d foi removido do inicio da lista\n",lista->cabeca->dados);
      removerInicio(lista);
    }
  
}

void arquivoRemoverFim(ListaEncadeada * lista){
  for(int i = 0; i<2; i++){
      Nodo* aux = lista->cabeca;
      while(aux->proximo != NULL){
       aux = aux->proximo;   
      }
      printf("No %d foi removido do final da lista\n",aux->dados);
      removerFim(lista);
    }
}

void mostrarLista(Nodo * aux){

while (aux != NULL){
printf("%d\n",aux->dados);
aux = aux->proximo;
}

}

void armazenarListaArquivo(Nodo * aux, FILE * file){

while(aux != NULL){
    fprintf(file,"%d\n",aux->dados);        
    aux = aux->proximo;
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

