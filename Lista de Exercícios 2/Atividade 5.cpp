/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios 2 de APC2 e LAB2

Exerc�cio 5 - Fa�a um programa que tendo como entrada dois pontos quaisquer do plano
P(x1,y1) e Q(x2,y2), utilizando ponteiros para passagem dos valores, imprima a
dist�ncia entre eles.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

//declara��o da fun��o que ir� calcular a dist�ncia entre dois pontos no plano usando a f�rmula da dist�ncia euclidiana.
float distancia(float *x1, float *y1, float *x2, float *y2);

int main (){
	setlocale(LC_ALL, "Portuguese"); //valores decimais devem ser inseridos com v�rgula por conta da configura��o em portugu�s.
	float x1, y1, x2, y2;
	float result;
	
	printf("Digite os pontos, x1 e y1, do plano P, respectivamente:\n"); //solicita ao usu�rio que insira os pontos x1 e y1 do plano P.
	scanf("%f %f", &x1, &y1);
    
	printf("Digite os pontos, x2 e y2, do plano Q, respectivamente:\n"); //solicita ao usu�rio que insira os pontos x2 e y2 do plano Q.
	scanf("%f %f", &x2, &y2);
	
	//chama a fun��o "distancia" para calcular a dist�ncia entre os pontos P e Q e atribui seu resultado em "result".
	result = distancia(&x1, &y1, &x2, &y2);
	
	printf("Dist�ncia entre os pontos P e Q: %.2f", result);
	return 0;
}
float distancia(float *x1, float *y1, float *x2, float *y2){
	float resultado = 0;
	
	//c�lculo da dist�ncia.
	resultado = sqrt(pow((*x2 - *x1), 2) + pow((*y2 - *y1), 2));
	
	return resultado; //retorna o resultado calculado.
}
