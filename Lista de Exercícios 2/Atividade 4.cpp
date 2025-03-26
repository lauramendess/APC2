/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios 2 de APC2 e LAB2

Exerc�cio 4 - Fazer uma fun��o que recebe 3 par�metros: um vetor de inteiros, um n�mero inteiro n
enviado com passagem por valor e outro n�mero x enviado como passagem por refer�ncia. 
Em uma fun��o verifica(), envie todos os elementos utilizando ponteiros para
suas manipula��es e veja se os n�meros n e x est�o no vetor e imprima se estiver.*/
#include<stdio.h>
#include<locale.h>

//declara��o das fun��es:
void parametros (int *vetor, int n, int *x); 
void verifica (int *vet, int *n, int *x);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int vetor[10], n, x;
	
	printf("Digite um conjunto de 10 n�meros inteiros:\n");
	
	parametros (vetor, n, &x); //chamada da fun��o "parametros" que ir� obter os valores do vetor, de n e de x.
	
	return 0;
}

//fun��o que recebe um vetor, n e x como par�metros e imprime o vetor.
void parametros (int *vetor, int n, int *x){
	int i;
	
	//for para preencher o vetor com valores digitados pelo usu�rio e imprimir cada valor.
	for (i = 0; i < 10; i++){
		scanf("%d", &vetor[i]);
		printf("Vetor[%d]: %d\n", i + 1, vetor[i]);
	}
	
	//solicita ao usu�rio que digite valores para n e x.
	printf("Agora digite um valor inteiro para N e um valor inteiro para X, respectivamente.\n");
	scanf("%d %d", &n, &*x);
	
	verifica(vetor, &n, x); //chama a fun��o "verifica" para verificar se n e x est�o no vetor.
}

//fun��o respons�vel por verificar a presen�a de n e x no vetor.
void verifica (int *vet, int *n, int *x){
	int i = 0, nnovetor = 0, xnovetor = 0;
	
	//condi��o que ir� se repetir at� o fim da verifica��o (enquanto i for menor que 10) para descobrir se n e x est�o no vetor. 
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
	//imprime se n est� presente ou n�o no vetor.
	if (nnovetor) {
        printf("N = %d est� presente no conjunto digitado.\n", *n);
    } else {
        printf("N = %d n�o foi encontrado no conjunto digitado.\n", *n);
    }

    //imprime se x est� presente ou n�o no vetor.
    if (xnovetor) {
        printf("X = %d est� presente no conjunto digitado.\n", *x);
    } else {
        printf("X = %d n�o foi encontrado no conjunto digitado.\n", *x);
    }
}
