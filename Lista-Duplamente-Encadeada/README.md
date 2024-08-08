
### Relatório de implementação da lista duplamente encadeada no modelo simplesmente encadeado fornecido

## 1. Introdução

Ao contrário das listas simplesmente encadeadas que percorrem apenas para uma direção, as listas duplamente encadeadas
conseguem percorrer para ambas as direções. Cada elemento de uma lista denomidado nó, contém um dado, e dois ponteiros:
um para o próximo nó e outro para o nó anterior.

## 2. Construção da Lista

### 2.1 Definição do ponteiro anterior no nó

Em uma lista simplesmente encadeada, possuímos o que denominamos de estrutura nó, que contém os seguintes atributos:

Dado: Um valor ou informação que o nó armazena.
Ponteiro para o próximo nó: Referência para o nó que vem após o nó atual.

Pode ser visto amostra de código:

```
struct Nodo{
  int dados;
  Nodo* proximo;
};
```

Porém, em uma lista duplamente encadeada, além desses atributos, há um novo:

Ponteiro para o nó anterior: Referência para o nó que vem antes do nó atual.

Pode ser visto amostra de código:

```
struct Nodo{
    int dados;
    Nodo* proximo;
    Nodo* anterior;
};
```

Em casos especiais, os ponteiros não terão referência de um nó, o que será explicado mais adiante.

### 2.2 Implementação da Lista

Após a alteração da estrutura nó para se refletir no duplo encadeamento, o próximo passo que é o mesmo
na lista simplesmente encadeada é a implementação da nova lista. Isso envolve:

### **Criação da Classe da Lista:** 

Se cria uma nova estrutura de nome comumente ListaEncadeada, contendo dois atributos:

**Cabeça**: é o ponteiro que recebea a refêrencia do nó que está no início da sequência, possui tipo nó.
Tamanho: Variável responsável por definir o tamanho da lista, visto que, diferente de uma sequêncial,
onde o espaço de memória é contínuo, os espaços da lista encadeada são dispersos e independentes entre si,
sendo função dessa variável denominar com precisão os espaços presentes, isso é feito com operações de incrementação
e decrementação, vistos adiante.

Amostra de código:

```
struct ListaEncadeada {
    Nodo* cabeca;
    int tamanho;
};
```

Operações da Lista do modelo fornecido:

No modelo de lista simplesmente encadeada proposta, as operações base são:

**Criar lista vazia:** Aloca-se um espaço de mémoria para a classe lista, processo este, explicado de forma mais detalhada no
próximo módulo.

**Adicionar nó no início:** Aloca-se um espaço de memória para um nó e este é adicionado no início da lista encadeada.

**Adicionar nó no fim:** Aloca-se um espaço de memória para um nó e este é adicionado no final da lista encadeada.

**Remover nó do início:** Remove um nó do início da lista, o nó que vem após agora é o início.

**Remvover nó do fim:** Remove um nó do fim da lista, o nó que vem antes agora é o fim.

**Obter elemento por indíce:** Informa-se um determinado índice na lista a se obter um dado ou informação.

**Obter tamanho da lista:** Informa o tamanho atual da lista.

**Verificar se a lista esta vazia:** Verifica se a lista possui uma referência para seu nó de início.

***Para a re-implementação destas operações na lista duplamente encadeada, alterações de lógica foram necessárias, essas,
explicadas no próximo módulo.***

**Operações de abstração de código pós implementação proposta:**

**Mostrar lista:** Mostra os dados percorrendo nó a nó, do início até o final da lista.

**Ler aquivo e adicionar ao início:** Obtém determinado dado em um arquivo, atribui a um nó e insere no início da lista utilizando
a operação adicionar ao início, oferece um output do nó adicionado.

**Ler aquivo e adicionar ao fim:** Obtém determinado dado em um arquivo, atribui a um nó e insere no fim da lista utilizando
a operação adicionar ao fim, oferece um output do nó adicionado.

**Remover nós do início da lista provida do arquivo:** Após formar a lista baseada no conteúdo do arquivo, remove nós do início,
e oferece um output do nó removido.

**Remover nós do fim da lista provida do arquivo:** Após formar a lista baseada no conteúdo do arquivo, remove nós do fim,
oferece um output do nó removido.

**Armazenar lista pós-operações em um arquivo de saída:** Após realizar determinadas operações na lista, armazena os elementos da
lista em uma arquivo de saída, linha por linha.

***Após a visão geral da implementação, o próximo módulo detalhará as modificações exatas para a re-implementação da simples encadeada,
para a duplamente encadeada. As amostras de códigos farão parte da estrutura modular seguinte.***

## 3. Estratégias Utilizadas na re-implemtação para a duplamente encadeada

Este módulo descreverá especificamente função a função implementada, explicando detalhadamente a lógica por trás de cada linha,
contará também, com amostras de código na estrutura modular e também nas demonstrações e comparações.

### 3.1 Modificações nas funções base:

*Lógica das funções da lista encadeada para a duplamente encadeada:*

### Função criarLista():
A função **criarLista** é uma funcão do tipo ponteiro de tipo, nesse caso, tipo ListaEncadeada:
```ListaEncadeada* criarLista*```. Na primeira operação dentro da função, é se criado um ponteiro de tipo ListaEncadeada que recebe o
o endereço de memória da instância alocada dinamicamente da estrutura ListaEncadeada: ```ListaEncadeada * lista = 
(ListaEncadeada*) malloc(sizeof(ListaEncadeada))```. A seguir, verifica-se com o condicional se o ponteiro lista possui realmente
o endereço dessa memória alocada, e, caso possua, seta os atributos cabeca para NULL, pois nenhum nó foi adicionado, e tamanho para
0, exatamente pelo mesmo motivo. Se o espaço foi alocado agora, presume-se que não há nós:

```
if(lista != NULL){
 lista->cabeca = NULL;
 lista->tamanho = 0;
}
```

Esta primeira atribuição ao ponteiro cabeça é importante pois, na função explicada posteriormente, o endereço inicial de cabeça será
repassado ao ponteiro próximo.
Ao final da função, retorna o endereço dessa nova lista, que será atribuido pelo novo ponteiro na main: ```return lista;```

