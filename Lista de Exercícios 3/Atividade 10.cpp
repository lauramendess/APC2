/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Excercício 10 - Peça ao usuário para digitar dez valores numéricos e ordene por ordem crescente esses valores,
guardando-os num vetor. Por meio da função ordena() e com o uso de ponteiros ordene o número assim
que ele for digitado. Mostre ao final na tela os valores em ordem, por meio da função imprime().*/
#include<stdio.h>
#define N 10

//declaração dos protótipos das funções que serão usadas no programa.
void ordena(float *vetor, int *qnt);
void imprime(float *vetor, int *qnt);

int main (){
	int i, quantidade = 0;
	float vetor[N];
	
	printf("Digite 10 valores reais:\n");
	for(i = 0; i < N; i++){
		scanf("%f", &vetor[i]);
		quantidade++;
		
		ordena(vetor, &quantidade); //chamada da função que irá ordenar os valores assim que for digitado.
		imprime(vetor, &quantidade); //chamada da função que irá imprimir os valores.
	}
	
	return 0;
}
//função para ordenar o vetor em ordem crescente
void ordena(float *vetor, int *qnt){
	int i, j;
	float aux;
	
	for(i = 0; i < *qnt; i++){
		for(j = i + 1; j < *qnt; j++){
			if(*(vetor + i) > *(vetor + j)){ //troca os elementos se estiverem fora de ordem
				aux = *(vetor + i);
				*(vetor + i) =  *(vetor + j);
				*(vetor + j) = aux;
			}
		}
	}
}
//função para imprimir os valores ordenados
void imprime(float *vetor, int *qnt){
	int i;
	
	printf("Valores ordenados:\n");
	for(i = 0; i < *qnt; i++){
		printf("%.1f ", *(vetor + i));
	}
}
