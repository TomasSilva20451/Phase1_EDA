#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "electric_mobility.h"

#define PRICE 0.25

struct electric_mobility *mobility_head = NULL;

// create_electric_mobility
ElectricMobility *create_electric_mobility(int id, char *name, char *license_plate, char *location, float price, int stock, float rent, float autonomy, int battery_level)
{
    ElectricMobility *em = malloc(sizeof(ElectricMobility));
    if (em == NULL)
    {
        printf("Error: Could not allocate memory for ElectricMobility.\n");
        exit(1);
    }

    em->id = id;
    em->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(em->name, name);

    // char to string
    em->license_plate = malloc((strlen(license_plate) + 1) * sizeof(char));
    strcpy(em->license_plate, license_plate);

    em->location = malloc((strlen(location) + 1) * sizeof(char));
    strcpy(em->location, location);

    em->price = price;
    em->stock = stock;
    em->rent = rent;
    em->autonomy = autonomy;
    em->battery_level = battery_level;

    return em;
}

void destroy_electric_mobility(ElectricMobility *em)
{
    free(em);
}

// add_mobility -int or void
int add_mobility(int id, char *name, char *license_plate, char *location, float price, int stock, float rent, float autonomy, int battery_level)
{
    struct electric_mobility *new_mobility = malloc(sizeof(struct electric_mobility));
    if (new_mobility == NULL)
    {
        printf("Error: Failed to allocate memory for new electric mobility.\n");
        return 0; // Return 0 to indicate failure
    }

    new_mobility->id = id;
    new_mobility->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(new_mobility->name, name);

    new_mobility->license_plate = malloc((strlen(license_plate) + 1) * sizeof(char));
    strcpy(new_mobility->license_plate, license_plate);

    new_mobility->location = malloc((strlen(location) + 1) * sizeof(char));
    strcpy(new_mobility->location, location);

    new_mobility->price = price;
    new_mobility->stock = stock;
    new_mobility->rent = rent;
    new_mobility->autonomy = autonomy;
    new_mobility->battery_level = battery_level;
    new_mobility->next = NULL;

    if (mobility_head == NULL) // Empty list
    {
        mobility_head = new_mobility;
    }
    else // Non-empty list
    {
        struct electric_mobility *current_mobility = mobility_head;
        while (current_mobility->next != NULL)
        {
            current_mobility = current_mobility->next;
        }
        current_mobility->next = new_mobility;
    }

    return 1; // Return 1 to indicate success
}

// list_mobility
int list_mobility()
{
    struct electric_mobility *current = mobility_head;
    while (current != NULL)
    {
        printf("ID: %d\n", current->id);
        printf("Name: %s\n", current->name);
        printf("License Plate: %s\n", current->license_plate);
        printf("Location: %s\n", current->location);
        printf("Price: %f\n", current->price);
        printf("Stock: %d\n", current->stock);
        printf("Rent: %f\n", current->rent);
        printf("Autonomy: %f\n", current->autonomy);
        printf("Battery Level: %d\n", current->battery_level);
        printf("\n");
        current = current->next;
    }
    return 1; // Return 1 to indicate success
}

// remove_electric_mobility
int remove_electric_mobility(char *license_plate)
{
    if (mobility_head == NULL) // Empty list
    {
        printf("Error: No electric mobility to remove.\n");
        return 0; // Return 0 to indicate failure
    }

    // Special case: remove head node
    if (strcmp(mobility_head->license_plate, license_plate) == 0)
    {
        struct electric_mobility *temp = mobility_head;
        mobility_head = mobility_head->next;
        destroy_electric_mobility(temp);

        return 1; // Return 1 to indicate success
    }

    struct electric_mobility *current_mobility = mobility_head->next;
    struct electric_mobility *previous_mobility = mobility_head;

    while (current_mobility != NULL)
    {
        if (strcmp(current_mobility->license_plate, license_plate) == 0)
        {
            previous_mobility->next = current_mobility->next;
            destroy_electric_mobility(current_mobility);
            printf("Electric mobility with license plate %s has been removed.\n", license_plate);
            return 1; // Return 1 to indicate success
        }

        previous_mobility = current_mobility;
        current_mobility = current_mobility->next;
    }

    printf("Error: Electric mobility with license plate %s not found.\n", license_plate);
    return 0; // Return 0 to indicate failure
}

// list_electric_mobility_by_location
void list_electric_mobility_by_location(char *location)
{
    struct electric_mobility *current = mobility_head;
    while (current != NULL)
    {
        if (strcmp(current->location, location) == 0)
        {
            printf("ID: %d\n", current->id);
            printf("Name: %s\n", current->name);
            printf("License Plate: %s\n", current->license_plate);
            printf("Location: %s\n", current->location);
            printf("Price: %f\n", current->price);
            printf("Stock: %d\n", current->stock);
            printf("Rent: %f\n", current->rent);
            printf("Autonomy: %f\n", current->autonomy);
            printf("Battery Level: %d\n", current->battery_level);
            printf("\n");
        }
        current = current->next;
    }
}