### Função adicionarInicio():
 A função **adicionarInicio** é uma funçao do tipo void, que recebe os parâmetros, lista que é um ponteiro do
tipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada, e valor 
que é um inteiro que recebe dados para o nó:
```void adicionarInicio(ListaEncadeada* lista, int valor)```. Na primeira operação dentro da
função, é se criado um ponteiro de tipo Nodo que recebe o endereço de memória da instância alocada dinamicamente da 
estrutura Nodo, criando-se efetivamente um nó, segundo a convenção: ```Nodo* no = (Nodo*) malloc (sizeof(Nodo))```.
Por conseguinte, verifica-se com o condicional se o ponteiro no possui realmente endereço dessa memória alocada, e, caso 
possua, seta valor para o atributo dados do nó, seta o endereço do ponteiro próximo para cabeca, que, após a criação da lista é
vazio, fazendo efetivimante o ponteiro apontar para vazio no caso de ser o primeiro nó. Eis aqui o diferencial da lista duplamente 
encadeada, o ponteiro anterior deve ser também atribuido vazio, pois não há nenhum nó antes também, isto caso de seja o primeiro nó na 
lista:

```
if(no != NULL){
 no->dados = valor;
 no->proximo = lista->cabeca;
 no->anterior = NULL;
```

O que segue no código, é uma verificação condicional da condicional que verifica se o ponteiro cabeca é diferente de vazio,
verificando necessariamente, se existe um nó presente na lista, ou seja, se aquela lista não está vazia. Caso a lista realmente não
seja vazia, o ponteiro anterior da cabeca atual recebe o endereço desse novo nó:

```if(lista->cabeca != NULL){
 lista->cabeca->anterior = no;
}
```

Isto é importante e será explicado agora.
Se a lista for vazia, o ponteiro anterior e ponteiro próximo permanecem vazios, pois está adicionado o primeiro elemento na lista, 
podendo ser representado:

```NULL <- ( H 1 ) -> NULL```

Se a lista não estiver vazia, o ponteiro anterior deve ser ser atualizado recebendo o endereço desse novo nó pois, nas linhas
seguintes da função, o ponteiro cabeca irá receber necessariamente o endereço do novo nó, tornando-se o novo início da lista:
```lista->cabeca = no```. Logo, o ex início da lista não pode continuar com o ponteiro vazio como atríbuido no caso base da lista vazia,
pois, não será possível percorrer a lista inversamente, pode ser visto na representação:

Caso base:

```NULL <- ( H 1 ) -> NULL```

Lista não está vazia:

```NULL < - ( 1 ) -> NULL <- ( H 2 ) -> NULL```

O ponteiro anterior do início atual aponta para o novo nó, até aquele ponto, ainda é o início:
 
```NULL <- ( 1 ) <-> ( H 2 ) -> NULL```

**O ponteiro próximo do novo nó onde o ponteiro do início não é vazio, recebe seu endereço, tendo seu próximo como o início atual da
lista.**

O ponteiro que indica o início é atualizado para o novo nó:

```NULL <- ( H 1 ) <-> ( 2 ) -> NULL```

**O ex início agora aponta para o início, logicamente.**

No final da função, nos dois casos, a variável tamanho é incrementada: ```lista->tamanho++```.

***OBS: As representações são em sequência por intuitividade, na memória, os espaços alocados podem não estar dispersos de maneira 
uniforme, necessariamente.***

### Função adicionarFim(): 
A função **adicionarFim** é uma funçao do tipo void, que recebe os parâmetros, lista que é um ponteiro do
tipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada, e valor 
que é um inteiro que recebe dados para o nó: ```void adicionarInicio(ListaEncadeada* lista, int valor)```. Na primeira operação dentro da
função, é se criado um ponteiro de tipo Nodo que recebe o endereço de memória da instância alocada dinamicamente da 
estrutura Nodo, criando-se efetivamente um nó, segundo a convenção: ```Nodo* no = (Nodo*) malloc (sizeof(Nodo))```. Ao que se segue, 
verifica-se com o condicional se o ponteiro no possui realmente endereço dessa memória alocada, e, caso possua seta valor para
o atributo dados do nó, seta o endereço do ponteiro próximo para vazio, que é necessário entender que, o que vem após o final,
é o vazio, na convenção. Também pode-se entender como o próximo não tem um nó seguinte a apontar. O diferencial ponteiro anterior 
também não há um nó antes a apontar considerando caso base da lista estar vazia:

```
 no->dados = valor;
 no->proximo = NULL;
 no->anterior = NULL;
 ```

O que vem a seguir no código, é uma verificação condicional da condicional que verifica se o ponteiro cabeca é vazio, verificando 
necessariamente, se não existe um nó presente na lista, ou seja, se aquela lista está vazia. Caso a lista realmente seja vazia, 
o ponteiro que aponta para a cabeca recebe o endereço desse novo nó:

```
if(lista->cabeca == NULL){
 lista->cabeca = no;
}
```

Necessariamente, considerando a adição ao final em uma lista que está vazia. Se a lista não está vazia, este verificador é
desconsiderado, e repassa ao condicional senão, que chama sempre seus argumentos caso a lista tiver pelo menos um elemento até
a chamada da função:

```
if(lista->cabeca == NULL){
 lista->cabeca = no;
}
else{
```

O primeiro argumento do se não, define um nó auxiliar pois, em uma inserção no fim, diferente do início em que temos o endereço exato
fornecido pelo descritor cabeça na estrutura ListaEncadeada, não há no modelo fornecido um descritor próprio para o final da lista,
tendo que utilizar lógica para se obtê-lo, é necessário percorrer até o final da lista e encontrar o elemento atualmente presente lá.
A questão é, porque não usar o descritor para percorrer a lista?, bem, a resposta é simples, o descritor cabeça guarda o endereço do
primeiro nó da lista, se utilizarmos o mesmo para percorrer, perderemos a referência do início da lista, fator esse crucial utilizado
nas funções de operações em lista, vistos acima, também observado na seguinte apresentação: 

