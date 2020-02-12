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
    pilha *botas[31];

    for (int i = 0; i < 31; i++)
    {
        botas[i] = inicia();
    }

    int tam;
    char pe;
    int par = 0;

    while (scanf("%d %c", &tam, &pe) != EOF)
    {

        if (botas[tam - 30]->next == NULL)
        {
            insere(botas[tam - 30], pe);
        }
        else if (botas[tam - 30]->next->c == 'D')
        {
            if (pe == 'E')
            {
                par++;
                pop(botas[tam - 30]);
            }
            else
            {
                insere(botas[tam - 30], pe);
            }
        }
        else
        {
            if (pe == 'D')
            {
                par++;
                pop(botas[tam - 30]);
            }
            else
            {
                insere(botas[tam - 30], pe);
            }
        }
    }

    for (int i = 0; i < 31; i++)
    {
        destroi(botas[i]);
        free(botas[i]);
    }

    printf("%d\n", par);

    return 0;
}