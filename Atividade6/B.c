#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pilha
{
    char c;
    struct Pilha *next;
} pilha;

pilha *inicia()
{
    pilha *new = malloc(sizeof(pilha));
    new->next = NULL;

    return new;
}
void pop(pilha *topo)
{
    if (topo->next == NULL)
    {
        exit(1);
    }

    char top_val = topo->next->c;
    pilha *lixo = topo->next;
    topo->next = lixo->next;
    free(lixo);
}
void insere(pilha *topo, char c)
{
    pilha *novo = malloc(sizeof(pilha));
    if (novo == NULL)
    {
        exit(1);
    }
    novo->c = c;
    novo->next = topo->next;
    topo->next = novo;
}
void destroi(pilha *topo)
{
    while (topo->next)
    {
        pop(topo);
    }
}

int main()
{

    pilha *p = malloc(sizeof(pilha));
    p->next = NULL;
    int N;
    char str[100000];

    scanf("%d", &N);
    scanf("%s", str);

    for (int i = 0; i < N; i++)
    {
        insere(p, str[i]);
    }

    int i = 0;
    while (i < N)
    {

        if (p->next->c == str[i])
        {
            pop(p);
        }
        else
        {
            break;
        }
        i++;
    }

    if (p->next != NULL)
    {
        printf("%d\n", 0);
    }
    else
    {
        printf("%d\n", 1);
    }

    destroi(p);
    free(p);
    return 0;
}