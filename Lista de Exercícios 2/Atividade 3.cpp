/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios 2 de APC2 e LAB2

Exercício 3:  Faça um programa que dado 2 variáveis inteiras a=2 e b=3, use a função void troca(int
*a1, int *b1), que deve fazer a inversão dos valores de a e b. Após a chamada da função,
imprimir os valores de a e b. A função troca também deve ser implementada e deve ter
tipo de retorno void. Todas as manipulações deve se dar usando ponteiros. */

#include <stdio.h>

//declaração da função troca que aceita dois ponteiros para inteiros como parâmetros e inverte ambos. 
void troca(int *a1, int *b1);

int main (){
	
	int a = 2;
	int b = 3;
	
	printf("Valores antes de serem invertidos: \nA = %d\nB = %d", a, b); //impressão dos valores antes da inversão.
	
	troca(&a, &b);  //chamada da função que irá trocar a e b, passando os endereços das variáveis a e b.
	
	printf("\nValores invertidos: \nA = %d\nB = %d", a, b); //impressão dos valores após a inversão pela função troca.
	
	return 0;
}

//função responsável por inverter os valores.
void troca(int *a1, int *b1){
	int aux;
	
	aux = *a1; //armazena o valor apontado por a1 em aux.
	*a1 = *b1; //atribui o valor apontado por b1 em a1.
	*b1 = aux; //atribui o valor armazenado em aux em b1.
}
