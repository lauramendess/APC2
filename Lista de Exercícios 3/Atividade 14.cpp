/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 14 - Fa�a um programa que receba a entrada utilizando argc argv. Por exemplo, dada uma entrada no
formato (Dia M�s Ano) 28 08 2022 retorne 28 de agosto de 2022. Fa�a verifica��o de erros para o n�mero
de par�metros e para datas n�o v�lidas (28 08 2022).*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
		     
    //verifica se o n�mero de argumentos fornecidos � diferente de 4.
	if(argc != 4){
		printf("-----ERRO-----\nUse data no formato: dia m�s ano, inserindo todos n�meros como inteiros!\n");
	    exit(1);
    }
    else {
    //declara��o das vari�veis para armazenar o dia, m�s e ano fornecidos como argumentos.
	int mes, dia, ano;
	
	//array de strings contendo os nomes dos meses.
	char *nomemeses[] = {"Janeiro", "Fevereiro", "Mar�o", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	
	//array de inteiros representando o n�mero de dias em cada m�s. O primeiro elemento (�ndice 0) � zero, pois n�o existe m�s com �ndice zero. 
	int diasmes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	//atoi retorna o valor inteiro representado pela string.
		dia = atoi(argv[1]);
		mes = atoi(argv[2]); 
		ano = atoi(argv[3]);
		
	//verifica se o ano � bissexto e atualiza o n�mero de dias em fevereiro.
  	if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
		diasmes[2] = 29;
		printf("Ano bissexto! ");
    }
     //verifica se a data fornecida � v�lida.
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1 || dia > diasmes[mes]){
           printf("A data n�o � v�lida!\nUse data no formato: dia m�s ano, inserindo todos n�meros como inteiros!\n");
           return 1;
    }
    //imprime a data v�lida no formato especificado.
	else
		printf("Data v�lida!\nData: %s de %s de %s\n", argv[1], nomemeses[mes - 1], argv[3]);
    }
	return 0;
}
