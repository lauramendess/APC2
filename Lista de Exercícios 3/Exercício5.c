/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 5 - Faca uma funcao recursiva que imprima um inteiro usando recursao.
*/
#include <stdio.h>

void imprime(int n) { 
    if (n < 10) {
        printf("%d", n);
        return;
    }
    
    imprime(n / 10);
    printf("%d", n % 10);
}

int main() {
    int n;
    
    printf("Insira um numero: "); 
    scanf("%d", &n);
    printf("\nNumero inteiro: "); 
    imprime(n); // chamada da funcao recursiva imprime um numero inteiro.
    
    return 0;
}
