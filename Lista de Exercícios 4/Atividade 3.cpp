/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 3 - Implemente uma função recursiva que imprima de 0 a n.*/
#include<stdio.h>
#include<locale.h>

int imprime(int n){
	if(n == 0){ //para imprimir o zero.
      printf("%d ", n);
      return n;
    }
    else{
	  imprime(n - 1); //cahamada da função recursiva para n - 1.
	  printf("%d ", n); //imprime o número atual.
    }
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Digite um número inteiro positivo: "); //pede ao usuário que insira um número.
	scanf("%d", &n);
	
	if (n < 0) { //para testar se n é um número inválido, ou seja, menor do que zero.
        printf("\nNÚMERO INVÁLIDO!\nInsira um número inteiro positivo.\n");
        return 1;
    }
	printf("Impressão dos números de 0 a %d:\n", n);
	imprime(n); //chamada da função que irá imprimir os números.
	
	return 0;
}
