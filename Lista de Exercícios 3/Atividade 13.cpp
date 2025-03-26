/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 13- Fa�a um programa que calcule o desvio padr�o de um vetor v contendo n=10 n�meros, onde m � a
m�dia do vetor.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>
#define N 10

//declara��o dos prot�tipos das fun��es que ser�o utilizadas.
float *calculomedia(float *vetor, float *med);
void calculodesviopadrao(float *vetor, float *med);

int main(){
	setlocale(LC_ALL, "Portuguese");
	float vetorV[N], med;
	float *m;
	int i;
	
	printf("Digite 10 n�meros para o conjunto V\n");
	for(i = 0; i < N; i++){
		scanf("%f", &vetorV[i]);
	}
    m = calculomedia(vetorV, &med); //chama a fun��o para calcular a m�dia e armazena o resultado em 'm'.
	calculodesviopadrao(vetorV, m); //chama a fun��o para calcular o desvio padr�o.
}

//fun��o para calcular a m�dia do conjunto.
float *calculomedia(float *vetor, float *med){
	int i;
	float soma = 0;
	
	for(i = 0; i < N; i++){
	  soma += *(vetor + i);
	}
	*med = soma / N; //calcula a m�dia e armazena o resultado em 'med'.
	
	return med; //retorna o endere�o de 'med'.
}

//fun��o para calcular o desvio padr�o do conjunto.
void calculodesviopadrao(float *vetor, float *med){
	int i;
	float somatorio = 0, dp;
	
    //calcula o somat�rio necess�rio para o c�lculo do desvio padr�o.
	for(i = 0; i < N; i++){
	   somatorio += pow((*(vetor + i)) - (*med), 2);
	}
	//calcula o desvio padr�o e imprime o resultado.
    dp = sqrt(somatorio / (N - 1));
    printf("O desvio padr�o �: %.2f", dp);	
}
