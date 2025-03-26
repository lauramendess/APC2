/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 5 - Leia um vetor com 20 numeros inteiros. Crie a funcao repetidos() para acessar os
elementos do vetor e imprimir eliminando os numeros repetidos.
*/
#include<stdio.h>
 
void repetidos (int *vetores, int quantidade);

int main () {
	
	int i, Vetor[20];
	
	printf("Digite 20 numeros inteiros:\n"); 
	for(i = 0; i < 20; i++){   
		scanf("%d", &Vetor[i]);
		printf("Vetor[%d] = %d\n", i, Vetor[i]);
	}

	repetidos(Vetor, 20); // chamando a funcao que ira verificar se existem numeros repetidos e, se houver, exclui-los 
	
	return 0;
}
void repetidos (int *vetores, int quantidade){
	int i, j, aux;
	
	printf("\nNumeros inseridos pelo usuario (sem repeticao):\n");
	
	for (i = 0; i < quantidade; i++){
		aux = 0;
		for (j = i - 1; j >= 0; j--){
			if(vetores[i] == vetores[j]){
				aux = 1;   // se o numero for repetido, o aux ira receber 1, se nao, continuara igual a 0.
			}
		}
		if (aux == 0){ // imprimindo os numeros excluindo os repetidos, ou seja, excluindo os aux = 1.
			printf("%d ", vetores[i]);
		}
	}
}
