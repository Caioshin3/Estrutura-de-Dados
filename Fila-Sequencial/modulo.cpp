#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

struct Fila {
    int frente, traseira, tamanho;
    int capacidade;
    int* vetor;
};

// Função para criar uma fila de capacidade dada. Inicializa tamanho da fila como 0.
Fila* criarFila(int capacidade) {
Fila * fila = (Fila*)malloc(sizeof(Fila));
if(fila != NULL){
fila->vetor = (int*)malloc(sizeof((int)*capacidade));
if(fila->vetor != NULL){
fila->capacidade = capacidade;
fila->frente = 0;
fila->traseira = -1;
fila->tamanho = 0;
}
}
return fila;

}

// Fila está cheia quando tamanho é igual à capacidade
int estaCheia(Fila* fila) {
if(fila->tamanho == fila->capacidade);
}

// Fila está vazia quando tamanho é 0
int estaVazia(Fila* fila) {
if(fila->tamanho == 0);
}

// Função para adicionar um item à fila. Incrementa o índice da traseira e tamanho da fila.
void enfileirar(Fila* fila, int item) {
if(fila != NULL){
if(estaCheia(fila))return;
fila->traseira = (fila->traseira + 1) % fila->capacidade;
fila->vetor[fila->traseira] = item;
}
fila->tamanho++;
printf("%d\n",fila->traseira);  
}    


// Função para remover um item da fila. Incrementa o índice da frente e diminui o tamanho da fila.
int desenfileirar(Fila* fila) {
if(fila != NULL){
if(estaVazia(fila))return -1;
int aux = fila->vetor[fila->frente];
fila->tamanho--;
fila->frente = (fila->frente + 1) % fila->frente;
return aux;    
}

// Função para retornar o item da frente da fila sem removê-lo.
int frente(Fila* fila){
if(fila != NULL){
if(estaVazia(fila))return -1;
return fila->frente;
}
}

// Função para retornar o item do final da fila sem removê-lo.
int traseira(Fila* fila) {
if(fila != NULL){
if(estaVazia(fila))return -1;
return fila->traseira;
}
}
