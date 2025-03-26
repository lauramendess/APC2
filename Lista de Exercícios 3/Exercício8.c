/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 8 - Fazer uma fun��o recursiva que conta o n�mero de ocorr�ncias de um determinado caracter, caract(char c, char s[]).*/
#include<stdio.h>
#include<locale.h>
#include<ctype.h>
#define N 30

int caract(char c, char s[]){
	if(s[0] == '\0') //para caso a string esteja vazia.
      return 0;
    //para caso o caracter atual seja diferente. Foi utilizada uma convers�o para min�sculo a fim de compara��es(caso seja digitado alguma letra mai�scula).
	else if (tolower(c) != tolower(s[0])) 
	  return caract(c, s + 1);
	else
	  return 1 + caract(c, s + 1); //se o caracter atual for igual ao procurado ir� somar 1 e fazer a chamada recursiva novamente.
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	char str[N];
	char c;
	
	printf("Insira uma string: "); //pede ao usu�rio que insira uma string.
	gets(str);
	printf("\nInsira um caracter para contar o n�mero de ocorr�ncias do mesmo: "); //pede ao usu�rio que insira um caracter.
	scanf("%c", &c);
	
	//imprime o valor de ocorr�ncias do caracter na string, j� chamando a fun��o direta.
	printf("\nO n�mero de ocorr�ncias do caracter '%c' na string %s � igual a = %d", c, str, caract(c, str)); 
	
	return 0;
}
