/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 6 - Escreva uma funcao recursiva para calcular o valor de uma base x elevada a um expoente y.
*/
#include<stdio.h>

int potencia(int base, int exp){
	if (exp == 0) // se o expoente for 0, retorna 1.
		return 1;
		
	else         // calcula a potencia chamando a funcao recursiva para a base e exp - 1.
		return base * potencia(base, exp - 1);
}

int main (){
	int base, exp;

	printf("Insira a base e o expoente, respectivamente, para calcular a potencia de um numero: ");
	scanf("%d %d", &base, &exp);
	
	// impressao do resultado da potencia e a chamada da funcao recursiva direto no printf.
	printf("Valor da base %d elevada ao expoente %d: %d", base, exp, potencia(base, exp));
	
	return 0;
}
