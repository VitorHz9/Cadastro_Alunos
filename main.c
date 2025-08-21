#include <stdio.h>
#include <stdlib.h>
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

void cadastrarAluno(struct Aluno alunos[], int *qtd) {
    printf("\n--- Cadastro de Aluno ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", alunos[*qtd].nome);
    printf("Idade: ");
    scanf("%d", &alunos[*qtd].idade);
    printf("Nota: ");
    scanf("%f", &alunos[*qtd].nota);

    (*qtd)++;
    printf("Aluno cadastrado com sucesso!\n");
}

void listarAlunos(struct Aluno alunos[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhum aluno cadastrado.\n");
    } else {
        printf("\n--- Lista de Alunos ---\n");
        for (int i = 0; i < qtd; i++) {
            printf("%d - Nome: %s | Idade: %d | Nota: %.2f\n",
                   i+1, alunos[i].nome, alunos[i].idade, alunos[i].nota);
        }
    }
}

int main() {
    struct Aluno alunos[50];
    int qtd = 0;
    int opcao;

    do {
        printf("\n==== MENU ====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarAluno(alunos, &qtd);
                break;
            case 2:
                listarAlunos(alunos, qtd);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}

