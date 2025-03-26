/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 8 - Leia um vetor com 10 n�meros reais, ordene os elementos deste vetor utilizando a fun��o ordena() e no
final escreva os elementos do vetor ordenado com o uso da fun��o imprima(). Utilize ponteiros para
acessar os elementos do vetor nas fun��es.*/
#include<stdio.h>
#include<locale.h>
#define N 10

//declara��o dos prot�tipos das fun��es que ser�o utilizadas no programa.
void ordena(float *vet);
void imprima(float *vet);

int main (){
	setlocale(LC_ALL, "Portuguese");
	float vetor[N];
	int i;
	
	//solicita ao usu�rio que insira 10 n�meros reais.
	printf("Digite 10 n�meros reais:\n");
	for(i = 0; i < N; i++){
		scanf("%f", &vetor[i]);
		printf("N�mero %d digitado: %.2f\n", i + 1, vetor[i]);
	}
    ordena(vetor); //chama a fun��o para ordenar os elementos do vetor.
    imprima(vetor); //chama a fun��o para imprimir os elementos do vetor ordenado.
   
   return 0;
}
//fun��o que ordena os elementos do vetor.
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
//fun��o que imprime os elementos do vetor ap�s a ordena��o.
void imprima(float *vet){
	int i;
	
	printf("\nElementos do vetor ap�s ordena��o:\n");
	for(i = 0; i < N; i++){
	    printf("%.2f ", *(vet + i));
	}
}
