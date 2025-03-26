/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios 2 de APC2 e LAB2

Exerc�cio 7 - Escreva um programa que l� tr�s n�meros inteiros do teclado e, utilizando uma fun��o e
acessando os n�meros no vetor por meio de ponteiros, ordene os tr�s n�meros e imprima-os
em ordem crescente. */

#include<stdio.h>
#include<locale.h>

 void ordem_crescente(int *n1, int *n2, int *n3); //prot�tipo da fun��o que ir� imprimir tr�s n�meros em ordem crescente.

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	//declara��o de vari�veis para os tr�s n�meros que ser�o inseridos pelo usu�rio.
	int num1, num2, num3;
	
	printf("Digite o primeiro n�mero:\n");
	scanf("%d", &num1);
		
	printf("Digite o segundo n�mero:\n");
	scanf("%d", &num2);
		
	printf("Digite o terceiro n�mero:\n");
	scanf("%d", &num3);
	
	ordem_crescente(&num1, &num2, &num3); //chamada da fun��o que ir� organizar os n�meros inseridos em ordem crescente.
	
	return 0;
}
//fun��o para organizar os n�meros digitados pelo usu�rio em ordem crescente.
 void ordem_crescente(int *n1, int *n2, int *n3){
 	int aux;
    
    //ir� verificar e realizar as trocas para garantir que os n�meros estejam na ordem: n1, n2 e n3.
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
	
	//imprime os n�meros em ordem crescente.
	printf("Ordem crescente: %d %d %d\n", *n1, *n2, *n3);
}
