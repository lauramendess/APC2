/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 2 - Faça um programa para imprimir a sequência de Fibonacci(da mesma forma que está na imagem do enunciado da questão na lista)*/
#include<stdio.h>
#include<locale.h>

int fibonacci(int n){    //função que calcula a sequência de fibonacci.
	if (n == 0) 
        return 0;  
    else if (n == 1) 
        return 1;
    else 
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	int n, i;
	
	printf("Digite um número de termos para calcular a Sequência de Fibonacci: "); //solicita ao usuário que informe o número de termos desejado.
	scanf("%d", &n);
	
	if (n < 0) { //para testar se n é um número inválido, ou seja, menor do que zero.
        printf("\nNÚMERO INVÁLIDO!\nInsira um número inteiro positivo para calcular a Sequência de Fibonacci.\n");
        return 1;
    }
	
	printf("\nSequência de Fibonacci: "); //imprime a sequência de fibonacci, chamando a função dentro do printf.
	for(i = 0; i < n; i++){
		printf("%d ", fibonacci(i));
	}
	return 0;
}
