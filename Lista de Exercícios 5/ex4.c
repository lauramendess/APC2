/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professor(a): Luanna Lopes Lobato e Jose Junior
Lista de Exercicios 5 de APC2 e LAB2

Atividade 4: Em um supermercado, existe um equipamento que efetua a leitura do estoque de mercadorias. O equipamento le o codigo das mercadorias e
as respectivas quantidades existentes. Em seguida, sao feitos os pedidos dos clientes. Usando Struct, sua empresa deve desenvolver um sistema 
que permita a atualizacao do estoque de tal modo:
- seja lido e mostrado o estoque inicial (maximo de 100 mercadorias)
- sejam lidos os pedidos dos clientes, constituidos, cada um, do numero do cliente, codigo da mercadoria e quantidade desejada
- seja verificado, para cada pedido, se ele pode ser integralmente atendido.
    Em caso negativo, mostrar o numero do cliente e uma mensagem de aviso que nao possui a mercadoria em estoque de forma suficiente. O sistema
    deve informar quantidade atual e o cliente pode optar por fazer um novo pedido com a quantidade suficiente
- seja atualizado o estoque apos cada operacao
- seja listado o estoque final.
Para encerrar os pedidos, basta informar o numero do cliente como 9999.
*/
#include <stdio.h>
#include <stdlib.h>

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
    
    Mercadoria estoque[N];
    
    printf("----------SUPERMERCADO MENDES-----------\n\n");
    
    lerestoque(estoque); 
    mostrarestoque(estoque); 
    pedidos(estoque); 
    mostrarestoque(estoque);
    
    return 0;
}

// funcao para buscar um item no estoque pelo codigo.
int buscar(int codigo, Mercadoria *estoque) {
    int i;
    for (i = 0; i < n; i++) {
        if (estoque[i].codigo == codigo) {
            return i; // retorna o indice do item no estoque.
        }
    }
    return -1; // retorna -1 se o item nao for encontrado.
}

// funcao para exibir informacoes de uma mercadoria.
void exibirmercadoria(Mercadoria *produtos){
    printf("Codigo: %d\n", produtos->codigo);
    printf("Quantidade: %d\n", produtos->quantidade);
    printf("Preco: %.2f\n", produtos->preco);
}

// funcao para mostrar o estoque.
void mostrarestoque(Mercadoria *estoque) {
    int i;
    
    printf("\nINFORMACOES DO ESTOQUE:\n");
    for (i = 0; i < n; i++) {
        exibirmercadoria(&estoque[i]); // chama a funcao para exibir cada item do estoque.
        printf("\n");
    }
}

// funcao para ler as informacoes do estoque.
void lerestoque(Mercadoria *produtos) {
    int i;
    
    printf("Digite o numero de mercadorias existentes no estoque (o maximo de mercadorias e %d):\n", N);
    scanf("%d", &n); 
    
    if (n > N) {
        printf("Atencao, o numero maximo de mercadorias e %d!\n", N);
        exit(1);
    }
    
    printf("\nInsira as seguintes informacoes sobre as mercadorias:\n");
    for (i = 0; i < n; i++) {
        printf("\nMercadoria %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo); // le o codigo da mercadoria.
        
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade); // le a quantidade da mercadoria.
        
        printf("Preco: ");
        scanf("%f", &produtos[i].preco); // le o preco da mercadoria.
    }
}

// funcao para processar pedidos dos clientes.
void pedidos(Mercadoria *produtos){
    int num_cliente, cod_mercadoria, qtd_desejada, indice, qtd_atual;
    float valor_total;
    char opcao;
    
    printf("Digite os pedidos dos clientes:\n");
    while (1) {
        printf("\nNumero do cliente (digite 9999 para encerrar): ");
        scanf("%d", &num_cliente);
        
        if (num_cliente == 9999) {
            break;
        }
        do {
            printf("Codigo da mercadoria: ");
            scanf("%d", &cod_mercadoria);
            
            printf("Quantidade desejada: ");
            scanf("%d", &qtd_desejada);
            
            indice = buscar(cod_mercadoria, produtos); // busca a mercadoria no estoque.
            if (indice == -1) { // se nao encontrada.
                printf("Mercadoria nao encontrada.\n");
                break;
            } 
            else { //se encontrada.
                qtd_atual = produtos[indice].quantidade; 
                if (qtd_atual < qtd_desejada) { // se nao ha estoque suficiente.
                    printf("Nao ha estoque suficiente para atender o pedido.\n");
                    printf("Quantidade atual: %d\n", qtd_atual);
                    printf("Deseja fazer um novo pedido com a quantidade disponivel? (S/N)\n");
                    scanf(" %c", &opcao);
                    if (opcao == 'S' || opcao == 's') {
                        qtd_desejada = qtd_atual;
                    }
                    else {
                        break;
                    }
                } 
                valor_total = qtd_desejada * produtos[indice].preco; // calcula o valor total.
                printf("Pedido atendido.\n");
                printf("Valor total: %.2f\n", valor_total); 
                produtos[indice].quantidade -= qtd_desejada; // atualiza a quantidade no estoque.
            }
        } while (0);
        printf("\n");
    }
}
