/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 6 - Implemente um programa que faça o cálculo da média e da variância de um conjunto de 10 números
reais. Implementação: Os valores são lidos e armazenados em um vetor de 10 posições. Os cálculos da
média e da variância são efetuados sobre o conjunto de valores armazenados no vetor. O vetor deve ser
passado para a função media(), o parâmetro do vetor deve ser recebido como ponteiro, onde será
calculado a média e retornará o valor da mesma. Após os valores, são também passados para a função variância().*/
#include<stdio.h>
#include<locale.h>
#include<math.h>

#define TAM 10
//declaração dos protótipos das funções que serão usadas no programa.
float *media(float *vetor, float *med);
float *variancia(float *vetor, float *var, float *med);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i; 
	float conjunto[TAM], med, var;
	float *resultmedia, *resultvariancia;
	
	printf("Digite 10 números reais para calcular a média e a variância do conjunto inserido:\n");
	for(i = 0; i < TAM; i++){
	  scanf("%f", &conjunto[i]);
	}
	resultmedia = media(conjunto, &med); //chamada da função que irá calcular a média e armazenar em resultmedia.
	printf("A média do conjunto de números reais inseridos é: %.2f\n", *resultmedia);
	
	resultvariancia = variancia(conjunto, &var, resultmedia); //chamada da função que irá calcular a variância e armazenar em resultvariancia.
	printf("A variância do conjunto de números reais inseridos é: %.2f\n", *resultvariancia);
	
	return 0;
}
//função que calcula a média do conjunto.
float *media(float *vetor, float *med){
	int i;
	float soma = 0;   
	for(i = 0; i < TAM; i++){
	  soma += *(vetor + i);
	}
	*med = soma / TAM; //calcula a média e armazena o resultado em med.
	return med; //retorna o ponteiro para a média.
}
//função que calcula a variância do conjunto.
float *variancia(float *vetor, float *var, float *med){
	int i;
	float somatorio = 0;
	
	for(i = 0; i < TAM; i++){
	   somatorio += pow((*(vetor + i)) - (*med), 2);  //calcula o somatório necessário para a fórmula da variância.
	}
	*var = somatorio / (TAM - 1); //calcula a variância e armazena o resultado em var.
	return var; //retorna o ponteiro para a variância.
}
