/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 7 - Escrever uma função recursiva que retorna o tamanho de um string, tamstring(char s[]).*/
#include<stdio.h>
#include<locale.h>
#define N 30

int tamstring(char s[]){
	if(s[0] == '\0') //para caso a string esteja vazia.
      return 0;
	else
	  return 1 + tamstring(s + 1); //soma 1 ao tamanho da string e chama a função recursiva novamente.
}
int main (){
	setlocale(LC_ALL, "Portuguese");
	char str[N];
	
	printf("Insira uma string: "); //pede ao usuário que insira uma string.
	gets(str);
	
	printf("O tamanho da string digitado é = %d", tamstring(str)); //imprime o tamanho e chama a função direto no printf.
	
	return 0;
}
