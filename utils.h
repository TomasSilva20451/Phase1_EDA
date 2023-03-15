#ifndef UTILS_H
#define UTILS_H

#define MAX_STRING_LENGTH 100

/* Função para ler uma string do utilizador */
void read_string(char *str, int max_length);

/* Função para validar um NIF */
int validate_nif(char *nif);

#endif
