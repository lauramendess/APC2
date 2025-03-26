/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 3 - Implemente uma funcao recursiva que imprima de 0 a n.
*/

#include<stdio.h>

int imprime(int n){
	if(n == 0){ // para imprimir o zero.
	  printf("%d ", n);
	  return n;
	}
	else{
	  imprime(n - 1); // chamada da funcao recursiva para n - 1.
	  printf("%d ", n); // imprime o numero atual.
	}
}

int main (){
	int n;
	
	printf("Digite um numero inteiro positivo: "); 
	scanf("%d", &n);
	
	if (n < 0) { // para testar se n e um numero invalido, ou seja, menor do que zero.
		printf("\nNUMERO INVALIDO!\nInsira um numero inteiro positivo.\n");
		return 1;
	}
	printf("Impressao dos numeros de 0 a %d:\n", n);
	imprime(n); 
	
	return 0;
}
