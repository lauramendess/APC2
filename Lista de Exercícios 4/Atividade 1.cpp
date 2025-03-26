/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 1 - Faça um programa que dado um número n, informado pelo usuário, faça a soma com todos os
seus antecessores pares e com ele, se ele for par.*/
#include<stdio.h>
#include<locale.h>

int soma(int n){
	if(n <= 0)  //caso n seja menor ou igual a zero, retornará 0.
	    return 0;
	    
	else if(n % 2 != 0) //caso n não seja um número par.
		return soma(n - 1);

	else //caso n seja um número par.
	    return n + soma(n - 2);
}
int main (){
	setlocale(LC_ALL, "Portuguese");
	int n;
	
	printf("Digite um número para calcular a soma com os seu antecessores pares (e com ele mesmo se também for par): "); //pede que o usuário informe o número.
	scanf("%d", &n);
	
	if (n < 0) { //testando se o número digitado é inválido, ou seja, negativo.
        printf("ERRO! Informe um número inteiro positivo.\n");
        return 1; 
    }
	
	printf("\nResultado: %d\n", soma(n)); //imprime o valor da soma já com a chamada da função direto no printf.
	
	return 0;
}
