#include <stdio.h>
#include <string.h>

struct Funcionario {
    char nome[50];
    float salarioBase;
    int horasExtras;
    float salarioFinal;
};

struct Funcionario funcionarios[100];
int contador = 0;

void cadastrarFuncionario() {
    printf("Nome: ");
    scanf("%s", funcionarios[contador].nome);

    printf("Salario base: ");
    scanf("%f", &funcionarios[contador].salarioBase);

    printf("Horas extras: ");
    scanf("%d", &funcionarios[contador].horasExtras);

    funcionarios[contador].salarioFinal =
        funcionarios[contador].salarioBase +
        (funcionarios[contador].horasExtras * 20);

    contador++;
}

void listarFuncionarios() {
    for (int i = 0; i < contador; i++) {
        printf("\nNome: %s", funcionarios[i].nome);
        printf("\nSalario final: %.2f", funcionarios[i].salarioFinal);

        if (funcionarios[i].salarioFinal <= 2000) {
            printf("\nClassificacao: Baixo\n");
        } else if (funcionarios[i].salarioFinal <= 4000) {
            printf("\nClassificacao: Medio\n");
        } else {
            printf("\nClassificacao: Alto\n");
        }
    }
}

int main() {
    int opcao;

    while (1) {
        printf("\n1 - Cadastrar funcionario");
        printf("\n2 - Listar funcionarios");
        printf("\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario();
                break;
            case 2:
                listarFuncionarios();
                break;
            case 0:
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }
}