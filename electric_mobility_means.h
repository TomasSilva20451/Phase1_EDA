// Electric_mobility_means.h
#ifndef ELECTRIC_MOBILITY_MEANS_H
#define ELECTRIC_MOBILITY_MEANS_H

typedef struct
{
    char name[50];
    int battery_charge;
    float cost;
    char type[50];
} Electric_mobility_means;

void insert_mobility_means_data(Electric_mobility_means *mobility_means);
void remove_mobility_means_data(Electric_mobility_means *mobility_means);
void change_mobility_means_data(Electric_mobility_means *mobility_means);
void register_mobility_means_rental(Electric_mobility_means *mobility_means);

#endif