
#include "lib.h"

int main() {
    ListaEncadeada* lista = criarLista();
    
    adicionarInicio(lista, 5);
    adicionarFim(lista, 10);
    adicionarFim(lista, 15);
    
    printf("Elemento no Indice 1: %d\n", obterElemento(lista, 2));
    
    removerInicio(lista);
    
    printf("Elemento no Indice 0 apos remocao: %d\n", obterElemento(lista, 0));
    
    destruirLista(lista);
    
    return 0;
}
