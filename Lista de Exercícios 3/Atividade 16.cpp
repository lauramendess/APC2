/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 16 - Construa um programa que receba da linha de comando, com a qual o programa é executado, três
valores em ponto flutuante, verifique por meio de uma função chamada triangulo() qual seu tipo, e, informe
na saída padrão se estes podem ou não formar os lados de um triângulo e qual tipo seria: Equilátero,
Isósceles ou Escaleno. Os valores devem ser passados para a função triangulo() por meio de ponteiros.*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//declaração do protótipo da função que será usado.
void triangulo(float *num1, float *num2, float *num3);

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
	
	//verifica se foram fornecidos exatamente três argumentos.
	if(argc != 4){
		printf("-----ERRO-----\nVocê não inseriu os números corretamente!\nInsira três valores reais no formato: n1 n2 n3.\n");
	    exit(1);
	}
	else {
	//atof retorna o valor em ponto flutuante representado por uma sequência de caracteres 
		float lado1 = atof(argv[1]);
		float lado2 = atof(argv[2]); 
		float lado3 = atof(argv[3]);
		
		triangulo(&lado1, &lado2, &lado3); //chamada da função que irá verificar se os números podem formar um triângulo.
	}
	
	return 0;
}

//função para verificar se os lados podem formar um triângulo e, se sim, o tipo de triângulo com base nos lados fornecidos.
void triangulo(float *num1, float *num2, float *num3){
	
	//verifica se os lados fornecidos atendem à Desigualdade Triangular.
	if ((*num1 + *num2 > *num3) && (*num1 + *num3 > *num2) && (*num2 + *num3 > *num1)){
		printf("Os valores inseridos podem formar um triângulo do tipo: ");
	
	//verifica o tipo de triângulo com base nos lados fornecidos.
	   if (*num1 == *num2 && *num2 == *num3)
		 printf("Equilátero\nTodos os lados iguais!\n");
   	    
   	   else if (*num1 == *num2 || *num1 == *num3 || *num2 == *num3)
   	   	 printf("Isósceles\nPossui dois lados com medidas iguais!\n");
	
	   else
	     printf("Escaleno\nTodos os lados com medidas diferentes!\n");
    }
	else 
		printf("Os valores inseridos não atendem a regrinha da Desigualdade Triangular. Logo, não podem formar um triângulo!\n");
		
   system("pause");	
}
