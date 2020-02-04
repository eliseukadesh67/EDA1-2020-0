# Aula 1 - Pilha

## O que é?

É uma estrutura de dados que implementa operações de inserção e remoção do tipo LIFO (Last in First Out).

## Implementação

PIlhas podem ser implementadas usando vetores e listas encadeadas.

### 1 - Vetores

Elementos necessários :

- Um vetor para armazenar os elementos;
- Um indicador (podendo ser um inteiro) para a posição que é o topo da pilha.

A pilha pode assuimir dois estados:

1) Pilha vazia, quando o topo for igual a zero;

2) Pilha cheia, quando o topo for N(sendo N o tamanho do vetor que representa a pilha).


### Exemplo de implementação com vetor

        typedef struct pilha{
            int *dados;
            int topo;
            int N;
        }pilha;

As operações que devem ser implementadas são :

- Inicialização;
- Inserção;
- Remoção;
- Destruição.

### 1. Inicialização

    void inicializa(pilha *p){
        
        p->N = 10;
        p->dados = malloc(p->N*sizeof(int));
        if(p->dados==NULL){
            exit(1);
        }

        p->topo = 0;

    }
### 2. Inserção

    void empilha(pilha *p, int x){
        if(p->topo == p->N){
        
            p->dados = realloc(p->dados, 2*N*sizeof  (int));
            
            // Dobrando a capacidade da pilha para evitar chamadas da função realloc().
            
            if(p->dados==NULL){
                exit(1);
            }
            
            p->N *= 2;
        }

        p->dados[p->topo] = x; // Inserindo o elemento;
        p->topo++; // Incrementando o topo
    }

A complexidade da inserção no pior dos casos é O(n), que raramente acontace, apenas nos casos em que o realloc consuma O(n), mas na maioria dos casos este algoritmo é O(1).

### 3. Remoção

        int desempilha(pilha *p){
            p->top--;
            return p->dados[p->top];
        }

A função desempilha tem complexidade O(1).

<strong>OBS 1 : A função desempilha assim implementada so deve ser chamada se a pilha não estiver vazia.</strong>

<strong>OBS 2 : O elemento removido não é desalocado, portanto se o vetor que armazena os dados for muito grande pode haver um desperdício de espaço na memória.</strong>

### 4. Destruição

        void destroi(pilha *p){
            free(p->dados);
        }

## Exemplos de codigos

- [Exemplo de inicialização de uma pilha](./ex1pilha.c)