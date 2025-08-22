#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

void inserir_contato(Contato **ptr_contatos, int *tamanho);
void listar_contatos(Contato *ptr_contatos, int tamanho);
void buscar_contato(Contato *ptr_contatos, int tamanho);
void remover_contato(Contato **ptr_contatos, int *tamanho);

int main()
{
    Contato *contatos = NULL;
    int opcao = 0, tamanho = 0;

    while(opcao != 5) {
        puts("1 - Inserir novo contato");
        puts("2 - Listar todos os contatos");
        puts("3 - Buscar um contato");
        puts("4 - Remover um contato");
        puts("5 - Sair");
        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                inserir_contato(&contatos, &tamanho);
                break;
            case 2:
                listar_contatos(contatos, tamanho);
                break;
            case 3:
                buscar_contato(contatos, tamanho);
                break;
            case 4:
                remover_contato(&contatos, &tamanho);
                break;
            case 5:
                free(contatos);
                return 0;
            default:
                printf("Opcao invalida!\n\n");
                break;
        }
    }

    return 0;
}

void inserir_contato(Contato **ptr_contatos, int *tamanho) {
    char nome[50], telefone[20];

    printf("\nDigite o nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o telefone: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    Contato *tmp = realloc(*ptr_contatos, ((*tamanho) + 1) * sizeof(Contato));

    if (tmp == NULL) {
        printf("Erro ao alocar memoria!\n\n");
        return;
    }
    *ptr_contatos = tmp;
    
    strcpy((*ptr_contatos + *tamanho)->nome, nome);
    strcpy((*ptr_contatos + *tamanho)->telefone, telefone);

    (*tamanho)++;

    printf("\nContato cadastrado!\n\n");
}

void listar_contatos(Contato *ptr_contatos, int tamanho) {
    
    if (tamanho == 0) {
        printf("\nNenhum contato cadastrado!\n\n");
        return;
    }

    printf("\n--- Lista de Contatos ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d) Nome: %s | Telefone: %s\n", i + 1, ptr_contatos[i].nome, ptr_contatos[i].telefone);
    }
    printf("-----------------------------------------------------------\n\n");
}

void buscar_contato(Contato *ptr_contatos, int tamanho) {
    char contato[50];

    printf("Nome do contato a ser buscado: ");
    fgets(contato, sizeof(contato), stdin);
    contato[strcspn(contato, "\n")] = '\0';

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(ptr_contatos[i].nome, contato) == 0) {
            printf("\n--- Contato encontrado ---\n");
            printf("Nome: %s | Telefone: %s\n", ptr_contatos[i].nome, ptr_contatos[i].telefone);
            printf("-----------------------------------------------------------------------\n\n");
            return;
        }
    }

    printf("\nContato nao encontrado!\n\n");
}

void remover_contato(Contato **ptr_contatos, int *tamanho) {
    char contato[50];

    printf("Nome do contato a ser removido: ");
    fgets(contato, sizeof(contato), stdin);
    contato[strcspn(contato, "\n")] = '\0';

    for (int i = 0; i < *tamanho; i++) {
        if (strcmp((*ptr_contatos)[i].nome, contato) == 0) {

            for (int j = i; j < (*tamanho) - 1; j++) {
                (*ptr_contatos)[j] = (*ptr_contatos)[j + 1];
            }

            (*tamanho)--;

            Contato *tmp = realloc((*ptr_contatos), (*tamanho) * sizeof(Contato));

            if (tmp == NULL) {
                printf("\nAlocacao de memoria falhou!\n");
                return;
            }

            *ptr_contatos = tmp;

            printf("\nContato removido!\n");
            printf("-----------------------------------------------------------------\n\n");
            return;
        }
    }

    printf("\nContato nao encontrado!\n");
    printf("-----------------------------------------------------------------\n\n");
}