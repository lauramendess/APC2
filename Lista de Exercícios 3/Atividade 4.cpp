/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 4 - Leia dois vetores de inteiros x e y, cada um com 10 elementos (verifique e não permita que o usuário informe
elementos repetidos). Calcule e mostre os vetores resultantes em cada caso abaixo, utilize uma função menu()
para chamar cada função e manipule o vetor nas funções com o uso de ponteiros: Soma() -> soma de cada
elemento de x com o elemento da mesma posição em y. Produto() -> multiplicação de cada elemento de x
com o elemento da mesma posição em y. Diferença() -> todos os elementos de x que não existam em y
Interseção() -> apenas os elementos que aparecem nos dois vetores. Uniao() -> todos os elementos de x, e
todos os elementos de y que não estão em x.*/
#include<stdio.h>
#include<locale.h>

#define TAM 10
//declaração dos protótipos das funções que serão utilizadas no programa.
void leitura(int *vetor);
void menu(int *vet1, int *vet2);
void soma(int *vet1, int *vet2);
void produto(int *vet1, int *vet2);
void diferenca(int *vetx, int *vety);
void interseccao(int *vetx, int *vety);
void uniao(int *vetx, int *vety);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int i, x[TAM], y[TAM];

	printf("Digite 10 números inteiros, sem repetição, para o VETOR X:\n");
	leitura(x);
	
	printf("Digite 10 números inteiros, sem repetição, para o VETOR Y:\n");
	leitura(y);
	
	//chama a função "menu" e exibe o menu de operações com os vetores X e Y
	printf("\n-----MENU DE OPERAÇÕES REALIZADAS COM O VETOR X E Y-----\n");
	menu(x, y);
	
	return 0;
} 
//função para ler os elementos do vetor, sem repetições.
void leitura(int *vetor){
	int i, j, aux, repet;
	
	for(i = 0; i < TAM; i++){
		do{
		   repet = 0;
		   printf("Insira [%d]: ", i + 1);
           scanf("%d", &aux);
           
           //verifica se o número já foi inserido anteriormente para evitar repetições.
           for ( j = 0; j < i; j++) {
           	if(*(vetor + j) == aux){
           	repet = 1;
           	printf("Número já inserido! Digite novamente, sem repetir.\n");
            break;  //para evitar que o código continue até o fim mesmo se tiver encontrado um número repetido.
		    }
	   	   }
	       if (!repet) {  //se não for repetição, armazena o número no vetor.
             *(vetor + i) = aux;
           }
	    } while(repet);
    }
}
//função que exibe o menu de operações e chama as funções correspondentes.
void menu(int *vet1, int *vet2){
	
	printf("1 - SOMA (soma de cada elemento de x com o elemento da mesma posição em y).\n");
	soma(vet1, vet2);
	
	printf("2 - PRODUTO (multiplicação de cada elemento de x com o elemento da mesma posição em y).\n");
	produto(vet1, vet2);
	
	printf("3 - DIFERENÇA (todos os elementos de x que não existam em y).\n");
	diferenca(vet1, vet2);
	
	printf("4 - INTERSECÇÃO (apenas os elementos que aparecem nos dois vetores).\n");
	interseccao(vet1, vet2);
	
	printf("5 - UNIÃO (todos os elementos de x e todos os elementos de y que não estão em x).\n");
	uniao(vet1, vet2);
}
//função que calcula a soma dos elementos dos vetores X e Y.
void soma(int *vet1, int *vet2){
	int i;
	
	for (i = 0; i < TAM; i++){
  	  printf("VETOR X [%d] + VETOR Y [%d] = %d\n", i + 1, i + 1, *(vet1 + i) + *(vet2 + i));	
	}
	printf("\n");
}
//função que calcula o produto dos elementos dos vetores X e Y.
void produto(int *vet1, int *vet2){
	int i;
	
	for (i = 0; i < TAM; i++){
	  printf("VETOR X [%d] * VETOR Y [%d] = %d\n", i + 1, i + 1, (*(vet1 + i)) * (*(vet2 + i)));
	}
	printf("\n");
}
//função que calcula a diferença entre os elementos dos vetores X e Y.
void diferenca(int *vetx, int *vety){
	int i, j, aux;
	
	for (i = 0; i < TAM; i++){
	  aux = 0;
	   for (j = 0; j < TAM; j++){
     	if (*(vetx + i) == *(vety + j))	{
     		aux = 1;  //caso seja encontrado números comuns em ambos os vetores.
     		break; 
		}
      }
       if (!aux) { //caso não seja encontrado números comuns em ambos os vetores, entrará no if para imprimir a diferença.
      	printf("%d ", *(vetx + i));
	  }
	}
   printf("\n\n");
}
//função que calcula a interseção entre os elementos dos vetores X e Y.
void interseccao(int *vetx, int *vety){
	int i, j;
	
	for(i = 0; i < TAM; i++){
      for(j = 0; j < TAM; j++){
	    if(*(vetx + i) == *(vety + j)){
	      printf("%d ", *(vetx + i));
		}
      }
    }
   printf("\n\n");
}
//função que calcula a união entre os elementos dos vetores X e Y.
void uniao(int *vetx, int *vety){
	int i, j, uniaovet[TAM * 2], tamanho = TAM, aux;
	
	// copia os elementos do vetor X para o vetor de união.
	for (i = 0; i < TAM; i++){
	  *(uniaovet + i) = *(vetx + i);
	}
	//adiciona os elementos de Y que não estão em X ao vetor de união.
	for (i = 0; i < TAM; i++){
      aux = 0;  
	   for (j = 0; j < TAM; j++){
	 	if (*(vety + i) == *(uniaovet + j)){
         aux = 1;
         break;
	 }
    }
      if(!aux){
      	*(uniaovet + tamanho) = *(vety + i);
      	tamanho++;
	  }
   }
   //mostra o vetor união.
   for(i = 0; i < tamanho; i++){
   	  printf("%d ", *(uniaovet + i));
   }
 }
