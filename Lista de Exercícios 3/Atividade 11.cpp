/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 11 - Escreva um programa que leia um número inteiro positivo n e em seguida imprima n linhas do chamado
Triângulo de Pascal*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//função para gerar e imprimir o Triângulo de Pascal.
void triangulopascal(int n);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Insira um número inteiro positivo:\n");
	scanf("%d", &n);
	
    printf("Triângulo pascal:\n");
	triangulopascal(n); //chama a função para gerar e imprimir o Triângulo de Pascal
	
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
	//calcula os valores das demais colunas usando a fórmula do Triângulo de Pascal.
	for(i = 1; i < n; i++){
		for(j = 1; j < n; j++){
			triangulo[i][j] = triangulo[i - 1][j] + triangulo[i - 1][j - 1];
		}
	}
	//imprime o Triângulo de Pascal.
	for (i = 0; i < n; i++){
		for(j = 0; j <= i; j++){
			printf("%d ", triangulo[i][j]);
		}
		printf("\n");
	}
}
