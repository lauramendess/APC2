/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 8 - Fazer uma função recursiva que conta o número de ocorrências de um determinado caracter, caract(char c, char s[]).*/
#include<stdio.h>
#include<locale.h>
#include<ctype.h>
#define N 30

int caract(char c, char s[]){
	if(s[0] == '\0') //para caso a string esteja vazia.
      return 0;
    //para caso o caracter atual seja diferente. Foi utilizada uma conversão para minúsculo a fim de comparações(caso seja digitado alguma letra maiúscula).
	else if (tolower(c) != tolower(s[0])) 
	  return caract(c, s + 1);
	else
	  return 1 + caract(c, s + 1); //se o caracter atual for igual ao procurado irá somar 1 e fazer a chamada recursiva novamente.
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	char str[N];
	char c;
	
	printf("Insira uma string: "); //pede ao usuário que insira uma string.
	gets(str);
	printf("\nInsira um caracter para contar o número de ocorrências do mesmo: "); //pede ao usuário que insira um caracter.
	scanf("%c", &c);
	
	//imprime o valor de ocorrências do caracter na string, já chamando a função direta.
	printf("\nO número de ocorrências do caracter '%c' na string %s é igual a = %d", c, str, caract(c, str)); 
	
	return 0;
}
