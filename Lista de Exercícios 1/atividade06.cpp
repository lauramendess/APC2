/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 6 - Faça um programa que leia um vetor de 10 posições para números reais e um código inteiro que escolhe uma opção na função menu(). Na função menu(), se o
código for 0 finalize o programa; se for 1 chame a função imprime() e imprima o vetor na ordem direta; se for 2, chama a mesma função imprime() e mostre o vetor
na ordem inversa. Caso, o código seja diferente escreva uma mensagem informando código inválido. Todas as funções devem manipulador os vetores com o uso de ponteiros. 
*/
#include<stdio.h>
#include<locale.h>
 
 void menu (float *Vet);
 void imprime (int opcao, float *Vet);
 
 int main (){
 	setlocale(LC_ALL, "Portuguese");
 	
 	float vet[10];
 	int i;
 		
	printf("-Insira 10 números reais:\n");
	
	for (i = 0; i < 10; i++){  //lê os números inseridos pelo usuário
	 scanf("%f", &vet[i]);
	}
	
	printf("Escolha um opção desejada no menu a seguir:\n");
	menu (vet); //chamada da função menu 
	
	return 0;
}
  void menu (float *Vet){ //função menu que imprime ao usuário as opções para escolha e as manipula com o apoio da função imprime.
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
    	
    	default: printf("\nOpção inválida!\nEscolha uma opção válida para executar o código:\n"); break;
	 }
	} while (opcao != 0);    
}
   void imprime (int opcao, float *Vet){ //função imprime que irá mostrar os vetores na tela com base a opção escolhida.
   	 int i;

   	    if (opcao == 1) {                //imprimirá na ordem direta
        for (i = 0; i < 10; i++) {
            printf("%.2f ", *(Vet + i));
        }
    } else if (opcao == 2) {            //imprimirá na ordem inversa
        for (i = 10 - 1; i >= 0; i--) {
            printf("%.2f ", *(Vet + i));
        }
     } 
   }