Consire uma lista com dois elementos:

```NULL <- ( H 2 ) <-> ( 3 ) -> NULL```

Percorremos utilizando o descritor cabeça até o fim:

```NULL <- ( 2 ) <-> ( H 3 ) -> NULL```

Tentativa de inserção no início, ponteiro próximo do novo nó recebe o endereço do início da lista:

    NULL <- ( 2 ) <-> ( H 3 ) -> NULL 
                         ^
                         |
               NULL <- ( 1 )      

O ponteiro que indica a cabeça da lista, recebe o endereço do novo nó:

    NULL <- ( 2 ) <-> ( 3 ) -> NULL
                        ^
                        |
             NULL <- ( H 1 )

Ponteiro próximo do elemento de dado um e início da lista aponta para três, três tem seu próximo apontando para vazio, e, por mais que
ainda se tenha a referência de dois salva no ponteiro anterior do elemento de dado três, a ideia de duplo encadeamento é perdida,
não é mais possível acessar dois com o ponteiro próximo de um nó, resultando, na perda também da ideia de sequênciação na conveção.
Como citado, só possível salvar referência de dois por causa do comportamento duplamente encadeado de percorrer em duas direções,
porém, há um exemplo de simplesmente encadeada:

Consire uma lista simplesmente encadeada com dois elementos:

```NULL <- ( H 2 ) -> ( 3 ) -> NULL```

Percorremos utilizando o descritor cabeça até o fim:

```NULL <- ( 2 ) -> ( H 3 ) -> NULL```

Tentativa de inserção no início, ponteiro próximo do novo nó recebe o endereço do início da lista:

    NULL <- ( 2 ) -> ( H 3 ) -> NULL
                        ^
                  ( 1 ) |

O ponteiro que indica a cabeça da lista, recebe o endereço do novo nó:

    NULL <- ( 2 ) -> ( 3 ) -> NULL
                       ^
               ( H 1 ) |

Por causa da característica do simples encadeamento de única direção percorrida, o início do elemento de dado um aponta para três, e
três aponta para vazio, fazendo necessariamente, que o endereço de dois se perda na memória, os dados contidos nesse nó se tornam
inacessíveis. Após tais considerações, prosseguiremos.

Após descobrirmos o motivo de se criar uma variável auxiliar ao invés do uso do descritor, a mesma recebe o endereço do descritor que
é o início da lista, como trata-se de uma ponteiro de ponteiro, com ambos possuindo tipo Nodo, o ponteiro cabeça não terá seu endereço
salvo alterado: ```aux = lista->cabeca;```

Representação: 

```aux -> cabeça -> nó do início```

Representação com atríbuições, caso o nó do início tenha o dado um:

```aux -> cabeça -> 1```

Tanto nó quanto cabeça tem o endereço de um, pois ao apontar para cabeça, está necessariamente apontando um e nada se altera 
o descritor:

```cabeça -> 1```
```aux -> 1```

Representação caso percorra cabeça ao invés de aux:

```cabeça -> 1```

**O início da lista é 1.**

Cabeça recebe o endereço do próximo elemento, digamos que dois:

```cabeça -> próximo -> 2```

Resultado:

```cabeça -> 2```

**O elemento 1 é perdido na memória.**

Após sabermos qual o primeiro elemento da lista, utilizamos a estrutura de repetição enquanto, possuindo a condição de, enquanto
o ponteiro próximo de auxiliar for diferente de vazio:

```while(aux->proximo != NULL){```

Em uma lista simplesmente encadeada e duplamente encadeada, o último elemento da lista sempre apontará para vazio:

 ```NULL <- ( H 1 ) -> ( 2 ) -> NULL```
 
 ```NULL <- ( H 1 ) <-> ( 2 ) -> NULL```

Dois é o último elemento da lista pois, possui seu ponteiro próximo apontando para vazio.

Os argumentos do enquanto, realizam uma nova atribuição a variável auxiliar para acessar o endereço do novo elemento, enquanto o nó
acessado não possuir a referência vazia. A seguinte representação explica:

Considere uma lista de elementos de 1 a 3, em sequência:

```NULL <- ( H 1 ) <-> ( 2 ) <-> ( 3 ) -> NULL```

Auxiliar tem a referência apontada por cabeça, que é:

```aux -> cabeça -> 1```

```cabeça -> 1```
```aux -> 1```

**aux e cabeça tem a referência de um.**

Verifica-se se o ponteiro próximo de um é vazio:

```próximo -> 2```

**O ponteiro próximo não é vazio, contém o endereço de dois, então aux recebe o endereço desse nó:**

```aux -> próximo -> 2```

```uax -> 2```

aux agora tem a referência de dois, cabeça ainda tem a referência de um:

```cabeça -> 1```
```aux -> 2```

Verifica-se se o ponteiro próximo de dois é vazio:

```aux -> próximo -> 3```

O ponteiro próximo não é vazio, contém o endereço de três, então aux recebe o endereço desse nó:

```aux -> próximo -> 3```

```uax -> 3```

aux agora tem a referência de três, cabeça ainda tem a referência de um:

```cabeça -> 1```
```aux -> 3```

***Como visto, o início da lista está salvo, não sendo necessário mais repetir tal sentença.***

Verifica-se se o ponteiro próximo de três é vazio:

```aux -> próximo -> NULL```

O ponteiro próximo é vazio, três é o final da lista, aux guarda esse endereço para uso nas operações a seguir e o loop é
quebrado.

O que vem a seguir na função, é a atribuição do endereço do novo nó ao ponteiro próximo de aux, que tem o endereço do nó atualmente,
```final da lista: aux->proximo = no.``` Logicamente, como o endereço do ponteiro do nó final da lista é atualizado para o novo nó final,
o ex nó final agora é o penúltimo, pois não aponta mais para vazio. No caso base, o ponteiro anterior recebeu um endereço vazio, como
possuia pelo menos um item na lista, o ponteiro anterior do novo nó deve necessariamente apontar para o endereço contido em aux, pois
esse novo nó tem seu ponteiro próximo apontado para vazio, ditando que é o novo nó final, como a estrutura proposta é uma lista
duplamente encadeada, deve ser possível percorrer do início ao fim, e do fim ao início: ```no->anterior = aux.```

