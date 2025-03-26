/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 4 -  Fa�a um programa que recebe do usu�rio o vetor com 10 posi��es, com o uso da 
fun��o imprimir() mostre o maior, o menor elemento do vetor e quais suas
posi��es. Na fun��o imprimir() o vetor � manipulado com o uso de ponteiros.
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

 void imprimir(int *vet, int quantidade, int *vmaior, int *vmenor, int *posicaomaior, int *posicaomenor);

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int i, Vetor[10], maior, menor, posmaior, posmenor;
	
	printf("Digite 10 n�meros inteiros:\n");  //for para ler os n�meros inseridos pelo usu�rio para o vetor.
	for(i = 0; i < 10; i++){
		scanf("%d", &Vetor[i]);
		printf("Vetor[%d] = %d\n", i, Vetor[i]);
	}
    
	imprimir(Vetor, 10, &maior, &menor, &posmaior, &posmenor); //chamando a fun��o que ir� verificar o maior e o menor valor e imprimir estes.
   
   system("pause");
}

 void imprimir(int *vet, int quantidade, int *vmaior, int *vmenor, int *posicaomaior, int *posicaomenor){ //fun��o que imprime o maior e o menor n�mero do vetor e suas posi��es.
 	int i;
	*posicaomaior = 0;
	*posicaomenor = 0;
 	*vmenor = *vet;
 	*vmaior = *vet;
 	
 	for(i = 0; i < quantidade; i++){  //for que ir� verificar qual o valor maior do vetor e qual a sua posi��o.
 		if (*vmaior < *(vet + i)) {
 		  *vmaior = *(vet + i);
 		  *posicaomaior = i;
      }
 		if (*vmenor > *(vet + i)){   //for que ir� verificar qual o valor menor do vetor e qual a sua posi��o.
 		  *vmenor = *(vet + i);
 		  *posicaomenor = i;
	  }
	 }
	 printf("\nVetor maior = %d\nPosi��o do vetor maior = %d\n", *vmaior, *posicaomaior);
	 printf("\nVetor menor = %d\nPosi��o do vetor menor = %d\n", *vmenor, *posicaomenor);
 }
