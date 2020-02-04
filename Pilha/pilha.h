#include <stdlib.h>
#if tipo == 0
#define item char
#elif tipo == 1
#define item int
#elif tipo == 2
#endif

typedef struct pilha
{
    int topo;
    int *dados;
    int N;

} pilha;