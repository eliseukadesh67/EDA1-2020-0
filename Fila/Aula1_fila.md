# Fila

## O que é?

É uma estrutura em que os dados são inseridos e removidos no esquema FIFO(First in First Out).

## Implementando uma fila

Podemos assim como a pilha implementar nossa estrutura com vetores ou com lista encadeada.

## 1. Utilizando Vetor

Elementos necessários :

- Um vetor para armazenar os elementos;
- Dois indicadores do inicio e final da fila;

Estados :

1. Vazia, quando o indicador do inicio for igual ao indicador do final;

2. Cheia , quando o indicador do final da fila for igual ao tamanho maximo da fila;

Para representar a fila :

        typedef struct fila{
            item *dados;
            int first, last, N;
        }fila;

Implementa-se 4 operações:

1. Inicialização;
2. Inserção;
3. Remoção;
4. Destruição.

### 1. Inicialização

        void incialização(fila *f){
            f->N = 10;
            f->dados = malloc(f->N*sizeof(fila));
            f->fisrt = f->last = 0;
        }// Complexidade 0(1);

### 2. Inserção

        void enfileira(fila *f, item x){
            if(f->last==f->N){
                f->N *= 2;
                f->dados = realloc(f->dados, f->N*sizeof(fila));
                
                if(f->dados==NULL){
                    exit(1);
                }
            }

            f->dado[f->last] = x;
            f->last++;
        }

A complexidade da inserção por conta do malloc() pode ser O(n), mas em geral é O(1);

### 3. Remoção

        int desenfileira(fila *f){
            if(f->first == f->last){
                return 0;
            }
            else{
                f->first++;
                return 1;
            }
        }

### Problemas na remoção:

Quando removemos um elemento, o espaço a esquerda do vetor fica inutilizado.

**Solucão para este problema :**

- Utilizar uma fila circular;

Pode-se implementar desta forma também, para resgatar o valor que foi retirado<strong>(Exemplo maluco do professor)</strong> :

        int desenfileira(fila *f, item *y){
            if(f->first == f->last){
                return 0;
            }
            else{
                *y = f->dados[f->first];
                f->first++;
                return 1;
            }
        }
 
 A complexidade da remoção é 0(1);

        void destroi(fila *f){
            free(f->dados);
        }

## Fila circular

- É como uma fila normal, porem o final da fila pode ser colocado no inicio se for implementada como um vetor.

### Estados da fila circular:

1. Vazia, quando o primeiro for igual ao ultimo.
2. Cheia, quando o primeiro for igual ao ultimo.

Podemos observar uma ambiguidade.

Para resolvermos, redefinimos o conceito de fila cheia de duas maneiras:

1. A fila está cheia quando primeiro = 0, e quando o ultimo = N-1; 

2. A fila está cheia quando o primeiro>0, e o utlimo = primeiro-1;

Ou seja: (ultimo+1)%N = P;

## 1. Inicialização

A incialização é igual a fila implementada com vetores.

## 2. Remoção

        int desenfileira(fila *f){
            if(f->first==f->last){
                return 0;
            }
            f->first++;
            
            f->first = (f->first+1)%f->N;

            return 1;
        }// Complexidade 0(1);

## 3. Inserção