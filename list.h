#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/* Definição da estrutura nó */
struct node
{
    void *data;
    struct node *next;
};

/* Definição da estrutura lista */
struct list
{
    struct node *head;
    int size;
};

/* Cria uma nova lista */
struct list *create_list();

/* Insere um novo nó no início da lista */
void insert_node(struct list *list, void *data);

/* Remove o primeiro nó da lista e retorna o seu valor */
void *remove_first_node(struct list *list);

/* Verifica se a lista está vazia */
bool is_empty(struct list *list);

/* Retorna o tamanho da lista */
int get_list_size(struct list *list);

/* Busca um nó na lista pelo índice */
struct node *get_node_by_index(struct list *list, int index);

#endif /* LIST_H */