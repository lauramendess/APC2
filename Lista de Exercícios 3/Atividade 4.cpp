/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professora: Luanna Lopes Lobato
Lista de exerc�cios de APC2 e LAB2

Exerc�cio 4 - Leia dois vetores de inteiros x e y, cada um com 10 elementos (verifique e n�o permita que o usu�rio informe
elementos repetidos). Calcule e mostre os vetores resultantes em cada caso abaixo, utilize uma fun��o menu()
para chamar cada fun��o e manipule o vetor nas fun��es com o uso de ponteiros: Soma() -> soma de cada
elemento de x com o elemento da mesma posi��o em y. Produto() -> multiplica��o de cada elemento de x
com o elemento da mesma posi��o em y. Diferen�a() -> todos os elementos de x que n�o existam em y
Interse��o() -> apenas os elementos que aparecem nos dois vetores. Uniao() -> todos os elementos de x, e
todos os elementos de y que n�o est�o em x.*/
#include<stdio.h>
#include<locale.h>

#define TAM 10
//declara��o dos prot�tipos das fun��es que ser�o utilizadas no programa.
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

	printf("Digite 10 n�meros inteiros, sem repeti��o, para o VETOR X:\n");
	leitura(x);
	
	printf("Digite 10 n�meros inteiros, sem repeti��o, para o VETOR Y:\n");
	leitura(y);
	
	//chama a fun��o "menu" e exibe o menu de opera��es com os vetores X e Y
	printf("\n-----MENU DE OPERA��ES REALIZADAS COM O VETOR X E Y-----\n");
	menu(x, y);
	
	return 0;
} 
//fun��o para ler os elementos do vetor, sem repeti��es.
void leitura(int *vetor){
	int i, j, aux, repet;
	
	for(i = 0; i < TAM; i++){
		do{
		   repet = 0;
		   printf("Insira [%d]: ", i + 1);
           scanf("%d", &aux);
           
           //verifica se o n�mero j� foi inserido anteriormente para evitar repeti��es.
           for ( j = 0; j < i; j++) {
           	if(*(vetor + j) == aux){
           	repet = 1;
           	printf("N�mero j� inserido! Digite novamente, sem repetir.\n");
            break;  //para evitar que o c�digo continue at� o fim mesmo se tiver encontrado um n�mero repetido.
		    }
	   	   }
	       if (!repet) {  //se n�o for repeti��o, armazena o n�mero no vetor.
             *(vetor + i) = aux;
           }
	    } while(repet);
    }
}
//fun��o que exibe o menu de opera��es e chama as fun��es correspondentes.
void menu(int *vet1, int *vet2){
	
	printf("1 - SOMA (soma de cada elemento de x com o elemento da mesma posi��o em y).\n");
	soma(vet1, vet2);
	
	printf("2 - PRODUTO (multiplica��o de cada elemento de x com o elemento da mesma posi��o em y).\n");
	produto(vet1, vet2);
	
	printf("3 - DIFEREN�A (todos os elementos de x que n�o existam em y).\n");
	diferenca(vet1, vet2);
	
	printf("4 - INTERSEC��O (apenas os elementos que aparecem nos dois vetores).\n");
	interseccao(vet1, vet2);
	
	printf("5 - UNI�O (todos os elementos de x e todos os elementos de y que n�o est�o em x).\n");
	uniao(vet1, vet2);
}
//fun��o que calcula a soma dos elementos dos vetores X e Y.
void soma(int *vet1, int *vet2){
	int i;
	
	for (i = 0; i < TAM; i++){
  	  printf("VETOR X [%d] + VETOR Y [%d] = %d\n", i + 1, i + 1, *(vet1 + i) + *(vet2 + i));	
	}
	printf("\n");
}
//fun��o que calcula o produto dos elementos dos vetores X e Y.
void produto(int *vet1, int *vet2){
	int i;
	
	for (i = 0; i < TAM; i++){
	  printf("VETOR X [%d] * VETOR Y [%d] = %d\n", i + 1, i + 1, (*(vet1 + i)) * (*(vet2 + i)));
	}
	printf("\n");
}
//fun��o que calcula a diferen�a entre os elementos dos vetores X e Y.
void diferenca(int *vetx, int *vety){
	int i, j, aux;
	
	for (i = 0; i < TAM; i++){
	  aux = 0;
	   for (j = 0; j < TAM; j++){
     	if (*(vetx + i) == *(vety + j))	{
     		aux = 1;  //caso seja encontrado n�meros comuns em ambos os vetores.
     		break; 
		}
      }
       if (!aux) { //caso n�o seja encontrado n�meros comuns em ambos os vetores, entrar� no if para imprimir a diferen�a.
      	printf("%d ", *(vetx + i));
	  }
	}
   printf("\n\n");
}
//fun��o que calcula a interse��o entre os elementos dos vetores X e Y.
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
//fun��o que calcula a uni�o entre os elementos dos vetores X e Y.
void uniao(int *vetx, int *vety){
	int i, j, uniaovet[TAM * 2], tamanho = TAM, aux;
	
	// copia os elementos do vetor X para o vetor de uni�o.
	for (i = 0; i < TAM; i++){
	  *(uniaovet + i) = *(vetx + i);
	}
	//adiciona os elementos de Y que n�o est�o em X ao vetor de uni�o.
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
   //mostra o vetor uni�o.
   for(i = 0; i < tamanho; i++){
   	  printf("%d ", *(uniaovet + i));
   }
 }
