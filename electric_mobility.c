#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electric_mobility.h"

struct electric_mobility *electric_mobility_head = NULL;

void add_electric_mobility(char *id, char *type, char *model, char *manufacturer,
                            char *power_source, int max_speed, float autonomy,
                            float price, float battery_level)
{
    struct electric_mobility *new_node = malloc(sizeof(struct electric_mobility));
    new_node->id = strdup(id);
    new_node->type = strdup(type);
    new_node->model = strdup(model);
    new_node->manufacturer = strdup(manufacturer);
    new_node->power_source = strdup(power_source);
    new_node->max_speed = max_speed;
    new_node->autonomy = autonomy;
    new_node->price = price;
    new_node->battery_level = battery_level;
    new_node->next = NULL;

    if (electric_mobility_head == NULL)
    {
        electric_mobility_head = new_node;
    }
    else
    {
        struct electric_mobility *current = electric_mobility_head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_all_electric_mobility()
{
    struct electric_mobility *current = electric_mobility_head;
    while (current != NULL)
    {
        printf("ID: %s\n", current->id);
        printf("Tipo: %s\n", current->type);
        printf("Modelo: %s\n", current->model);
        printf("Fabricante: %s\n", current->manufacturer);
        printf("Fonte de energia: %s\n", current->power_source);
        printf("Velocidade máxima: %d\n", current->max_speed);
        printf("Autonomia: %.2f km\n", current->autonomy);
        printf("Preço: R$%.2f\n", current->price);
        printf("Bateria: %.2f%%\n", current->battery_level);
        printf("\n");

        current = current->next;
    }
}

struct electric_mobility *get_electric_mobility_head()
{
    return electric_mobility_head;
}

void update_electric_mobility_battery_level(char *id, float battery_level)
{
    struct electric_mobility *current = electric_mobility_head;
    while (current != NULL)
    {
        if (strcmp(current->id, id) == 0)
        {
            current->battery_level = battery_level;
            break;
        }
        current = current->next;
    }
}

struct electric_mobility *find_electric_mobility(char *id)
{
    struct electric_mobility *current = electric_mobility_head;
    while (current != NULL)
    {
        if (strcmp(current->id, id) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}