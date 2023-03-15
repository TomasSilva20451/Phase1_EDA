#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electric_mobility.h"
#include "client.h"
#include "manager.h"

int main() {
    int option;

    /* Carrega os dados dos meios de mobilidade elétrica a partir do ficheiro */
    load_electric_mobility_data_from_file("electric_mobility.txt");

    /* Carrega os dados dos clientes a partir do ficheiro */
    load_client_data_from_file("client.txt");

    /* Carrega os dados dos gestores a partir do ficheiro */
    load_manager_data_from_file("manager.bin");

    /* Loop do menu */
    do {
        printf("\n-- Menu --\n");
        printf("1. Adicionar um novo cliente\n");
        printf("2. Remover um cliente\n");
        printf("3. Alterar os dados de um cliente\n");
        printf("4. Registar o aluguer de um meio de mobilidade elétrica\n");
        printf("5. Listar os meios de mobilidade elétrica por ordem decrescente de autonomia\n");
        printf("6. Listar os meios de mobilidade elétrica existentes numa localização com determinado geocódigo\n");
        printf("7. Adicionar um novo gestor\n");
        printf("8. Remover um gestor\n");
        printf("9. Alterar os dados de um gestor\n");
        printf("10. Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &option);
        getchar();  /* Limpa o buffer do teclado */

        switch(option) {
            case 1:
                add_new_client();
                break;
            case 2:
                remove_client();
                break;
            case 3:
                alter_client_data();
                break;
            case 4:
                register_rental();
                break;
            case 5:
                list_electric_mobility_by_autonomy_descending_order();
                break;
            case 6:
                list_electric_mobility_by_location();
                break;
            case 7:
                add_new_manager();
                break;
            case 8:
                remove_manager();
                break;
            case 9:
                alter_manager_data();
                break;
            case 10:
                printf("A sair do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (option != 10);

    /* Grava os dados dos meios de mobilidade elétrica no ficheiro */
    save_electric_mobility_data_to_file("electric_mobility.txt");

    /* Grava os dados dos clientes no ficheiro */
    save_client_data_to_file("client.txt");

    /* Grava os dados dos gestores no ficheiro */
    save_manager_data_to_file("manager.bin");

    return 0;
}
