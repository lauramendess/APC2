/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 5 - Faça um programa que leia um vetor de 15 posições e o compacte, ou seja, elimine as posições com valor
zero. Para isso, todos os elementos a frente do valor zero, devem ser movidos uma posição para trás no vetor
por meio da função compacta() utilizando ponteiros para acessar as posições. */
#include<stdio.h>
#include<locale.h>

#define TAM 15
//declaração do protótipo da função que irá compactar o vetor, eliminando as posições com valor zero
void compacta(int *vetor);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i, vet[15];
	 
	printf("Insira 15 números inteiros para um conjunto:\n"); //pede ao usuário que insira 15 números para preencher o vetor.
	for(i = 0; i < TAM; i++){
	  scanf("%d", &vet[i]);
	}
	compacta(vet); //chamada da função que irá eliminar as posições com zero.
	
	return 0;
}
void compacta(int *vetor){
	int i, j, novotam = TAM;
	
	//loop que verifica se há posições com zero.
	for(i = 0; i < novotam; i++){
		if(*(vetor + i) == 0){
			for(j = i; j < novotam - 1; j++){
				*(vetor + j) = *(vetor + j + 1);
			}
			novotam--; //após a eliminação das posições que contém zeros, o tamanho do vetor é ajustado.
			i--;      //i é decrementado para garantir que a posição seja verificada novamente, evitando que um outro zero a tenha ocupado!
		}
    }
    for(i = 0; i < novotam; i++){
    	printf("%d ", *(vetor + i));
	}
}
