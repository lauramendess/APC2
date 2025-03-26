/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 1 - Fa�a um programa que dado um n�mero n, informado pelo usu�rio, fa�a a soma com todos os
seus antecessores pares e com ele, se ele for par.*/
#include<stdio.h>
#include<locale.h>

int soma(int n){
	if(n <= 0)  //caso n seja menor ou igual a zero, retornar� 0.
	    return 0;
	    
	else if(n % 2 != 0) //caso n n�o seja um n�mero par.
		return soma(n - 1);

	else //caso n seja um n�mero par.
	    return n + soma(n - 2);
}
int main (){
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Digite um n�mero para calcular a soma com os seu antecessores pares (e com ele mesmo se tamb�m for par): "); //pede que o usu�rio informe o n�mero.
	scanf("%d", &n);
	
	if (n < 0) { //testando se o n�mero digitado � inv�lido, ou seja, negativo.
        printf("ERRO! Informe um n�mero inteiro positivo.\n");
        return 1; 
    }
	
	printf("\nResultado: %d\n", soma(n)); //imprime o valor da soma j� com a chamada da fun��o direto no printf.
	
	return 0;
}
