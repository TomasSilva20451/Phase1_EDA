#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electric_mobility.h"
#include "rental.h"

void write_electric_mobility_to_file(FILE *fp, ElectricMobility *em)
{
    fwrite(em, sizeof(ElectricMobility), 1, fp);
}

ElectricMobility *read_electric_mobility_file(FILE *fp)
{
    ElectricMobility *em = (ElectricMobility *)malloc(sizeof(ElectricMobility));
    fread(em, sizeof(ElectricMobility), 1, fp);
    return em;
}

void save_electric_mobility_to_file(ElectricMobility *em)
{
    FILE *fp = fopen("electric_mobility.dat", "ab");
    write_electric_mobility_to_file(fp, em);
    fclose(fp);
}

/*ElectricMobility *find_electric_mobility_by_id(ElectricMobility *electric_mobility_list,int id)
{
    FILE *fp = fopen("electric_mobility.dat", "rb"); 
    ElectricMobility *em;

    while ((em = read_electric_mobility_file(fp)) != NULL)
    {
        if (em->id == id)
        {
            fclose(fp);
            return em;
        }
    }

    fclose(fp);
    return NULL;
}*/

void delete_electric_mobility(int id)
{
    FILE *fp = fopen("electric_mobility.dat", "rb");
    FILE *tmp = fopen("tmp.dat", "wb");
    ElectricMobility *em;

    while ((em = read_electric_mobility_file(fp)) != NULL)
    {
        if (em->id != id)
        {
            write_electric_mobility_to_file(tmp, em);
        }
    }

    fclose(fp);
    fclose(tmp);
    remove("electric_mobility.dat");
    rename("tmp.dat", "electric_mobility.dat");
}
