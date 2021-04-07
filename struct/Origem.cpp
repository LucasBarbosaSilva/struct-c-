#include <stdio.h>
#include <stdlib.h>


int main()
{
	struct tp_aluno {
		char nome[20];
		int matricula;
		float nota;
		int faltas;
	};

	tp_aluno aluno[2]; /* Em c++ não é necessário por o nome struct na frente de "tp_aluno", mas em C é. */

	FILE *arq, *arqb;
	errno_t erro1, erro2;

	erro1 = fopen_s(&arq, "arquivo.txt", "w" );
	erro2 = fopen_s(&arqb, "arquivo.bin", "w");

	for (int i = 0; i < 2; i++) {
		printf("Entrada de Dados:\n");
		printf("Nome: "); scanf_s("%19s", aluno[i].nome, 20);
		printf("Matrícula: "); scanf_s("%d", &aluno[i].matricula);
		printf("Nota: "); scanf_s("%f ", &aluno[i].nota);
		printf("Faltas: "); scanf_s("%d ", &aluno[i].faltas);

		fprintf(arq, "%s ", aluno[i].nome);
		fprintf(arq, "%d ", aluno[i].matricula);
		fprintf(arq, "%6.2f ", aluno[i].nota);
		fprintf(arq, "%d \n", aluno[i].faltas);

		/*fwrite(&aluno[i], sizeof(tp_aluno), 1, arqb);*/
	}

	fclose(arq);
	fclose(arqb);
	/*
	for (int i = 0; i < 2; i++) {
		printf("Entre com os dados do aluno\n");
		printf("Nome: %s", aluno[i].nome);
		printf("Matrícula: %d", aluno[i].matricula);
		printf("Nota: %f", aluno[i].nota);
		printf("Faltas: %d", aluno[i].faltas);
	}*/


	return 0;
}

