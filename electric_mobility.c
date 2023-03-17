#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "electric_mobility.h"

#define PRICE 0.25

/*struct electric_mobility_t
{
    int battery_level;
};*/

ElectricMobility *create_electric_mobility(int id, char *name, float price, int stock, float rent, float autonomy, int battery_level)
{
    ElectricMobility *em = malloc(sizeof(struct ElectricMobilit *));
    em->id = id;
    strcpy(em->name, name);
    em->price = price;
    em->stock = stock;
    em->rent = rent;
    em->autonomy = autonomy;
    em->battery_level = battery_level;

    return em;
}

void charge(ElectricMobility *em)
{
    em->battery_level = 100;
    printf("Battery charged to 100%%\n");
}

/*
void ride(ElectricMobility *em, Client *client, int distance)
{
    if (em->battery_level <= 0)
    {
        printf("Error: Battery is dead. Please charge the vehicle before riding.\n");
        return;
    }
    if (distance > em->battery_level * 4)
    {
        printf("Error: Vehicle can't make the trip. Please choose a shorter distance or charge the vehicle.\n");
        return;
    }
    float cost = distance * PRICE;

    if (withdraw(client, cost))
    {
        em->battery_level -= distance / 4;
        printf("Ride completed. Your new account balance is $%.2f. Vehicle's battery level is now %d%%.\n", get_balance(client), em->battery_level);
    }
    else
    {
        printf("Error: Insufficient funds to complete the ride.\n");
    }
}
*/

void destroy_electric_mobility(ElectricMobility *em)
{
    free(em);
}

void print_electric_mobility(ElectricMobility *em)
{

    printf("ID: %d\n", em->id);
    printf("name: %s\n", em->name);
    printf("price: %f €\n", em->price);
    printf("stock: %d\n", em->stock);
    printf("rent: %f\n", em->rent);
    printf("autonomy: %f km\n", em->autonomy);
    printf("battery_level: %d\n", em->battery_level);
}

/*
ElectricMobility *create_electric_mobility(int id, char *name, float price, int stock, float rent, float autonomy, int battery_level)
{
    ElectricMobility *em = (ElectricMobility *)malloc(sizeof(ElectricMobility));
    if (em == NULL)
    {
        printf("Error: Could not allocate memory for ElectricMobility.\n");
        exit(1);
    }

    em->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    if (em->name == NULL)
    {
        printf("Error: Could not allocate memory for ElectricMobility model.\n");
        exit(1);
    }
    strcpy(em->name, name);

    em->price = (float *)malloc((strlen(price) + 1) * sizeof(char));
    if (em->price == NULL)
    {
        printf("Error: Could not allocate memory for ElectricMobility brand.\n");
        exit(1);
    }
    strcpy(em->price, price);

    em->color = (char *)malloc((strlen(color) + 1) * sizeof(char));
    if (em->color == NULL)
    {
        printf("Error: Could not allocate memory for ElectricMobility color.\n");
        exit(1);
    }
    strcpy(em->color, color);

em->year = year;
em->range = range;
em->top_speed = top_speed;
em->battery_capacity = battery_capacity;
em->price = price;

return em;
}
*/