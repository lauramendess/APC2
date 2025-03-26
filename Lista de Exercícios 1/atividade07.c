/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 7 - Faca um vetor de tamanho 50 preenchido com o seguinte valor: (i+5*i)%(i+1), sendo i a posicao do elemento no vetor. Em seguida, usando a
funcao imprima() mostre os valores do vetor.
*/
#include<stdio.h>

void imprima (int *vet);

int main (){

	int i;
	int vet[50];
	
	for (i = 0; i < 50; i++) {     // preenchendo o vetor com os valores
	  vet[i] = (i + 5 * i) % (i + 1); 
	}
	imprima (vet); // chamando a funcao para imprimir os valores do vetor
	 
	return 0;
}
void imprima (int *vet){ // funcao que ira mostrar ao usuario os valores do vetor
	int i;
	
	for(i = 0; i < 50; i++){
		printf("Vetor[%d] = %d\n", i, *vet);
		vet++;
	 }
}
