#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	char nome[50];
    char descricao[80];
    int quantidade, produto;
    
}Produto;

Produto produto[10];


void registrarProduto();
void listarProduto();
void realizarCompra();


int numProduto = 0;


int main () {
    int option;

    do {
        printf("---SuperMais Supermercado---\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produto\n");    
        printf("3- Realizar Compra\n");
        printf("0 - Sair\n");
        scanf("%d", &option);

        getchar(); 

        switch (option) {
            case 1:
                registrarProduto();
                break;
            case 2:
                listarProduto();
                break;
            case 3:
                realizarCompra();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");    
        }

    } while (option != 0);

    return 0;
}

void registrarProduto() {
	
    printf("-Nova Tarefa-\n");
    printf("Nome: ");
    scanf(" %[^\n]", produto[numProduto].nome);
    printf("Descricao: ");
    scanf(" %[^\n]", produto[numProduto].descricao);
    printf("Quantidade: ");
    scanf(" %d", &produto[numProduto].quantidade);
	
    numProduto++;

    printf("ENTER para continuar...");
    getchar();
}

void listarProduto() {
    
    printf("Itens em Estoque:\n");

    for (int i = 0; i < numProduto; i++) {
        printf("Nome     : %s\n", produto[i].nome);
        printf("Descricao: %s\n", produto[i].descricao);
        printf("Horario  : %d\n", produto[i].quantidade);
    }

	printf("ENTER para continuar...");
    getchar();
}

void realizarCompra() {
    
	int quantidade;
    printf("Itens em Estoque:\n");
    if (numProduto == 0) {
        printf("produto nao cadastrado\n");
    } 	
	else {
        printf("Quantidade em estoque: %d\n", produto[0].quantidade);
        printf("Quantidade para a compra: ");
        scanf("%d", &quantidade);

        produto[0].quantidade -= quantidade;
    }
    printf("ENTER para continuar...");
    getchar();
}