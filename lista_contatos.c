#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

void inserir_contato(Contato **ptr_contatos, int *tamanho);

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