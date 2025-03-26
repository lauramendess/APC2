/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 5 - Fa�a uma fun��o recursiva que imprima um inteiro usando recurs�o.*/
#include <stdio.h>
#include <locale.h>

void imprime(int n) { //fun��o recursiva que imprime um inteiro.
    if (n < 10) {
        printf("%d", n);
        return;
    }
    imprime(n / 10);
    printf("%d", n % 10);
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int n;
    
    printf("Insira um n�mero: "); //pede ao usu�rio que insira um n�mero.
    scanf("%d", &n);
    printf("\nN�mero inteiro: "); 
    imprime(n); //chamada da fun��o recursiva imprime um n�mero inteiro.
    
    return 0;
}