Representação de como ocorre esse processo:

Caso base do novo nó:

```NULL <- ( 4 ) -> NULL```

Como no exemplo fornecido foi se percorrido de um até três, quatro será o nó do final a ser implementado, para se ter a ideia 
de sequência númerica.

[NULL <-> ( H 1 ) <-> ( 2 ) <-> ( A 3 ) -> NULL <- ( 4 ) -> NULL]()

Considere H o início da lista e A o ponteiro auxiliar que percorreu até o final da lista, A possui o final atual da lista.

O ponteiro aux que recebe o endereço de três, atribuí ao nó três que seu ponteiro próximo recebe o endereço novo nó, ou seja,
ponteiro próximo de três agora aponta para quatro:
 
[NULL <-> ( H 1 ) <-> ( 2 ) <-> ( A 3 ) <-> ( 4 ) -> NULL]()

A agora não possui mais o endereço do final da lista pois, o ponteiro próximo de três agora aponta para quatro, como o próximo 
de três não é vazio, três não é mais o final da lista, A aponta o penúltimo item da lista. Como quatro agora é o elemento que 
aponta para vazio, pois no caso base recebeu um ponteiro próximo e este não foi alterado na função, quatro agora é o final da lista.
Dada a característica de duplo encadeadamente, cada elemento deve ter seus ponteiros apontando para o seu elemento antecessor e 
sucessor na lista. Como A possui referência do penúltimo nó da lista, o ponteiro anterior de quatro deve apontar para o endereço
de A, ou seja, três. O elemento quatro foi adicionado com sucesso no final da lista, No final da função, nos dois casos, 
a variável tamanho é incrementada: ```lista->tamanho++```.

**Considerações:**

Caso não fosse feito as atribuições gerais:

Consire uma lista duplamente encadeada com dois elementos:

```NULL <- ( H 1 ) <-> ( 2 ) -> NULL```

Percorremos utilizando o nó auxiliar até o fim:

```NULL <- ( H 1 ) <-> ( A 2 ) -> NULL```

Tentativa de inserção no final, nenhuma atribuição é feita, caso base é mantido no novo nó:

[NULL <- ( H 1 ) -> ( A 2 ) -> NULL <- ( 3 ) -> NULL]()

Nada foi alterado na lista, o novo nó permanece inacessível.

Caso não fosse feito a atribuições ao ponteiro anterior:

Consire uma lista duplamente encadeada com dois elementos:

```NULL <- ( H 1 ) -> ( 2 ) -> NULL```

Percorremos utilizando o nó auxiliar até o fim:

```NULL <- ( H 1 ) -> ( A 2 ) -> NULL```

Tentativa de inserção no final, aux que tem o endereço dois recebe a referência do novo nó quatro no ponteiro próximo de três,
ou seja, ponteiro próximo de dois aponta para três:

    NULL <- ( H 1 ) -> ( A 2 ) -> ( 3 ) -> NULL
                                    |
                               NULL <

Como o ponteiro anterior do novo nó não é alterado desde o caso base, continua sendo vazio, o que implica que, o ponteiro anterior
ao novo final da lista é vazio, o que é incorreto. A lista só poderá percorrer em uma direção, dado que, caso tente percorrer
inversamente, após se obter o final da lista, o ponteiro anterior de três indicará que seu anterior é vazio, ou seja, que não há
um elemento anterior a este, o que é incorreto, metódos de percorrer serão explicados posteriormente.

***OBS: As representações são em sequência por intuitividade, na memória, os espaços alocados podem não estar dispersos de maneira 
uniforme, necessariamente.***

### Função removerInício():
A função **removerInício** é uma função do tipo void, que recebe os parâmetros, lista que é um ponteiro do
tipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada: 
```void adicionarInício(ListaEncadeada* lista)```. Ao que se segue, verifica-se com o condicional se o ponteiro cabeça possui o
endereço vazio, e, caso não possua, adentra os argumentos:

```if(lista->cabeca != NULL){```

O que vem primeiro é a declaração do ponteiro auxiliar de tipo Nodo para salvar o endereço do nó que é atualmente a cabeça:
```Nodo* aux = lista->cabeca```. O motivo agora é diferente do proposto anteriormente, não, não será percorrido até o fim utilizando aux,
mas, utilizaremos um príncipio citado anteriormente, que é a capacidade de obter o endereço que a cabeça atualmente está apontando,
e o salvar sem sofrer alterações, aux salva independentemente endereço apontado pelo ponteiro cabeça, o que será de utilidade aos
passos seguintes: ```Nodo* aux = lista->cabeca```. Após este passo, o descritor cabeça que possui o endereço do nó inicial atual, recebe o
endereço do ponteiro próximo, que aponta necessariamente para o nó que vem a seguir do nó que era o ínicio da lista, fazendo
necessariamente, o descritor atualizar seu endereço e indicar este como o novo início da lista. Eis aí a função do ponteiro aux,
ao percorrer-se adiante para o próximo endereço após o início atual, o descritor perde a referência daquele nó que era o início da 
lista, e, por se tratar de uma instância do tipo Nodo que foi alocada na memória dinamicamente, aquele espaço continuará alocado
até que se libere explicitamente com uma função explicada posteriormente. O espaço continua alocado mesmo após o final da execução da
função, e com a alteração do endereço do descritor cabeça sem a declaração de um ponteiro auxiliar que salve esse endereço, esse nó e
seus dados continuam a alocados na memória, e agora inacessíveis normalmente. Dependendo do tipo de dado, considerando a sensibilidade
dos mesmos, é uma prática errônea possuir dados na memória mesmo sinalizando sua remoção. Então se há definida a função de aux, salvar
esse endereço para que seja possível acessar por meios comuns, e o descritor consiga trocar o endereço pelo próximo apontado,
atribuindo necessariamente, um novo início a lista: ```lista->cabeca = lista->cabeca->proximo```. Há apenas mais uma correção necessária,
como o descritor cabeça recebeu o endereço do próximo nó após o atual início da lista, este mesmo nó possui o endereço do nó que
era o início da lista guardado no ponteiro anterior, visto a característica duplamente encadeada da implementação. Como bem definido,
o que vem antes do início da lista é o valor vazio sempre atribuído nos casos bases, então como descritor cabeça agora aponta para
o próximo nó, esse nó é o início da lista, então, seu ponteiro não deve mais apontar ao nó anterior, pois ele será excluído, devendo
então, se atribuir o endereço vazio ao seu ponteiro anterior: ```lista->cabeca->anterior = NULL```. Após os passos conseguintes, lista
estará modificada com sucesso, restando liberar o espaço de memória do tipo Nodo, como aux guardou o endereço desse espaço até o 
final da operação, é possível liberá-lo utilizando a função seguinte: ```free(aux)```. Não se deve inferir erroneamente que a função
free está desalocando o espaço de memória do ponteiro aux, não é o que está acontencendo. Na verdade aux será liberado assim que a 
função terminar de ser executada. O que realmente acontece é que, o comando free capta que aux é um ponteiro e há um endereço
salvo no mesmo, free então irá liberar esse espaço de memória apontado pelo ponteiro auxiliar, necessariamente, desalocando o espaço
de memória dedicado a aquele nó, necessariamente o destruindo. No final da função, após as operações, a variável tamanho diferente
de quando foi nas funções de inserção, deve ser decrementada, pois a lista agora diminuiu de tamanho: ```lista->tamanho--```.

