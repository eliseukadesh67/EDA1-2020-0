#include <stdlib.h>
#if tipo == 0
#define item char
#elif tipo == 1
#define item int
#elif tipo == 2
#define item float
#elif tipo == 3
#define item double
#elif tipo == 4
#define item long int
#elif tipo == 5
#define item long long int
#endif

typedef struct pilha
{
    int topo;
    item *dados;
    int N;

} pilha;

void inicializa(pilha *p)
{

    p->N = 10;
    p->dados = malloc(p->N * sizeof(item));
    if (p->dados == NULL)
    {
        exit(1);
    }

    p->topo = 0;
}
void empilha(pilha *p, item x)
{

    if (p->topo == p->N)
    {

        p->dados = realloc(p->dados, 2 * p->N * sizeof(item));

        // Dobrando a capacidade da pilha para evitar chamadas da função realloc().

        if (p->dados == NULL)
        {
            exit(1);
        }

        p->N *= 2;
    }

    p->dados[p->topo] = x; // Inserindo o elemento;
    p->topo++;             // Incrementando o topo
}
void desempilha(pilha *p)
{
    p->topo--;
}
item top(pilha *p)
{
    return p->dados[p->topo - 1];
}
void destroi(pilha *p)
{
    free(p->dados);
}