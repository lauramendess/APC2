/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios 2 de APC2 e LAB2

Exercício 7 - Escreva um programa que lê três números inteiros do teclado e, utilizando uma função e
acessando os números no vetor por meio de ponteiros, ordene os três números e imprima-os
em ordem crescente. */

#include<stdio.h>
#include<locale.h>

 void ordem_crescente(int *n1, int *n2, int *n3); //protótipo da função que irá imprimir três números em ordem crescente.

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	//declaração de variáveis para os três números que serão inseridos pelo usuário.
	int num1, num2, num3;
	
	printf("Digite o primeiro número:\n");
	scanf("%d", &num1);
		
	printf("Digite o segundo número:\n");
	scanf("%d", &num2);
		
	printf("Digite o terceiro número:\n");
	scanf("%d", &num3);
	
	ordem_crescente(&num1, &num2, &num3); //chamada da função que irá organizar os números inseridos em ordem crescente.
	
	return 0;
}
//função para organizar os números digitados pelo usuário em ordem crescente.
 void ordem_crescente(int *n1, int *n2, int *n3){
 	int aux;
    
    //irá verificar e realizar as trocas para garantir que os números estejam na ordem: n1, n2 e n3.
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
	
	//imprime os números em ordem crescente.
	printf("Ordem crescente: %d %d %d\n", *n1, *n2, *n3);
}
