/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios 2 de APC2 e LAB2

Exercicio 5 - Faca um programa que tendo como entrada dois pontos quaisquer do plano
P(x1,y1) e Q(x2,y2), utilizando ponteiros para passagem dos valores, imprima a
distancia entre eles.*/
#include<stdio.h>
#include<math.h>

//declaracao da funcao que ira calcular a distancia entre dois pontos no plano usando a formula da distancia euclidiana.
float distancia(float *x1, float *y1, float *x2, float *y2);

int main (){
	float x1, y1, x2, y2;
	float result;
	
	printf("Digite os pontos, x1 e y1, do plano P, respectivamente:\n"); //solicita ao usuario que insira os pontos x1 e y1 do plano P.
	scanf("%f %f", &x1, &y1);
	
	printf("Digite os pontos, x2 e y2, do plano Q, respectivamente:\n"); //solicita ao usuario que insira os pontos x2 e y2 do plano Q.
	scanf("%f %f", &x2, &y2);
	
	//chama a funcao "distancia" para calcular a distancia entre os pontos P e Q e atribui seu resultado em "result".
	result = distancia(&x1, &y1, &x2, &y2);
	
	printf("Distancia entre os pontos P e Q: %.2f", result);
	return 0;
}
float distancia(float *x1, float *y1, float *x2, float *y2){
	float resultado = 0;
	
	//calculo da distancia.
	resultado = sqrt(pow((*x2 - *x1), 2) + pow((*y2 - *y1), 2));
	
	return resultado; //retorna o resultado calculado.
}
