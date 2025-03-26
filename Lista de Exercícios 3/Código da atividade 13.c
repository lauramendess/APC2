/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 13 - Implemente o exemplo visto. Se X e a funcao recursiva abaixo, qual o valor de X(7)?
*/

#include<stdio.h>

int calculo(int n) {    //funcao recursiva que calcula o valor de x = 7.
    if (n == 1 || n == 2) 
        return n;
    else 
        return calculo(n - 1) + n * calculo(n - 2);
}

int main() {
    int n = 7; //declara n igual a 7.
    
    printf("O valor de X(%d) e igual a = %d\n", n, calculo(n)); //imprime o valor de x = 7 e chama a funcao direto no printf.

    return 0;
}
