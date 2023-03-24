#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

/*cria um pointer NULL para o início de uma linked list de objetos struct client, 
que pode ser usado para armazenar informações sobre clientes*/
struct client *clients_head = NULL;

// add_client
/*função que adiciona um novo cliente a uma lista de clientes vinculada individualmente.
 A função cria um novo nó de cliente, atribui as informações do cliente
  aos campos do nó e, em seguida, adiciona o nó ao final da linked list.
   Se a linked list estiver vazia, o novo nó se tornará o chefe da linked list.
    A função retorna void e, se houver um erro alocando memória para o novo nó,
    uma mensagem de erro é impressa.*/
void add_client(char *name, int phone_number, char *email, int nif)
{
    struct client *new_client = malloc(sizeof(struct client));
    if (new_client == NULL)
    {
        printf("Erro ao alocar memória para novo cliente\n");
        return;
    }
    strcpy(new_client->name, name);
    new_client->phone_number = phone_number;
    strcpy(new_client->email, email);
    new_client->nif = nif;
    new_client->next = NULL;
    if (clients_head == NULL)
    {
        clients_head = new_client;
        return;
    }

    struct client *current = clients_head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_client;
}

// list_clients
/*Imprime informações
 sobre todos os clientes em uma lista vinculada. A função itera através da lista vinculada
  usando um loop while e imprime o nome, e-mail, número de telefone e NIF do cliente 
  para cada nó na lista. A função pressupõe que uma variável global clients_head 
  aponta para o cabeçalho da lista vinculada. A função não modifica a lista vinculada 
  nem retorna quaisquer valores.*/
void list_clients(char *name, int phone_number, char *email, int nif)
{
    struct client *current = clients_head;
    // while loop
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone number: %d\n", current->phone_number);
        printf("NIF: %d\n", current->nif);
        printf("\n");
        current = current->next;
    }
}

// remove_client
void remove_client(int nif)
{
    struct client *current = clients_head;
    struct client *previous = NULL;

    while (current != NULL)
    {
        if (current->nif == nif)
        {
            if (previous == NULL)
            {
                clients_head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// update_client_data
/*função que atualiza o e-mail e o número de telefone de um
cliente com um determinado NIF em uma lista vinculada individualmente.
A função usa três argumentos: o NIF (um inteiro) do cliente
 e o novo e-mail e número de telefone (strings).
 A função começa no topo da lista vinculada
  e itera através de cada nó usando um loop while.
   Para cada nó, a função verifica se o campo nif do nó corresponde
   o NIF dado. Se for encontrada uma correspondência, a função é atualizada
   o campo de e-mail do nó com a nova string de e-mail usando o strcpy
   e atualiza o campo de phone_number do nó com o novo telefone
    string numérica convertida em um inteiro usando a função atoi.
    Em seguida, a função imprime uma mensagem de sucesso e retorna.
    Se nenhuma correspondência for encontrada para o NIF fornecido, a função imprime um erro
     mensagem e devoluções.*/
void update_client_data(int nif, char *new_email, char *new_phone_number)
{
    struct client *current = clients_head;
    while (current != NULL)
    {
        // Esta é uma instrução condicional que compara o valor do parâmetro nif 
        // com o campo nif do objeto struct client apontado pelo ponteiro atual.
        if (current->nif == nif)
        {
            /*A função strcpy() é usada para copiar o conteúdo da cadeia de caracteres new_email 
            para o campo de e-mail do objeto struct client apontado pela corrente. 
            Isso atualiza o endereço de e-mail do cliente.

            A função atoi() é usada para converter a cadeia de caracteres new_phone_number 
            (contém um valor numérico) em um inteiro, 
            ue é então atribuído ao campo phone_number do objeto struct client apontado pela corrente. 
            Isso atualiza o número de telefone do cliente. */
            strcpy(current->email, new_email);
            current->phone_number = atoi(new_phone_number);
            printf("Dados do cliente atualizados com sucesso.\n");
            return;
        }
        current = current->next;
    }
    printf("NIF do cliente não encontrado.\n");
}

// load_clients file
/*função que lê dados do cliente de um arquivo binário e cria uma
 lista de clientes individualmente vinculada. 
 A função retorna um apontador para o cabeçalho da lista vinculada.

   A função primeiro tenta abrir o arquivo no modo binário usando 
   a função fopen. Se o ficheiro não puder ser aberto, a função imprime 
   uma mensagem de erro e retorna NULL. 
   
   Em seguida, a função lê os dados do cliente 
   do arquivo usando a função fread, que lê um número fixo de 
   bytes do arquivo para o buffer especificado. 

   A função lê o nome do cliente, e-mail, número de telefone, 
   e NIF, por esta ordem, e utiliza o add_client 
   para criar um novo nó de cliente com os dados lidos.
    A função repete esse processo até que o final do arquivo seja alcançado. 
    Finalmente, a função fecha o arquivo usando a função fclose e retorna 
    um apontador para o cabeçalho da lista vinculada.*/
Client *load_clients(char *filename)
{
    // Tenta abrir o arquivo no modo binário
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL];
    char phone_number[15];
    char nif[20];

    /* A função lê o nome do cliente, e-mail, número de telefone, 
   e NIF, por esta ordem, e utiliza o add_client */

    while (fread(name, MAX_NAME_LENGTH - 1, 1, fp) == 1)
    {
        name[MAX_NAME_LENGTH - 1] = '\0';
        fread(email, MAX_EMAIL - 1, 1, fp);
        email[MAX_EMAIL - 1] = '\0';
        fread(phone_number, MAX_PHONE_NUMBER_LENGTH - 1, 1, fp);
        phone_number[MAX_PHONE_NUMBER_LENGTH - 1] = '\0';
        fread(nif, MAX_NIF_LENGTH - 1, 1, fp);
        nif[MAX_NIF_LENGTH - 1] = '\0';

        add_client(name, atoi(phone_number), email, atoi(nif));
    }

    fclose(fp);
    return clients_head;
}

// save_client_data_to_file
/*Esta função salva os dados do cliente em um arquivo binário especificado pelo parâmetro filename. 
Ele abre o arquivo no modo de gravação e grava os dados de cada cliente de forma sequencial usando fwrite().
 Ele também formata o número de telefone e NIF como strings antes de gravá-los no arquivo usando snprintf(). 
Finalmente, ele imprime uma mensagem de sucesso e fecha o arquivo usando fclose().*/
void save_client_data_to_file(char *filename)
{
    // salva os dados do cliente em um arquivo binário pelo parâmetro filename
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    struct client *current = clients_head;
    while (current != NULL)
    {
        // grava os dados de cada cliente de forma sequencial usando fwrite()
        fwrite(current->name, MAX_NAME_LENGTH - 1, 1, fp);
        fwrite(current->email, MAX_EMAIL - 1, 1, fp);
        char phone_number[MAX_PHONE_NUMBER_LENGTH];
        snprintf(phone_number, MAX_PHONE_NUMBER_LENGTH, "%d", current->phone_number);
        fwrite(phone_number, MAX_PHONE_NUMBER_LENGTH - 1, 1, fp);
        char nif[MAX_NIF_LENGTH];
        snprintf(nif, MAX_NIF_LENGTH, "%d", current->nif);
        fwrite(nif, MAX_NIF_LENGTH - 1, 1, fp);
        current = current->next;
    }
    
    printf("Client  data saved to file %s.\n", filename);
    fclose(fp);
}
