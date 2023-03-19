#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "electric_mobility.h"

#define PRICE 0.25
#define MAX_MOBILITY 100

struct electric_mobility *mobility_head = NULL;

// create_electric_mobility
/*This is a function that creates and initializes a new ElectricMobility struct 
with the given parameters, allocating memory for the struct and its fields as necessary. 
It returns a pointer to the newly created struct.*/
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

// destroy_electric_mobility
/*This function releases the memory allocated for an ElectricMobility struct.*/
void destroy_electric_mobility(ElectricMobility *em)
{
    free(em);
}

// add_mobility
/*The function dynamically allocates memory for the new mobility using malloc and initializes 
its fields with the arguments passed to the function.
 It then checks if the linked list is empty,
 and if it is, sets the new mobility as the head of the list. 
 If the list is not empty, it traverses the list to find the last mobility and adds
  the new mobility as its next element.*/
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
/*This function is used to print out the details of each electric mobility item in the linked list. 
It starts from the head of the list and iterates through each node, printing out the various properties 
of each electric mobility item. Once it has iterated through the entire list, it returns 1 to 
indicate success.*/
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
/*This function takes a license plate as input and removes 
the electric mobility with that license plate from the linked list.
 It first checks if the list is empty, and returns 0 if it is. 
 If the license plate matches the one of the head node, 
 it removes the head node and returns 1 to indicate success.
  Otherwise, it traverses the linked list looking for the electric mobility 
  with the given license plate, and removes it if found. 
  If it is not found, it returns 0 to indicate failure. 
  The function returns 1 to indicate success if the electric mobility is successfully removed.*/
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
/*The newNode function takes in the parameters for creating a new ElectricMobility node 
and returns a pointer to the newly created node. The function first allocates memory
 for the new node, initializes the node's fields with the provided values, 
 and sets the node's next pointer to NULL. Finally, the function returns a pointer
 to the newly created node.*/
