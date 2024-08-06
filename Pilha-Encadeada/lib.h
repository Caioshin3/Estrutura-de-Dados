// Definição do tipo Pilha como ponteiro opaco
typedef struct Pilha Pilha;

// Protótipos das funções para manipulação da pilha
Pilha* criarPilha();
void destruirPilha(Pilha* pilha);
int estaVazia(Pilha* pilha);
void empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);
int verTopo(Pilha* pilha);
void exibirPilha(Pilha* pilha);

