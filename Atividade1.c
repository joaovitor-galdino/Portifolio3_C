#include <stdio.h>
#include <string.h>

struct Venda {
    char produto[50];
    int quantidade;
    float valorUnitario;
    float total;
};
struct Venda vendas[100];
int contador = 0;

void cadastrarVenda() {
    printf("Nome do produto: ");
    scanf("%s", vendas[contador].produto);

    printf("Quantidade: ");
    scanf("%d", &vendas[contador].quantidade);

    printf("Valor unitario: ");
    scanf("%f", &vendas[contador].valorUnitario);
    vendas[contador].total = vendas[contador].quantidade * vendas[contador].valorUnitario;
    if (vendas[contador].total > 100) {
        vendas[contador].total *= 0.9;
    }

    contador++;
}

void listarVendas() {
    float totalGeral = 0;

    for (int i = 0; i < contador; i++) {
        printf("\nProduto: %s", vendas[i].produto);
        printf("\nQuantidade: %d", vendas[i].quantidade);
        printf("\nTotal: %.2f\n", vendas[i].total);

        totalGeral += vendas[i].total;
    }

    printf("\nTotal Geral: %.2f\n", totalGeral);
}

int main() {
    int opcao;

    while (1) {
        printf("\n1 - Cadastrar venda");
        printf("\n2 - Listar vendas");
        printf("\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVenda();
                break;
            case 2:
                listarVendas();
                break;
            case 0:
                return 0;
            default:
                printf("opcao invalida\n");
        }
    }
}
