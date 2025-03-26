/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 1 - Ler um conjunto de números reais, armazenando-os em vetor, enviá-los para a
função quadrado() e calcular o quadrado de cada número, armazenando o
resultado em outro vetor. Os vetores têm 10 elementos cada. Imprimir todos
os vetores por meio da função imprimir().
*/
#include<stdio.h>
#include<stdlib.h>

void quadrado(float *vetoresiniciais, float *vetorescalculados, int n);
void imprimir(float *vet, int n);

int main (){
	
	float vetiniciais[10], vetcalculados[10];
	int i;
	
	printf("-Insira 10 numeros reais:\n");
	
	for (i = 0; i < 10; i++){
		scanf("%f", &vetiniciais[i]);
	}
	
	quadrado(vetiniciais, vetcalculados, 10); // Chamada da função que calcula o quadrado dos números.
	
    printf("Vetores de entrada:\n");
    imprimir(vetiniciais, 10);

    printf("Vetores calculados:\n");
    imprimir(vetcalculados, 10);
	
	system("pause");
}
 void quadrado(float *vetoresiniciais, float *vetorescalculados, int n){ // Função que calculará os quadrados dos números.
 	int i;
 	for (i = 0; i < n; i++){
 	 vetorescalculados[i] = vetoresiniciais[i] * vetoresiniciais[i];
   }
 }
   
 void imprimir(float *vet, int n){ //Função que irá imprimir na tela os números dos vetores.
 	int i;
 	for (i = 0; i < n; i++){
 		printf("Vetor [%d]: %.2f\n", i, vet[i]);
	 }
  }
 