ElectricMobility *newNode(int id, char *name, char *license_plate, char *location,
                          float price, int stock, float rent, float autonomy, int battery_level)
{
    ElectricMobility *new_node = (ElectricMobility *)malloc(sizeof(ElectricMobility));
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
/*The push function takes a pointer to a pointer of an ElectricMobility struct (head_ref)
 and an ElectricMobility struct (new_node) and inserts new_node at the beginning 
 of the linked list pointed to by head_ref. It does this by first setting the next 
 pointer of new_node to point to the current head of the list (*head_ref), 
 and then setting *head_ref to point to new_node, making new_node the new head of the list.*/
void push(ElectricMobility **head_ref, ElectricMobility *new_node)
{
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to swap two nodes in the linked list
/*
head_ref: a pointer to a pointer to the head node of the linked list.
prev_x: a pointer to the node that comes before the first node to be swapped.
prev_y: a pointer to the node that comes before the second node to be swapped.
*/
void swapNodes(ElectricMobility **head_ref, ElectricMobility *prev_x, ElectricMobility *prev_y)
{
    ElectricMobility *temp = prev_y->next;
    prev_y->next = prev_x->next;
    prev_x->next = temp;
    temp = prev_y->next->next;
    prev_y->next->next = prev_x->next->next;
    prev_x->next->next = temp;
}

// Function to sort the linked list by decreasing autonomy
/*This is a function called sortByAutonomy that implements a selection sort algorithm 
to sort a linked list of electric mobility nodes in descending order based on their autonomy attribute.

It first checks if the list is empty or contains only one node, 
in which case no sorting is necessary and the function simply returns.

It then iterates over the list and for each node,
it finds the node with the maximum autonomy in the rest of the list. If the node with the maximum autonomy is not the current node, it swaps the positions of the two nodes.

After sorting the list, it returns the sorted list with the head node now pointing 
to the node with the maximum autonomy.*/
void sortByAutonomy(ElectricMobility **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        return;
    }
    ElectricMobility *current = *head_ref;
    ElectricMobility *prev = NULL;
    while (current != NULL)
    {
        ElectricMobility *max_node = current;
        ElectricMobility *temp = current->next;
        while (temp != NULL)
        {
            if (temp->autonomy > max_node->autonomy)
            {
                max_node = temp;
            }
            temp = temp->next;
        }
        if (current != max_node)
        {
            swapNodes(head_ref, prev, max_node);
            current = max_node;
        }
        prev = current;
        current = current->next;
    }
}

// list_electric_mobility_by_autonomy
/*The function list_electric_mobility_by_autonomy takes a pointer to 
the head of a linked list of ElectricMobility nodes and sorts the list by 
the autonomy of the electric mobility, then prints the list in a table format
 with various attributes of each mobility. 
 The sorting is done using the sortByAutonomy function which uses a selection sort algorithm.
  Once the list is sorted, the function prints the list in the required format using a 
  loop that iterates over each node in the list and prints its attributes.*/
void list_electric_mobility_by_autonomy(ElectricMobility *head)
{
    sortByAutonomy(&head);
    printf("Electric mobility list sorted by autonomy:\n");
    printf("ID\tName\t\tLicense Plate\tLocation\tPrice\tStock\tRent\tAutonomy\tBattery Level\n");
    printf("----------------------------------------------------------------------------------------\n");
    ElectricMobility *current = head;
    while (current != NULL)
    {
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
/*The function list_electric_mobility_by_autonomy_and_location takes
 a char* parameter location, and its purpose is to list all the electric mobility
  in a given location, sorted by autonomy. It first creates an array to store electric mobility
   with the given location and then traverses the linked list to add electric mobility with the 
   given location to the array. Then, it uses a bubble sort algorithm to sort the array by autonomy.
   Finally, it outputs the electric mobility in the array and frees the memory allocated for the 
   electric mobility in the array.*/
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
            if (mobility_array[j]->autonomy < mobility_array[j + 1]->autonomy)
            {
                ElectricMobility *temp = mobility_array[j];
                mobility_array[j] = mobility_array[j + 1];
                mobility_array[j + 1] = temp;
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

// read_electric_mobility_file
void read_electric_mobility_file(const char *filename) {
    FILE *fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return; // Return nothing to indicate failure
    }

    int count = 0;
    ElectricMobility em;
    while (fread(&em, sizeof(ElectricMobility), 1, fp) == 1) {
        if (add_mobility(em.id, em.name, em.license_plate, em.location, em.price, em.stock, em.rent, em.autonomy, em.battery_level) == 0) {
            fprintf(stderr, "Error: Failed to add electric mobility.\n");
            fclose(fp);
            return; // Return nothing to indicate failure
        }
        count++;
    }

    fclose(fp);

    printf("Successfully read %d electric mobility from file %s.\n", count, filename);
}


// save_electric_mobility_data_to_file
/*This function saves the data of the electric mobility stored in the linked 
list to a binary file specified by the input filename. 
The function first opens the file for writing in binary mode using the fopen() 
function. If the file cannot be opened, an error message is printed and the function returns.
 The function then traverses the linked list and writes the data of each electric mobility to
  the file using the fwrite() function. The size of each element being written is determined
   by sizeof(struct electric_mobility), and the function writes one element at a time. 
   Finally, the file is closed using the fclose() function, and a message is printed indicating 
   that the electric mobility data has been saved to the file.*/
void save_electric_mobility_data_to_file(char *filename) {
    FILE *file = fopen(filename, "wb"); // Open file for writing in binary mode
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    struct electric_mobility *current_mobility = mobility_head;
    while (current_mobility != NULL) {
        fwrite(current_mobility, sizeof(struct electric_mobility), 1, file); // Write mobility data to file
        current_mobility = current_mobility->next;
    }

    fclose(file);
    printf("Electric mobility data saved to file %s.\n", filename);
}
