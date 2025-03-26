/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 9 - Ler 2 conjuntos de 15 números reais, use a função armazenar() para guardar cada conjunto em um vetor diferente. Utilizando a função escalar() calcule o
produto escalar entre eles, dado por x1 * y1 + x2 * y2 + ... + xn * yn. A função imprimir() imprimirá, usando ponteiros, os dois vetores e o produto escalar.
*/
#include<stdio.h>
#include<locale.h>

void armazenar (float *vet);
float escalar (float *vet1, float *vet2);
void imprime (float *vetor1, float *vetor2, float *prodescalar);

int main(){
     setlocale(LC_ALL, "Portuguese");
     
     float conjunto1[15], conjunto2[15];
     float produtoescalar = 0;
     
    printf("Digite 15 valores para o vetor 1:\n");
    armazenar(conjunto1);                          //chamada da função que irá armazenar tanto o conjunto1, quanto o conjunto 2 digitados pelo usuário.

    printf("Digite 15 valores para o vetor 2:\n");
    armazenar(conjunto2);
    
    escalar(conjunto1, conjunto2); //chamada da função que irá calcular o produto escalar.
    
    produtoescalar = escalar(conjunto1, conjunto2); //atribuindo o valor do retorno da função chamada na variável "produtoescalar".
    
    imprime (conjunto1, conjunto2, &produtoescalar); //função que irá imprimir ambos os vetores e o produto usando ponteiros.
    
    return 0;
}
void armazenar(float *vet){ //para armazenar os conjuntos de números digitados pelo usuário tanto no primeiro vetor, quanto no segundo.
	int i;
	
	for(i = 0; i < 15; i++){
		scanf("%f", &vet[i]); 
	}
}
float escalar (float *vet1, float *vet2){ //função que irá calcular o produto escalar dos vetores.
	int i;
	float produtoescalar = 0;
	
	for (i = 0; i < 15; i++){
		produtoescalar += vet1[i] * vet2[i];
	}
	return produtoescalar; //retorna o valor calculado ao local de chamada da função, ou seja, o valor do produto escalar.
}
void imprime (float *vetor1, float *vetor2, float *prodescalar){ //função que irá imprimir os conjuntos e o seu produto escalar.
	int i;
	
	for (i = 0; i < 15; i++){
		printf("Vetor 1 [%d] = %.2f\n", i, *(vetor1 + i));
	}
	for (i = 0; i < 15; i++){
		printf("Vetor 2 [%d] = %.2f\n", i, *(vetor2 + i));
	}
	printf("Produto escalar dos dois conjuntos de vetores: %.2f", *prodescalar);
}

