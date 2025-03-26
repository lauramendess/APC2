/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 1 - Ler um conjunto de n�meros reais, armazenando-os em vetor, envi�-los para a
fun��o quadrado() e calcular o quadrado de cada n�mero, armazenando o
resultado em outro vetor. Os vetores t�m 10 elementos cada. Imprimir todos
os vetores por meio da fun��o imprimir().
*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void quadrado(float *vetoresiniciais, float *vetorescalculados, int n);
void imprimir(float *vet, int n);

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	float vetiniciais[10], vetcalculados[10];
	int i;
	
	printf("-Insira 10 n�meros reais:\n");
	
	for (i = 0; i < 10; i++){
		scanf("%f", &vetiniciais[i]);
	}
	
	quadrado(vetiniciais, vetcalculados, 10); //Chamada da fun��o que calcula o quadrado dos n�meros.
	
    printf("Vetores de entrada:\n");
    imprimir(vetiniciais, 10);

    printf("Vetores calculados:\n");
    imprimir(vetcalculados, 10);
	
	system("pause");
}
 void quadrado(float *vetoresiniciais, float *vetorescalculados, int n){ //Fun��o que calcular� os quadrados dos n�meros.
 	int i;
 	for (i = 0; i < n; i++){
 	 vetorescalculados[i] = vetoresiniciais[i] * vetoresiniciais[i];
   }
 }
   
 void imprimir(float *vet, int n){ //Fun��o que ir� imprimir na tela os n�meros dos vetores.
 	int i;
 	for (i = 0; i < n; i++){
 		printf("Vetor [%d]: %.2f\n", i, vet[i]);
	 }
  }
 
