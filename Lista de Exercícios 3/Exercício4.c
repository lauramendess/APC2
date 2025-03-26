/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 4 - Implemente uma funcao recursiva que faca a soma de N numeros.
*/
#include<stdio.h>

// funcao recursiva que faz a soma de N numeros.
int soma(int n){ 
	if(n == 1 || n == 0){       
	  printf("%d =", n);
	  return n;
	}
	else{
	  printf("%d + ", n);
	  return n + soma(n-1); // chama a funcao recursiva para n-1 e soma n.
	}
}
int main (){
	int n;
	
	printf("Digite um numero inteiro positivo para calcular a soma de N numeros: "); 
	scanf("%d", &n);
	
	if (n < 0) { // para testar se n é um número menor do que zero.
		printf("\nNUMERO INVALIDO!\nInsira um numero inteiro positivo para calcular a soma de N numeros.\n");
		return 1;
	}
	
	printf("\nSoma e resultado:\n");
	printf(" %d\n", soma(n));
	
	return 0;
}
