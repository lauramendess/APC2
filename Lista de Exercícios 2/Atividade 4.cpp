/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios 2 de APC2 e LAB2

Exercício 4 - Fazer uma função que recebe 3 parâmetros: um vetor de inteiros, um número inteiro n
enviado com passagem por valor e outro número x enviado como passagem por referência. 
Em uma função verifica(), envie todos os elementos utilizando ponteiros para
suas manipulações e veja se os números n e x estão no vetor e imprima se estiver.*/
#include<stdio.h>
#include<locale.h>

//declaração das funções:
void parametros (int *vetor, int n, int *x); 
void verifica (int *vet, int *n, int *x);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int vetor[10], n, x;
	
	printf("Digite um conjunto de 10 números inteiros:\n");
	
	parametros (vetor, n, &x); //chamada da função "parametros" que irá obter os valores do vetor, de n e de x.
	
	return 0;
}

//função que recebe um vetor, n e x como parâmetros e imprime o vetor.
void parametros (int *vetor, int n, int *x){
	int i;
	
	//for para preencher o vetor com valores digitados pelo usuário e imprimir cada valor.
	for (i = 0; i < 10; i++){
		scanf("%d", &vetor[i]);
		printf("Vetor[%d]: %d\n", i + 1, vetor[i]);
	}
	
	//solicita ao usuário que digite valores para n e x.
	printf("Agora digite um valor inteiro para N e um valor inteiro para X, respectivamente.\n");
	scanf("%d %d", &n, &*x);
	
	verifica(vetor, &n, x); //chama a função "verifica" para verificar se n e x estão no vetor.
}

//função responsável por verificar a presença de n e x no vetor.
void verifica (int *vet, int *n, int *x){
	int i = 0, nnovetor = 0, xnovetor = 0;
	
	//condição que irá se repetir até o fim da verificação (enquanto i for menor que 10) para descobrir se n e x estão no vetor. 
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
	//imprime se n está presente ou não no vetor.
	if (nnovetor) {
        printf("N = %d está presente no conjunto digitado.\n", *n);
    } else {
        printf("N = %d não foi encontrado no conjunto digitado.\n", *n);
    }

    //imprime se x está presente ou não no vetor.
    if (xnovetor) {
        printf("X = %d está presente no conjunto digitado.\n", *x);
    } else {
        printf("X = %d não foi encontrado no conjunto digitado.\n", *x);
    }
}
