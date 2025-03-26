/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios 2 de APC2 e LAB2

Exerc�cio 2 - Crie e teste a fun��o void InverteS(char *s) que retorna uma string invertida, utilizando ponteiros.
� Por exemplo, se s = �Palindromo�,
� Ap�s a chamada a fun��o InverteS(), s = �omordnilaP�. */

#include<stdio.h>
#include<string.h>
#include<locale.h>

#define TAM 50 //defini��o de um valor para a constante TAM.

//declara��o da fun��o respons�vel por inverter uma string.
 void inverteS(char *s);
 
 int main (){
 	setlocale(LC_ALL, "Portuguese"); //configura a localiza��o para Portugu�s, para acentos e caracteres especiais.
 	
 	char str[TAM];  //declara��o de uma string com tamanho m�ximo j� definido anteriormente.
 	
 	printf("Digite algo:\n");
 	fgets(str, TAM, stdin); 
 	
 	printf("String antes da invers�o: %s\n", str); 
 	
 	inverteS(str);  //chamada da fun��o que ir� inverter a string inserida pelo usu�rio.
 	
 	printf("String ap�s a invers�o: %s\n", str);  //impress�o da string ap�s a chamada da fun��o inverteS.
 	
 	return 0;
 }
 
 //fun��o respons�vel por inverter a string inserida pelo usu�rio:
 void inverteS(char *s){   
 
    char *inicio = s; //ponteiro que aponta para o in�cio da string
    char *fim = s + strlen(s) - 1; //ponteiro que aponta para o final da string.
    char aux; 
    
    //enquanto o ponteiro de in�cio for menor que o ponteiro de fim, a condi��o ir� se repetir.
    while (inicio < fim){
    	
    	//troca os caracteres apontados por inicio e fim com a ajuda da vari�vel "aux".
    	aux = *inicio;
    	*inicio = *fim;
    	*fim = aux;
    	
    	inicio++;
    	fim--;
	}
 }
