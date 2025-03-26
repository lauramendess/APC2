/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 6 - Escreva uma função recursiva para calcular o valor de uma base x elevada a um expoente y.*/
#include<stdio.h>
#include<locale.h>

int potencia(int base, int exp){
	if (exp == 0) //se o expoente for 0, retorna 1.
	 return 1;
	else         //calcula a potência chamando a função recursiva para a base e exp - 1.
	 return base * potencia(base, exp - 1);
}
int main (){
	setlocale(LC_ALL, "Portuguese");
	int base, exp;
	
	//solicita ao usuário que insira a base e o expoente.
	printf("Insira a base e o expoente, respectivamente, para calcular a potência de um número: ");
	scanf("%d %d", &base, &exp);
	
	//impressão do resultado da potência e a chamada da função recursiva direto no printf.
	printf("Valor da base %d elevada ao expoente %d: %d", base, exp, potencia(base, exp));
	
	return 0;
}
