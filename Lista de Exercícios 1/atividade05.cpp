/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 5 -Leia um vetor com 20 números inteiros. Crie a função repetidos() para acessar os
elementos do vetor e imprimir eliminando os números repetidos.
*/
#include<stdio.h>
#include<locale.h>
 
 void repetidos (int *vetores, int quantidade);

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int i, Vetor[20];
	
	printf("Digite 20 números inteiros:\n"); 
	for(i = 0; i < 20; i++){   //for para fazer a leitura dos números do vetor
		scanf("%d", &Vetor[i]);
		printf("Vetor[%d] = %d\n", i, Vetor[i]);
	}

	repetidos(Vetor, 20); //chamando a função que irá verificar se existem números repetidos e, se houver, excluí-los 
	
	return 0;
}
 void repetidos (int *vetores, int quantidade){
	int i, j, aux;
	
	printf("\nNúmeros inseridos pelo usuário (sem repetição):\n");
	
	for (i = 0; i < quantidade; i++){
		aux = 0;
	 for (j = i - 1; j >= 0; j--){
	   if(vetores[i] == vetores[j]){
	 	 aux = 1;   //se o número for repetido, o aux irá receber 1, se não, continuará igual a 0.
	   }
	 }
	 if (aux == 0){ //imprimindo os números excluindo os repetidos, ou seja, excluindo os aux = 1.
	 	printf("%d ", vetores[i]);
	 }
   }
}

