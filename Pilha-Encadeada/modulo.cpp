#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

// Estrutura do nó da pilha
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Estrutura da pilha
struct Pilha {
    No* topo;
};

// Função para criar uma nova pilha
Pilha* criarPilha() {
Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
if(pilha != NULL){
pilha->Topo = NULL;
}
return pilha;
}


// Função para destruir a pilha e liberar memória
void destruirPilha(Pilha* pilha){
if(pilha != NULL){
No * aux = pilha->topo;
while(aux != NULL){
free(aux);
}
free(pilha);
}
}



// Verifica se a pilha está vazia
int estaVazia(Pilha* pilha) {
if(pilha == NULL){
 return 1;
}
 return 0;
}

// Empilha um valor
void empilhar(Pilha* pilha, int valor) {
No * no = (No*)malloc(sizeof(No));
if(no != NULL){
no->dado = valor;
no->proximo = NULL;

if(Pilha->topo == NULL){
Pilha->topo = no;
}else{
no->proximo = pilha->topo;
pilha->topo = no;
}
}
}

// Desempilha um valor
int desempilhar(Pilha* pilha) {
if(pilha != NULL){
No * aux = pilha->topo;
int temp = aux->dado;
pilha->topo = pilha->topo->proximo;
free(aux);
return temp;
}
}

// Retorna o valor do topo da pilha sem desempilhar
int verTopo(Pilha* pilha) {
if(pilha != NULL){
return pilha->topo->dado;
}
}

// Exibe os elementos da pilha
void exibirPilha(Pilha* pilha) {
if(pilha != NULL){
No * aux = pilha->topo;
while(aux !=  NULL){
printf("%d\n",aux->dado);
aux = aux->proximo;    
}
}
}
