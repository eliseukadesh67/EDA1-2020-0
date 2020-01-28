# Lista encadeada

## Considerações iniciais.

### Desvantagens de usar um array.
 
 - Inserção e remoção de um elemento;

Para uma sequencia de M operações da inserção e remoção, a complexidade torna-se O(MxN). Isso é ruim quando m e n são muito grandes.

## O que é uma lista encadeada

Lista encadeada é uma estrutura de dados linear, que consite em uma sequencia de ponteiros, sendo que cada um possui um ponteiro que aponta para o proximo elemento, cada elemento chamamos de nó.Esses nós podem não ocupar posições sequenciais na memória, assim sendo cada nó deve saber onde está o próximo elemento.

A lista encadeada é vantajosa quando comparada ao vetor na manipulação(Inserção e a Remoção) dos elementos.

## Nó de uma lista

O nó é uma estrutura que possui um valor e um ponteiro para o próximo nó da lista.

Ex :
    
        #ifndef NODE_H
        #define NODE_H
        #include<stdlib.h>
        #include<stdio.h>


            typedef struct node{
                int val;
                struct node* next;
            }node_t 
        
        #endif

## Inicializando uma lista

Quando inicalizamos uma lista, podemos começar pelo "nó-cabeça", ou "head". Este nó seria o primeiro elemento da lista, quando a lista está vazia este elemento aponta para `NULL`.

Ex :

        #include<stdlib.h>
        #include "node.h"

        int main(){
            node_t *p = malloc(size(node_t));
            free(node_t);
        }

## Exemplos de código

- [Arquivo de implementação de um nó](./node.h)

- [Exemplo de código com lista encadeada.](./linked_list_ex.c)