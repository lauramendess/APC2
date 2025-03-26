/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professor(a): Luanna Lopes Lobato e Jos� J�nior
Lista de Exerc�cios 5 de APC2 e LAB2

Atividade 4: Em um supermercado, existe um equipamento que efetua a leitura do estoque de mercadorias. O equipamento l� o c�digo das mercadorias e
as respectivas quantidades existentes. Em seguida, s�o feitos os pedidos dos clientes. Usando Struct, sua empresa deve desenvolver um sistema 
que permita a atualiza��o do estoque de tal modo:
� seja lido e mostrado o estoque inicial (m�ximo de 100 mercadorias)
� sejam lidos os pedidos dos clientes, constitu�dos, cada um, do n�mero do cliente, c�digo da mercadoria e quantidade desejada
� seja verificado, para cada pedido, se ele pode ser integralmente atendido.
Em caso negativo, mostrar o n�mero do cliente e uma mensagem de aviso que n�o possui a mercadoria em estoque de forma suficiente. O sistema
deve informar quantidade atual e o cliente pode optar por fazer um novo pedido com a quantidade suficiente
� seja atualizado o estoque ap�s cada opera��o
� seja listado o estoque final.
Para encerrar os pedidos, basta informar o n�mero do cliente como 9999.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 100

typedef struct {
    int codigo; 
    int quantidade; 
    float preco; 
} Mercadoria;

int n;

int buscar(int codigo, Mercadoria *estoque);
void exibirmercadoria(Mercadoria *produtos);
void lerestoque(Mercadoria *produtos);
void mostrarestoque(Mercadoria *estoque);
void pedidos(Mercadoria *produtos);

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Mercadoria estoque[N];
	
	printf("----------SUPERMERCADO MENDES-----------\n\n");
	
    lerestoque(estoque); //chamada da fun��o para ler o estoque.
    mostrarestoque(estoque); //chamada da fun��o para mostrar o estoque.
    pedidos(estoque); //chamada da fun��o para processar pedidos.
    mostrarestoque(estoque); //chamada da fun��o para mostrar o estoque ap�s processar os pedidos.
    
    return 0;
}
//fun��o para buscar um item no estoque pelo c�digo.
int buscar(int codigo, Mercadoria *estoque) {
    int i;
    for (i = 0; i < n; i++) {
        if (estoque[i].codigo == codigo) {
            return i; //retorna o �ndice do item no estoque.
        }
    }
    return -1; //retorna -1 se o item n�o for encontrado.
}
//fun��o para exibir informa��es de uma mercadoria.
void exibirmercadoria(Mercadoria *produtos){
    printf("C�digo: %d\n", produtos->codigo);
    printf("Quantidade: %d\n", produtos->quantidade);
    printf("Pre�o: %.2f\n", produtos->preco);
}
//fun��o para mostrar o estoque.
void mostrarestoque(Mercadoria *estoque) {
    int i;
    
    printf("\nINFORMA��ES DO ESTOQUE:\n");
    for (i = 0; i < n; i++) {
        exibirmercadoria(&estoque[i]); //chama a fun��o para exibir cada item do estoque.
        printf("\n");
    }
}
//fun��o para ler as informa��es do estoque.
void lerestoque(Mercadoria *produtos) {
    int i;
    
    printf("Digite o n�mero de mercadorias existentes no estoque (o m�ximo de mercadorias � %d):\n", N);
    scanf("%d", &n); 
    
    if (n > N) {
        printf("Aten��o, o n�mero m�ximo de mercadorias � %d!\n", N);
        exit(1);
    }
    
    printf("\nInsira as seguintes informa��es sobre as mercadorias:\n");
    for (i = 0; i < n; i++) {
        printf("\nMercadoria %d:\n", i + 1);
        printf("C�digo: ");
        scanf("%d", &produtos[i].codigo); //l� o c�digo da mercadoria.
        
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade); //l� a quantidade da mercadoria.
        
        printf("Pre�o: ");
        scanf("%f", &produtos[i].preco); //l� o pre�o da mercadoria.
    }
}
//fun��o para processar pedidos dos clientes.
void pedidos(Mercadoria *produtos){
    int num_cliente, cod_mercadoria, qtd_desejada, indice, qtd_atual;
    float valor_total;
    char opcao;
    
    printf("Digite os pedidos dos clientes:\n");
    while (1) {
        printf("\nN�mero do cliente (digite 9999 para encerrar): ");
        scanf("%d", &num_cliente);
        
        if (num_cliente == 9999) {
            break;
        }
        do {
            printf("C�digo da mercadoria: ");
            scanf("%d", &cod_mercadoria);
            
            printf("Quantidade desejada: ");
            scanf("%d", &qtd_desejada);
            
            indice = buscar(cod_mercadoria, produtos); //busca a mercadoria no estoque.
            if (indice == -1) { //se n�o encontrada.
                printf("Mercadoria n�o encontrada.\n");
                break;
            } 
		    else { //se encontrada.
                qtd_atual = produtos[indice].quantidade; 
                if (qtd_atual < qtd_desejada) { //se n�o h� estoque suficiente.
                    printf("N�o h� estoque suficiente para atender o pedido.\n");
                    printf("Quantidade atual: %d\n", qtd_atual);
                    printf("Deseja fazer um novo pedido com a quantidade dispon�vel? (S/N)\n");
                    scanf(" %c", &opcao);
                    if (opcao == 'S' || opcao == 's') {
                        qtd_desejada = qtd_atual;
                    }
                    else {
                        break;
                    }
                } 
                valor_total = qtd_desejada * produtos[indice].preco; //calcula o valor total.
                printf("Pedido atendido.\n");
                printf("Valor total: %.2f\n", valor_total); 
                produtos[indice].quantidade -= qtd_desejada; //atualiza a quantidade no estoque.
            }
        } while (0);
        printf("\n");
    }
}
