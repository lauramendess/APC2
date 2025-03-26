/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 9 - Escreva uma função recursiva que produza o reverso de um string, reverse(char s[]).*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#define N 30

void reverse(char s[], int i, int f) {
	int aux;	
	if (s[0] == '\0') { //para caso a string esteja vazia.
	 	printf("Nada foi digitado!");
        exit(1);
    }
    else if (i < f) { //para trocar os caracteres das posições i e f.
        aux = s[i];
        s[i] = s[f];
        s[f] = aux;
        reverse(s, i + 1, f - 1); //chamada da função recursiva até que tudo seja verificado.
    }
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    char str[N];
    int i = 0, f;

    printf("Digite uma string: "); //pede ao usuário que insira a string.
    gets(str);
    
    f = strlen(str) - 1; //atribuindo o tamanho da string a f, subtraindo o '\0'.
    reverse(str, i, f); //chama a função recursiva que irá inverter os caracteres.
    printf("String invertida: %s\n", str); //imprime a string invertida na tela.

    return 0;
}
