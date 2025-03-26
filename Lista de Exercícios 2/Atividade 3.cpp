/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios 2 de APC2 e LAB2

Exerc�cio 3:  Fa�a um programa que dado 2 vari�veis inteiras a=2 e b=3, use a fun��o void troca(int
*a1, int *b1), que deve fazer a invers�o dos valores de a e b. Ap�s a chamada da fun��o,
imprimir os valores de a e b. A fun��o troca tamb�m deve ser implementada e deve ter
tipo de retorno void. Todas as manipula��es deve se dar usando ponteiros. */

#include <stdio.h>

//declara��o da fun��o troca que aceita dois ponteiros para inteiros como par�metros e inverte ambos. 
void troca(int *a1, int *b1);

int main (){
	
	int a = 2;
	int b = 3;
	
	printf("Valores antes de serem invertidos: \nA = %d\nB = %d", a, b); //impress�o dos valores antes da invers�o.
	
	troca(&a, &b);  //chamada da fun��o que ir� trocar a e b, passando os endere�os das vari�veis a e b.
	
	printf("\nValores invertidos: \nA = %d\nB = %d", a, b); //impress�o dos valores ap�s a invers�o pela fun��o troca.
	
	return 0;
}

//fun��o respons�vel por inverter os valores.
void troca(int *a1, int *b1){
	int aux;
	
	aux = *a1; //armazena o valor apontado por a1 em aux.
	*a1 = *b1; //atribui o valor apontado por b1 em a1.
	*b1 = aux; //atribui o valor armazenado em aux em b1.
}
