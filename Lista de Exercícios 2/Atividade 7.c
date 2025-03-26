/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios 2 de APC2 e LAB2

Exercicio 7 - Escreva um programa que le tres numeros inteiros do teclado e, utilizando uma funcao e
acessando os numeros no vetor por meio de ponteiros, ordene os tres numeros e imprima-os
em ordem crescente. */

#include<stdio.h>

void ordem_crescente(int *n1, int *n2, int *n3); //prototipo da funcao que ira imprimir tres numeros em ordem crescente.

int main (){
	
	//declaracao de variaveis para os tres numeros que serao inseridos pelo usuario.
	int num1, num2, num3;
	
	printf("Digite o primeiro numero:\n");
	scanf("%d", &num1);
		
	printf("Digite o segundo numero:\n");
	scanf("%d", &num2);
		
	printf("Digite o terceiro numero:\n");
	scanf("%d", &num3);
	
	ordem_crescente(&num1, &num2, &num3); //chamada da funcao que ira organizar os numeros inseridos em ordem crescente.
	
	return 0;
}
//funcao para organizar os numeros digitados pelo usuario em ordem crescente.
void ordem_crescente(int *n1, int *n2, int *n3){
	int aux;
	
	//ira verificar e realizar as trocas para garantir que os numeros estejam na ordem: n1, n2 e n3.
	if (*n1 > *n2){
	  aux = *n1;
	  *n1 = *n2;
	  *n2 = aux;	
	}
	
	if (*n1 > *n3){
	  aux = *n1;
	  *n1 = *n3;
	  *n3 = aux;	
	}
	
	if (*n2 > *n3){
	  aux = *n2;
	  *n2 = *n3;
	  *n3 = aux;	
	}
	
	//imprime os numeros em ordem crescente.
	printf("Ordem crescente: %d %d %d\n", *n1, *n2, *n3);
}
