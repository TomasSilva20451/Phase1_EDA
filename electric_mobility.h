#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

struct electric_mobility {
    char code[7];
    char type[21];
    char location_geocode[17];
    int battery_level;
    float rental_cost;
    struct electric_mobility *next;
};

void load_electric_mobility_data();
void save_electric_mobility_data();
void insert_electric_mobility(struct electric_mobility new_electric_mobility);
void remove_electric_mobility(char *code);
void update_electric_mobility(char *code, char *type, char *location_geocode, int battery_level, float rental_cost);
void rent_electric_mobility(char *code);
void list_electric_mobility_by_autonomy();
void list_electric_mobility_by_location(char *geocode);

#endif /* ELECTRIC_MOBILITY_H */
