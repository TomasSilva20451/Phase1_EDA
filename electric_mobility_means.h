// Electric_mobility_means.h
#ifndef electric_mobility_means_h
#define electric_mobility_means_h


typedef struct Electric_mobility_means {
    char name[20];
    float range;
} Electric_mobility_means;

void insert_data(Electric_mobility_means *mobility_means);
void remove_data(Electric_mobility_means *mobility_means);


#endif
