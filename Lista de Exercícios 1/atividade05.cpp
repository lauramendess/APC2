/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 5 -Leia um vetor com 20 n�meros inteiros. Crie a fun��o repetidos() para acessar os
elementos do vetor e imprimir eliminando os n�meros repetidos.
*/
#include<stdio.h>
#include<locale.h>
 
 void repetidos (int *vetores, int quantidade);

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int i, Vetor[20];
	
	printf("Digite 20 n�meros inteiros:\n"); 
	for(i = 0; i < 20; i++){   //for para fazer a leitura dos n�meros do vetor
		scanf("%d", &Vetor[i]);
		printf("Vetor[%d] = %d\n", i, Vetor[i]);
	}

	repetidos(Vetor, 20); //chamando a fun��o que ir� verificar se existem n�meros repetidos e, se houver, exclu�-los 
	
	return 0;
}
 void repetidos (int *vetores, int quantidade){
	int i, j, aux;
	
	printf("\nN�meros inseridos pelo usu�rio (sem repeti��o):\n");
	
	for (i = 0; i < quantidade; i++){
		aux = 0;
	 for (j = i - 1; j >= 0; j--){
	   if(vetores[i] == vetores[j]){
	 	 aux = 1;   //se o n�mero for repetido, o aux ir� receber 1, se n�o, continuar� igual a 0.
	   }
	 }
	 if (aux == 0){ //imprimindo os n�meros excluindo os repetidos, ou seja, excluindo os aux = 1.
	 	printf("%d ", vetores[i]);
	 }
   }
}

