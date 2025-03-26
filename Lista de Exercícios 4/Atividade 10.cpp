/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 10 - Escreva a versão iterativa da função MaximoR.*/
#include<stdio.h>
#include<locale.h>

int MaximoR(int v[], int n){ //função que encontra o máximo de um vetor.
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
    
    printf("Digite o tamanho do conjunto que deseja inserir:\n"); //pede ao usuário que insira o tamanho do vetor que será inserido posteriormente.
    scanf("%d", &n);
    
    printf("Digite os valores do conjunto para descobrir o seu máximo:\n"); //pede ao usuário que insira os valores para o vetor.
    for(i = 0; i < n; i++){
    scanf("%d", &v[i]);
    }
    printf("O valor máximo do conjunto inserido é: %d", MaximoR(v, n)); //imprime na tela o valor máximo do vetor.
    
    return 0;
}
