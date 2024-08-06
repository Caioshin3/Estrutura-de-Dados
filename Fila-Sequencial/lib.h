// Declaração do tipo Fila
typedef struct Fila Fila;

// Cria uma nova fila com a capacidade especificada
Fila* criarFila(int capacidade);

// Verifica se a fila está cheia
int estaCheia(Fila* fila);

// Verifica se a fila está vazia
int estaVazia(Fila* fila);

// Adiciona um item à fila
void enfileirar(Fila* fila, int item);

// Remove um item da fila
int desenfileirar(Fila* fila);

// Retorna o item da frente da fila sem removê-lo
int frente(Fila* fila);

// Retorna o item do final da fila sem removê-lo
int traseira(Fila* fila);
