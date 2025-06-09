#include <stdio.h>

typedef struct aluno {
	char nome[50];
	int idade;
	int alunos;
	float nota;
}Aluno;

Aluno alunos[3];

void listarAlunos ();

int main (){

	for(int i = 0; i <3; i++) {
		printf("Informe os dados do aluno:\n");
		printf("Nome:");
		scanf("%s",alunos[i].nome);
		printf("Idade:");
		scanf("%d",&alunos[i].idade);
		printf("Nota:");
		scanf("%.2f",&alunos[i].nota);
	}
	return 0;
}
