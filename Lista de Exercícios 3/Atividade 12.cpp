/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 12 - Faça um programa que preencha um vetor de tamanho 100 com os 100 primeiros naturais que não são
múltiplos de 7 ou que terminam com 7.*/
#include<stdio.h>
#include<locale.h>
#define N 100

//protótipo da função que irá preencher o vetor conforme enunciado.
void preencher(int *vetor);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i, vetor[N];
	
	preencher(vetor); //chama a função para preencher o vetor.
	
	//imprime os 100 primeiros números naturais que não são múltiplos de 7 ou que terminam com 7.
	printf("100 primeiros números naturais que não são múltiplos de 7 ou que terminam com 7:\n");
    for (i = 0; i < N; i++) {
        printf("%d\n", vetor[i]);
    }

    return 0;
}
//função para preencher o vetor com os primeiros N números naturais que não são múltiplos de 7 ou terminam com 7.
void preencher(int *vetor){
	int i, aux = 0;
	
	for(i = 0; aux < N; i++){
		//condição para incluir apenas os números que não são múltiplos de 7 ou terminam com 7.
		if (i % 7 != 0 && i % 10 != 7){
			//atribui o valor ao vetor e incrementa o índice aux.
			*(vetor + aux) = i;  
			aux++;
		}
	}
}
