#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pizza
{
    char nome[30];
    float vl;
};
struct cliente
{
    char numero[20],nome[30],cpf[20];
    float vl;
};

struct pizza pizzas[20];
struct cliente clientes[20];

int nomepizza = 0;
int nomecliente = 0;

void cadastrarpizza();
void cadastrarcliente();
void listarpizzas();
void listarclientes();
void venderpizza();

int main(){
    int option;
    do{
        printf("<<< Nostra Pizza >>>\n");
        printf("1 - Cadastrar pizza\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Listar pizzas\n");
        printf("4 - Listar clientes\n");
        printf("5 - Vender\n");
        printf("0 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            cadastrarpizza();
            break;
        case 2:
            cadastrarcliente();
            break;
        case 3:
            listarpizzas();
            break;
        case 4:
            listarclientes();
            break;
        case 5:
            venderpizza();
            break;
        case 0:
            printf("Fechando sistema...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
        printf("\nENTER para continuar\n");
        getchar();
        getchar();
    }while (option!=0);
    return 0;
}
void cadastrarpizza(){
    printf("Digite o nome da pizza:\n");
    scanf("%s",pizzas[nomepizza].nome);
    printf("Digite o valor da pizza:\n");
    scanf("%f",&pizzas[nomepizza].vl);
    nomepizza++;
}
void cadastrarcliente(){
    printf("Digite o nome do cliente:\n");
    scanf("%s",clientes[nomecliente].nome);
    printf("Digite o cpf do cliente:\n");
    scanf("%s",clientes[nomecliente].cpf);
    printf("Digite o numero de telefone:\n");
    scanf("%s",clientes[nomecliente].numero);
    nomecliente++;
}
void listarpizzas(){
    for(int i=0;i<nomepizza;i++){
        printf("Nome: %s\n",pizzas[i].nome);
        printf("Valor: %.2f\n\n",pizzas[i].vl);
    }
}
void listarclientes(){
    for(int i=0;i<nomecliente;i++){
        printf("Nome: %s\n",clientes[i].nome);
        printf("CPF: %s\n",clientes[i].cpf);
        printf("Numero: %s\n",clientes[i].numero);
        printf("Valor gasto: %.2f\n\n",clientes[i].vl);
    }
}
void vender(){
    char cpf[20];
    int contador = 0;
    printf("Digite o CPF do cliente:\n");
    scanf("%s",cpf);
    for(int i=0;i<nomecliente;i++){
        if(strcmp(cpf,clientes[i].cpf)==0){
            do{
            char nome[30];
            int quant;
        	printf("Digite o nome da pizza que deseja comprar:\n");
            scanf("%s",nome);
                for(int i = 0;i<nomepizza;i++){
                    if(strcmp(nome,pizzas[i].nome)==0){
                        printf("Valor: %.2f\n",pizzas[i].vl);
                        printf("Digite a quantidade que deseja comprar:\n");
                        scanf("%d",&quant);
                        printf("Compra realizada\n");
                        printf("Valor total de %d pizzas %s: %.2f",quant,pizzas[i].nome,pizzas[i].vl*quant);
                        clientes[i].vl=pizzas[i].vl*quant;
                        contador = 1;
                        return;
                    }
                }
                printf("A pizza nao encontrada\n");
            }while(contador == 0);
        }
    }
    printf("O usuario nao foi encontrado\n");
}