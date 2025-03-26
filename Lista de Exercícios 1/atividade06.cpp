/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 6 - Fa�a um programa que leia um vetor de 10 posi��es para n�meros reais e um c�digo inteiro que escolhe uma op��o na fun��o menu(). Na fun��o menu(), se o
c�digo for 0 finalize o programa; se for 1 chame a fun��o imprime() e imprima o vetor na ordem direta; se for 2, chama a mesma fun��o imprime() e mostre o vetor
na ordem inversa. Caso, o c�digo seja diferente escreva uma mensagem informando c�digo inv�lido. Todas as fun��es devem manipulador os vetores com o uso de ponteiros. 
*/
#include<stdio.h>
#include<locale.h>
 
 void menu (float *Vet);
 void imprime (int opcao, float *Vet);
 
 int main (){
 	setlocale(LC_ALL, "Portuguese");
 	
 	float vet[10];
 	int i;
 		
	printf("-Insira 10 n�meros reais:\n");
	
	for (i = 0; i < 10; i++){  //l� os n�meros inseridos pelo usu�rio
	 scanf("%f", &vet[i]);
	}
	
	printf("Escolha um op��o desejada no menu a seguir:\n");
	menu (vet); //chamada da fun��o menu 
	
	return 0;
}
  void menu (float *Vet){ //fun��o menu que imprime ao usu�rio as op��es para escolha e as manipula com o apoio da fun��o imprime.
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
    	
    	default: printf("\nOp��o inv�lida!\nEscolha uma op��o v�lida para executar o c�digo:\n"); break;
	 }
	} while (opcao != 0);    
}
   void imprime (int opcao, float *Vet){ //fun��o imprime que ir� mostrar os vetores na tela com base a op��o escolhida.
   	 int i;

   	    if (opcao == 1) {                //imprimir� na ordem direta
        for (i = 0; i < 10; i++) {
            printf("%.2f ", *(Vet + i));
        }
    } else if (opcao == 2) {            //imprimir� na ordem inversa
        for (i = 10 - 1; i >= 0; i--) {
            printf("%.2f ", *(Vet + i));
        }
     } 
   }
