/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios 2 de APC2 e LAB2

Exercício 6 - Construa um programa que calcule a quantidade de latas de tinta necessárias e o custo para
pintar tanques cilíndricos de combustível. Use ponteiros para envio dos dados a uma função calcula(). Onde são fornecidos a altura e o raio desse cilindro.
– Sabendo que: 
• a lata de tinta custa R$20,00
• cada lata contém 5 litros
• cada litro de tinta pinta 3 metros quadrados.
• Área do cilindro = 2 vezes a área da base + circunferência da base vezes a altura (A = 2pr² + 2prh)
• o raio e altura são dados de entrada*/
#include<stdio.h>
#include<math.h>
#include<locale.h>

//definição de constantes.
#define PRECO 20
#define L 5
#define P 3

double calcula(double *raio, double *altura); //protótipo da função que irá calcular a área do cilindro.
void custocalculo(double *area, double *quantidade, double *custototal); //protótipo da função que irá calcular a quantidade de latas e o custo total.

int main (){
	setlocale(LC_ALL, "Portuguese"); //valores decimais devem ser inseridos com vírgula por conta da configuração em português.
  
    double raiocilindro, alturacilindro, areacilindro, qntlatas, custo;
    
    //solicita ao usuário que insira o raio e a altura do cilindro.
    printf("Informe o raio e a altura do cilindro, respectivamente, a serem pintados:\n");
    scanf("%lf %lf", &raiocilindro, &alturacilindro);
    
    //imprime as informações ao usuário. 
    printf("\tDADOS\t\nRaio do cilindro = %.2lf metros.\nAltura do cilindro = %.2lf metros.\n", raiocilindro, alturacilindro);
    printf("Preço da lata de tinta = R$%d,00 reais.\nVolume da lata de tinta = %d litros.\nÁrea pintada por litro de tinta = %d metros quadrados.\n", PRECO, L, P);
    
    //chama a função que calcula a área do cilindro e atribui seu valor a variável "areacilindro".
    areacilindro = calcula(&raiocilindro, &alturacilindro);
    
    printf("Área do cilindro = %.2lf metros quadrados.\n", areacilindro);         
    
    custocalculo(&areacilindro, &qntlatas, &custo); //chamada da função que calcula a quantidade de latas e o seu custo total e os imprime.
    
    return 0;
}
//função com retorno que irá calcular a área do cilindro.
double calcula(double *raio, double *altura){
	double area = 0;
    
    //cálculo da área do cilindro.
    area = 2 * (M_PI * pow(*raio, 2)) + (2 * M_PI * (*raio) * (*altura));

    return area; //retorna o resultado da área.
}
//função que irá calcular o custo total e a quantidade de latas necessárias.
void custocalculo(double *area, double *quantidade, double *custototal){
	
	printf("\n-----RESULTADO DA QUANTIDADE DE LATAS NECESSÁRIAS E DO CUSTO PARA PINTAR TANQUES CILÍNDRICOS-----\n");
	
	//calcula a quantidade de latas necessárias arredondando para cima. 
	*quantidade = ceil((*area/P)/L);
	printf("A quantidade de latas de tinta necessárias são = %d unidades.\n", (int)(*quantidade));   
	
	//cálculo do custo total. 
	*custototal = (*quantidade) * PRECO;
    printf("O custo total é = R$%.2lf reais.\n", *custototal);
}
