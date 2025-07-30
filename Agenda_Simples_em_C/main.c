#include <stdio.h>
#include "agenda.h"

int main() {
    int menu = -1;

    exibirMenu();

    do {
        printf("Sua escolha: ");
        scanf("%d", &menu);
        getchar();
        printf("\n");

        switch (menu) {
            case 0:
                printf("Encerrando manipulador de arquivos...\n");
                break;
            case 1:
                adicionarContato();
                break;
            case 2:
                listarContatos();
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (menu != 0);

    return 0;
}


