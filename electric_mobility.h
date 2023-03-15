#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

#define MAX_ELECTRIC_MOBILITY 100

typedef struct ElectricMobility {
    char license_plate[10];
    char make[20];
    char model[20];
    char color[10];
    char location[20];
    int price;
} ElectricMobility;

void add_electric_mobility(ElectricMobility em);
void list_electric_mobility_by_location(char *location);
void delete_electric_mobility(char *license_plate);

#endif