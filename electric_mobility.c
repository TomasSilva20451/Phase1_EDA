#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "electric_mobility.h"

#define PRICE 0.25
#define MAX_MOBILITY 100

struct electric_mobility *mobility_head = NULL;

// create_electric_mobility
/*Esta é uma função que cria e inicializa uma nova estrutura de Mobilidade Elétrica 
com os parâmetros fornecidos, alocando memória para o struct e seus campos conforme necessário. 
Ele retorna um ponteiro para a estrutura recém-criada.*/
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
/*Esta função liberta a memória alocada para um struct ElectricMobility.*/
void destroy_electric_mobility(ElectricMobility *em)
{
    free(em);
}

// add_mobility
/*A função aloca memória dinamicamente para a nova mobilidade usando malloc e inicializa 
seus campos com os argumentos passados para a função.
 Em seguida, verifica se a lista vinculada está vazia,
 e, se for, coloca a nova mobilidade como cabeça de lista. 
 Se a lista não estiver vazia, percorre a lista para encontrar a última mobilidade e adiciona
  a nova mobilidade como seu próximo elemento.*/
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
/*Esta função é usada para imprimir os detalhes de cada item de mobilidade elétrica na lista vinculada. 
Começa no topo da lista e itera através de cada nó, imprimindo as várias propriedades 
de cada item de mobilidade elétrica. Depois de iterar toda a lista, ele retorna 1 para 
indicam sucesso.*/
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
/*Esta função toma uma placa de carro como entrada e remove 
a mobilidade elétrica com essa matrícula da lista ligada.
 Primeiro, verifica se a lista está vazia e devolve 0 se estiver. 
 Se a matrícula corresponder à do nó principal, 
 ele remove o nó principal e retorna 1 para indicar sucesso.
  Caso contrário, percorre a lista ligada à procura da mobilidade elétrica 
  com a placa fornecida, e remove-a se encontrado. 
  Se não for encontrado, ele retornará 0 para indicar falha. 
  A função retorna 1 para indicar o sucesso se a mobilidade elétrica for removida com sucesso.*/
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
/*A função newNode recebe os parâmetros para criar um novo nó ElectricMobility 
e retorna um ponteiro para o nó recém-criado. A função primeiro aloca memória
 para o novo nó, inicializa os campos do nó com os valores fornecidos, 
 e define o próximo ponteiro do nó como NULL. Finalmente, a função retorna um ponteiro
 para o nó recém-criado.*/
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
/*A função push leva um ponteiro para um ponteiro de uma estrutura de ElectricMobility (head_ref)
 e uma estrutura de Mobilidade Elétrica (new_node) e insere new_node no início 
 da lista vinculada apontada por head_ref. Ele faz isso definindo primeiro o próximo 
 ponteiro de new_node para apontar para o atual chefe da lista (*head_ref), 
 e, em seguida, definir *head_ref para apontar para new_node, tornando new_node o novo chefe da lista.*/
void push(ElectricMobility **head_ref, ElectricMobility *new_node)
{
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to swap two nodes in the linked list
/*
head_ref: um ponteiro para um ponteiro para o nó principal da lista vinculada.
prev_x: um ponteiro para o nó que vem antes do primeiro nó a ser trocado.
prev_y: um ponteiro para o nó que vem antes do segundo nó a ser trocado.
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
/*Esta é uma função chamada sortByAutonomy que implementa um algoritmo de classificação de seleção 
para classificar uma lista vinculada de nós de mobilidade elétrica em ordem decrescente com base em seu atributo de autonomia.

Primeiro, verifica se a lista está vazia ou contém apenas um nó, 
nesse caso, nenhuma classificação é necessária e a função simplesmente retorna.

Em seguida, itera sobre a lista e para cada nó,
ele encontra o nó com a autonomia máxima no resto da lista. Se o nó com a autonomia máxima não for o nó atual, ele troca as posições dos dois nós.

Depois de classificar a lista, ele retorna a lista ordenada com o nó principal apontando agora 
ao nó com a máxima autonomia.*/
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
/*A função list_electric_mobility_by_autonomy leva um ponteiro para 
o chefe de uma lista vinculada de nós ElectricMobility e classifica a lista por 
a autonomia da mobilidade elétrica e, em seguida, imprime a lista em formato de tabela
 com vários atributos de cada mobilidade. 
 A classificação é feita usando a função sortByAutonomy que usa um algoritmo de classificação de seleção.
  Depois que a lista é classificada, a função imprime a lista no formato necessário usando um 
  loop que itera sobre cada nó na lista e imprime seus atributos.*/
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
/*A função list_electric_mobility_by_autonomy_and_location assume
 uma localização de parâmetro char*, e seu objetivo é listar toda a mobilidade elétrica
  num determinado local, ordenado por autonomia. Primeiro, cria uma matriz para armazenar a mobilidade elétrica
   com a localização dada e, em seguida, percorre a lista vinculada para adicionar mobilidade elétrica com o 
   dada localização à matriz. Em seguida, ele usa um algoritmo de classificação por bolha para classificar a matriz por autonomia.
   Finalmente, ele produz a mobilidade elétrica no array e libera a memória alocada para o 
   mobilidade elétrica na matriz.*/
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
/*Esta função guarda os dados da mobilidade elétrica armazenados no link 
para um arquivo binário especificado pelo nome do arquivo de entrada. 
A função primeiro abre o arquivo para gravação no modo binário usando o fopen() 
função. Se o arquivo não puder ser aberto, uma mensagem de erro será impressa e a função retornará.
 Em seguida, a função percorre a lista vinculada e grava os dados de cada mobilidade elétrica em
  o arquivo usando a função fwrite(). O tamanho de cada elemento que está sendo escrito é determinado
   por sizeof(struct electric_mobility), e a função escreve um elemento de cada vez. 
   Finalmente, o arquivo é fechado usando a função fclose() e uma mensagem é impressa indicando 
   que os dados de mobilidade elétrica foram salvos no arquivo.*/
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