Representação de como ocorre esse processo linha a linha:

Considere o exemplo de lista duplamente encadeada de três elementos: 

```NULL <- ( H 1 ) <-> ( 2 ) <-> ( 3 ) -> NULL```

**Considere H o início da lista e A o ponteiro auxiliar.**

O ponteiro aux recebe o endereço do descritor cabeça da lista, ou seja, um:
 
```NULL <- ( H 1 A ) <-> ( 2 ) <-> ( 3 ) -> NULL```

O descritor cabeça recebe o endereço do próximo elemento após este, ou seja, dois:

```NULL <- ( A 1 ) <-> ( H 2 ) <-> ( 3 ) -> NULL```

O descritor cabeça recebe o endereço vazio para seu ponteiro anterior, a referência a um é agora apenas salva em aux, ou seja,
dois não aponta mas para um como seu antecessor, pois agora o antecessor é vazio:

```NULL <- ( A 1 ) -> NULL <- ( H 2 ) <-> ( 3 ) -> NULL```

Após as operações, aux indica o endereço de um a ser desalocado por free, necessariamente o removendo e destruindo:

```NULL <- ( H 2 ) <-> ( 3 ) -> NULL```

A remoção do nó ocorreu com sucesso, sem restar nenhuma referência ao espaço de memória na lista. Apenas o nó auxiliar possue, e
será desalocado ao final da chamada de função.

**Considerações:**

Caso não fosse feito as atribuições gerais:

Consire uma lista duplamente encadeada com dois elementos:

```NULL <- ( H 2 ) <-> ( 1 ) -> NULL```

Nó auxiliar recebe o endereço de cabeça, que é o início da lista, ou seja, dois:

```NULL <- ( H 2 A ) <-> ( 1 ) -> NULL```

Tentativa de remoção ao início, como não há atribuições, o comando free libera a memória apontada por aux, dois é excluido da lista:

```NULL <- ( H ? A ) <-> ( 1 ) -> NULL```

Como o descritor cabeça aponta para um endereço de memória alocado que não existe mais na memória, o ponteiro salva algo que pode ter
sido reescrito nesse espaço desalocado, tornando o comportamente incerto e o conteúdo desse endereço imprevísivel. Como a estrutura
nó não existe mais nesse endereço, os ponteiros desse nó não existem também, impossibilitando percorrer essa lista, inferindo 
logicamente, que todos os elementos dessa lista foram perdidos na memória e se encontram alocados, mas inacessíveis. 
**A lista foi quebrada.**

Caso não fosse feito a atribuição ao ponteiro anterior:

Consire uma lista duplamente encadeada com dois elementos:

```NULL <- ( H 2 ) <-> ( 1 ) -> NULL```

Nó auxiliar recebe o endereço de cabeça, que é o início da lista, ou seja, dois:

```NULL <- ( H 2 A ) <-> ( 1 ) -> NULL```

Tentativa de remoção ao início, descritor cabeça recebe o endereço do próximo nó após o atual, tornando este o novo início da lista.
um é o novo início da lista. aux salvou o endereço do nó alocado na memória que era o ex início, 
assim conseguindo liberá-lo da memória:

```( A ? ) <- ( H 1 ) -> NULL```

A lista pode parecer funcional, porém, como o ponteiro anterior do nó que agora é o início da lista, apontava para o ex início, e este
foi desalocado e destruído, ou seja, um apontava para dois quando dois era o início da lista, como o descritor fez um ser o novo 
início da lista, e dois foi excluído, se o ponteiro anterior de um ainda aponta para o endereço desalocado de dois, esse ponteiro
agora possui o endereço de um espaço com um conteúdo imprevísivel, o que provocará erros se percorrer inversamente a lista.

### Função removerFim(): 
A função removerFim é uma função do tipo void, que recebe os parâmetros, lista que é um ponteiro do
tipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada: 
```void adicionarInício(ListaEncadeada* lista)```. Ao que se segue, verifica-se com o condicional se o ponteiro cabeça possui o
endereço vazio, e, caso não possua, adentra os argumentos:

```if(lista->cabeca != NULL){```

