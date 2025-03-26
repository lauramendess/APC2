/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 2 - Ler um vetor de 8 posições e 2 valores X e Y, utilizando a função procurar() veja
se os 2 valores estão no vetor. Escrever os valores, se encontrados, e quais as
posições que X e Y estão no vetor.
*/
#include<stdio.h>
#include<stdlib.h>

void procurar(int *vetores, int quant, int x, int y);

int main (){
	
	int vet[8], i;
	int X, Y;
	
	printf("-Digite 8 valores inteiros:\n");  
	for (i = 0; i < 8; i++){
		scanf("%d", &vet[i]);
		printf("Vetor[%d]:%d\n", i, vet[i]);
	}
	
	printf("\nDigite um valor para X: ");
	scanf("%d", &X);
	printf("\nDigite um valor para Y: ");
	scanf("%d", &Y);
	printf("\nValor de X:%d\nValor de Y:%d\n", X, Y);
	
	procurar (vet, 8, X, Y); //chamada da função que irá verificar se existem números no vetor iguais a x e y
	
	system("pause");
}

void procurar (int *vetores, int quant, int x, int y){ //função que irá buscar no vetor valores iguais ao de x e y
	int i;
	
	for (i = 0; i < quant; i++){
		if (x == vetores[i]) {  // verificadno se existe um número comum a x no vetor 
			printf("\nO valor de X = %d foi encontrado no vetor na posicao: %d\n", x, i);
	  }
	    if (y == vetores[i]){   // verificadno se existe um número comum a y no vetor 
	    	printf("\nO valor de Y = %d foi encontrado no vetor na posicao: %d\n", y, i);
	  }
    }
}
