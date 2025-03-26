/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 4 -  Faca um programa que recebe do usuario o vetor com 10 posicoes, com o uso da 
funcao imprimir() mostre o maior, o menor elemento do vetor e quais suas
posicoes. Na funcao imprimir() o vetor e manipulado com o uso de ponteiros.
*/
#include<stdio.h>
#include<stdlib.h>

 void imprimir(int *vet, int quantidade, int *vmaior, int *vmenor, int *posicaomaior, int *posicaomenor);

int main () {
	
	int i, Vetor[10], maior, menor, posmaior, posmenor;
	
	printf("Digite 10 numeros inteiros:\n");  // for para ler os numeros inseridos pelo usuario para o vetor.
	for(i = 0; i < 10; i++){
		scanf("%d", &Vetor[i]);
		printf("Vetor[%d] = %d\n", i, Vetor[i]);
	}
	
	imprimir(Vetor, 10, &maior, &menor, &posmaior, &posmenor); // chamando a funcao que ira verificar o maior e o menor valor e imprimir estes.
   
   system("pause");
}

 void imprimir(int *vet, int quantidade, int *vmaior, int *vmenor, int *posicaomaior, int *posicaomenor){ // funcao que imprime o maior e o menor numero do vetor e suas posicoes.
	int i;
	*posicaomaior = 0;
	*posicaomenor = 0;
	*vmenor = *vet;
	*vmaior = *vet;
	
	for(i = 0; i < quantidade; i++){  // for que ira verificar qual o valor maior do vetor e qual a sua posicao.
		if (*vmaior < *(vet + i)) {
		  *vmaior = *(vet + i);
		  *posicaomaior = i;
	  }
		if (*vmenor > *(vet + i)){   // for que ira verificar qual o valor menor do vetor e qual a sua posicao.
		  *vmenor = *(vet + i);
		  *posicaomenor = i;
	  }
	 }
	 printf("\nVetor maior = %d\nPosicao do vetor maior = %d\n", *vmaior, *posicaomaior);
	 printf("\nVetor menor = %d\nPosicao do vetor menor = %d\n", *vmenor, *posicaomenor);
 }
