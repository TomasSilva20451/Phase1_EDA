#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "electric_mobility.h"

#define PRICE 0.25
#define MAX_MOBILITY 100


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


// Function to create a new node with given data
ElectricMobility* newNode(int id, char* name, char* license_plate, char* location, 
                          float price, int stock, float rent, float autonomy, int battery_level) {
    ElectricMobility* new_node = (ElectricMobility*) malloc(sizeof(ElectricMobility));
    new_node->id = id;
    new_node->name = name;
    new_node->license_plate = license_plate;
    new_node->location = location;
    new_node->price = price;
    new_node->stock = stock;
    new_node->rent = rent;
    new_node->autonomy = autonomy;
    new_node->battery_level = battery_level;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
void push(ElectricMobility** head_ref, ElectricMobility* new_node) {
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to swap two nodes in the linked list
void swapNodes(ElectricMobility** head_ref, ElectricMobility* prev_x, ElectricMobility* prev_y) {
    ElectricMobility* temp = prev_y->next;
    prev_y->next = prev_x->next;
    prev_x->next = temp;
    temp = prev_y->next->next;
    prev_y->next->next = prev_x->next->next;
    prev_x->next->next = temp;
}

// Function to sort the linked list by decreasing autonomy
void sortByAutonomy(ElectricMobility** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        return;
    }
    ElectricMobility* current = *head_ref;
    ElectricMobility* prev = NULL;
    while (current != NULL) {
        ElectricMobility* max_node = current;
        ElectricMobility* temp = current->next;
        while (temp != NULL) {
            if (temp->autonomy > max_node->autonomy) {
                max_node = temp;
            }
            temp = temp->next;
        }
        if (current != max_node) {
            swapNodes(head_ref, prev, max_node);
            current = max_node;
        }
        prev = current;
        current = current->next;
    }
}

void list_electric_mobility_by_autonomy(ElectricMobility* head) {
    sortByAutonomy(&head);
    printf("Electric mobility list sorted by autonomy:\n");
    printf("ID\tName\t\tLicense Plate\tLocation\tPrice\tStock\tRent\tAutonomy\tBattery Level\n");
    printf("----------------------------------------------------------------------------------------\n");
    ElectricMobility* current = head;
    while (current != NULL) {
        printf("%d\t%s\t%s\t%s\t%.2f\t%d\t%.2f\t%.2f\t%d\n", 
        current->id, 
        current->name,
        current->license_plate, 
        current->location, 
        current->price, 
        current->stock,
        current->rent,
        current->autonomy,
        current->battery_level);
        current = current->next;
    }
}

// list_electric_mobility_by_autonomy_and_location
void list_electric_mobility_by_autonomy_and_location(char *location)
{
    // Create an array to store electric mobility with the given location
    ElectricMobility *mobility_array[MAX_MOBILITY];
    int num_mobility = 0;

    // Traverse the linked list and add electric mobility with the given location to the array
    struct electric_mobility *current = mobility_head;
    while (current != NULL)
    {
        if (strcmp(current->location, location) == 0)
        {
            mobility_array[num_mobility] = create_electric_mobility(current->id, current->name, current->license_plate, current->location, current->price, current->stock, current->rent, current->autonomy, current->battery_level);
            num_mobility++;
        }
        current = current->next;
    }

    // Sort the array by autonomy using bubble sort
    for (int i = 0; i < num_mobility - 1; i++)
    {
        for (int j = 0; j < num_mobility - i - 1; j++)
        {
            if (mobility_array[j]->autonomy < mobility_array[j+1]->autonomy)
            {
                ElectricMobility *temp = mobility_array[j];
                mobility_array[j] = mobility_array[j+1];
                mobility_array[j+1] = temp;
            }
        }
    }

    // Output the electric mobility in the array
    for (int i = 0; i < num_mobility; i++)
    {
        printf("ID: %d\n", mobility_array[i]->id);
        printf("Name: %s\n", mobility_array[i]->name);
        printf("License Plate: %s\n", mobility_array[i]->license_plate);
        printf("Location: %s\n", mobility_array[i]->location);
        printf("Price: %f\n", mobility_array[i]->price);
        printf("Stock: %d\n", mobility_array[i]->stock);
        printf("Rent: %f\n", mobility_array[i]->rent);
        printf("Autonomy: %f\n", mobility_array[i]->autonomy);
        printf("Battery Level: %d\n", mobility_array[i]->battery_level);
        printf("\n");
    }

    // Free the memory allocated for the electric mobility in the array
    for (int i = 0; i < num_mobility; i++)
    {
        destroy_electric_mobility(mobility_array[i]);
    }
}
