/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professor(a): Luanna Lopes Lobato e Jos� J�nior
Lista de Exerc�cios 5 de APC2 e LAB2

Atividade 1: Em uma cidade do Sul do pa�s, sabe-se que de Janeiro a Abril
(assumindo 121 dias), n�o ocorreu temperatura inferior a 15�C nem
superior a 30�C. As temperaturas registradas em cada dia est�o
armazenadas em documentos da central do tempo. Assim, sua
empresa foi contratada para desenvolver um sistema que calcule e
imprima:
� a menor temperatura ocorrida
� a maior temperatura ocorrida
� a temperatura m�dia
� o n�mero de dias no qual a temperatura foi menor e maior do que a temperatura m�dia.*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define D 121

//defini��o da estrutura para armazenar a temperatura de cada dia.
typedef struct {
    float temperatura;
} RegistrodaTemperatura;

//prot�tipos das fun��es.
void registrodastemp(RegistrodaTemperatura *registros);
void maioremenortemp(RegistrodaTemperatura *registros, float *maiortemp, float *menortemp);
void mediatemp(RegistrodaTemperatura *registros, float *tempmedia);
void diasmenoremaior(RegistrodaTemperatura *registros, float *tempmedia, int *abaixodamedia, int *acimadamedia);

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	//declara��o das vari�veis
	RegistrodaTemperatura temp[D];
	float menortemperatura; 
	float maiortemperatura; 
	float temperaturamedia;
	int diasmenor;
	int diasmaior;
	
	printf("BEM VINDO AO SISTEMA DE INFORMA��ES CLIM�TICAS DE BAG� - RS!\n");
	//chamada das fun��es:
	registrodastemp(temp);
	maioremenortemp(temp, &maiortemperatura, &menortemperatura);
	mediatemp(temp, &temperaturamedia);
	diasmenoremaior(temp, &temperaturamedia, &diasmenor, &diasmaior);
	
	return 0;
}
//fun��o para obter os registros de temperatura de cada dia.
void registrodastemp(RegistrodaTemperatura *registros){
	int i;
	
	printf("\nForne�a as temperaturas registradas em cada dia (de Janeiro a Abril - total de 121 dias) utilizando V�RGULA:\n---EM GRAUS CELSIUS---\n");
	printf("(LEMBRE-SE QUE: N�o ocorreu temperatura inferior a 15�C nem superior a 30�C).\n\n");
	
	for(i = 0; i < D; i++){
	  do{
		printf("Dia %d: ", i + 1);
		scanf("%f", &registros[i].temperatura);
		
	   //verifica��o para ver se n�o foi inserido uma temperatura inferior a 15�C e superior a 30�C, ou seja, se est� dentro dos limites.
	   if (registros[i].temperatura < 15 || registros[i].temperatura > 30) {     
                printf("ATEN��O: A temperatura inserida � inferior a 15�C ou superior a 30�C! Por favor, digite novamente.\n");
            }
	   } while(registros[i].temperatura < 15 || registros[i].temperatura > 30);
   } 
}
//fun��o para encontrar a maior e a menor temperatura registrada.
void maioremenortemp(RegistrodaTemperatura *registros, float *maiortemp, float *menortemp){
	int i; 
	*maiortemp = registros[0].temperatura; //inicializa a vari�vel 'maiortemp' com a temperatura do primeiro dia.
	*menortemp = registros[0].temperatura; //inicializa a vari�vel 'menortemp' com a temperatura do primeiro dia.
	
	for(i = 1; i < D; i++){
		if(*maiortemp < registros[i].temperatura){
			*maiortemp = registros[i].temperatura;
		}
		if(*menortemp > registros[i].temperatura){
			*menortemp = registros[i].temperatura;
		}
	}
	printf("\nA maior temperatura registrada foi %.2f�C\n", *maiortemp);
	printf("A menor temperatura registrada foi %.2f�C\n", *menortemp);
}
//fun��o para calcular a m�dia das temperaturas registradas.
void mediatemp(RegistrodaTemperatura *registros, float *tempmedia){
	int i;
	float soma = 0;
	
	//realiza a soma de todas as temperaturas:
	for(i = 0; i < D; i++){
		soma +=  registros[i].temperatura;
	}
	//calcula a m�dia e a atribui a vari�vel "tempmedia":
	*tempmedia = soma / D;
	printf("A m�dia das temperaturas registradas foi %.2f�C\n", *tempmedia);
}
//fun��o para contar o n�mero de dias em que a temperatura foi menor e maior que a m�dia.
void diasmenoremaior(RegistrodaTemperatura *registros, float *tempmedia, int *abaixodamedia, int *acimadamedia){
	int i;
	*abaixodamedia = 0; 
	*acimadamedia = 0;  
	
	for(i = 0; i < D; i++){
		if (registros[i].temperatura < *tempmedia)
		(*abaixodamedia)++; 
		 
		else if (registros[i].temperatura > *tempmedia)
		(*acimadamedia)++;
	}
	printf("N�mero de dias que a temperatura foi menor do que a temperatura m�dia: %d\n", *abaixodamedia);
	printf("N�mero de dias que a temperatura foi maior do que a temperatura m�dia: %d\n", *acimadamedia);
}
