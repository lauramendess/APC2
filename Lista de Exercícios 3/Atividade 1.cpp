/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 1 - Leia 10 n�meros inteiros e armazene em um vetor. Por meio da fun��o primo() e utilizando ponteiros imprima
na tela os elementos que s�o primos e suas respectivas posi��es no vetor. */
#include<stdio.h>
#include<locale.h>

#define TAM 10

void primo(int *vetor);  //declara��o do prot�tipo da fun��o que ir� mostrar os n�meros primos.

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int i, vet[TAM];
	
	printf("Digite 10 n�meros inteiros:\n");  //preenchimento do array com n�meros inseridos pelo usu�rio.
	for(i = 0; i < TAM; i++){
		scanf("%d", &vet[i]);
		printf("Vetor[%d] = %d\n", i, vet[i]);
	}
	
	primo(vet); //chamada da fun��o que ir� imprimir os n�meros primos.
	
	return 0;
}
void primo(int *vetor){
	int i, j, cont;
	
	//for para verificar se o n�mero � primo (divis�vel apenas por 1 e por ele mesmo).
	for (i = 0; i < TAM; i++){
		cont = 0;
	    for(j = 1; j <= *(vetor + i); j++){
	    	if (*(vetor + i) % j == 0){
			cont++;
	     }
      }
      if (cont == 2){
      	printf("\nO n�mero %d na posi��o %d � primo!\n", *(vetor + i), i); //impress�o dos n�meros que s�o primos e suas respectivas posi��es.
	  }
	}
}
