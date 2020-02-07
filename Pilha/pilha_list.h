#include <stdlib.h>
#include <stdio.h>
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

typedef struct Pno
{
    item dado;
    struct Pno *anterior;

} Pno;

Pno *init_stack()
{
    Pno *topo = (Pno *)malloc(sizeof(Pno));
    if (topo == NULL)
    {
        exit(1);
    }
    topo->anterior = NULL;
    return topo;
}
void push(Pno *topo, item x)
{
    Pno *novo = (Pno *)malloc(sizeof(Pno));
    if (novo == NULL)
    {
        exit(1);
    }
    novo->dado = x;
    novo->anterior = topo->anterior;
    topo->anterior = novo;
}
item pop(Pno *topo)
{
    if (topo->anterior == NULL)
    {
        exit(1);
    }

    item top_val = topo->anterior->dado;
    free(topo->anterior);

    return top_val;
}
void free_stack(Pno *top)
{
    while (top->anterior)
    {
        pop(top);
    }

    free(top);
}
// Ta errado!