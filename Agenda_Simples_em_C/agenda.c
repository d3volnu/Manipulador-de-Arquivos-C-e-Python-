#include <stdio.h>
#include <string.h>
#include "agenda.h"

void exibirMenu() {
    printf("+---------------------------+\n");
    printf("| Lista de Opções da Agenda |\n");
    printf("+---------------------------+\n");
    printf("| 1. Adicionar contato      |\n");
    printf("| 2. Listar contatos        |\n");
    printf("| 0. Sair                   |\n");
    printf("+---------------------------+\n");
}

void adicionarContato() {
    FILE *pont = fopen("agenda.txt", "a");
    if (pont == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char nome[100];
    char telefone[20];
    char email[150];

    printf("Informe um nome completo a ser adicionado: ");
    fgets(nome, sizeof(nome), stdin);
    printf("Informe um número de telefone a ser adicionado: ");
    fgets(telefone, sizeof(telefone), stdin);
    printf("Informe um e-mail a ser adicionado: ");
    fgets(email, sizeof(email), stdin);

    fputs("Nome: ", pont);
    fputs(nome, pont);
    fputs("Telefone: ", pont);
    fputs(telefone, pont);
    fputs("Email: ", pont);
    fputs(email, pont);

    fclose(pont);
    printf("Contato adicionado com sucesso!\n\n");
}

void listarContatos() {
    FILE *pont = fopen("agenda.txt", "r");
    if (pont == NULL) {
        printf("Agenda não existe. Informe algum contato primeiro!\n\n");
        return;
    }

    printf("--- Lista de Contatos ---\n");
    char linha[200];
    while (fgets(linha, sizeof(linha), pont) != NULL) {
        printf("%s", linha);
    }
    printf("-------------------------\n\n");

    fclose(pont);
}