Ademais, se é declarado um ponteiro auxiliar que recebe o endereço que o descritor cabeça atualmente aponta, como a explicação dessa
ação foi descrita detalhadamente anteriormente, prosseguiremos: ```Nodo* aux = lista->cabeca```. Após tal ação, é necessário encontrar o 
fim atual dessa lista, fazemos isso utilizando a estrutura de repetição enquanto, com a condição de checagem. Se o ponteiro próximo
não de valor vazio, adentra-se os argumentos do enquanto, que, trata-se de atribuir a aux o endereço do próximo nó até que se atinja

a condição e o loop seja quebrado, tal procedimento também foi explicado detalhadamente anteriormente:

```
while(aux->proximo != NULL){
  aux = aux->proximo; 
}
```

Se obtendo o endereço do nó final da lista salvo em aux, cria-se um segundo ponteiro auxiliar declarado como ```aux2```, como foi explicado
anteriormente a uso dos mesmos, devo explicar o tipo de atribuição de endereço específico que aux2 receberá. aux2 recebe o endereço
do nó anterior a aux que é o final atual, ou seja, aux2 recebe o endereço do penúltimo nó da lista: ```Nodo* aux2 = aux->anterior```.
Recebendo tal endereço, o ponteiro próximo de aux2 recebe o endereço vazio que dita que, agora o antes penúltimo nó da lista é o 
último, pois possui seu ponteiro próximo indicando que não há mais nós após este, ou seja, tem endereço vazio: ```aux2->proximo = NULL```. 
A referência ao endereço do nó que será apagado é necessariamente salva apenas no ponteiro auxiliar aux, especificando o endereço 
do espaço de memória do nó a ser desalocado, logo destruído, utilizando a função free: ```free(aux)```. No final da função, após as 
operações, a variável tamanho diferente de quando foi nas funções de inserção, deve ser decrementada, pois a lista agora diminuiu 
de tamanho: ```lista->tamanho--```.

Representação de como ocorre esse processo linha a linha:

Considere o exemplo de lista duplamente encadeada de três elementos: 

```NULL <- ( H 1 ) <-> ( 2 ) <-> ( 3 ) -> NULL```

**Considere H o início da lista e A o ponteiro auxiliar.**

O ponteiro aux recebe o endereço do descritor cabeça da lista, ou seja, um:
 
```NULL <- ( H 1 A ) <-> ( 2 ) <-> ( 3 ) -> NULL```

aux percorre a lista até encontrar o elemento que aponta para vazio, que é onde está o final da lista. aux então recebe o endereço
de três:

```NULL <- ( H 1 ) <-> ( 2 ) <-> ( A 3 ) -> NULL```

O ponteiro auxiliar aux2 é declarado, recebendo o endereço do elemento anterior ao fim da lista, ou seja, o que vem antes do três
é o dois:

```NULL <- ( H 1 ) <-> ( B 2 ) <-> ( A 3 ) -> NULL```

**Considere B o segundo ponteiro auxiliar.**

aux2 atribui o ponteiro do penúltimo nó da lista o valor vazio, ditando necessariamente que este agora é o final da lista, e não
possui mais a referência do ex útimo final da lista, salva apenas em aux:

    NULL <- ( H 1 ) <-> ( B 2 ) -> NULL
                           ^ 
                           |
                        ( A 3 ) -> NULL

Após as operações, aux indica o endereço de três a ser desalocado por free, necessariamente o removendo e destruindo:
 
```NULL <- ( H 1 ) <-> ( B 2 ) -> NULL```

A remoção do nó no fim ocorreu com sucesso, sem restar nenhuma referência ao espaço de memória na lista. Apenas o nó auxiliar possue, 
e será desalocado ao final da chamada de função.


**Considerações:**

Caso não fosse feito a atribuição ao ponteiro próximo:

Consire uma lista duplamente encadeada com três elementos:

```NULL <- ( H 1 ) <-> ( 2 ) <-> ( 3 ) -> NULL```

Nó auxiliar recebe o endereço de cabeça, que é o início da lista, ou seja, um:

```NULL <- ( H 1 A ) <-> ( 2 ) <-> ( 3 ) -> NULL```

Percorre-se com aux até o fim da lista, ou seja, aux recebe o endereço de três, que é o nó que aponta para vazio:

```NULL <- ( H 1 ) <-> ( 2 ) <-> ( A 3 ) -> NULL```

Como não há atribuições, o passo é prosseguido até a liberação de aux com o free, desalocando o elemento três:
 
```NULL <- ( H 1 ) <-> ( 2 ) -> ( A ? ) NULL```

Como o ponteiro próximo de dois ainda possui o endereço do espaço de memória que era alocado para três, quando se tentar percorrer
até o final da lista com o enquanto e sua condição, gerará uma situação incerta, pois não se sabe o conteúdo atual daquele determinada
espaço de memória alocado, gerando incerteza na quebra do loop, podendo gerar n iterações. Nesse cenário, a lista não possui um fim
claro, logo, **está quebrada**.

### Função obterElemento():
A função **obterElemento** é uma funçao do tipo int, que recebe os parâmetros, lista que é um ponteiro do
tipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada, e índice 
que é um inteiro que recebe determinada posição a ser buscada na lista: ```void adicionarInicio(ListaEncadeada* lista, int indice)```.
Ao que se segue na função, primeiro verifica-se com uma condicional se o índice é menor que zero, pois a contagem posteriormente 
considera a lógica de vetores, que começam em zero. Caso o índice for maior ou igual que o tamanho atual da lista, tem-se checagem
semelhante. Caso índice ir em acordo com uma das condições, adentrará os argumentos, como tendo um argumento único com output de
erro: 

```
if(indice<0 || indice >= lista->tamanho)
    	printf("Erro");
```

Caso não, o índice é considerado válido, e prosseguirá para os argumentos de senão:

```
else{
```

É se então declarado um ponteiro auxiliar que recebe o endereço do descritor cabeça, como explicado anteriormente o motivo,
prosseguiremos: ```Nodo * aux = lista->cabeca```. A forma de percorrer aqui é diferente, ao invés de um enquanto checando o final da lista,
é índice que indica até onde aux deverá percorrer. Os argumentos estão em uma estrutura de repetição para, ditando que o contador 
começa em zero e deve percorrer até o número menor índice, ou seja, utilizando a lógica dos vetores que iniciam em zero:

