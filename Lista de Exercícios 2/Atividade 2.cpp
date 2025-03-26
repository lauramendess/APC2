/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios 2 de APC2 e LAB2

Exercício 2 - Crie e teste a função void InverteS(char *s) que retorna uma string invertida, utilizando ponteiros.
– Por exemplo, se s = “Palindromo”,
– Após a chamada a função InverteS(), s = “omordnilaP”. */

#include<stdio.h>
#include<string.h>
#include<locale.h>

#define TAM 50 //definição de um valor para a constante TAM.

//declaração da função responsável por inverter uma string.
 void inverteS(char *s);
 
 int main (){
 	setlocale(LC_ALL, "Portuguese"); //configura a localização para Português, para acentos e caracteres especiais.
 	
 	char str[TAM];  //declaração de uma string com tamanho máximo já definido anteriormente.
 	
 	printf("Digite algo:\n");
 	fgets(str, TAM, stdin); 
 	
 	printf("String antes da inversão: %s\n", str); 
 	
 	inverteS(str);  //chamada da função que irá inverter a string inserida pelo usuário.
 	
 	printf("String após a inversão: %s\n", str);  //impressão da string após a chamada da função inverteS.
 	
 	return 0;
 }
 
 //função responsável por inverter a string inserida pelo usuário:
 void inverteS(char *s){   
 
    char *inicio = s; //ponteiro que aponta para o início da string
    char *fim = s + strlen(s) - 1; //ponteiro que aponta para o final da string.
    char aux; 
    
    //enquanto o ponteiro de início for menor que o ponteiro de fim, a condição irá se repetir.
    while (inicio < fim){
    	
    	//troca os caracteres apontados por inicio e fim com a ajuda da variável "aux".
    	aux = *inicio;
    	*inicio = *fim;
    	*fim = aux;
    	
    	inicio++;
    	fim--;
	}
 }
