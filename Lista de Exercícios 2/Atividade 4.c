/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios 2 de APC2 e LAB2

Exercicio 4 - Fazer uma funcao que recebe 3 parametros: um vetor de inteiros, um numero inteiro n
enviado com passagem por valor e outro numero x enviado como passagem por referencia. 
Em uma funcao verifica(), envie todos os elementos utilizando ponteiros para
suas manipulacoes e veja se os numeros n e x estao no vetor e imprima se estiver.
*/
#include<stdio.h>

//declaracao das funcoes:
void parametros (int *vetor, int n, int *x); 
void verifica (int *vet, int *n, int *x);

int main (){
	int vetor[10], n, x;
	
	printf("Digite um conjunto de 10 numeros inteiros:\n");
	
	parametros (vetor, n, &x); //chamada da funcao "parametros" que ira obter os valores do vetor, de n e de x.
	
	return 0;
}

//funcao que recebe um vetor, n e x como parametros e imprime o vetor.
void parametros (int *vetor, int n, int *x){
	int i;
	
	//for para preencher o vetor com valores digitados pelo usuario e imprimir cada valor.
	for (i = 0; i < 10; i++){
		scanf("%d", &vetor[i]);
		printf("Vetor[%d]: %d\n", i + 1, vetor[i]);
	}
	
	//solicita ao usuario que digite valores para n e x.
	printf("Agora digite um valor inteiro para N e um valor inteiro para X, respectivamente.\n");
	scanf("%d %d", &n, &*x);
	
	verifica(vetor, &n, x); //chama a funcao "verifica" para verificar se n e x estao no vetor.
}

//funcao responsavel por verificar a presenca de n e x no vetor.
void verifica (int *vet, int *n, int *x){
	int i = 0, nnovetor = 0, xnovetor = 0;
	
	//condicao que ira se repetir ate o fim da verificacao (enquanto i for menor que 10) para descobrir se n e x estao no vetor. 
	while(i < 10){
		
		if(*vet == *n){
		  nnovetor = 1;
		}
		if(*vet == *x){
		  xnovetor = 1;
		}
		  vet++;
		  i++;
	}
	
	//imprime se n esta presente ou nao no vetor.
	if (nnovetor) {
		printf("N = %d esta presente no conjunto digitado.\n", *n);
	} else {
		printf("N = %d nao foi encontrado no conjunto digitado.\n", *n);
	}

	//imprime se x esta presente ou nao no vetor.
	if (xnovetor) {
		printf("X = %d esta presente no conjunto digitado.\n", *x);
	} else {
		printf("X = %d nao foi encontrado no conjunto digitado.\n", *x);
	}
}
