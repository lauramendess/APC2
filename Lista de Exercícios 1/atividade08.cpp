/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 8 - Leia 2 vetores de 10 posi��es e, usando a fun��o armazena(), grave em um
terceiro vetor os valores contendo nas posi��es pares os elementos do 1�
vetor e nas �mpares os valores do 2� vetor. Use ponteiros para isso.
*/
#include<stdio.h>
#include<locale.h>

void armazena (int *vetor1, int *vetor2);

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int vet1[10], vet2[10];
	int i;
	
	printf("Digite 10 valores para o primeiro vetor:\n");
	for (i = 0; i < 10; i++){
		scanf("%d", &vet1[i]);
		printf("Vetor1 [%d] = %d\n", i, vet1[i]);
	}
	printf("\nDigite 10 valores para o segundo vetor:\n");
	for (i = 0; i < 10; i++){
		scanf("%d", &vet2[i]);
		printf("Vetor2 [%d] = %d\n", i, vet2[i]);
	}
	armazena (vet1, vet2); //chamando a fun��o que armazena os valores do vetor 1 e 2 no vetor 3
	
	return 0;
}

 void armazena (int *vetor1, int *vetor2){
 	int i; 
    int vetor3[10]; //declara��o do vetor que receber� os valores das posi��es pares do vetor 1 e das posi��es �mpares do vetor 2
    
 	for (i = 0; i < 10; i++){
  		if (i % 2 == 0)
  		 *(vetor3 + i) = *(vetor1 + i); //receber� os elementos das posi��es pares do vetor 1
  		 
  		else if (i % 2 == 1)
  		 *(vetor3 + i) = *(vetor2 + i); //receber� os elementos das posi��es �mpares do vetor 2
	}
	 
	printf("Terceiro vetor contendo valores das posi��es pares do vetor 1 e das posi��es �mpares do vetor 2:\n");
	for (i = 0; i < 10; i++){
		printf("Vetor 3 = %d\n", *(vetor3 + i)); //para imprimir o vetor 3 ao usu�rio
	}
 }