```for(int i = 0; i< indice; i++)```

Enquanto determinada posição não for atingida, aux irá receber o endereço do próximo elemento, isso támbem foi explicado
anteriormente: ```aux = aux->proximo```. Quando determinado elemento da posição indicada for encontrado, retorna-se os dados
desse elemento: ```return aux->dados```.

Representação:

**Caso o índice = 5**

A iteração irá iniciar de zero até quatro, pois:

**4 < 5**

Necessariamente, percorrendo 5 posições e retornando a quinta posição do vetor.

### Função estaVazia(): 
A função estaVazia é uma função do tipo int, que recebe o parâmetro lista, que é um ponteiro do tipo estrutura ListaEncadeada, e recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada: 
```void estaVazia(ListaEncadeada* lista)```. A função possui como único argumento um retorno checando se descritor cabeça da lista
está vazia: ```return lista->cabeca == NULL```. Visto o comportamento booleano das condicionais, retornará verdade, ou seja, um, caso a lista esteja vazia e falso, ou seja, zero, caso não esteja.

### Função obterTamanho():
A função obterTamanho é uma função do tipo int, que recebe o parâmetro lista, que é um ponteiro do tipo estrutura ListaEncadeada, e recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada: 
```void estaVazia(ListaEncadeada* lista)```. Acessa o ponteiro lista e retorna o tamanho da lista contido na instância lista:
```return lista->tamanho```.

### 3.2 Funções extras adicionadas:

Este sub módulo descreverá função a função extra implementada, explicando a visão geral da lógica aplicada em cada uma por não ser o 
foco do que foi requerido, contará também com amostras de código na estrutura modular e também algumas demonstrações e comparações.

**Funções extras:**

### Função arquivoInicio():
A função arquivoInicio é uma funçao do tipo void, que recebe os parâmetros, lista que é um ponteiro do tipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada, e um
ponteiro do tipo FILE, que recebe o endereço de uma estrutura arquivo: ```arquivoInicio(ListaEncadeada * lista, FILE * file)```. Aos passos que seguem adianta, é se declarado um buffer chamado temp: ```char temp [100]```. Tal buffer será utilizado nas operações de captura de dados do arquivo. É se então declarado um para, como no que foi proposto, para cinco operações, então, o para fará cinco iterações: 

```for(int i = 0; i<5; i++){```

Adiante, é se utilizado a função do sistema fgets, para capturar os dados da linha do arquivo para uso posterior. Dado o comportamento
do ponteiro file em sempre prosseguir para a próxima linha após uma leitura, o dado será sempre alterado na próxima iteração:
```fgets(temp, sizeof(temp), file)```. Adiante, declara-se uma variável do tipo inteiro de nome valor, esta variável receberá os dados
do buffer com a função sscanf, e logo após, chamará a função que insere no ínicio para enviar o ponteiro lista, e dado será
armazenado no início da lista duplamente encadeda. Após tais operações, há uma verificação para organizar os outputs de feedback,
definindo que o quinto output terá dois espaços com \n, **a operação de cinco inserções ao início, lida do arquivo, 
é realizada com sucesso**:

```
 int valor = 0;
 sscanf(temp, "%d", &valor);
 adicionarInicio(lista,valor);
if(i<4){
  printf("No %d foi adicionado no inicio da lista\n",valor);
}if(i==4){
  printf("No %d foi adicionado no inicio da lista\n\n",valor);
}
```

### Função arquivoFim():
A função arquivoFim é uma funçao do tipo void, que recebe os parâmetros, lista que é um ponteiro dotipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada, e um ponteirodo tipo FILE, que recebe o endereço de uma estrutura arquivo: ```arquivoInicio(ListaEncadeada * lista, FILE * file)```. Aos passos queseguem adianta, é se declarado um buffer chamado temp: ```char temp [100]```. Tal buffer será utilizado nas operações de captura de dados do arquivo. É se então declarado um para, como no que foi proposto, para cinco operações, então, o para fará cinco iterações: 

```for(int i = 0; i<5; i++){```

Adiante, é se utilizado a função do sistema fgets, para capturar os dados da linha do arquivo para uso posterior. Dado o comportamento
do ponteiro file em sempre prosseguir para a próxima linha após uma leitura, o dado será sempre alterado na próxima iteração:
```fgets(temp, sizeof(temp), file)```. Adiante, declara-se uma variável do tipo inteiro de nome valor, esta variável receberá os dados
do buffer com a função sscanf, e logo após, chamará a função que insere no ínicio para enviar o ponteiro lista, e dado será
armazenado no fim da lista duplamente encadeda. Após tais operações, há uma verificação para organizar os outputs de feedback,
definindo que o quinto output terá dois espaços com \n, **a operação de cinco inserções ao fim, lida do arquivo, 
é realizada com sucesso**:

```
 int valor = 0;
 sscanf(temp, "%d", &valor);
 adicionarInicio(lista,valor);
if(i<4){
  printf("No %d foi adicionado no inicio da lista\n",valor);
}if(i==4){
  printf("No %d foi adicionado no inicio da lista\n\n",valor);
}
```

### Função arquivoRemoverInicio():
A função arquivoInicio é uma funçao do tipo void, que recebe o parâmetro, lista que é um ponteiro do tipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada:
```arquivoRemoverInicio(ListaEncadeada * lista)```. Aos passos que seguem adiante, é se então declarado um para, como no que foi 
proposto, para duas operações, então, o para fará duas iterações: 

```for(int i = 0; i<2; i++){```

É se então, fornecido um output meramente visual para mostrar o elemento no início a ser removido da lista, que se segue com 
a chamada da função enviando o endereço do espaço de memória da lista:

```
 printf("No %d foi removido do inicio da lista\n",lista->cabeca->dados);
 removerInicio(lista);
```

**A operação de remoção dupla ao início da lista, é realizada com sucesso.**

