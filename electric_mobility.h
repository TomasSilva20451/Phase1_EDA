#ifndef ELECTRIC_MOBILITY_H
#define ELECTRIC_MOBILITY_H

#define MAX_ID_LENGTH 100
#define MAX_NAME_MOBILITY_LENGTH 100
#define MAX_LICENSE_PLATE_LENGTH 10
#define MAX_LOCATION_PLATE_LENGTH 100
#define MAX_PRICE_LENGTH 100
#define MAX_STOCK_LENGTH 100
#define MAX_RENT_LENGTH 100
#define MAX_AUTONOMY_LENGTH 100
#define MAX_BATTERY_LEVEL_LENGTH 100

#include "client.h"

/*
id: um número inteiro que representa o identificador único do objeto de mobilidade elétrica.
name: um ponteiro para uma matriz de caracteres que representa o nome do objeto de mobilidade elétrica.
license_plate: um ponteiro para uma matriz de caracteres que representa o número da placa do objeto de mobilidade elétrica.
localização: um ponteiro para uma matriz de caracteres que representa a localização atual do objeto de mobilidade elétrica.
preço: um flutuador que representa o custo do aluguer do objeto de mobilidade elétrica.
stock: um número inteiro que representa o número de objetos de mobilidade elétrica disponíveis para alugar.

aluguer: um flutuador que representa o custo do aluguel do objeto de mobilidade elétrica por hora.
autonomia: um flutuador que representa a distância que o objeto de mobilidade elétrica pode percorrer com uma única carga.
battery_level: um número inteiro que representa o nível atual da bateria do objeto de mobilidade elétrica.
em seguida: um ponteiro para o próximo objeto de mobilidade elétrica em uma lista vinculada de objetos de mobilidade elétrica.

Esta declaração typedef renomeia o electric_mobility struct como ElectricMobility para conveniência.*/
typedef struct electric_mobility
{
    int id;
    char *name;
    char *license_plate;
    char *location;
    float price;
    int stock;
    float rent;
    float autonomy;
    int battery_level;
    struct electric_mobility *next;
} ElectricMobility;

extern struct electric_mobility *mobility_head;

/*Estas são funções relacionadas com a gestão da mobilidade elétrica num serviço de aluguer:

int add_mobility(int id, char *name, char *license_plate, char *location, float price, int stock, float rent, float autonomy, int battery_level): Adiciona uma nova mobilidade elétrica ao serviço de aluguer. Ele leva em vários parâmetros como id, nome, license_plate, localização, preço, estoque, aluguel, autonomia e battery_level. Ele retorna um valor inteiro indicando se a adição foi bem-sucedida ou não.

void save_electric_mobility_data_to_file(char *filename): salva os dados de mobilidade elétrica em um arquivo. Ele recebe o nome do arquivo como parâmetro, abre o arquivo para gravação no modo binário e grava os dados de mobilidade elétrica no arquivo. Ele também imprime uma mensagem indicando se a operação foi bem-sucedida ou não.
void destroy_electric_mobility(ElectricMobility *em): liberta a memória alocada para um objeto de mobilidade elétrica. Ele recebe um ponteiro para o objeto de mobilidade elétrica e libera a memória associada a ele.

void read_electric_mobility_file(const char *filename): lê os dados de mobilidade elétrica de um arquivo. Ele recebe o nome do arquivo como parâmetro, abre o arquivo para leitura no modo binário, lê os dados de mobilidade elétrica do arquivo e cria uma lista vinculada de objetos de mobilidade elétrica.*/
int add_mobility(int id, char *name, char *license_plate, char *location, float price, int stock, float rent, float autonomy, int battery_level);
void save_electric_mobility_data_to_file(char *filename);
void destroy_electric_mobility(ElectricMobility *em);
void read_electric_mobility_file(const char *filename) ;



#endif /* ELECTRIC_MOBILITY_H */
