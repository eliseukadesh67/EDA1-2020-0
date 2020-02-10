# Aula 2 - Fila

## Implementação com lista encadeada

        typedef struct celula{
            item dado;
            struct celula *prox;  
        }celula;

## Estados da fila:

1. Vazia se o proximo do nó cabeça é o próprio nó cabeça;

## 1. Inicialização

        celula * incialização(){
            celula *novo = malloc(sizeof(celula));
            if(novo!=NULL){
                novo->prox = novo;
            }

            return novo;
        }// Complexidade 0(1);

## 2. Inserção

Para remover em O(1), precisamos trocar o nó cabeça.

        celula *enfileira(celula f, item x){
            celula *nova = malloc(sizeof(celula));
            if(nova!=NULL){
                novo->prox = f->prox;
                f->prox = novo;
                f->dado = x;
            }

            return novo;
        }// Complexidade 0(1);
## 3. Remoção

    int desenfileira(fila *f, item *y){
        if(f->prox == f){
            return 0;
        }
        celula *lixo = f->prox;
        *y = lixo->dado;
        f->prox = lixo->prox;
        free(lixo);
        return 1;
    }

## 4. Destruição

        void destroi(celula *f){
            item num;
            while(desenfileira(f, &num));
            free(f);
        }// Complexidade O(n);