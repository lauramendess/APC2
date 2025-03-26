/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 2 - Faca um programa para imprimir a sequencia de Fibonacci (da mesma forma que esta na imagem do enunciado da questao na lista) 
*/
#include<stdio.h>

int fibonacci(int n) { // funcao que calcula a sequencia de fibonacci.
	if (n == 0) 
		return 0;  
	else if (n == 1) 
		return 1;
	else 
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n, i;
	
	printf("Digite um numero de termos para calcular a Sequencia de Fibonacci: "); 
	scanf("%d", &n);
	
	if (n < 0) { // para testar se n e um numero invalido, ou seja, menor do que zero.
		printf("\nNUMERO INVALIDO!\nInsira um numero inteiro positivo para calcular a Sequencia de Fibonacci.\n");
		return 1;
	}
	
	printf("\nSequencia de Fibonacci: "); // imprime a sequencia de fibonacci, chamando a funcao dentro do printf.
	for (i = 0; i < n; i++) {
		printf("%d ", fibonacci(i));
	}
	return 0;
}
