/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 2 - Ler um vetor de 8 posi��es e 2 valores X e Y, utilizando a fun��o procurar() veja
se os 2 valores est�o no vetor. Escrever os valores, se encontrados, e quais as
posi��es que X e Y est�o no vetor.
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void procurar(int *vetores, int quant, int x, int y);

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int vet[8], i;
	int X, Y;
	
	printf("-Digite 8 valores inteiros:\n");  //for que ir� ler os n�meros digitados pelo usu�rio para o vetor
	for (i = 0; i < 8; i++){
		scanf("%d", &vet[i]);
		printf("Vetor[%d]:%d\n", i, vet[i]);
	}
	
	printf("\nDigite um valor para X: ");
	scanf("%d", &X);
	printf("\nDigite um valor para Y: ");
	scanf("%d", &Y);
	printf("\nValor de X:%d\nValor de Y:%d\n", X, Y);
	
	procurar (vet, 8, X, Y); //chamada da fun��o que ir� verificar se existem n�meros no vetor iguais a x e y
	
	system("pause");
}

void procurar (int *vetores, int quant, int x, int y){ //fun��o que ir� buscar no vetor valores iguais ao de x e y
	int i;
	
	for (i = 0; i < quant; i++){
		if (x == vetores[i]) {  //verificadno se existe um n�mero comum a x no vetor 
			printf("\nO valor de X = %d foi encontrado no vetor na posi��o: %d\n", x, i);
	  }
	    if (y == vetores[i]){   //verificadno se existe um n�mero comum a y no vetor 
	    	printf("\nO valor de Y = %d foi encontrado no vetor na posi��o: %d\n", y, i);
	  }
    }
}
