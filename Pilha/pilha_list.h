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
Pno *pop(Pno *topo)
{
    if (topo->anterior == NULL)
    {
        return NULL;
    }

    Pno *top = topo->anterior;
    free(top);

    return topo;
}
void free_stack(Pno *top)
{
    if (pop(top)->anterior == NULL)
    {
        return;
    }
    else
    {
        free_stack(top->anterior);
    }

    //free(top);
}