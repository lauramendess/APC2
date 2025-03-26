/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 3 - Leia valores para um vetor de 10 posições por meio da função leitura(), 
passando o vetor como ponteiro, imprimir quais valores são pares e quais são
ímpares, por meio das funções imprimepar() e imprimeimpar().
*/
#include<stdio.h>
#include<locale.h>

 void leitura (int *vetores, int quantidade);
 void imprimepar (int *vetpares, int quantidade);
 void imprimeimpar (int *vetimpares, int quantidade);
 
 int main () {
 	setlocale(LC_ALL, "Portuguese");
 	
 	int vet[10];
 	
 	//chamada das funções:
 	leitura (vet, 10); 
 	imprimepar (vet, 10);
 	imprimeimpar (vet, 10);
 	
 	return 0;
 }
  void leitura (int *vetores, int quantidade){ //função que faz a leitura dos números do vetor
  	 int i;
  	 
  	 printf("Digite 10 valores inteiros para o vetor:\n");
  	 for (i = 0; i < quantidade; i++){
  	 	scanf("%d", &vetores[i]);
    }
 }
  void imprimepar (int *vetpares, int quantidade){ //função que verifica quais valores do vetor são pares
  	int i;
  	
  	printf("Valores pares do vetor inseridos pelo usuário:\n");
  	for (i = 0; i < quantidade; i++){
  		if (vetpares[i] % 2 == 0) 
  			printf("%d\n", vetpares[i]);
	  }
  }
   void imprimeimpar (int *vetimpares, int quantidade){ //função que verifica quais valores do vetor são ímpares
  	int i;
  	
  	printf("Valores ímpares do vetor inseridos pelo usuário:\n");
  	for (i = 0; i < quantidade; i++){
  		if (vetimpares[i] % 2 == 1) 
  			printf("%d\n", vetimpares[i]);
	  }
  }
