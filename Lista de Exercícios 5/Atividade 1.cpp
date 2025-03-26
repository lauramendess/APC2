/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professor(a): Luanna Lopes Lobato e José Júnior
Lista de Exercícios 5 de APC2 e LAB2

Atividade 1: Em uma cidade do Sul do país, sabe-se que de Janeiro a Abril
(assumindo 121 dias), não ocorreu temperatura inferior a 15°C nem
superior a 30°C. As temperaturas registradas em cada dia estão
armazenadas em documentos da central do tempo. Assim, sua
empresa foi contratada para desenvolver um sistema que calcule e
imprima:
• a menor temperatura ocorrida
• a maior temperatura ocorrida
• a temperatura média
• o número de dias no qual a temperatura foi menor e maior do que a temperatura média.*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define D 121

//definição da estrutura para armazenar a temperatura de cada dia.
typedef struct {
    float temperatura;
} RegistrodaTemperatura;

//protótipos das funções.
void registrodastemp(RegistrodaTemperatura *registros);
void maioremenortemp(RegistrodaTemperatura *registros, float *maiortemp, float *menortemp);
void mediatemp(RegistrodaTemperatura *registros, float *tempmedia);
void diasmenoremaior(RegistrodaTemperatura *registros, float *tempmedia, int *abaixodamedia, int *acimadamedia);

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	//declaração das variáveis
	RegistrodaTemperatura temp[D];
	float menortemperatura; 
	float maiortemperatura; 
	float temperaturamedia;
	int diasmenor;
	int diasmaior;
	
	printf("BEM VINDO AO SISTEMA DE INFORMAÇÕES CLIMÁTICAS DE BAGÉ - RS!\n");
	//chamada das funções:
	registrodastemp(temp);
	maioremenortemp(temp, &maiortemperatura, &menortemperatura);
	mediatemp(temp, &temperaturamedia);
	diasmenoremaior(temp, &temperaturamedia, &diasmenor, &diasmaior);
	
	return 0;
}
//função para obter os registros de temperatura de cada dia.
void registrodastemp(RegistrodaTemperatura *registros){
	int i;
	
	printf("\nForneça as temperaturas registradas em cada dia (de Janeiro a Abril - total de 121 dias) utilizando VÍRGULA:\n---EM GRAUS CELSIUS---\n");
	printf("(LEMBRE-SE QUE: Não ocorreu temperatura inferior a 15°C nem superior a 30°C).\n\n");
	
	for(i = 0; i < D; i++){
	  do{
		printf("Dia %d: ", i + 1);
		scanf("%f", &registros[i].temperatura);
		
	   //verificação para ver se não foi inserido uma temperatura inferior a 15°C e superior a 30°C, ou seja, se está dentro dos limites.
	   if (registros[i].temperatura < 15 || registros[i].temperatura > 30) {     
                printf("ATENÇÃO: A temperatura inserida é inferior a 15°C ou superior a 30°C! Por favor, digite novamente.\n");
            }
	   } while(registros[i].temperatura < 15 || registros[i].temperatura > 30);
   } 
}
//função para encontrar a maior e a menor temperatura registrada.
void maioremenortemp(RegistrodaTemperatura *registros, float *maiortemp, float *menortemp){
	int i; 
	*maiortemp = registros[0].temperatura; //inicializa a variável 'maiortemp' com a temperatura do primeiro dia.
	*menortemp = registros[0].temperatura; //inicializa a variável 'menortemp' com a temperatura do primeiro dia.
	
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
//função para calcular a média das temperaturas registradas.
void mediatemp(RegistrodaTemperatura *registros, float *tempmedia){
	int i;
	float soma = 0;
	
	//realiza a soma de todas as temperaturas:
	for(i = 0; i < D; i++){
		soma +=  registros[i].temperatura;
	}
	//calcula a média e a atribui a variável "tempmedia":
	*tempmedia = soma / D;
	printf("A média das temperaturas registradas foi %.2f°C\n", *tempmedia);
}
//função para contar o número de dias em que a temperatura foi menor e maior que a média.
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
	printf("Número de dias que a temperatura foi menor do que a temperatura média: %d\n", *abaixodamedia);
	printf("Número de dias que a temperatura foi maior do que a temperatura média: %d\n", *acimadamedia);
}
