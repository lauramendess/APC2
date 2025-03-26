/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 6 - Implemente um programa que fa�a o c�lculo da m�dia e da vari�ncia de um conjunto de 10 n�meros
reais. Implementa��o: Os valores s�o lidos e armazenados em um vetor de 10 posi��es. Os c�lculos da
m�dia e da vari�ncia s�o efetuados sobre o conjunto de valores armazenados no vetor. O vetor deve ser
passado para a fun��o media(), o par�metro do vetor deve ser recebido como ponteiro, onde ser�
calculado a m�dia e retornar� o valor da mesma. Ap�s os valores, s�o tamb�m passados para a fun��o vari�ncia().*/
#include<stdio.h>
#include<locale.h>
#include<math.h>

#define TAM 10
//declara��o dos prot�tipos das fun��es que ser�o usadas no programa.
float *media(float *vetor, float *med);
float *variancia(float *vetor, float *var, float *med);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i; 
	float conjunto[TAM], med, var;
	float *resultmedia, *resultvariancia;
	
	printf("Digite 10 n�meros reais para calcular a m�dia e a vari�ncia do conjunto inserido:\n");
	for(i = 0; i < TAM; i++){
	  scanf("%f", &conjunto[i]);
	}
	resultmedia = media(conjunto, &med); //chamada da fun��o que ir� calcular a m�dia e armazenar em resultmedia.
	printf("A m�dia do conjunto de n�meros reais inseridos �: %.2f\n", *resultmedia);
	
	resultvariancia = variancia(conjunto, &var, resultmedia); //chamada da fun��o que ir� calcular a vari�ncia e armazenar em resultvariancia.
	printf("A vari�ncia do conjunto de n�meros reais inseridos �: %.2f\n", *resultvariancia);
	
	return 0;
}
//fun��o que calcula a m�dia do conjunto.
float *media(float *vetor, float *med){
	int i;
	float soma = 0;   
	for(i = 0; i < TAM; i++){
	  soma += *(vetor + i);
	}
	*med = soma / TAM; //calcula a m�dia e armazena o resultado em med.
	return med; //retorna o ponteiro para a m�dia.
}
//fun��o que calcula a vari�ncia do conjunto.
float *variancia(float *vetor, float *var, float *med){
	int i;
	float somatorio = 0;
	
	for(i = 0; i < TAM; i++){
	   somatorio += pow((*(vetor + i)) - (*med), 2);  //calcula o somat�rio necess�rio para a f�rmula da vari�ncia.
	}
	*var = somatorio / (TAM - 1); //calcula a vari�ncia e armazena o resultado em var.
	return var; //retorna o ponteiro para a vari�ncia.
}
