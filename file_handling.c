#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electric_mobility.h"
#include "rental.h"

void write_electric_mobility_to_file(FILE *fp, Electric_mobility *em)
{
    fwrite(em, sizeof(Electric_mobility), 1, fp);
}

Electric_mobility *read_electric_mobility_from_file(FILE *fp)
{
    Electric_mobility *em = (Electric_mobility *)malloc(sizeof(Electric_mobility));
    fread(em, sizeof(Electric_mobility), 1, fp);
    return em;
}

void save_electric_mobility_to_file(Electric_mobility *em)
{
    FILE *fp = fopen("electric_mobility.dat", "ab");
    write_electric_mobility_to_file(fp, em);
    fclose(fp);
}

Electric_mobility *find_electric_mobility_by_id(int id)
{
    FILE *fp = fopen("electric_mobility.dat", "rb");
    Electric_mobility *em;

    while ((em = read_electric_mobility_from_file(fp)) != NULL)
    {
        if (em->id == id)
        {
            fclose(fp);
            return em;
        }
    }

    fclose(fp);
    return NULL;
}

void delete_electric_mobility(int id)
{
    FILE *fp = fopen("electric_mobility.dat", "rb");
    FILE *tmp = fopen("tmp.dat", "wb");
    Electric_mobility *em;

    while ((em = read_electric_mobility_from_file(fp)) != NULL)
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
