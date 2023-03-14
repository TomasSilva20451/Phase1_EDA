// Electric_mobility_means.h
#ifndef electric_mobility_means_h
#define electric_mobility_means_h


typedef struct Electric_mobility_means {
    char name[50];
    char geocode[50]; // add new member 'geocode'
} Electric_mobility_means;

void initialize(Electric_mobility_means *mobility_means);
void print_data(Electric_mobility_means mobility_means);

#endif
