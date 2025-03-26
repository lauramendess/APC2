/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professor(a): Luanna Lopes Lobato e Jose Junior
Lista de Exercicios 5 de APC2 e LAB2

Atividade 1: Em uma cidade do Sul do pais, sabe-se que de Janeiro a Abril
(assumindo 121 dias), nao ocorreu temperatura inferior a 15°C nem
superior a 30°C. As temperaturas registradas em cada dia estao
armazenadas em documentos da central do tempo. Assim, sua
empresa foi contratada para desenvolver um sistema que calcule e
imprima:
- a menor temperatura ocorrida
- a maior temperatura ocorrida
- a temperatura media
- o numero de dias no qual a temperatura foi menor e maior do que a temperatura media.
*/
#include<stdio.h>
#include<stdlib.h>
#define D 121

// definicao da estrutura para armazenar a temperatura de cada dia.
typedef struct {
	float temperatura;
} RegistrodaTemperatura;

// prototipos das funcoes.
void registrodastemp(RegistrodaTemperatura *registros);
void maioremenortemp(RegistrodaTemperatura *registros, float *maiortemp, float *menortemp);
void mediatemp(RegistrodaTemperatura *registros, float *tempmedia);
void diasmenoremaior(RegistrodaTemperatura *registros, float *tempmedia, int *abaixodamedia, int *acimadamedia);

int main (){
	
	// declaracao das variaveis
	RegistrodaTemperatura temp[D];
	float menortemperatura; 
	float maiortemperatura; 
	float temperaturamedia;
	int diasmenor;
	int diasmaior;
	
	printf("BEM VINDO AO SISTEMA DE INFORMACOES CLIMATICAS DE BAGÉ - RS!\n");
	// chamada das funcoes:
	registrodastemp(temp);
	maioremenortemp(temp, &maiortemperatura, &menortemperatura);
	mediatemp(temp, &temperaturamedia);
	diasmenoremaior(temp, &temperaturamedia, &diasmenor, &diasmaior);
	
	return 0;
}

// funcao para obter os registros de temperatura de cada dia.
void registrodastemp(RegistrodaTemperatura *registros){
	int i;
	
	printf("\nForneca as temperaturas registradas em cada dia (de Janeiro a Abril - total de 121 dias) utilizando VIRGULA:\n---EM GRAUS CELSIUS---\n");
	printf("(LEMBRE-SE QUE: Nao ocorreu temperatura inferior a 15°C nem superior a 30°C).\n\n");
	
	for(i = 0; i < D; i++){
	  do{
		printf("Dia %d: ", i + 1);
		scanf("%f", &registros[i].temperatura);
		
	   // verificacao para ver se nao foi inserido uma temperatura inferior a 15°C e superior a 30°C, ou seja, se esta dentro dos limites.
	   if (registros[i].temperatura < 15 || registros[i].temperatura > 30) {     
				printf("ATENCAO: A temperatura inserida e inferior a 15°C ou superior a 30°C! Por favor, digite novamente.\n");
			}
	   } while(registros[i].temperatura < 15 || registros[i].temperatura > 30);
   } 
}

// funcao para encontrar a maior e a menor temperatura registrada.
void maioremenortemp(RegistrodaTemperatura *registros, float *maiortemp, float *menortemp){
	int i; 
	*maiortemp = registros[0].temperatura; // inicializa a variavel 'maiortemp' com a temperatura do primeiro dia.
	*menortemp = registros[0].temperatura; // inicializa a variavel 'menortemp' com a temperatura do primeiro dia.
	
	for(i = 1; i < D; i++){
		if(*maiortemp < registros[i].temperatura){
			*maiortemp = registros[i].temperatura;
		}
		if(*menortemp > registros[i].temperatura){
			*menortemp = registros[i].temperatura;
		}
	}
	printf("\nA maior temperatura registrada foi %.2f°C\n", *maiortemp);
	printf("A menor temperatura registrada foi %.2f°C\n", *menortemp);
}

// funcao para calcular a media das temperaturas registradas.
void mediatemp(RegistrodaTemperatura *registros, float *tempmedia){
	int i;
	float soma = 0;
	
	// realiza a soma de todas as temperaturas:
	for(i = 0; i < D; i++){
		soma +=  registros[i].temperatura;
	}

	// calcula a media e a atribui a variavel "tempmedia":
	*tempmedia = soma / D;
	printf("A media das temperaturas registradas foi %.2f°C\n", *tempmedia);
}

// funcao para contar o numero de dias em que a temperatura foi menor e maior que a media.
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
	printf("Numero de dias que a temperatura foi menor do que a temperatura media: %d\n", *abaixodamedia);
	printf("Numero de dias que a temperatura foi maior do que a temperatura media: %d\n", *acimadamedia);
}
