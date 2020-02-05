#include <stdio.h>
#include "pilha_vet.h"

int main()
{
#if tipo == 0
    char elem;
    scanf("%c", &elem);
#elif tipo == 1
    int elem;
    scanf("%d", &elem);
#elif tipo == 2
    float elem;
    scanf("%f", &elem);
#elif tipo == 3
    double elem;
    scanf("%f", &elem);
#elif tipo == 4
    long int elem;
    scanf("%ld", &elem);
#elif tipo == 5
    long long int elem;
    scanf("%lld", &elem);
#endif
    pilha *stack1 = malloc(sizeof(pilha));
    inicializa(stack1);
    empilha(stack1, elem);
    printf("Topo da pilha : %d\n", top(stack1));
    destroi(stack1);
    free(stack1);
    return 0;
}