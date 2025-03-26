/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 7 -  Implemente um programa para gerenciamento de uma Locadora (utilizando fun��es e vetores). Deve-se
usar ponteiros para uso dos vetores (nos par�metros, na manipula��o). Fun��es a serem criadas: cadastro
de produtos, controle de estoque, venda, renda mensal. Verifique no in�cio do programa: Quantos produtos
ser�o cadastrados. Os produtos podem ser referenciados pelo �ndice, mas deve ter cadastrado o c�digo do
mesmo. Dados do produto: nome, quantidade, valor.*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 30

//Defini��o de uma estrutura para representar o produto.
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float valor;
} Produto;

//Declara��o dos prot�tipos das fun��es.
void cadastrodeprod(Produto *produtos);
void controledeest(Produto *produtos);
void venda(Produto *produtos);
void rendamensal(Produto *produtos);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Produto produtos[TAM] = {0}; //Inicializa��o de um vetor de produtos com tamanho definido pela constante TAM.
    int opcao;

    printf("Bem-vindo a locadora APC!");
    
    //Loop com menu de op��es fornecidos ao usu�rio.
    do {
        printf("\n1 - Cadastrar produtos\n");
        printf("2 - Exibir informa��es do estoque\n");
        printf("3 - Realizar vendas\n");
        printf("4 - Visualizar renda mensal\n");
        printf("0 - Sair\n");
        printf("Selecione a op��o desejada: ");
        scanf("%d", &opcao);
        
    //Switch para a sele��o da escolha do usu�rio.
        switch (opcao) {
            case 1:
                cadastrodeprod(produtos); break; //chamada da fun��o cadastro.
            case 2:
                controledeest(produtos); break; //chamada da fun��o controle de estoque.
            case 3:
                venda(produtos); break; //chamada da fun��o venda.
            case 4:
                rendamensal(produtos); break; //chamada da fun��o renda mensal.
            case 0:
                printf("\nPrograma finalizado!\n"); break; //op��o para o usu�rio sair do programa.
            default:
                printf("\nOp��o inv�lida!\n"); //quando nenhuma op��o v�lida � selecionada.
        }
    } while (opcao != 0); //condi��o para sair do loop.

    return 0;
}
//fun��o para cadastrar produtos.
void cadastrodeprod(Produto *produtos) {
    int qntprodutos, i, j;
    
    //solicita a usu�rio o n�mero de produtos que ele deseja cadastrar.
    printf("\nQuantos produtos voc� deseja cadastrar?(O m�ximo de produtos para cadastro � 30).\n");
    scanf("%d", &qntprodutos);
    
    //para verificaf se o n�mero de produtos passou do limite.
    if (qntprodutos > TAM) {
        printf("\nN�mero de produtos excede o limite do m�ximo 30.\n");
        exit(1);
    }
    //loop para cadastrar os produtos.
    for (i = 0; i < qntprodutos; i++) {
    	//for para encontrar uma posi��o dispon�vel no vetor de produtos.
        for (j = 0; j < TAM; j++) {
            if (produtos[j].codigo == 0) {
                printf("\nDigite o c�digo do produto: ");
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
//fun��o para mostrar informa��es do estoque.
void controledeest(Produto *produtos) {
	int i;
	
	//imprime uma tabela com as inform��es do estoque
    printf("\n----------Estoque-----------\nInforma��es dos produtos cadastrados:\n\n");
    printf("%-10s%-15s%-20s%-15s%-10s\n", "C�digo", "�ndice", "Nome", "Quantidade", "Valor");
    
    for (i = 0; i < TAM; i++) {
        if (produtos[i].codigo != 0) {
            printf("%-10d%-15d%-20s%-15d%-10.2f\n", produtos[i].codigo, i, produtos[i].nome, produtos[i].quantidade, produtos[i].valor);
        }
    }
    printf("\n");
}
//fun��o para realizar vendas.
void venda(Produto *produtos) {
	int codigoparavenda, quantidadevendida, i;
	
	//solicita o c�digo do produto para vender.
	printf("\nDigite o c�digo do produto para realizar a venda do mesmo: ");
    scanf("%d", &codigoparavenda);
    
    //for para encontrar o produto no estoque
    for (i = 0; i < TAM; i++) {
     if (produtos[i].codigo == codigoparavenda) {
      printf("\nDigite a quantidade vendida do produto %s: ", produtos[i].nome);
      scanf("%d", &quantidadevendida);

     if (quantidadevendida > produtos[i].quantidade) {  //verifica se a quantidade vendida � maior do que a quantidade estocada.
        printf("\nQuantidade indispon�vel no estoque!\n");
     }  else {                                           //atualiza a quantidade estocada ap�s a venda.
        produtos[i].quantidade -= quantidadevendida;
        printf("\nProduto(s) vendido(s) com sucesso!\n");
        }
      }
   }
}
//fun��o para calculo da renda mensal.
void rendamensal(Produto *produtos) {
    int i;
	float renda = 0;
    for (i = 0; i < TAM; i++) {
        renda += produtos[i].valor * (float)(produtos[i].quantidade);
    }
    printf("\nRenda mensal: R$%.2f\n", renda);
}
