/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 3 - Fa�a um programa que leia dois vetores de 10 elementos. Crie um terceiro vetor, ainda no main(), que seja a
intersec��o entre os 2 vetores anteriores, ou seja, que cont�m apenas os n�meros que est�o em ambos os
vetores, n�o devendo conter n�meros repetidos. A verifica��o da intersec��o e armazenamento no vetor deve
ser feito por meio da fun��o intersec��o() e os vetores manipulados nessa fun��o com ponteiros.*/
#include<stdio.h>
#include<locale.h>

#define TAM 10
//prot�tipo da fun��o que calcula a interse��o de dois vetores.
void interseccao(int *vet1, int *vet2, int *vet3);

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int i, vetor1[TAM], vetor2[TAM], vetor3[TAM];
	
	printf("Digite 10 n�meros inteiros para o VETOR 1:\n"); //solicita ao usu�rio que digite 10 n�meros inteiros para o VETOR 1.
	for(i = 0; i < TAM; i++){
		scanf("%d", &vetor1[i]);
	}
	printf("\nDigite 10 n�meros inteiros para o VETOR 2:\n"); //solicita ao usu�rio que digite 10 n�meros inteiros para o VETOR 2.
	for(i = 0; i < TAM; i++){
		scanf("%d", &vetor2[i]);
	}
	
	interseccao(vetor1, vetor2, vetor3); //chama a fun��o para calcular a interse��o dos vetores 1 e 2 e adicionar no vetor 3.
	
	return 0;
}
 void interseccao(int *vet1, int *vet2, int *vet3){
	int i, j, aux;
	
	//calcula a interse��o dos vetores 1 e 2 e inicializa o vetor 3 com zeros.
	for(i = 0; i < TAM; i++){
	  *(vet3 + i) = 0;
		 for(j = 0; j < TAM; j++){
	       if(*(vet1 + i) == *(vet2 + j)){
	        *(vet3 + i) = *(vet1 + i);  //se o elemento � comum, armazena no vetor de interse��o 3.
		   }
        }
    }
    //mostra o vetor de interse��o, vetor 3, sem repetir n�meros.
    printf("\nVETOR 3 (Interse���o do VETOR 1 com o VETOR 2, sem repetir n�meros):\n");
    for(i = 0; i < TAM; i++){
    	if(*(vet3 + i) != 0){
    	  aux = 0;
    	
	 //verifica se o n�mero j� foi exibido anteriormente para evitar repeti��es.
         for (j = i - 1; j >= 0; j--){
    		if (*(vet3 + i) == *(vet3 + j))	
    		 aux = 1; //se o n�mero for repetido ele ir� receber 1.
		  }
		  //se n�o for repetido, exibe o n�mero, ou seja, se aux for igual a 0.
          if (aux == 0)
    	    printf("%d ", *(vet3 + i));
	   }
	}
}
