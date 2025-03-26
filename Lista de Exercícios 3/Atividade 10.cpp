/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Excerc�cio 10 - Pe�a ao usu�rio para digitar dez valores num�ricos e ordene por ordem crescente esses valores,
guardando-os num vetor. Por meio da fun��o ordena() e com o uso de ponteiros ordene o n�mero assim
que ele for digitado. Mostre ao final na tela os valores em ordem, por meio da fun��o imprime().*/
#include<stdio.h>
#define N 10

//declara��o dos prot�tipos das fun��es que ser�o usadas no programa.
void ordena(float *vetor, int *qnt);
void imprime(float *vetor, int *qnt);

int main (){
	int i, quantidade = 0;
	float vetor[N];
	
	printf("Digite 10 valores reais:\n");
	for(i = 0; i < N; i++){
		scanf("%f", &vetor[i]);
		quantidade++;
		
		ordena(vetor, &quantidade); //chamada da fun��o que ir� ordenar os valores assim que for digitado.
		imprime(vetor, &quantidade); //chamada da fun��o que ir� imprimir os valores.
	}
	
	return 0;
}
//fun��o para ordenar o vetor em ordem crescente
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
//fun��o para imprimir os valores ordenados
void imprime(float *vetor, int *qnt){
	int i;
	
	printf("Valores ordenados:\n");
	for(i = 0; i < *qnt; i++){
		printf("%.1f ", *(vetor + i));
	}
}
