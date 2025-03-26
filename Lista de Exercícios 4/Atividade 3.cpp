/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 3 - Implemente uma fun��o recursiva que imprima de 0 a n.*/
#include<stdio.h>
#include<locale.h>

int imprime(int n){
	if(n == 0){ //para imprimir o zero.
      printf("%d ", n);
      return n;
    }
    else{
	  imprime(n - 1); //cahamada da fun��o recursiva para n - 1.
	  printf("%d ", n); //imprime o n�mero atual.
    }
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Digite um n�mero inteiro positivo: "); //pede ao usu�rio que insira um n�mero.
	scanf("%d", &n);
	
	if (n < 0) { //para testar se n � um n�mero inv�lido, ou seja, menor do que zero.
        printf("\nN�MERO INV�LIDO!\nInsira um n�mero inteiro positivo.\n");
        return 1;
    }
	printf("Impress�o dos n�meros de 0 a %d:\n", n);
	imprime(n); //chamada da fun��o que ir� imprimir os n�meros.
	
	return 0;
}
