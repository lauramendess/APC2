/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 9 - Considere um vetor A com 11 elementos onde A1 < A2 < · · · < A6 > A7 > A8 > · · · > A11, ou seja, está
ordenado em ordem crescente até o sexto elemento e a partir desse elemento está ordenado em ordem
decrescente. Dado o vetor da questão anterior, faça uma função para ordenar os elementos, acesse o vetor
por meio de ponteiros.*/
#include<stdio.h>
#include<locale.h>

#define tamanho 11

//função para ordenar o vetor conforme especificações do enunciado.
void ordena(float *vetor){
	int i, j, aux, meio = 5;
	
	//ordena a primeira metade em ordem crescente
	for(i = 0; i < meio; i++){
		for(j = i + 1; j < meio; j++){
			if(*(vetor + i) > *(vetor + j)){
				aux = *(vetor + i);
				*(vetor + i) = *(vetor + j); 
				*(vetor + j) = aux;
			}
		}
	}
	//ordena a segunda metade em ordem decrescente
	for(i = meio; i < tamanho; i++){
		for(j = i + 1; j < tamanho; j++){
			if(*(vetor + i) < *(vetor + j)){
				aux = *(vetor + i);
				*(vetor + i) = 	*(vetor + j); 
				*(vetor + j) = aux;
			}
		}
	}
}
//função para imprimir os vetores ordenados.
void ordenaeimprime(float *vetor, float *crescente){
	int i, j, aux;
	
	//imprime os números ordenados no formato dado no enunciado da questão.
	printf("Vetores ordenados no formato: A1 < A2 < · · · < A6 > A7 > A8 > · · · > A11\n");
	for(i = 0; i < tamanho; i++){
		printf("%.1f ", *(vetor + i));
	}
	printf("\n");
	//ordena o vetor em ordem crescente.
	for(i = 0; i < tamanho; i++){
		for(j = i + 1; j < tamanho; j++){
			if(*(crescente + i) > *(crescente + j)){
				aux = *(crescente + i);
				*(crescente + i) = *(crescente + j);
				*(crescente + j) = aux;
			}
		}
	}
	printf("\nVetores ordenados em ordem crescente:\n"); //imprime o vetor original, mas todos os números em ordem crescente.
	for (i = 0; i < tamanho; i++){
		printf("%.1f ", *(crescente + i));
	}
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	float vetor[] = {1, 4, 5, 3, 2, 6, 8, 7, 10, 9, 11};
	float crescente[tamanho];
	
    for (int i = 0; i < tamanho; i++) {
        crescente[i] = vetor[i];
    }
	ordena(vetor); //chama a função para ordenar o vetor conforme o formato do enunciado.
	ordenaeimprime(vetor, crescente); //chama a função para imprimir os vetores ordenados e ordenar em crescente.
	
	return 0;
}
