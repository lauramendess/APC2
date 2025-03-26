/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 7 - Faça um vetor de tamanho 50 preenchido com o seguinte valor: (i+5*i)%(i+1), sendo i a posição do elemento no vetor. Em seguida, usando a
função imprima() mostre os valores do vetor.
*/
#include<stdio.h>
#include<locale.h>

 void imprima (int *vet);

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int i;
	int vet[50];
	
	for (i = 0; i < 50; i++) {     //preenchendo o vetor com os valores
      vet[i] = (i + 5 * i) % (i + 1); 
    }
    imprima (vet); //chamando a função para imprimir os valores do vetor
     
    return 0;
}
 void imprima (int *vet){ //função que irá mostrar ao usuário os valores do vetor
 	int i;
 	
 	for(i = 0; i < 50; i++){
 		printf("Vetor[%d] = %d\n", i, *vet);
 		vet++;
	 }
 }
