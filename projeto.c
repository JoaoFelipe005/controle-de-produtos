#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_PRODUTOS 30
#define ARQUIVO "produtos.txt"

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    double preco;
    int quantidade;
} Produto;

int lerProdutos(Produto p[]) {
    FILE *arq = fopen(ARQUIVO, "r");
    if (!arq) return 0;
    int i = 0;
    while (i < MAX_PRODUTOS &&
           fscanf(arq, "%d %s %lf %d",
                  &p[i].codigo, p[i].nome, &p[i].preco, &p[i].quantidade) == 4) {
        i++;
    }
    fclose(arq);
    return i;
}

void imprimir(Produto p[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (int i = 0; i < total; i++)
        printf("%d  %s  R$%.2lf  Qt:%d\n",
               p[i].codigo, p[i].nome, p[i].preco, p[i].quantidade);
}

int buscar(Produto p[], int total, int codigo) {
    for (int i = 0; i < total; i++)
        if (p[i].codigo == codigo) return i;
    return -1;
}

void ordenarPorPreco(Produto p[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (p[j].preco > p[j+1].preco) {
                Produto tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
            }
        }
    }
    printf("Produtos ordenados por preco.\n");
}

void adicionar(Produto p[], int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Capacidade maxima atingida.\n");
        return;
    }

    int codigo;
    while (1) {
        printf("Codigo: ");
        if (scanf("%d", &codigo) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }
        if (buscar(p, *total, codigo) != -1) {
            printf("Codigo ja existente. Digite outro.\n");
            continue;
        }
        break;
    }
    p[*total].codigo = codigo;

    printf("Nome: ");
    scanf("%s", p[*total].nome);

    printf("Preco: ");
    scanf("%lf", &p[*total].preco);

    printf("Quantidade: ");
    scanf("%d", &p[*total].quantidade);

    (*total)++;
    printf("Produto adicionado.\n");
}

int main() {
    Produto estoque[MAX_PRODUTOS];
    int total = lerProdutos(estoque);
    int opcao, codigo, pos;

    do {
        printf("\n1-Adicionar  2-Buscar  3-Listar  4-Ordenar por preco  5-Sair\nOpcao: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            opcao = 0;
        }

        switch (opcao) {
            case 1:
                adicionar(estoque, &total);
                break;

            case 2:
                printf("Codigo: ");
                if (scanf("%d", &codigo) != 1) {
                    while (getchar() != '\n');
                    printf("Entrada invalida.\n");
                    break;
                }
                pos = buscar(estoque, total, codigo);
                if (pos == -1) printf("Produto nao encontrado.\n");
                else printf("%d %s R$%.2lf Qt:%d\n", estoque[pos].codigo, estoque[pos].nome, estoque[pos].preco, estoque[pos].quantidade);
                break;

            case 3:
                imprimir(estoque, total);
                break;

            case 4:
                ordenarPorPreco(estoque, total);
                imprimir(estoque, total);
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 5);

    return 0;
}
