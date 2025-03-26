/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professor(a): Luanna Lopes Lobato e José Júnior
Lista de Exercícios 5 de APC2 e LAB2

Atividade 2: Sua empresa foi contratada para o desenvolvimento de um sistema que gerencia as reservas de passagens aéreas de uma companhia.
– O sistema deve permitir a leitura do número dos vôos e a respectiva quantidade de lugares disponíveis, além de pedidos
de reserva, armazenados via Struct, constituídos do número da carteira de identidade do cliente e do vôo desejado.
– Para cada cliente, o sistema deve verificar se há disponibilidade no vôo desejado. Em caso afirmativo, o sistema deve imprimir
o número da identidade do cliente e o número do vôo, atualizando o número de lugares disponíveis.
– Caso contrário, o sistema deve avisar ao cliente da inexistência de lugares. A companhia área tem 30 números de vôos.
– De modo a indicar o fim do cadastro de reservas, existe um passageiro cuja identidade é 9999.*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

#define VOOS 30
#define N 50

//definição das estruturas que serão utilizadas no programa.
typedef struct {
    long int numerovoo; 
    int assentosdisp; 
} voo;

typedef struct {
    long int identidade;
    long int voodesejado;
} cliente;

//protótipo das funções.
void leitura(voo *numeros);
void reservascadastro(cliente *clientes, voo *numeros, int *qnt);

int main (){
    setlocale(LC_ALL, "Portuguese");
    
    voo numeros[VOOS];
    cliente Clientes[N];
    int qntclientes = 0; 
    
    printf("------RESERVAS DE PASSAGENS AÉREAS------");
    leitura(numeros);
    
    printf("\nDigite a quantidade de clientes que solicitaram a reserva: ");
    scanf("%d", &qntclientes);
    
    reservascadastro(Clientes, numeros, &qntclientes);
    
    return 0;
}
//função para leitura dos números e da quantidade de lugares disponíveis para cada vôo.
void leitura(voo *numeros){
    int i, j;
    int existe; 
    
    printf("\nDigite o número e a quantidade de lugares disponíveis para cada vôo:\n");
    for (i = 0; i < VOOS; i++){
        printf("\nNúmero do vôo %d = ", i + 1);
        scanf("%ld", &numeros[i].numerovoo); 
        existe = 1; 
        for (j = 0; j < i; j++) { //verifica se há um número de vôo para evitar repetições.
            if (numeros[i].numerovoo == numeros[j].numerovoo) {
                printf("\nEsse número de vôo já existe. Digite um novo número.\n");
                existe = 0; 
                break;
            }
        }
        if (existe == 0) { 
            i--; 
            continue; 
        }
        printf("Quantidade de lugares disponíveis = ");
        scanf("%d", &numeros[i].assentosdisp);
    }
}
//função para cadastrar as reservas dos clientes.
void reservascadastro(cliente *clientes, voo *numeros, int *qnt){
    int i, j;
    
    printf("\n------RESERVAS-----\n");
    
    for (i = 0; i < *qnt; i++){
        printf("\nDigite o número da identidade do cliente ou 9999 para encerrar: ");
        scanf("%ld", &clientes[i].identidade);
        
        if (clientes[i].identidade == 9999) {
            printf("Fim do cadastro de reservas.\n");
            break;
        }
        
        //verifica se a identidade já foi cadastrada.
        for (j = 0; j < i; j++) {
            if (clientes[i].identidade == clientes[j].identidade) {
                printf("\nEssa identidade já foi cadastrada. Digite uma identidade diferente.\n");
                i--; 
                break;
            }
        }
        
        printf("\nDigite o número do voo desejado: ");
        scanf("%ld", &clientes[i].voodesejado);

        //verificar se o vôo existe e se há lugares disponíveis.
        int aux = 0; //variável para indicar se o vôo foi encontrado.
        
        for (j = 0; j < VOOS; j++) {
            if (numeros[j].numerovoo == clientes[i].voodesejado) { //se o vôo existe.
                aux = 1; //marcar que o vôo foi encontrado.
                
                if (numeros[j].assentosdisp > 0) { //se há lugares disponíveis.
                    printf("\nReserva confirmada para o cliente de identidade = %ld no vôo %ld\n", clientes[i].identidade, clientes[i].voodesejado); 
                    numeros[j].assentosdisp--; //diminuir um lugar.
                }
                else { // se não há lugares disponíveis.
                    printf("\nDesculpe, não há assentos disponíveis no vôo %ld\n", clientes[i].voodesejado); 
                }
                break; 
            }
        }
        if (aux == 0) { //se o vôo não foi encontrado.
            printf("\nDesculpe, o vôo %ld não existe\n", clientes[i].voodesejado); 
        }
    }
}
