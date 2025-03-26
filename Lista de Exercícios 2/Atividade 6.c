/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios 2 de APC2 e LAB2

Exercicio 6 - Construa um programa que calcule a quantidade de latas de tinta necessarias e o custo para
pintar tanques cilindricos de combustivel. Use ponteiros para envio dos dados a uma funcao calcula(). Onde sao fornecidos a altura e o raio desse cilindro.
- Sabendo que: 
- a lata de tinta custa R$20,00
- cada lata contem 5 litros
- cada litro de tinta pinta 3 metros quadrados.
- area do cilindro = 2 vezes a area da base + circunferencia da base vezes a altura (A = 2pr² + 2prh)
- o raio e altura sao dados de entrada
*/
#include<stdio.h>

// Definindo pi manualmente
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//definicao de constantes.
#define PRECO 20
#define L 5
#define P 3

double calcula(double *raio, double *altura); 
void custocalculo(double *area, double *quantidade, double *custototal); 
int main (){
  
    double raiocilindro, alturacilindro, areacilindro, qntlatas, custo;
    
    // solicita ao usuario que insira o raio e a altura do cilindro.
    printf("Informe o raio e a altura do cilindro, respectivamente, a serem pintados:\n");
    scanf("%lf %lf", &raiocilindro, &alturacilindro);
    
    // imprime as informacoes ao usuario. 
    printf("\tDADOS\t\nRaio do cilindro = %.2lf metros.\nAltura do cilindro = %.2lf metros.\n", raiocilindro, alturacilindro);
    printf("Preco da lata de tinta = R$%d,00 reais.\nVolume da lata de tinta = %d litros.\nArea pintada por litro de tinta = %d metros quadrados.\n", PRECO, L, P);
    
    // chama a funcao que calcula a area do cilindro e atribui seu valor a variavel "areacilindro".
    areacilindro = calcula(&raiocilindro, &alturacilindro);
    
    printf("Area do cilindro = %.2lf metros quadrados.\n", areacilindro);         
    
    custocalculo(&areacilindro, &qntlatas, &custo); // chamada da funcao que calcula a quantidade de latas e o seu custo total e os imprime.
    
    return 0;
}

// funcao com retorno que ira calcular a area do cilindro.
double calcula(double *raio, double *altura){
    double area = 0;
    
    //calculo da area do cilindro.
    area = 2 * (M_PI * pow(*raio, 2)) + (2 * M_PI * (*raio) * (*altura));

    return area; //retorna o resultado da area.
}

// funcao que ira calcular o custo total e a quantidade de latas necessarias.
void custocalculo(double *area, double *quantidade, double *custototal){
    
    printf("\n-----RESULTADO DA QUANTIDADE DE LATAS NECESSARIAS E DO CUSTO PARA PINTAR TANQUES CILINDRICOS-----\n");
    
    //calcula a quantidade de latas necessarias arredondando para cima. 
    *quantidade = ceil((*area/P)/L);
    printf("A quantidade de latas de tinta necessarias sao = %d unidades.\n", (int)(*quantidade));   
    
    //calculo do custo total. 
    *custototal = (*quantidade) * PRECO;
    printf("O custo total e = R$%.2lf reais.\n", *custototal);
}
