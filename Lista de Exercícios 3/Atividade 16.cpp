/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 16 - Construa um programa que receba da linha de comando, com a qual o programa � executado, tr�s
valores em ponto flutuante, verifique por meio de uma fun��o chamada triangulo() qual seu tipo, e, informe
na sa�da padr�o se estes podem ou n�o formar os lados de um tri�ngulo e qual tipo seria: Equil�tero,
Is�sceles ou Escaleno. Os valores devem ser passados para a fun��o triangulo() por meio de ponteiros.*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//declara��o do prot�tipo da fun��o que ser� usado.
void triangulo(float *num1, float *num2, float *num3);

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
	
	//verifica se foram fornecidos exatamente tr�s argumentos.
	if(argc != 4){
		printf("-----ERRO-----\nVoc� n�o inseriu os n�meros corretamente!\nInsira tr�s valores reais no formato: n1 n2 n3.\n");
	    exit(1);
	}
	else {
	//atof retorna o valor em ponto flutuante representado por uma sequ�ncia de caracteres 
		float lado1 = atof(argv[1]);
		float lado2 = atof(argv[2]); 
		float lado3 = atof(argv[3]);
		
		triangulo(&lado1, &lado2, &lado3); //chamada da fun��o que ir� verificar se os n�meros podem formar um tri�ngulo.
	}
	
	return 0;
}

//fun��o para verificar se os lados podem formar um tri�ngulo e, se sim, o tipo de tri�ngulo com base nos lados fornecidos.
void triangulo(float *num1, float *num2, float *num3){
	
	//verifica se os lados fornecidos atendem � Desigualdade Triangular.
	if ((*num1 + *num2 > *num3) && (*num1 + *num3 > *num2) && (*num2 + *num3 > *num1)){
		printf("Os valores inseridos podem formar um tri�ngulo do tipo: ");
	
	//verifica o tipo de tri�ngulo com base nos lados fornecidos.
	   if (*num1 == *num2 && *num2 == *num3)
		 printf("Equil�tero\nTodos os lados iguais!\n");
   	    
   	   else if (*num1 == *num2 || *num1 == *num3 || *num2 == *num3)
   	   	 printf("Is�sceles\nPossui dois lados com medidas iguais!\n");
	
	   else
	     printf("Escaleno\nTodos os lados com medidas diferentes!\n");
    }
	else 
		printf("Os valores inseridos n�o atendem a regrinha da Desigualdade Triangular. Logo, n�o podem formar um tri�ngulo!\n");
		
   system("pause");	
}
