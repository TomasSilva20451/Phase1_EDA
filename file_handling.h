#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include "electric_mobility.h"
#include "client.h"
#include "manager.h"

void read_electric_mobility_file(char *filename);
void write_electric_mobility_file(char *filename);
void read_clients_file(char *filename);
void write_clients_file(char *filename);
void read_managers_file(char *filename);
void write_managers_file(char *filename);

#endif
