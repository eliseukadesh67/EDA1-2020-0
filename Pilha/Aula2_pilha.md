# Aula 2 - Pilha

## Utilizando lista encadeda

.....

## Exemplos de aplicações de pilha

### Ex 1 :

O sistema operacional utiliza uma pilha para realizar as execuções de programas.

- Ex :

        int F(int a, int b){
            int x = G(a);
            int y = G(b);
        }
        int G(int p){
            .
            .
            .
        }

## Ex 2

Printar uma pilha ao contrario

- Ex:  

        void invStr2(char *str){
            pilha *p;
            incializa(p);
            while(str!= '\0){
                empilha(p, str);
                str++;
            }

            while(p->prox != NULL){
                printf("%c", desempilha(p));
            }

            destroi(p);
        }
