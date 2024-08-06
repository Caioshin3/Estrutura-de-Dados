#include "lib.h"

int main (){

ListaEncadeada * lista = criarLista();

FILE * file = fopen("entrada.txt", "r");

    arquivoInicio(lista,file);
    arquivoFim(lista,file);
    
    arquivoRemoverInicio(lista);
    arquivoRemoverFim(lista);
    
    fclose(file);
    
FILE * file2 = fopen("saída.txt","w");
Nodo * aux = lista->cabeca;
    
    armazenarListaArquivo(aux,file2);
    
    fclose(file2);
    
    printf("\n");
    mostrarLista(aux);
    
    return 0;
}
