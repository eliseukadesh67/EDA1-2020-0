#include <stdlib.h>
#include <stdio.h>
#include "node.h"

int conta_busca(node_t *head, int x)
{
    if (head == NULL)
    {
        return 0;
    }
    else if (head->val == x)
    {
        return conta_busca(head->next, x) + 1;
    }
    else
    {
        return conta_busca(head->next, x);
    }
}

int main()
{
    node_t *head = malloc(sizeof(node_t));
    head->val = 1;
    node_t *p1 = malloc(sizeof(node_t));
    if (head)
    {
        head->next = p1;
        p1->next = NULL;
    }
    else
    {
        exit(1);
    }

    printf("%d\n", conta_busca(head, 1));

    free(p1);
    free(head);

    return 0;
}