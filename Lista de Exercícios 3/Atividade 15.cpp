/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 15 - Construa um programa que receba da linha de comando, por meio do argc argv, um número inteiro e
retorne seu fatorial na saída padrão, o qual é calculado por uma função denominada fat(). O número deve
ser enviado e manipulado na função como ponteiro.*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int fat(int *numero); //protótipo da função que irá calcular o fatorial.

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
		
    //verifica se foi fornecido exatamente um argumento.
	if(argc != 2){
	    printf("-----ERRO-----\nVocê não inseriu um número natural!!\n");
	    return 1;
	}
	else {
	//converte o argumento para inteiro.
    int num = atoi(argv[1]);
    //exibe o resultado do fatorial.
    printf("O fatorial de %s é %d.\n", argv[1], fat(&num));
	}
    
    return 0;
}
//função para calcular o fatorial de um número natural.
int fat(int *numero){
	 //verifica se o número é negativo.
	 if (*numero < 0) {
        printf("Número inválido!\nInsira um número natural e não números negativos!\n");
        exit(1);
    }
    int i, result = 1;
    //calculo do fatorial;
    for (i = 1; i <= *numero; i++) {
        result *= i;
    }
    return result;
}
