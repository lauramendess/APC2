/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 7 -  Implemente um programa para gerenciamento de uma Locadora (utilizando funções e vetores). Deve-se
usar ponteiros para uso dos vetores (nos parâmetros, na manipulação). Funções a serem criadas: cadastro
de produtos, controle de estoque, venda, renda mensal. Verifique no início do programa: Quantos produtos
serão cadastrados. Os produtos podem ser referenciados pelo índice, mas deve ter cadastrado o código do
mesmo. Dados do produto: nome, quantidade, valor.*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 30

//Definição de uma estrutura para representar o produto.
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float valor;
} Produto;

//Declaração dos protótipos das funções.
void cadastrodeprod(Produto *produtos);
void controledeest(Produto *produtos);
void venda(Produto *produtos);
void rendamensal(Produto *produtos);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Produto produtos[TAM] = {0}; //Inicialização de um vetor de produtos com tamanho definido pela constante TAM.
    int opcao;

    printf("Bem-vindo a locadora APC!");
    
    //Loop com menu de opções fornecidos ao usuário.
    do {
        printf("\n1 - Cadastrar produtos\n");
        printf("2 - Exibir informações do estoque\n");
        printf("3 - Realizar vendas\n");
        printf("4 - Visualizar renda mensal\n");
        printf("0 - Sair\n");
        printf("Selecione a opção desejada: ");
        scanf("%d", &opcao);
        
    //Switch para a seleção da escolha do usuário.
        switch (opcao) {
            case 1:
                cadastrodeprod(produtos); break; //chamada da função cadastro.
            case 2:
                controledeest(produtos); break; //chamada da função controle de estoque.
            case 3:
                venda(produtos); break; //chamada da função venda.
            case 4:
                rendamensal(produtos); break; //chamada da função renda mensal.
            case 0:
                printf("\nPrograma finalizado!\n"); break; //opção para o usuário sair do programa.
            default:
                printf("\nOpção inválida!\n"); //quando nenhuma opção válida é selecionada.
        }
    } while (opcao != 0); //condição para sair do loop.

    return 0;
}
//função para cadastrar produtos.
void cadastrodeprod(Produto *produtos) {
    int qntprodutos, i, j;
    
    //solicita a usuário o número de produtos que ele deseja cadastrar.
    printf("\nQuantos produtos você deseja cadastrar?(O máximo de produtos para cadastro é 30).\n");
    scanf("%d", &qntprodutos);
    
    //para verificaf se o número de produtos passou do limite.
    if (qntprodutos > TAM) {
        printf("\nNúmero de produtos excede o limite do máximo 30.\n");
        exit(1);
    }
    //loop para cadastrar os produtos.
    for (i = 0; i < qntprodutos; i++) {
    	//for para encontrar uma posição disponível no vetor de produtos.
        for (j = 0; j < TAM; j++) {
            if (produtos[j].codigo == 0) {
                printf("\nDigite o código do produto: ");
                scanf("%d", &produtos[j].codigo);

                printf("\nDigite o nome do produto: ");
                fflush(stdin);
                scanf("%49[^\n]s", produtos[j].nome);

                printf("\nDigite a quantidade do produto: ");
                fflush(stdin);
                scanf("%d", &produtos[j].quantidade);

                printf("\nDigite o valor do produto: ");
                fflush(stdin);
                scanf("%f", &produtos[j].valor);

                printf("\nProduto cadastrado com sucesso!\n");
                break;  
            }
        }
    }
}
//função para mostrar informações do estoque.
void controledeest(Produto *produtos) {
	int i;
	
	//imprime uma tabela com as informções do estoque
    printf("\n----------Estoque-----------\nInformações dos produtos cadastrados:\n\n");
    printf("%-10s%-15s%-20s%-15s%-10s\n", "Código", "Índice", "Nome", "Quantidade", "Valor");
    
    for (i = 0; i < TAM; i++) {
        if (produtos[i].codigo != 0) {
            printf("%-10d%-15d%-20s%-15d%-10.2f\n", produtos[i].codigo, i, produtos[i].nome, produtos[i].quantidade, produtos[i].valor);
        }
    }
    printf("\n");
}
//função para realizar vendas.
void venda(Produto *produtos) {
	int codigoparavenda, quantidadevendida, i;
	
	//solicita o código do produto para vender.
	printf("\nDigite o código do produto para realizar a venda do mesmo: ");
    scanf("%d", &codigoparavenda);
    
    //for para encontrar o produto no estoque
    for (i = 0; i < TAM; i++) {
     if (produtos[i].codigo == codigoparavenda) {
      printf("\nDigite a quantidade vendida do produto %s: ", produtos[i].nome);
      scanf("%d", &quantidadevendida);

     if (quantidadevendida > produtos[i].quantidade) {  //verifica se a quantidade vendida é maior do que a quantidade estocada.
        printf("\nQuantidade indisponível no estoque!\n");
     }  else {                                           //atualiza a quantidade estocada após a venda.
        produtos[i].quantidade -= quantidadevendida;
        printf("\nProduto(s) vendido(s) com sucesso!\n");
        }
      }
   }
}
//função para calculo da renda mensal.
void rendamensal(Produto *produtos) {
    int i;
	float renda = 0;
    for (i = 0; i < TAM; i++) {
        renda += produtos[i].valor * (float)(produtos[i].quantidade);
    }
    printf("\nRenda mensal: R$%.2f\n", renda);
}
