# Aula 2 - Lista encadeada

## Inicializado uma lista

Uma lista está vazia quando o nó cabeça aponta para NULL.

Para incializar, alocamos dinamicamente o nó cabeça.

- Ex :

        void_inicializa(Node *head){
            head = malloc(sizeof(Node));
            if(head==NULL){
                exit(1);
            }
            head->prox = NULL;
        }