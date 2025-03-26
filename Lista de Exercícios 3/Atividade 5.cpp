/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 5 - Fa�a um programa que leia um vetor de 15 posi��es e o compacte, ou seja, elimine as posi��es com valor
zero. Para isso, todos os elementos a frente do valor zero, devem ser movidos uma posi��o para tr�s no vetor
por meio da fun��o compacta() utilizando ponteiros para acessar as posi��es. */
#include<stdio.h>
#include<locale.h>

#define TAM 15
//declara��o do prot�tipo da fun��o que ir� compactar o vetor, eliminando as posi��es com valor zero
void compacta(int *vetor);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i, vet[15];
	 
	printf("Insira 15 n�meros inteiros para um conjunto:\n"); //pede ao usu�rio que insira 15 n�meros para preencher o vetor.
	for(i = 0; i < TAM; i++){
	  scanf("%d", &vet[i]);
	}
	compacta(vet); //chamada da fun��o que ir� eliminar as posi��es com zero.
	
	return 0;
}
void compacta(int *vetor){
	int i, j, novotam = TAM;
	
	//loop que verifica se h� posi��es com zero.
	for(i = 0; i < novotam; i++){
		if(*(vetor + i) == 0){
			for(j = i; j < novotam - 1; j++){
				*(vetor + j) = *(vetor + j + 1);
			}
			novotam--; //ap�s a elimina��o das posi��es que cont�m zeros, o tamanho do vetor � ajustado.
			i--;      //i � decrementado para garantir que a posi��o seja verificada novamente, evitando que um outro zero a tenha ocupado!
		}
    }
    for(i = 0; i < novotam; i++){
    	printf("%d ", *(vetor + i));
	}
}
