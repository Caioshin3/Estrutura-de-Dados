#include <stdio.h>
#include "lib.h"

int main() {
    Pilha* pilha = criarPilha();
    if (!pilha) {
        printf("Erro ao criar pilha.\n");
        return 1;
    }

    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);

    exibirPilha(pilha);

    printf("Topo da pilha: %d\n", verTopo(pilha));
    
    printf("Desempilhando: %d\n", desempilhar(pilha));
    printf("Desempilhando: %d\n", desempilhar(pilha));

    exibirPilha(pilha);

    destruirPilha(pilha);

    return 0;
}