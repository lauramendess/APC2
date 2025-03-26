/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercicios de APC2 e LAB2

Exercicio 9 - Ler 2 conjuntos de 15 numeros reais, use a funcao armazenar() para guardar cada conjunto em um vetor diferente. Utilizando a funcao escalar() calcule o
produto escalar entre eles, dado por x1 * y1 + x2 * y2 + ... + xn * yn. A funcao imprimir() imprimira, usando ponteiros, os dois vetores e o produto escalar.
*/
#include<stdio.h>

void armazenar (float *vet);
float escalar (float *vet1, float *vet2);
void imprime (float *vetor1, float *vetor2, float *prodescalar);

int main(){
	
	float conjunto1[15], conjunto2[15];
	float produtoescalar = 0;
	
	printf("Digite 15 valores para o vetor 1:\n");
	armazenar(conjunto1);                          // chamada da funcao que ira armazenar tanto o conjunto1, quanto o conjunto 2 digitados pelo usuario.

	printf("Digite 15 valores para o vetor 2:\n");
	armazenar(conjunto2);
	
	escalar(conjunto1, conjunto2); // chamada da funcao que ira calcular o produto escalar.
	
	produtoescalar = escalar(conjunto1, conjunto2); // atribuindo o valor do retorno da funcao chamada na variavel "produtoescalar".
	
	imprime (conjunto1, conjunto2, &produtoescalar); // funcao que ira imprimir ambos os vetores e o produto usando ponteiros.
	
	return 0;
}
void armazenar(float *vet){ // para armazenar os conjuntos de numeros digitados pelo usuario tanto no primeiro vetor, quanto no segundo.
	int i;
	
	for(i = 0; i < 15; i++){
		scanf("%f", &vet[i]); 
	}
}
float escalar (float *vet1, float *vet2){ // funcao que ira calcular o produto escalar dos vetores.
	int i;
	float produtoescalar = 0;
	
	for (i = 0; i < 15; i++){
		produtoescalar += vet1[i] * vet2[i];
	}
	return produtoescalar; //retorna o valor calculado ao local de chamada da funcao, ou seja, o valor do produto escalar.
}
void imprime (float *vetor1, float *vetor2, float *prodescalar){ // funcao que ira imprimir os conjuntos e o seu produto escalar.
	int i;
	
	for (i = 0; i < 15; i++){
		printf("Vetor 1 [%d] = %.2f\n", i, *(vetor1 + i));
	}
	for (i = 0; i < 15; i++){
		printf("Vetor 2 [%d] = %.2f\n", i, *(vetor2 + i));
	}
	printf("Produto escalar dos dois conjuntos de vetores: %.2f", *prodescalar);
}
