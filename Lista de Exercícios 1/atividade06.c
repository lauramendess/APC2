/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 6 - Faca um programa que leia um vetor de 10 posicoes para numeros reais e um codigo inteiro que escolhe uma opcao na funcao menu(). Na funcao menu(), se o
codigo for 0 finalize o programa; se for 1 chame a funcao imprime() e imprima o vetor na ordem direta; se for 2, chama a mesma funcao imprime() e mostre o vetor
na ordem inversa. Caso, o codigo seja diferente escreva uma mensagem informando codigo invalido. Todas as funcoes devem manipulador os vetores com o uso de ponteiros. 
*/
#include<stdio.h>
 
 void menu (float *Vet);
 void imprime (int opcao, float *Vet);
 
 int main (){
	
	float vet[10];
	int i;
		
	printf("-Insira 10 numeros reais:\n");
	
	for (i = 0; i < 10; i++){  // le os numeros inseridos pelo usuario
	 scanf("%f", &vet[i]);
	}
	
	printf("Escolha uma opcao desejada no menu a seguir:\n");
	menu (vet); // chamada da funcao menu 
	
	return 0;
}
  void menu (float *Vet){ // funcao menu que imprime ao usuario as opcoes para escolha e as manipula com o apoio da funcao imprime.
	int opcao;
	do{
	printf("\n1 - Mostrar o vetor na ordem direta\n");
	printf("\n2 - Mostrar o vetor na ordem inversa\n");
	printf("\n0 - Sair do programa\n");
	scanf("%d", &opcao);
	
	switch (opcao) 
	{
		case 1: imprime(opcao, Vet); break;
		
		case 2: imprime(opcao, Vet); break;
		
		case 0: printf("Programa finalizado!"); break;
		
		default: printf("\nOpcao invalida!\nEscolha uma opcao valida para executar o codigo:\n"); break;
	 }
	} while (opcao != 0);    
}
   void imprime (int opcao, float *Vet){ // funcao imprime que ira mostrar os vetores na tela com base a opcao escolhida.
	 int i;

		if (opcao == 1) {                // imprimira na ordem direta
		for (i = 0; i < 10; i++) {
			printf("%.2f ", *(Vet + i));
		}
	} else if (opcao == 2) {            // imprimira na ordem inversa
		for (i = 10 - 1; i >= 0; i--) {
			printf("%.2f ", *(Vet + i));
		}
	 } 
   }
