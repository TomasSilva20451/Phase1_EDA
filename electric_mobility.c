#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "electric_mobility.h"

#define PRICE 0.25

struct electric_mobility_t
{
    int battery_level;
};

ElectricMobility *create_electric_mobility(int battery_level)
{
    ElectricMobility *em = (ElectricMobility *)malloc(sizeof(ElectricMobility));
    em->battery_level = battery_level;
    return em;
}

void charge(ElectricMobility *em)
{
    em->battery_level = 100;
    printf("Battery charged to 100%%\n");
}

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

void destroy_electric_mobility(ElectricMobility *em)
{
    free(em->model);
    free(em->color);
    free(em->brand);
    free(em);
}

void print_electric_mobility(ElectricMobility *em)
{
    printf("Model: %s\n", em->model);
    printf("Brand: %s\n", em->brand);
    printf("Color: %s\n", em->color);
    printf("Year: %d\n", em->year);
    printf("Range: %d km\n", em->range);
    printf("Top speed: %d km/h\n", em->top_speed);
    printf("Battery capacity: %d kWh\n", em->battery_capacity);
    printf("Price: %d €\n", em->price);
}

ElectricMobility *create_electric_mobility(char *model, char *brand, char *color, int year,
                                           int range, int top_speed, int battery_capacity,
                                           int price)
{
    ElectricMobility *em = (ElectricMobility *)malloc(sizeof(ElectricMobility));
    if (em == NULL)
    {
        printf("Error: Could not allocate memory for ElectricMobility.\n");
        exit(1);
    }

    em->model = (char *)malloc((strlen(model) + 1) * sizeof(char));
    if (em->model == NULL)
    {
        printf("Error: Could not allocate memory for ElectricMobility model.\n");
        exit(1);
    }
    strcpy(em->model, model);

    em->brand = (char *)malloc((strlen(brand) + 1) * sizeof(char));
    if (em->brand == NULL)
    {
        printf("Error: Could not allocate memory for ElectricMobility brand.\n");
        exit(1);
    }
    strcpy(em->brand, brand);

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
