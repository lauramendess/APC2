/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios 2 de APC2 e LAB2

Exercicio 2 - Crie e teste a funcao void InverteS(char *s) que retorna uma string invertida, utilizando ponteiros.
Por exemplo, se s = "Palindromo",
Apos a chamada a funcao InverteS(), s = "omordnilaP". */

#include<stdio.h>
#include<string.h>

#define TAM 50 //definicao de um valor para a constante TAM.

//declaracao da funcao responsavel por inverter uma string.
void inverteS(char *s);

int main (){
	
	char str[TAM];  //declaracao de uma string com tamanho maximo ja definido anteriormente.
	
	printf("Digite algo:\n");
	fgets(str, TAM, stdin); 
	
	printf("String antes da inversao: %s\n", str); 
	
	inverteS(str);  //chamada da funcao que ira inverter a string inserida pelo usuario.
	
	printf("String apos a inversao: %s\n", str);  //impressao da string apos a chamada da funcao inverteS.
	
	return 0;
}

//funcao responsavel por inverter a string inserida pelo usuario:
void inverteS(char *s){   
	
	char *inicio = s; //ponteiro que aponta para o inicio da string
	char *fim = s + strlen(s) - 1; //ponteiro que aponta para o final da string.
	char aux; 
	
	//enquanto o ponteiro de inicio for menor que o ponteiro de fim, a condicao ira se repetir.
	while (inicio < fim){
		
		//troca os caracteres apontados por inicio e fim com a ajuda da variavel "aux".
		aux = *inicio;
		*inicio = *fim;
		*fim = aux;
		
		inicio++;
		fim--;
	}
}
