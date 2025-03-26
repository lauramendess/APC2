/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 7 - Fa�a um vetor de tamanho 50 preenchido com o seguinte valor: (i+5*i)%(i+1), sendo i a posi��o do elemento no vetor. Em seguida, usando a
fun��o imprima() mostre os valores do vetor.
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
    imprima (vet); //chamando a fun��o para imprimir os valores do vetor
     
    return 0;
}
 void imprima (int *vet){ //fun��o que ir� mostrar ao usu�rio os valores do vetor
 	int i;
 	
 	for(i = 0; i < 50; i++){
 		printf("Vetor[%d] = %d\n", i, *vet);
 		vet++;
	 }
 }
