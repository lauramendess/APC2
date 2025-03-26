/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 11 - Escreva um programa que leia um n�mero inteiro positivo n e em seguida imprima n linhas do chamado
Tri�ngulo de Pascal*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//fun��o para gerar e imprimir o Tri�ngulo de Pascal.
void triangulopascal(int n);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Insira um n�mero inteiro positivo:\n");
	scanf("%d", &n);
	
    printf("Tri�ngulo pascal:\n");
	triangulopascal(n); //chama a fun��o para gerar e imprimir o Tri�ngulo de Pascal
	
	return 0;
}
void triangulopascal(int n){
	int i, j, triangulo[n][n];
	
	for (i = 0; i < n; i++){
		triangulo[i][0] = 1; //inicializa a primeira coluna de cada linha com 1.
		for(j = 1; j < n; j++){
		   triangulo[i][j] = 0; //inicializa as demais colunas com 0.
		}
	}
	//calcula os valores das demais colunas usando a f�rmula do Tri�ngulo de Pascal.
	for(i = 1; i < n; i++){
		for(j = 1; j < n; j++){
			triangulo[i][j] = triangulo[i - 1][j] + triangulo[i - 1][j - 1];
		}
	}
	//imprime o Tri�ngulo de Pascal.
	for (i = 0; i < n; i++){
		for(j = 0; j <= i; j++){
			printf("%d ", triangulo[i][j]);
		}
		printf("\n");
	}
}
