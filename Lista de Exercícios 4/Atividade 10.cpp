/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 10 - Escreva a vers�o iterativa da fun��o MaximoR.*/
#include<stdio.h>
#include<locale.h>

int MaximoR(int v[], int n){ //fun��o que encontra o m�ximo de um vetor.
	int i;
	int max = v[0]; 
	for(i = 0; i < n; i++){
		if(v[i] > max)
		 max = v[i];
	}
	return max;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int v[50], n, i;
    
    printf("Digite o tamanho do conjunto que deseja inserir:\n"); //pede ao usu�rio que insira o tamanho do vetor que ser� inserido posteriormente.
    scanf("%d", &n);
    
    printf("Digite os valores do conjunto para descobrir o seu m�ximo:\n"); //pede ao usu�rio que insira os valores para o vetor.
    for(i = 0; i < n; i++){
    scanf("%d", &v[i]);
    }
    printf("O valor m�ximo do conjunto inserido �: %d", MaximoR(v, n)); //imprime na tela o valor m�ximo do vetor.
    
    return 0;
}
