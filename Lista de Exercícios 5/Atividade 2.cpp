/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professor(a): Luanna Lopes Lobato e Jos� J�nior
Lista de Exerc�cios 5 de APC2 e LAB2

Atividade 2: Sua empresa foi contratada para o desenvolvimento de um sistema que gerencia as reservas de passagens a�reas de uma companhia.
� O sistema deve permitir a leitura do n�mero dos v�os e a respectiva quantidade de lugares dispon�veis, al�m de pedidos
de reserva, armazenados via Struct, constitu�dos do n�mero da carteira de identidade do cliente e do v�o desejado.
� Para cada cliente, o sistema deve verificar se h� disponibilidade no v�o desejado. Em caso afirmativo, o sistema deve imprimir
o n�mero da identidade do cliente e o n�mero do v�o, atualizando o n�mero de lugares dispon�veis.
� Caso contr�rio, o sistema deve avisar ao cliente da inexist�ncia de lugares. A companhia �rea tem 30 n�meros de v�os.
� De modo a indicar o fim do cadastro de reservas, existe um passageiro cuja identidade � 9999.*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

#define VOOS 30
#define N 50

//defini��o das estruturas que ser�o utilizadas no programa.
typedef struct {
    long int numerovoo; 
    int assentosdisp; 
} voo;

typedef struct {
    long int identidade;
    long int voodesejado;
} cliente;

//prot�tipo das fun��es.
void leitura(voo *numeros);
void reservascadastro(cliente *clientes, voo *numeros, int *qnt);

int main (){
    setlocale(LC_ALL, "Portuguese");
    
    voo numeros[VOOS];
    cliente Clientes[N];
    int qntclientes = 0; 
    
    printf("------RESERVAS DE PASSAGENS A�REAS------");
    leitura(numeros);
    
    printf("\nDigite a quantidade de clientes que solicitaram a reserva: ");
    scanf("%d", &qntclientes);
    
    reservascadastro(Clientes, numeros, &qntclientes);
    
    return 0;
}
//fun��o para leitura dos n�meros e da quantidade de lugares dispon�veis para cada v�o.
void leitura(voo *numeros){
    int i, j;
    int existe; 
    
    printf("\nDigite o n�mero e a quantidade de lugares dispon�veis para cada v�o:\n");
    for (i = 0; i < VOOS; i++){
        printf("\nN�mero do v�o %d = ", i + 1);
        scanf("%ld", &numeros[i].numerovoo); 
        existe = 1; 
        for (j = 0; j < i; j++) { //verifica se h� um n�mero de v�o para evitar repeti��es.
            if (numeros[i].numerovoo == numeros[j].numerovoo) {
                printf("\nEsse n�mero de v�o j� existe. Digite um novo n�mero.\n");
                existe = 0; 
                break;
            }
        }
        if (existe == 0) { 
            i--; 
            continue; 
        }
        printf("Quantidade de lugares dispon�veis = ");
        scanf("%d", &numeros[i].assentosdisp);
    }
}
//fun��o para cadastrar as reservas dos clientes.
void reservascadastro(cliente *clientes, voo *numeros, int *qnt){
    int i, j;
    
    printf("\n------RESERVAS-----\n");
    
    for (i = 0; i < *qnt; i++){
        printf("\nDigite o n�mero da identidade do cliente ou 9999 para encerrar: ");
        scanf("%ld", &clientes[i].identidade);
        
        if (clientes[i].identidade == 9999) {
            printf("Fim do cadastro de reservas.\n");
            break;
        }
        
        //verifica se a identidade j� foi cadastrada.
        for (j = 0; j < i; j++) {
            if (clientes[i].identidade == clientes[j].identidade) {
                printf("\nEssa identidade j� foi cadastrada. Digite uma identidade diferente.\n");
                i--; 
                break;
            }
        }
        
        printf("\nDigite o n�mero do voo desejado: ");
        scanf("%ld", &clientes[i].voodesejado);

        //verificar se o v�o existe e se h� lugares dispon�veis.
        int aux = 0; //vari�vel para indicar se o v�o foi encontrado.
        
        for (j = 0; j < VOOS; j++) {
            if (numeros[j].numerovoo == clientes[i].voodesejado) { //se o v�o existe.
                aux = 1; //marcar que o v�o foi encontrado.
                
                if (numeros[j].assentosdisp > 0) { //se h� lugares dispon�veis.
                    printf("\nReserva confirmada para o cliente de identidade = %ld no v�o %ld\n", clientes[i].identidade, clientes[i].voodesejado); 
                    numeros[j].assentosdisp--; //diminuir um lugar.
                }
                else { // se n�o h� lugares dispon�veis.
                    printf("\nDesculpe, n�o h� assentos dispon�veis no v�o %ld\n", clientes[i].voodesejado); 
                }
                break; 
            }
        }
        if (aux == 0) { //se o v�o n�o foi encontrado.
            printf("\nDesculpe, o v�o %ld n�o existe\n", clientes[i].voodesejado); 
        }
    }
}
