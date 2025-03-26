/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 4 - Implemente uma função recursiva que faça a soma de N números.*/
#include<stdio.h>
#include<locale.h>

int soma(int n){ //função que irá calcular a soma recursiva de N números.
	if(n == 1 || n == 0){       
	  printf("%d =", n);
	  return n;
    }
	else{
      printf("%d + ", n);
	  return n + soma(n-1); //chama a função recursiva para n-1 e soma n.
    }
}
int main (){
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Digite um número inteiro positivo para calcular a soma de N números: "); //pede ao usuário que insira um número positivo para calcular.
	scanf("%d", &n);
	
	if (n < 0) { //para testar se n é um número inválido, ou seja, menor do que zero.
        printf("\nNÚMERO INVÁLIDO!\nInsira um número inteiro positivo para calcular a soma de N números.\n");
        return 1;
    }
	
	//imprime a soma e o resultado e faz a chamada da função recursiva dentro do printf.
	printf("\nSoma e resultado:\n");
	printf(" %d\n", soma(n));
	
	return 0;
}
