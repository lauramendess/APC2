/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 13 - Implemente o exemplo visto.
� Se X � a fun��o recursiva abaixo, qual o valor de X(7)?*/
#include<stdio.h>
#include<locale.h>

int calculo(int n) {    //fun��o recursiva que calcula o valor de x = 7.
    if (n == 1 || n == 2) 
        return n;
    else 
        return calculo(n - 1) + n * calculo(n - 2);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int n = 7; //declara n igual a 7.
	
    printf("O valor de X(%d) � igual a = %d\n", n, calculo(n)); //imprime o valor de x = 7 e chama a fun��o direto no printf.

    return 0;
}
