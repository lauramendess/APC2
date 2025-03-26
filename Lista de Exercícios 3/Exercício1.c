/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 1 - Faca um programa que dado um numero n, informado pelo usuario, faça a soma com todos os seus antecessores pares e com ele, se ele for par. 
*/
#include<stdio.h>

int soma(int n){
	if(n <= 0)  // caso n seja menor ou igual a zero, retornara 0.
		return 0;
		
	else if(n % 2 != 0) // caso n nao seja um numero par.
		return soma(n - 1);

	else // caso n seja um numero par.
		return n + soma(n - 2);
}
int main (){
	int n;
	
	printf("Digite um numero para calcular a soma com os seus antecessores pares (e com ele mesmo se tambem for par): "); 
	scanf("%d", &n);
	
	if (n < 0) { // testando se o numero digitado é inválido, ou seja, negativo.
		printf("ERRO! Informe um numero inteiro positivo.\n");
		return 1; 
	}
	
	printf("\nResultado: %d\n", soma(n)); // imprime o valor da soma ja com a chamada da funcao direto no printf.
	
	return 0;
}
