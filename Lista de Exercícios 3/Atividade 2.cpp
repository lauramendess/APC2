/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 2 - Fa�a um programa que receba 20 n�meros inteiros e, utilizando a fun��o exibir(), mostre: Os n�meros pares
digitados; A soma dos n�meros pares digitados; Os n�meros �mpares digitados; A quantidade de n�meros
�mpares digitados. Acesse o vetor utilizando ponteiros.*/
#include<stdio.h>
#include<locale.h>

#define TAM 20

void exibir(int *vetor); //prot�tipo da fun��o que ir� mostrar as informa��es dos n�meros pares e �mpares.

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i, conjunto[TAM];
	
	printf("Digite 20 n�meros inteiros:\n"); //solicita ao usu�rio que digite 20 n�meros inteiros.
	for(i = 0; i < TAM; i++){
		scanf("%d", &conjunto[i]);
	}
	exibir(conjunto); //chamada da fun��o para exibir as informa��es sobre os n�meros pares e �mpares.
	
	return 0;
}

void exibir(int *vetor){
	int i, somapares = 0, qntimpares = 0;
	
	//exibe os n�meros pares digitados e calcula a soma deles.
	printf("N�meros pares digitados: ");
	for(i = 0; i < TAM; i++){
		if(*(vetor + i) % 2 == 0){
		  printf("%d ", *(vetor + i));
		  somapares += (*(vetor + i));
		}
		else 
		  qntimpares++;  //conta a quantidade de n�meros �mpares se n�o encontrar nenhuma par.
	}
	//exibe os n�meros �mpares digitados.
    printf("\nN�meros �mpares digitados: ");
	for(i = 0; i < TAM; i++){
		if(*(vetor + i) % 2 == 1)
		  printf("%d ", *(vetor + i));
	}
	//para mostrar ao usu�rio a soma dos n�meros pares e a quantidade de n�meros �mpares.
	printf("\nSoma dos n�meros pares digitados: %d\n", somapares);
	printf("Quantidade de n�meros �mpares digitados: %d\n", qntimpares);
}
