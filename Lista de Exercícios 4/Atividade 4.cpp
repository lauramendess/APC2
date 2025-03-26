/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 4 - Implemente uma fun��o recursiva que fa�a a soma de N n�meros.*/
#include<stdio.h>
#include<locale.h>

int soma(int n){ //fun��o que ir� calcular a soma recursiva de N n�meros.
	if(n == 1 || n == 0){       
	  printf("%d =", n);
	  return n;
    }
	else{
      printf("%d + ", n);
	  return n + soma(n-1); //chama a fun��o recursiva para n-1 e soma n.
    }
}
int main (){
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Digite um n�mero inteiro positivo para calcular a soma de N n�meros: "); //pede ao usu�rio que insira um n�mero positivo para calcular.
	scanf("%d", &n);
	
	if (n < 0) { //para testar se n � um n�mero inv�lido, ou seja, menor do que zero.
        printf("\nN�MERO INV�LIDO!\nInsira um n�mero inteiro positivo para calcular a soma de N n�meros.\n");
        return 1;
    }
	
	//imprime a soma e o resultado e faz a chamada da fun��o recursiva dentro do printf.
	printf("\nSoma e resultado:\n");
	printf(" %d\n", soma(n));
	
	return 0;
}
