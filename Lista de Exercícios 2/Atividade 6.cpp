/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios 2 de APC2 e LAB2

Exerc�cio 6 - Construa um programa que calcule a quantidade de latas de tinta necess�rias e o custo para
pintar tanques cil�ndricos de combust�vel. Use ponteiros para envio dos dados a uma fun��o calcula(). Onde s�o fornecidos a altura e o raio desse cilindro.
� Sabendo que: 
� a lata de tinta custa R$20,00
� cada lata cont�m 5 litros
� cada litro de tinta pinta 3 metros quadrados.
� �rea do cilindro = 2 vezes a �rea da base + circunfer�ncia da base vezes a altura (A = 2pr� + 2prh)
� o raio e altura s�o dados de entrada*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

//defini��o de constantes.
#define PRECO 20
#define L 5
#define P 3

double calcula(double *raio, double *altura); //prot�tipo da fun��o que ir� calcular a �rea do cilindro.
void custocalculo(double *area, double *quantidade, double *custototal); //prot�tipo da fun��o que ir� calcular a quantidade de latas e o custo total.

int main (){
	setlocale(LC_ALL, "Portuguese"); //valores decimais devem ser inseridos com v�rgula por conta da configura��o em portugu�s.
  
    double raiocilindro, alturacilindro, areacilindro, qntlatas, custo;
    
    //solicita ao usu�rio que insira o raio e a altura do cilindro.
    printf("Informe o raio e a altura do cilindro, respectivamente, a serem pintados:\n");
    scanf("%lf %lf", &raiocilindro, &alturacilindro);
    
    //imprime as informa��es ao usu�rio. 
    printf("\tDADOS\t\nRaio do cilindro = %.2lf metros.\nAltura do cilindro = %.2lf metros.\n", raiocilindro, alturacilindro);
    printf("Pre�o da lata de tinta = R$%d,00 reais.\nVolume da lata de tinta = %d litros.\n�rea pintada por litro de tinta = %d metros quadrados.\n", PRECO, L, P);
    
    //chama a fun��o que calcula a �rea do cilindro e atribui seu valor a vari�vel "areacilindro".
    areacilindro = calcula(&raiocilindro, &alturacilindro);
    
    printf("�rea do cilindro = %.2lf metros quadrados.\n", areacilindro);         
    
    custocalculo(&areacilindro, &qntlatas, &custo); //chamada da fun��o que calcula a quantidade de latas e o seu custo total e os imprime.
    
    return 0;
}
//fun��o com retorno que ir� calcular a �rea do cilindro.
double calcula(double *raio, double *altura){
	double area = 0;
    
    //c�lculo da �rea do cilindro.
    area = 2 * (M_PI * pow(*raio, 2)) + (2 * M_PI * (*raio) * (*altura));

    return area; //retorna o resultado da �rea.
}
//fun��o que ir� calcular o custo total e a quantidade de latas necess�rias.
void custocalculo(double *area, double *quantidade, double *custototal){
	
	printf("\n-----RESULTADO DA QUANTIDADE DE LATAS NECESS�RIAS E DO CUSTO PARA PINTAR TANQUES CIL�NDRICOS-----\n");
	
	//calcula a quantidade de latas necess�rias arredondando para cima. 
	*quantidade = ceil((*area/P)/L);
	printf("A quantidade de latas de tinta necess�rias s�o = %d unidades.\n", (int)(*quantidade));   
	
	//c�lculo do custo total. 
	*custototal = (*quantidade) * PRECO;
    printf("O custo total � = R$%.2lf reais.\n", *custototal);
}
