/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 3 - Leia valores para um vetor de 10 posi��es por meio da fun��o leitura(), 
passando o vetor como ponteiro, imprimir quais valores s�o pares e quais s�o
�mpares, por meio das fun��es imprimepar() e imprimeimpar().
*/
#include<stdio.h>
#include<locale.h>

 void leitura (int *vetores, int quantidade);
 void imprimepar (int *vetpares, int quantidade);
 void imprimeimpar (int *vetimpares, int quantidade);
 
 int main () {
 	setlocale(LC_ALL, "Portuguese");
 	
 	int vet[10];
 	
 	//chamada das fun��es:
 	leitura (vet, 10); 
 	imprimepar (vet, 10);
 	imprimeimpar (vet, 10);
 	
 	return 0;
 }
  void leitura (int *vetores, int quantidade){ //fun��o que faz a leitura dos n�meros do vetor
  	 int i;
  	 
  	 printf("Digite 10 valores inteiros para o vetor:\n");
  	 for (i = 0; i < quantidade; i++){
  	 	scanf("%d", &vetores[i]);
    }
 }
  void imprimepar (int *vetpares, int quantidade){ //fun��o que verifica quais valores do vetor s�o pares
  	int i;
  	
  	printf("Valores pares do vetor inseridos pelo usu�rio:\n");
  	for (i = 0; i < quantidade; i++){
  		if (vetpares[i] % 2 == 0) 
  			printf("%d\n", vetpares[i]);
	  }
  }
   void imprimeimpar (int *vetimpares, int quantidade){ //fun��o que verifica quais valores do vetor s�o �mpares
  	int i;
  	
  	printf("Valores �mpares do vetor inseridos pelo usu�rio:\n");
  	for (i = 0; i < quantidade; i++){
  		if (vetimpares[i] % 2 == 1) 
  			printf("%d\n", vetimpares[i]);
	  }
  }
