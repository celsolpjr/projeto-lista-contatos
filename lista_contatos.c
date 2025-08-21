#include <stdio.h>

typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

void inserir_contato(Contato **ptr_contatos, int *tamanho);

int main()
{
    Contato *contatos;
    int opcao = 0, tamanho = 0;

    while(opcao != 5) {
        puts("1 - Inserir novo contato");
        puts("2 - Listar todos os contatos");
        puts("3 - Buscar um contato");
        puts("4 - Remover um contato");
        puts("5 - Sair");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserir_contato(&contatos, &tamanho);
                break;
            case 5:
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

    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("Digite o telefone: ");
    scanf("%s", telefone);

    
}