/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 8 - Leia um vetor com 10 números reais, ordene os elementos deste vetor utilizando a função ordena() e no
final escreva os elementos do vetor ordenado com o uso da função imprima(). Utilize ponteiros para
acessar os elementos do vetor nas funções.*/
#include<stdio.h>
#include<locale.h>
#define N 10

//declaração dos protótipos das funções que serão utilizadas no programa.
void ordena(float *vet);
void imprima(float *vet);

int main (){
	setlocale(LC_ALL, "Portuguese");
	float vetor[N];
	int i;
	
	//solicita ao usuário que insira 10 números reais.
	printf("Digite 10 números reais:\n");
	for(i = 0; i < N; i++){
		scanf("%f", &vetor[i]);
		printf("Número %d digitado: %.2f\n", i + 1, vetor[i]);
	}
    ordena(vetor); //chama a função para ordenar os elementos do vetor.
    imprima(vetor); //chama a função para imprimir os elementos do vetor ordenado.
   
   return 0;
}
//função que ordena os elementos do vetor.
void ordena(float *vet){
	int i, j;
	float aux;
	
	for(i = 0; i < N; i++){
		for(j = i + 1; j < N; j++){
			if(*(vet + i) > *(vet + j)){ //compara os elementos e troca-os se estiverem fora de ordem.
				aux = *(vet + i);
				*(vet + i) = *(vet + j);
				*(vet + j) = aux;
			}
		}
	}
}
//função que imprime os elementos do vetor após a ordenação.
void imprima(float *vet){
	int i;
	
	printf("\nElementos do vetor após ordenação:\n");
	for(i = 0; i < N; i++){
	    printf("%.2f ", *(vet + i));
	}
}
