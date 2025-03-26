/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 12 - Fa�a um programa que preencha um vetor de tamanho 100 com os 100 primeiros naturais que n�o s�o
m�ltiplos de 7 ou que terminam com 7.*/
#include<stdio.h>
#include<locale.h>
#define N 100

//prot�tipo da fun��o que ir� preencher o vetor conforme enunciado.
void preencher(int *vetor);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i, vetor[N];
	
	preencher(vetor); //chama a fun��o para preencher o vetor.
	
	//imprime os 100 primeiros n�meros naturais que n�o s�o m�ltiplos de 7 ou que terminam com 7.
	printf("100 primeiros n�meros naturais que n�o s�o m�ltiplos de 7 ou que terminam com 7:\n");
    for (i = 0; i < N; i++) {
        printf("%d\n", vetor[i]);
    }

    return 0;
}
//fun��o para preencher o vetor com os primeiros N n�meros naturais que n�o s�o m�ltiplos de 7 ou terminam com 7.
void preencher(int *vetor){
	int i, aux = 0;
	
	for(i = 0; aux < N; i++){
		//condi��o para incluir apenas os n�meros que n�o s�o m�ltiplos de 7 ou terminam com 7.
		if (i % 7 != 0 && i % 10 != 7){
			//atribui o valor ao vetor e incrementa o �ndice aux.
			*(vetor + aux) = i;  
			aux++;
		}
	}
}
