#include <stdio.h>
#include "lib.h"

int main() {
    Fila* fila = criarFila(100);
    
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);
    
    printf("%d desenfileirado\n", desenfileirar(fila));
    printf("%d desenfileirado\n", desenfileirar(fila));
    
    printf("Frente da fila: %d\n", frente(fila));
    printf("Traseira da fila: %d\n", traseira(fila));
    
    return 0;
}