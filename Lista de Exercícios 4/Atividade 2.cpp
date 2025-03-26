/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 2 - Fa�a um programa para imprimir a sequ�ncia de Fibonacci(da mesma forma que est� na imagem do enunciado da quest�o na lista)*/
#include<stdio.h>
#include<locale.h>

int fibonacci(int n){    //fun��o que calcula a sequ�ncia de fibonacci.
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
	
	printf("Digite um n�mero de termos para calcular a Sequ�ncia de Fibonacci: "); //solicita ao usu�rio que informe o n�mero de termos desejado.
	scanf("%d", &n);
	
	if (n < 0) { //para testar se n � um n�mero inv�lido, ou seja, menor do que zero.
        printf("\nN�MERO INV�LIDO!\nInsira um n�mero inteiro positivo para calcular a Sequ�ncia de Fibonacci.\n");
        return 1;
    }
	
	printf("\nSequ�ncia de Fibonacci: "); //imprime a sequ�ncia de fibonacci, chamando a fun��o dentro do printf.
	for(i = 0; i < n; i++){
		printf("%d ", fibonacci(i));
	}
	return 0;
}