### Função arquivoRemoverFim():
A função arquivoInicio é uma funçao do tipo void, que recebe o parâmetro, lista que é um ponteiro do tipo estrutura ListaEncadeada que recebe da main o endereço de um outro ponteiro que tem o endereço de uma lista criada:
```arquivoRemoverInicio(ListaEncadeada * lista)```. Aos passos que seguem adiante, é se então declarado um para, como no que foi 
proposto, para duas operações, então, o para fará duas iterações: 

```for(int i = 0; i<2; i++){```

É se então, declarado um ponteiro auxiliar que recebe o endereço da descritor cabeça, então percorre-se até o fianl atual da lista.
Tal operação tem uso somente visual, fornecendo o dado atualmente no final da lista ao output:

```
 Nodo* aux = lista->cabeca;
while(aux->proximo != NULL){
 aux = aux->proximo;   
}
printf("No %d foi removido do final da lista\n",aux->dados);
```

Após tal operação, envia-se o endereço do espaço de memória da lista:

```
removerFim(lista);
```

**A operação de remoção dupla ao início da lista, é realizada com sucesso.**


### Função mostrarLista():
A função mostrarLista é uma funçao do tipo void, que recebe o parâmetro aux, que é um ponteiro do tipo estrutura Nodo que recebe da main o endereço de um outro ponteiro auxiliar que tem o endereço do descritor cabeça da lista:
```mostrarLista(Nodo * aux)```. Ao que se segue, há o verificador enquanto que, diferente de usado anteriormente, tem como condição
de parada até que aux seja igual a vazio, ou seja, isso quer dizer que aux percorrerá além do último item, pois, a forma como output
está implementado antes de percorrer, faz necessário essa modificação:

```
while (aux != NULL){
printf("%d\n",aux->dados);
aux = aux->proximo;
}
```

**A lista foi mostrada com sucesso.**

**Extra:**

Representação dessa modificação:

Considere uma lista duplamente encadeada de três elementos:

Auxiliar tem a referência apontada por cabeça, que é:

```aux -> cabeça -> 1```

```cabeça -> 1```
```aux -> 1```


**aux e cabeça tem a referência de um.**

iteração:

```output: 1```

```aux -> próximo -> 2```

Verifica-se se o aux é vazio:

```aux -> 2```

**O ponteiro aux não é vazio, contém o endereço dois.**

iteração:

```output: 2```

```aux -> próximo -> 3```

Verifica-se se o aux é vazio:

```aux -> 3```

**O ponteiro aux não é vazio, contém o endereço três.**

iteração:

```output: 3```

```aux -> próximo -> NULL```

**O ponteiro aux é vazio, quebra de loop.**

### Função armazenarListaArquivo():
A função armazenarListaArquivo é uma funçao do tipo void, que recebe os parâmetros, lista que é um ponteiro do tipo Nodo que recebe da main o endereço de um outro ponteiro auxiliar que tem o endereço do descritor cabeça de uma
lista, e um ponteiro do tipo FILE, que recebe o endereço de uma estrutura arquivo: ```arquivoInicio(ListaEncadeada * lista, FILE * file).```
Na primeira linha, se há um enquanto com a verificação anteriomente discutida, para percorrer todos os items da lista até aux
ter valor vazio:

```while(aux != NULL){```

Após, utiliza-se a função fprintf para escrever no arquivo que o ponteiro file indica, os dados atuais do elemento indicado na
iteração atual:

```fprintf(file,"%d\n",aux->dados);```

Após a escritura, o ponteiro aux percorre e recebe o endereço do próximo elemento:

```aux = aux->proximo;```

Ao final das iterações, **a operação de armazenar em um arquivo é feita com sucesso.**

### 3.2 Função main:

Este sub módulo abordará a visão geral da main fornecida:

### Função main:

Cria-se a lista:

```ListaEncadeada * lista = criarLista();```

Lê-se o arquivo de entrada:

```FILE * file = fopen("entrada.txt", "r");```

Cinco inserções no início, cinco inserções no fim:

```
arquivoInicio(lista,file);
arquivoFim(lista,file);
```

Duas remoções no início, duas remoções no fim:

```
arquivoRemoverInicio(lista);
arquivoRemoverFim(lista);
```

Criação do arquivo de saída e declaração do ponteiro auxiliar recebendo o endereço do descritor cabeça:

```
FILE * file2 = fopen("saída.txt","w");
Nodo * aux = lista->cabeca;
```

Escritura de dados nesse arquivo:

```
armazenarListaArquivo(aux,file2);
```

Output auxiliar do resultado comparativo com o arquivo de saída:

```
printf("\n");
mostrarLista(aux);
```

**Explicação encerrada.**

## 4. Dificuldades enfrentadas

O módulo abordará as dificuldades enfrentada na implementação do duplo encadeamento no modelo simplesmente encadeado fornecido:

### 4.1 Instanciação

Foi me necessário depois de certo tempo, compreender que em cada chamada de função, um espaço de memória é alocado,
eu estava vendo como se utiliza-se apenas uma única estrutura nó é declarada para armazenar os valores dos ponteiros, o que não é
correto, na verdade, foi quando percebi que as funções tinham malloc, ou seja, mesmo após o final da função o espaço de memória
continua existindo. Foi aí que entendi que não usamos exatamente aquela estrutura nó declarada, mas sim, que ela é apenas o modelo
base, e operamos com as instâncias.

### 4.2 Lógica do ponteiro anterior

Foi me necessário compreender a lógica do retorno com várias tentivas e representações desenhadas por mim, além de alguns erros
que me exigiram muita revisão de código.

### 4.3 Arquivos

Como bem sabido, arquivos parecem me sempre problemáticos de se operar, ocorrendo diversos erros de leitura e escrita, 
a lógica de buffer foi implementada como solução.

## 5. Conclusão

A proposta de implementação foi concluida com sucesso, e, adquiri conhecimento extenso sobre manipulação de ponteiros e lógica
aplicada. A lista duplamente encadeada é uma estrutura fascinante. O encadeadamente e manipulação de nós é a chave para a 
compreensão de estruturas mais complexas como pilha, fila, árvore e grafo. 











