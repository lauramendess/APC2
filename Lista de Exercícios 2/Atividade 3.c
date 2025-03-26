/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios 2 de APC2 e LAB2

Exercicio 3: Faca um programa que dado 2 variaveis inteiras a=2 e b=3, use a funcao void troca(int
*a1, int *b1), que deve fazer a inversao dos valores de a e b. Apos a chamada da funcao,
imprimir os valores de a e b. A funcao troca tambem deve ser implementada e deve ter
tipo de retorno void. Todas as manipulacoes devem se dar usando ponteiros. */

#include <stdio.h>

//declaracao da funcao troca que aceita dois ponteiros para inteiros como parametros e inverte ambos.
void troca(int *a1, int *b1);

int main (){
	
	int a = 2;
	int b = 3;
	
	printf("Valores antes de serem invertidos: \nA = %d\nB = %d", a, b); //impressao dos valores antes da inversao.
	
	troca(&a, &b);  //chamada da funcao que ira trocar a e b, passando os enderecos das variaveis a e b.
	
	printf("\nValores invertidos: \nA = %d\nB = %d", a, b); //impressao dos valores apos a inversao pela funcao troca.
	
	return 0;
}

//funcao responsavel por inverter os valores.
void troca(int *a1, int *b1){
	int aux;
	
	aux = *a1; //armazena o valor apontado por a1 em aux.
	*a1 = *b1; //atribui o valor apontado por b1 em a1.
	*b1 = aux; //atribui o valor armazenado em aux em b1.
}
