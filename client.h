#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNTS 5
#define MAX_EMAIL 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_NIF_LENGTH 20
typedef struct client
{
    char name[100];
    int phone_number;
    char email[100];
    int nif;
    struct client *next;
} Client;

/*Esta é uma declaração externa de uma variável chamada clients_head do tipo struct client *.
 Esta variável é declarada como externa para indicar que está definida em outro arquivo de origem, 
 e permite que outros arquivos de origem acessem e usem. */
extern struct client *clients_head;

// add_client
/*Um protótipo de função é uma declaração de uma função que fornece o nome da função,
 tipo de retorno e tipos de parâmetro para o compilador, mas não contém a implementação real da função. 
 Ele é usado para informar o compilador sobre a existência de uma função para que ela possa ser chamada de outras partes do programa.*/
void add_client(char *name, int phone_number, char *email, int nif);

// save_client_data_to_file
/*A função save_client_data_to_file é usada para salvar os dados de todos os clientes em um arquivo 
com o nome especificado. 
A função usa um ponteiro para um nome de arquivo de cadeia de caracteres como entrada e não retorna nada.
 A função abre o arquivo no modo de gravação binária e grava os dados de cada cliente para o 
 arquivo um por um usando a função fwrite(). 
 Depois de gravar todos os dados no arquivo, ele fecha o arquivo e imprime uma mensagem indicando 
 que os dados do cliente foram salvos no arquivo.*/
void save_client_data_to_file(char *filename) ;


Client *new_client(char *name, char *address, int phone_number, int nif);

/*Esta função adiciona uma nova conta a um determinado cliente. 
É preciso um ponteiro para o cliente ao qual a conta deve ser adicionada, 
bem como o número da conta e o saldo inicial.*/
void add_account(Client *client, int account_number, double balance);

/* Esta função salva uma matriz de clientes em um arquivo. 
Ele leva o nome do arquivo para o qual os clientes devem ser salvos, 
um ponteiro para uma matriz de ponteiros de cliente e o número de clientes na matriz.*/
void save_clients(char *filename, Client **clients, int num_clients);

Client *load_clients(char *filename);

#endif /* CLIENT_H */
