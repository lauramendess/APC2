/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 3 - Leia valores para um vetor de 10 posicoes por meio da funcao leitura(), 
passando o vetor como ponteiro, imprimir quais valores sao pares e quais sao
impares, por meio das funcoes imprimepar() e imprimeimpar().
*/
#include<stdio.h>

 void leitura (int *vetores, int quantidade);
 void imprimepar (int *vetpares, int quantidade);
 void imprimeimpar (int *vetimpares, int quantidade);
 
 int main () {
	
	int vet[10];
	
	//chamada das funcoes:
	leitura (vet, 10); 
	imprimepar (vet, 10);
	imprimeimpar (vet, 10);
	
	return 0;
 }
  void leitura (int *vetores, int quantidade){ //funcao que faz a leitura dos numeros do vetor
	 int i;
	 
	 printf("Digite 10 valores inteiros para o vetor:\n");
	 for (i = 0; i < quantidade; i++){
		scanf("%d", &vetores[i]);
	}
 }
  void imprimepar (int *vetpares, int quantidade){ //funcao que verifica quais valores do vetor sao pares
	int i;
	
	printf("Valores pares do vetor inseridos pelo usuario:\n");
	for (i = 0; i < quantidade; i++){
		if (vetpares[i] % 2 == 0) 
			printf("%d\n", vetpares[i]);
	  }
  }
   void imprimeimpar (int *vetimpares, int quantidade){ //funcao que verifica quais valores do vetor sao impares
	int i;
	
	printf("Valores impares do vetor inseridos pelo usuario:\n");
	for (i = 0; i < quantidade; i++){
		if (vetimpares[i] % 2 == 1) 
			printf("%d\n", vetimpares[i]);
	  }
  }
