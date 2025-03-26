/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 7 - Escrever uma funcao recursiva que retorna o tamanho de um string, tamstring(char s[]).
*/
#include<stdio.h>
#define N 30

int tamstring(char s[]){
	if(s[0] == '\0') // para caso a string esteja vazia.
	  return 0;
	  
	else
	  return 1 + tamstring(s + 1); // soma 1 ao tamanho da string e chama a funcao recursiva novamente.
}

int main (){
	char str[N];
	
	printf("Insira uma string: "); 
	gets(str);
	
	printf("O tamanho da string digitado e = %d", tamstring(str)); // imprime o tamanho e chama a funcao direto no printf.
	
	return 0;
}
