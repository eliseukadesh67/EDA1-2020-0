#include "pilha_list.h"
#include <stdio.h>

int main()
{
    Pno *pilha = init_stack();
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    printf("%d\n", pilha->anterior->dado);
    free_stack(pilha);
}