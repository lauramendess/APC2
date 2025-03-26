/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 14 - Faça um programa que receba a entrada utilizando argc argv. Por exemplo, dada uma entrada no
formato (Dia Mês Ano) 28 08 2022 retorne 28 de agosto de 2022. Faça verificação de erros para o número
de parâmetros e para datas não válidas (28 08 2022).*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
		     
    //verifica se o número de argumentos fornecidos é diferente de 4.
	if(argc != 4){
		printf("-----ERRO-----\nUse data no formato: dia mês ano, inserindo todos números como inteiros!\n");
	    exit(1);
    }
    else {
    //declaração das variáveis para armazenar o dia, mês e ano fornecidos como argumentos.
	int mes, dia, ano;
	
	//array de strings contendo os nomes dos meses.
	char *nomemeses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	
	//array de inteiros representando o número de dias em cada mês. O primeiro elemento (índice 0) é zero, pois não existe mês com índice zero. 
	int diasmes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	//atoi retorna o valor inteiro representado pela string.
		dia = atoi(argv[1]);
		mes = atoi(argv[2]); 
		ano = atoi(argv[3]);
		
	//verifica se o ano é bissexto e atualiza o número de dias em fevereiro.
  	if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
		diasmes[2] = 29;
		printf("Ano bissexto! ");
    }
     //verifica se a data fornecida é válida.
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1 || dia > diasmes[mes]){
           printf("A data não é válida!\nUse data no formato: dia mês ano, inserindo todos números como inteiros!\n");
           return 1;
    }
    //imprime a data válida no formato especificado.
	else
		printf("Data válida!\nData: %s de %s de %s\n", argv[1], nomemeses[mes - 1], argv[3]);
    }
	return 0;
}
