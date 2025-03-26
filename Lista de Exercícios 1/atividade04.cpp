/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 4 -  Faça um programa que recebe do usuário o vetor com 10 posições, com o uso da 
função imprimir() mostre o maior, o menor elemento do vetor e quais suas
posições. Na função imprimir() o vetor é manipulado com o uso de ponteiros.
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

 void imprimir(int *vet, int quantidade, int *vmaior, int *vmenor, int *posicaomaior, int *posicaomenor);

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int i, Vetor[10], maior, menor, posmaior, posmenor;
	
	printf("Digite 10 números inteiros:\n");  //for para ler os números inseridos pelo usuário para o vetor.
	for(i = 0; i < 10; i++){
		scanf("%d", &Vetor[i]);
		printf("Vetor[%d] = %d\n", i, Vetor[i]);
	}
    
	imprimir(Vetor, 10, &maior, &menor, &posmaior, &posmenor); //chamando a função que irá verificar o maior e o menor valor e imprimir estes.
   
   system("pause");
}

 void imprimir(int *vet, int quantidade, int *vmaior, int *vmenor, int *posicaomaior, int *posicaomenor){ //função que imprime o maior e o menor número do vetor e suas posições.
 	int i;
	*posicaomaior = 0;
	*posicaomenor = 0;
 	*vmenor = *vet;
 	*vmaior = *vet;
 	
 	for(i = 0; i < quantidade; i++){  //for que irá verificar qual o valor maior do vetor e qual a sua posição.
 		if (*vmaior < *(vet + i)) {
 		  *vmaior = *(vet + i);
 		  *posicaomaior = i;
      }
 		if (*vmenor > *(vet + i)){   //for que irá verificar qual o valor menor do vetor e qual a sua posição.
 		  *vmenor = *(vet + i);
 		  *posicaomenor = i;
	  }
	 }
	 printf("\nVetor maior = %d\nPosição do vetor maior = %d\n", *vmaior, *posicaomaior);
	 printf("\nVetor menor = %d\nPosição do vetor menor = %d\n", *vmenor, *posicaomenor);
 }
