/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 5 - Faça uma função recursiva que imprima um inteiro usando recursão.*/
#include <stdio.h>
#include <locale.h>

void imprime(int n) { //função recursiva que imprime um inteiro.
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
    
    printf("Insira um número: "); //pede ao usuário que insira um número.
    scanf("%d", &n);
    printf("\nNúmero inteiro: "); 
    imprime(n); //chamada da função recursiva imprime um número inteiro.
    
    return 0;
}
