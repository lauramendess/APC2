/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 1 - Leia 10 números inteiros e armazene em um vetor. Por meio da função primo() e utilizando ponteiros imprima
na tela os elementos que são primos e suas respectivas posições no vetor. */
#include<stdio.h>
#include<locale.h>

#define TAM 10

void primo(int *vetor);  //declaração do protótipo da função que irá mostrar os números primos.

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int i, vet[TAM];
	
	printf("Digite 10 números inteiros:\n");  //preenchimento do array com números inseridos pelo usuário.
	for(i = 0; i < TAM; i++){
		scanf("%d", &vet[i]);
		printf("Vetor[%d] = %d\n", i, vet[i]);
	}
	
	primo(vet); //chamada da função que irá imprimir os números primos.
	
	return 0;
}
void primo(int *vetor){
	int i, j, cont;
	
	//for para verificar se o número é primo (divisível apenas por 1 e por ele mesmo).
	for (i = 0; i < TAM; i++){
		cont = 0;
	    for(j = 1; j <= *(vetor + i); j++){
	    	if (*(vetor + i) % j == 0){
			cont++;
	     }
      }
      if (cont == 2){
      	printf("\nO número %d na posição %d é primo!\n", *(vetor + i), i); //impressão dos números que são primos e suas respectivas posições.
	  }
	}
}
