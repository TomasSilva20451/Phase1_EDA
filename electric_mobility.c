#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "electric_mobility.h"

#define PRICE 0.25

// create_electric_mobility
ElectricMobility *create_electric_mobility(int id, char *name, float price, int stock, float rent, float autonomy, int battery_level, int max_rental_duration, int battery_level_per_minute)
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
    em->price = price;
    em->stock = stock;
    em->rent = rent;
    em->autonomy = autonomy;
    em->battery_level = battery_level;
    em->max_rental_duration = max_rental_duration;
    em->battery_level_per_minute = battery_level_per_minute;

    return em;
}

/*
void charge(ElectricMobility *em)
{
    em->battery_level = 100;
    printf("Battery charged to 100%%\n");
}
*/

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
/*
void print_electric_mobility(ElectricMobility *em) {
    printf("ID: %d\n", em->id);
    printf("Name: %s", em->name);
    printf("Price: %.2f\n", em->price);
    printf("Stock: %d\n", em->stock);
    printf("Rent: %.2f\n", em->rent);
    printf("Autonomy: %.2f km\n", em->autonomy);
    printf("Battery Level: %d%%\n", em->battery_level);
    printf("Max Rental Duration: %d hours\n", em->max_rental_duration);
    printf("Battery Level per Minute: %d%%\n", em->battery_level_per_minute);
}
*/