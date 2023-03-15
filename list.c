#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Função para criar um novo nó */
struct node *create_node(void *data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Função para inserir um novo nó no início da lista */
void insert_node(struct node **head, struct node *new_node) {
    new_node->next = *head;
    *head = new_node;
}

/* Função para remover um nó da lista */
void remove_node(struct node **head, struct node *node_to_remove) {
    if (*head == node_to_remove) {
        *head = node_to_remove->next;
        free(node_to_remove);
        return;
    }
    struct node *current = *head;
    while (current != NULL && current->next != node_to_remove) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    current->next = node_to_remove->next;
    free(node_to_remove);
}

/* Função para encontrar um nó na lista */
struct node *find_node(struct node *head, void *data_to_find, int (*cmp)(void *, void *)) {
    struct node *current = head;
    while (current != NULL) {
        if (cmp(current->data, data_to_find) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* Função para percorrer a lista */
void traverse_list(struct node *head, void (*fptr)(void *)) {
    struct node *current = head;
    while (current != NULL) {
        fptr(current->data);
        current = current->next;
    }
}

/* Função para libertar a memória alocada para a lista */
void free_list(struct node **head, void (*free_data)(void *)) {
    struct node *current = *head;
    while (current != NULL) {
        struct node *next_node = current->next;
        free_data(current->data);
        free(current);
        current = next_node;
    }
    *head = NULL;
}

