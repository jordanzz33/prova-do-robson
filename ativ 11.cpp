#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CD{
    char genero[20], banda[20];
    int ano, quant, id;
    float vl;
};

struct CD cds[20];

int nomecd = 0;

void cadastrar();
void vender();
void filtrar();
void consultar();

int main(){
    int option;
    do{
    	printf("\033[34m");
        printf("--- Som & Arte ---\n");
        printf("\033[0m");
        printf("1 - Cadastrar CD\n");
        printf("2 - Vender CD\n");
        printf("3 - Filtrar por banda\n");
        printf("4 - Consultar estoque\n");
        printf("0 - Sair\n");
        printf("Informe sua opcao: ");
        scanf("%d",&option);
        system("cls");

        switch (option)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            vender();
            break;
        case 3:
            filtrar();
            break;
        case 4:
            consultar();
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
        printf("\nENTER para continuar\n");
        getchar();
        getchar();
    }while (option!=0);
    return 0;
}
void cadastrar(){
    printf("Digite o genero do CD:\n");
    scanf("%s",cds[nomecd].genero);
    printf("Digite a banda do CD:\n");
    scanf("%s",cds[nomecd].banda);
    printf("Digite o ano do CD:\n");
    scanf("%d",&cds[nomecd].ano);
    printf("Digite a quantidade de copias que serao cadastradas:\n");
    scanf("%d",&cds[nomecd].quant);
    printf("Digite o valor de cada copia:\n");
    scanf("%f",&cds[nomecd].vl);
    printf("CD cadastrado no ID: %d!\n",nomecd);
    cds[nomecd].id = nomecd;
    nomecd++;
}
void vender(){
    int id, quant;
    printf("Digite o ID do CD para vender:\n");
    scanf("%d",&id);
    for(int i=0;i<nomecd;i++){
        if(id==cds[i].id){
        printf("Digite a quanitdade desejada para a venda:\n");
        scanf("%d",&quant);
            if(quant<=cds[i].quant){
                cds[i].quant-=quant;
                printf("CD(s) vendidos!\n");
                printf("Banda do CD: %s\n",cds[i].banda);
                printf("Genero do CD: %s\n",cds[i].genero);
                printf("Ano do CD: %d\n",cds[i].ano);
                printf("Quantidade vendida: %d\n",quant);
                printf("Valor da unidade: %.2f\n",cds[i].vl);
                printf("Valor total da venda: %.2f\n",cds[i].vl*quant);
                printf("Copias restantes em estoque: %d\n",cds[i].quant);
            }else{
                printf("Nao e possivel vender essa quantidade de copias!\n");
                printf("Copias restantes: %d\n",cds[i].quant);
            }
            return;
        }
    }
    printf("CD nao encontrado!\n");
}
void filtrar(){
    char banda[20];
    int contador = 0;
    printf("Digite a banda que deseja usar para filtrar:\n");
    scanf("%s",banda);
    for(int i=0;i<nomecd;i++){
        if(strcmp(banda,cds[i].banda)==0){
            printf("Genero do CD: %s\n",cds[i].genero);
            printf("Ano do CD: %d\n",cds[i].ano);
            printf("Valor da unidade: %.2f\n",cds[i].vl);
            printf("Copias restantes em estoque: %d\n",cds[i].quant);
            contador=1;
        }
    }
    if(contador==0){
        printf("Nenhum CD dessa banda encontrado\n");
    }
}
void consultar(){
    int id;
    printf("Digite o ID do CD que deseja vender:\n");
    scanf("%d",&id);
    for(int i=0;i<nomecd;i++){
        if(id==cds[i].id){
            printf("CD encontrado\n");
            printf("As copias restantes sao: %d\n",cds[i].quant);
            return;
        }
    }
    printf("CD nao encontrado\n");
}