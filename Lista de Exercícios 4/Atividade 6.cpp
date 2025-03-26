/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 6 - Escreva uma fun��o recursiva para calcular o valor de uma base x elevada a um expoente y.*/
#include<stdio.h>
#include<locale.h>

int potencia(int base, int exp){
	if (exp == 0) //se o expoente for 0, retorna 1.
	 return 1;
	else         //calcula a pot�ncia chamando a fun��o recursiva para a base e exp - 1.
	 return base * potencia(base, exp - 1);
}
int main (){
	setlocale(LC_ALL, "Portuguese");
	int base, exp;
	
	//solicita ao usu�rio que insira a base e o expoente.
	printf("Insira a base e o expoente, respectivamente, para calcular a pot�ncia de um n�mero: ");
	scanf("%d %d", &base, &exp);
	
	//impress�o do resultado da pot�ncia e a chamada da fun��o recursiva direto no printf.
	printf("Valor da base %d elevada ao expoente %d: %d", base, exp, potencia(base, exp));
	
	return 0;
}
