/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 2 - Faça um programa que receba 20 números inteiros e, utilizando a função exibir(), mostre: Os números pares
digitados; A soma dos números pares digitados; Os números ímpares digitados; A quantidade de números
ímpares digitados. Acesse o vetor utilizando ponteiros.*/
#include<stdio.h>
#include<locale.h>

#define TAM 20

void exibir(int *vetor); //protótipo da função que irá mostrar as informações dos números pares e ímpares.

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i, conjunto[TAM];
	
	printf("Digite 20 números inteiros:\n"); //solicita ao usuário que digite 20 números inteiros.
	for(i = 0; i < TAM; i++){
		scanf("%d", &conjunto[i]);
	}
	exibir(conjunto); //chamada da função para exibir as informações sobre os números pares e ímpares.
	
	return 0;
}

void exibir(int *vetor){
	int i, somapares = 0, qntimpares = 0;
	
	//exibe os números pares digitados e calcula a soma deles.
	printf("Números pares digitados: ");
	for(i = 0; i < TAM; i++){
		if(*(vetor + i) % 2 == 0){
		  printf("%d ", *(vetor + i));
		  somapares += (*(vetor + i));
		}
		else 
		  qntimpares++;  //conta a quantidade de números ímpares se não encontrar nenhuma par.
	}
	//exibe os números ímpares digitados.
    printf("\nNúmeros ímpares digitados: ");
	for(i = 0; i < TAM; i++){
		if(*(vetor + i) % 2 == 1)
		  printf("%d ", *(vetor + i));
	}
	//para mostrar ao usuário a soma dos números pares e a quantidade de números ímpares.
	printf("\nSoma dos números pares digitados: %d\n", somapares);
	printf("Quantidade de números ímpares digitados: %d\n", qntimpares);
}
