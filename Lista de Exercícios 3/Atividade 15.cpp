/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 15 - Construa um programa que receba da linha de comando, por meio do argc argv, um n�mero inteiro e
retorne seu fatorial na sa�da padr�o, o qual � calculado por uma fun��o denominada fat(). O n�mero deve
ser enviado e manipulado na fun��o como ponteiro.*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int fat(int *numero); //prot�tipo da fun��o que ir� calcular o fatorial.

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
		
    //verifica se foi fornecido exatamente um argumento.
	if(argc != 2){
	    printf("-----ERRO-----\nVoc� n�o inseriu um n�mero natural!!\n");
	    return 1;
	}
	else {
	//converte o argumento para inteiro.
    int num = atoi(argv[1]);
    //exibe o resultado do fatorial.
    printf("O fatorial de %s � %d.\n", argv[1], fat(&num));
	}
    
    return 0;
}
//fun��o para calcular o fatorial de um n�mero natural.
int fat(int *numero){
	 //verifica se o n�mero � negativo.
	 if (*numero < 0) {
        printf("N�mero inv�lido!\nInsira um n�mero natural e n�o n�meros negativos!\n");
        exit(1);
    }
    int i, result = 1;
    //calculo do fatorial;
    for (i = 1; i <= *numero; i++) {
        result *= i;
    }
    return result;
}
