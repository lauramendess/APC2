/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professor(a): Luanna Lopes Lobato e Jose Junior
Lista de Exercicios 5 de APC2 e LAB2

Atividade 2: Sua empresa foi contratada para o desenvolvimento de um sistema que gerencia as reservas de passagens aereas de uma companhia.
- O sistema deve permitir a leitura do numero dos voos e a respectiva quantidade de lugares disponiveis, alem de pedidos
de reserva, armazenados via Struct, constituidos do numero da carteira de identidade do cliente e do voo desejado.
- Para cada cliente, o sistema deve verificar se ha disponibilidade no voo desejado. Em caso afirmativo, o sistema deve imprimir
o numero da identidade do cliente e o numero do voo, atualizando o numero de lugares disponiveis.
- Caso contrario, o sistema deve avisar ao cliente da inexistencia de lugares. A companhia aerea tem 30 numeros de voos.
- De modo a indicar o fim do cadastro de reservas, existe um passageiro cuja identidade e 9999.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VOOS 30
#define N 50

// definicao das estruturas que serao utilizadas no programa.
typedef struct {
    long int numerovoo; 
    int assentosdisp; 
} voo;

typedef struct {
    long int identidade;
    long int voodesejado;
} cliente;

// prototipo das funcoes.
void leitura(voo *numeros);
void reservascadastro(cliente *clientes, voo *numeros, int *qnt);

int main (){
    voo numeros[VOOS];
    cliente Clientes[N];
    int qntclientes = 0; 
    
    printf("------RESERVAS DE PASSAGENS AEREAS------");
    leitura(numeros);
    
    printf("\nDigite a quantidade de clientes que solicitaram a reserva: ");
    scanf("%d", &qntclientes);
    
    reservascadastro(Clientes, numeros, &qntclientes);
    
    return 0;
}

// funcao para leitura dos numeros e da quantidade de lugares disponiveis para cada voo.
void leitura(voo *numeros){
    int i, j;
    int existe; 
    
    printf("\nDigite o numero e a quantidade de lugares disponiveis para cada voo:\n");
    for (i = 0; i < VOOS; i++){
        printf("\nNumero do voo %d = ", i + 1);
        scanf("%ld", &numeros[i].numerovoo); 
        existe = 1; 
        for (j = 0; j < i; j++) { // verifica se ha um numero de voo para evitar repeticoes.
            if (numeros[i].numerovoo == numeros[j].numerovoo) {
                printf("\nEsse numero de voo ja existe. Digite um novo numero.\n");
                existe = 0; 
                break;
            }
        }
        if (existe == 0) { 
            i--; 
            continue; 
        }
        printf("Quantidade de lugares disponiveis = ");
        scanf("%d", &numeros[i].assentosdisp);
    }
}

// funcao para cadastrar as reservas dos clientes.
void reservascadastro(cliente *clientes, voo *numeros, int *qnt){
    int i, j;
    
    printf("\n------RESERVAS-----\n");
    
    for (i = 0; i < *qnt; i++){
        printf("\nDigite o numero da identidade do cliente ou 9999 para encerrar: ");
        scanf("%ld", &clientes[i].identidade);
        
        if (clientes[i].identidade == 9999) {
            printf("Fim do cadastro de reservas.\n");
            break;
        }
        
        // verifica se a identidade ja foi cadastrada.
        for (j = 0; j < i; j++) {
            if (clientes[i].identidade == clientes[j].identidade) {
                printf("\nEssa identidade ja foi cadastrada. Digite uma identidade diferente.\n");
                i--; 
                break;
            }
        }
        
        printf("\nDigite o numero do voo desejado: ");
        scanf("%ld", &clientes[i].voodesejado);

        // verificar se o voo existe e se ha lugares disponiveis.
        int aux = 0; //variavel para indicar se o voo foi encontrado.
        
        for (j = 0; j < VOOS; j++) {
            if (numeros[j].numerovoo == clientes[i].voodesejado) { // se o voo existe.
                aux = 1; // marcar que o voo foi encontrado.
                
                if (numeros[j].assentosdisp > 0) { // se ha lugares disponiveis.
                    printf("\nReserva confirmada para o cliente de identidade = %ld no voo %ld\n", clientes[i].identidade, clientes[i].voodesejado); 
                    numeros[j].assentosdisp--; // diminuir um lugar.
                }
                else { // se nao ha lugares disponiveis.
                    printf("\nDesculpe, nao ha assentos disponiveis no voo %ld\n", clientes[i].voodesejado); 
                }
                break; 
            }
        }
        if (aux == 0) { // se o voo nao foi encontrado.
            printf("\nDesculpe, o voo %ld nao existe\n", clientes[i].voodesejado); 
        }
    }
}
