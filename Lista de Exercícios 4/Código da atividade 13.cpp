/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 13 - Implemente o exemplo visto.
– Se X é a função recursiva abaixo, qual o valor de X(7)?*/
#include<stdio.h>
#include<locale.h>

int calculo(int n) {    //função recursiva que calcula o valor de x = 7.
    if (n == 1 || n == 2) 
        return n;
    else 
        return calculo(n - 1) + n * calculo(n - 2);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int n = 7; //declara n igual a 7.
	
    printf("O valor de X(%d) é igual a = %d\n", n, calculo(n)); //imprime o valor de x = 7 e chama a função direto no printf.

    return 0;
}
