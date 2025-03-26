/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 3 - Faça um programa que leia dois vetores de 10 elementos. Crie um terceiro vetor, ainda no main(), que seja a
intersecção entre os 2 vetores anteriores, ou seja, que contêm apenas os números que estão em ambos os
vetores, não devendo conter números repetidos. A verificação da intersecção e armazenamento no vetor deve
ser feito por meio da função intersecção() e os vetores manipulados nessa função com ponteiros.*/
#include<stdio.h>
#include<locale.h>

#define TAM 10
//protótipo da função que calcula a interseção de dois vetores.
void interseccao(int *vet1, int *vet2, int *vet3);

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int i, vetor1[TAM], vetor2[TAM], vetor3[TAM];
	
	printf("Digite 10 números inteiros para o VETOR 1:\n"); //solicita ao usuário que digite 10 números inteiros para o VETOR 1.
	for(i = 0; i < TAM; i++){
		scanf("%d", &vetor1[i]);
	}
	printf("\nDigite 10 números inteiros para o VETOR 2:\n"); //solicita ao usuário que digite 10 números inteiros para o VETOR 2.
	for(i = 0; i < TAM; i++){
		scanf("%d", &vetor2[i]);
	}
	
	interseccao(vetor1, vetor2, vetor3); //chama a função para calcular a interseção dos vetores 1 e 2 e adicionar no vetor 3.
	
	return 0;
}
 void interseccao(int *vet1, int *vet2, int *vet3){
	int i, j, aux;
	
	//calcula a interseção dos vetores 1 e 2 e inicializa o vetor 3 com zeros.
	for(i = 0; i < TAM; i++){
	  *(vet3 + i) = 0;
		 for(j = 0; j < TAM; j++){
	       if(*(vet1 + i) == *(vet2 + j)){
	        *(vet3 + i) = *(vet1 + i);  //se o elemento é comum, armazena no vetor de interseção 3.
		   }
        }
    }
    //mostra o vetor de interseção, vetor 3, sem repetir números.
    printf("\nVETOR 3 (Interseçção do VETOR 1 com o VETOR 2, sem repetir números):\n");
    for(i = 0; i < TAM; i++){
    	if(*(vet3 + i) != 0){
    	  aux = 0;
    	
	 //verifica se o número já foi exibido anteriormente para evitar repetições.
         for (j = i - 1; j >= 0; j--){
    		if (*(vet3 + i) == *(vet3 + j))	
    		 aux = 1; //se o número for repetido ele irá receber 1.
		  }
		  //se não for repetido, exibe o número, ou seja, se aux for igual a 0.
          if (aux == 0)
    	    printf("%d ", *(vet3 + i));
	   }
	}
}
