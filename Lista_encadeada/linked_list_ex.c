#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
	char nome[256];
	char sexo[10];
	unsigned int idade;
	char tipo;
} pessoa;

typedef struct node
{
	struct node *next;
	pessoa person;
} Lnode;

Lnode *new_node(pessoa p)
{
	Lnode *node = (Lnode *)malloc(sizeof(Lnode));
	node->next = NULL;
	node->person = p;
	return node;
}

Lnode *insert_tail_node(Lnode *head, pessoa p)
{

	Lnode *new = new_node(p);

	if (head == NULL)
	{
		head = new;
	}
	else
	{
		Lnode *aux = head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = new;
		new->next = NULL;
	}

	return head;
}
Lnode *insert_head_node(Lnode *head, pessoa p)
{

	Lnode *new = new_node(p);

	if (head == NULL)
	{
		head = new;
	}
	else
	{
		Lnode *aux = head;
		new->next = aux;
		head = new;
	}

	return head;
}
void print_list(Lnode *head)
{
	Lnode *aux;
	aux = head;
	while (aux)
	{
		printf("%s\n", aux->person.nome);
		aux = aux->next;
	}
	//printf("\n");
}

void print_list_recursive(Lnode *head)
{

	Lnode *aux;
	aux = head;

	if (!aux)
	{
		return;
	}
	else
	{
		printf("%s\n", aux->person.nome);
		print_list(aux->next);
	}
}

void free_list(Lnode *head)
{
	Lnode *p, *aux;
	p = head;

	while (p)
	{
		aux = p->next;
		printf("Desalocando %s\n", p->person.nome);
		free(p);
		p = aux;
	}
}
Lnode *search(Lnode *head, char name[])
{
	if (strcmp(name, head->person.nome) == 0)
	{
		return head;
	}
	else
	{
		Lnode *aux = head;
		while (aux != NULL)
		{
			if (strcmp(name, aux->person.nome) == 0)
			{
				return aux;
			}
			aux = aux->next;
		}

		if (aux == NULL)
		{
			return aux;
		}
	}
}

int main(int argc, char const *argv[])
{

	char a[256];
	Lnode *head = NULL;
	printf("Digite nomes para adicionar.\n");
	while (scanf("%s", a) != EOF)
	{

		pessoa p4;
		strcpy(p4.nome, a);
		head = insert_tail_node(head, p4);
	}
	printf("Pessoas encontradas :\n");
	print_list(head);
	printf("\n");
	free_list(head);

	return 0;
}