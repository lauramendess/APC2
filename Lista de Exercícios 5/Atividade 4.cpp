/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professor(a): Luanna Lopes Lobato e José Júnior
Lista de Exercícios 5 de APC2 e LAB2

Atividade 4: Em um supermercado, existe um equipamento que efetua a leitura do estoque de mercadorias. O equipamento lê o código das mercadorias e
as respectivas quantidades existentes. Em seguida, são feitos os pedidos dos clientes. Usando Struct, sua empresa deve desenvolver um sistema 
que permita a atualização do estoque de tal modo:
– seja lido e mostrado o estoque inicial (máximo de 100 mercadorias)
– sejam lidos os pedidos dos clientes, constituídos, cada um, do número do cliente, código da mercadoria e quantidade desejada
– seja verificado, para cada pedido, se ele pode ser integralmente atendido.
Em caso negativo, mostrar o número do cliente e uma mensagem de aviso que não possui a mercadoria em estoque de forma suficiente. O sistema
deve informar quantidade atual e o cliente pode optar por fazer um novo pedido com a quantidade suficiente
– seja atualizado o estoque após cada operação
– seja listado o estoque final.
Para encerrar os pedidos, basta informar o número do cliente como 9999.*/
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
	
    lerestoque(estoque); //chamada da função para ler o estoque.
    mostrarestoque(estoque); //chamada da função para mostrar o estoque.
    pedidos(estoque); //chamada da função para processar pedidos.
    mostrarestoque(estoque); //chamada da função para mostrar o estoque após processar os pedidos.
    
    return 0;
}
//função para buscar um item no estoque pelo código.
int buscar(int codigo, Mercadoria *estoque) {
    int i;
    for (i = 0; i < n; i++) {
        if (estoque[i].codigo == codigo) {
            return i; //retorna o índice do item no estoque.
        }
    }
    return -1; //retorna -1 se o item não for encontrado.
}
//função para exibir informações de uma mercadoria.
void exibirmercadoria(Mercadoria *produtos){
    printf("Código: %d\n", produtos->codigo);
    printf("Quantidade: %d\n", produtos->quantidade);
    printf("Preço: %.2f\n", produtos->preco);
}
//função para mostrar o estoque.
void mostrarestoque(Mercadoria *estoque) {
    int i;
    
    printf("\nINFORMAÇÕES DO ESTOQUE:\n");
    for (i = 0; i < n; i++) {
        exibirmercadoria(&estoque[i]); //chama a função para exibir cada item do estoque.
        printf("\n");
    }
}
//função para ler as informações do estoque.
void lerestoque(Mercadoria *produtos) {
    int i;
    
    printf("Digite o número de mercadorias existentes no estoque (o máximo de mercadorias é %d):\n", N);
    scanf("%d", &n); 
    
    if (n > N) {
        printf("Atenção, o número máximo de mercadorias é %d!\n", N);
        exit(1);
    }
    
    printf("\nInsira as seguintes informações sobre as mercadorias:\n");
    for (i = 0; i < n; i++) {
        printf("\nMercadoria %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &produtos[i].codigo); //lê o código da mercadoria.
        
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade); //lê a quantidade da mercadoria.
        
        printf("Preço: ");
        scanf("%f", &produtos[i].preco); //lê o preço da mercadoria.
    }
}
//função para processar pedidos dos clientes.
void pedidos(Mercadoria *produtos){
    int num_cliente, cod_mercadoria, qtd_desejada, indice, qtd_atual;
    float valor_total;
    char opcao;
    
    printf("Digite os pedidos dos clientes:\n");
    while (1) {
        printf("\nNúmero do cliente (digite 9999 para encerrar): ");
        scanf("%d", &num_cliente);
        
        if (num_cliente == 9999) {
            break;
        }
        do {
            printf("Código da mercadoria: ");
            scanf("%d", &cod_mercadoria);
            
            printf("Quantidade desejada: ");
            scanf("%d", &qtd_desejada);
            
            indice = buscar(cod_mercadoria, produtos); //busca a mercadoria no estoque.
            if (indice == -1) { //se não encontrada.
                printf("Mercadoria não encontrada.\n");
                break;
            } 
		    else { //se encontrada.
                qtd_atual = produtos[indice].quantidade; 
                if (qtd_atual < qtd_desejada) { //se não há estoque suficiente.
                    printf("Não há estoque suficiente para atender o pedido.\n");
                    printf("Quantidade atual: %d\n", qtd_atual);
                    printf("Deseja fazer um novo pedido com a quantidade disponível? (S/N)\n");
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
