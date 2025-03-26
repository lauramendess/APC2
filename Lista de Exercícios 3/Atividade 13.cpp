/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 13- Faça um programa que calcule o desvio padrão de um vetor v contendo n=10 números, onde m é a
média do vetor.*/
#include<stdio.h>
#include<math.h>
#include<locale.h>
#define N 10

//declaração dos protótipos das funções que serão utilizadas.
float *calculomedia(float *vetor, float *med);
void calculodesviopadrao(float *vetor, float *med);

int main(){
	setlocale(LC_ALL, "Portuguese");
	float vetorV[N], med;
	float *m;
	int i;
	
	printf("Digite 10 números para o conjunto V\n");
	for(i = 0; i < N; i++){
		scanf("%f", &vetorV[i]);
	}
    m = calculomedia(vetorV, &med); //chama a função para calcular a média e armazena o resultado em 'm'.
	calculodesviopadrao(vetorV, m); //chama a função para calcular o desvio padrão.
}

//função para calcular a média do conjunto.
float *calculomedia(float *vetor, float *med){
	int i;
	float soma = 0;
	
	for(i = 0; i < N; i++){
	  soma += *(vetor + i);
	}
	*med = soma / N; //calcula a média e armazena o resultado em 'med'.
	
	return med; //retorna o endereço de 'med'.
}

//função para calcular o desvio padrão do conjunto.
void calculodesviopadrao(float *vetor, float *med){
	int i;
	float somatorio = 0, dp;
	
    //calcula o somatório necessário para o cálculo do desvio padrão.
	for(i = 0; i < N; i++){
	   somatorio += pow((*(vetor + i)) - (*med), 2);
	}
	//calcula o desvio padrão e imprime o resultado.
    dp = sqrt(somatorio / (N - 1));
    printf("O desvio padrão é: %.2f", dp);	
}
