/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professora: Luanna Lopes Lobato
Lista de exercícios de APC2 e LAB2

Exercício 10 - Faça um programa que leia o número de inscrição de 10 atletas, sua altura e peso. Guarde os valores em uma matriz 10x3. Em uma função busca()
encontre o atleta mais baixo, o mais alto, o mais leve e o que tem maior peso, mostrando o número desses atletas. Use ponteiros para manipular esses
valores na função busca(). 
*/
#include <stdio.h>
#include <locale.h>

#define N 10
#define D 3

void busca(float dados[][D], int quantidadeatletas, int *atletaalto, int *atletabaixo, int *atletaleve, int *atletapeso);

int main() {
    setlocale(LC_ALL, "Portuguese");

    float dadosdosatletas[N][D];
    int i;
    int atletamaisalto = 0, atletamaisbaixo = 0, atletamaisleve = 0, atletamaiorpeso = 0;

    printf("Preenchimento das informações dos atletas:");

    for (i = 0; i < N; i++) { //para ler os dados dos atletas e armazenar.

        printf("\n-Insira o número de inscrição do atleta %d: ", i + 1);
        scanf("%f", &dadosdosatletas[i][0]);
        fflush(stdin);
	
        printf("\n-Insira a altura, em metros, do atleta %d: ", i + 1);
        scanf("%f", &dadosdosatletas[i][1]);
        fflush(stdin);
        
        printf("\n-Insira o peso, em kg, do atleta %d: ", i + 1);
        scanf("%f", &dadosdosatletas[i][2]);
    }

    busca(dadosdosatletas, N, &atletamaisalto, &atletamaisbaixo, &atletamaisleve, &atletamaiorpeso);
    
    return 0;
}
//função que irá procurar o maior, menor, mais leve e mais pesado
void busca(float dados[][D], int quantidadeatletas, int *atletaalto, int *atletabaixo, int *atletaleve, int *atletapeso) { 
    int i;
    *atletaalto = 0;
    *atletabaixo = 0;
    *atletaleve = 0;
    *atletapeso = 0;

    for (i = 0; i < quantidadeatletas; i++) {
        if (dados[i][1] > dados[*atletaalto][1]) {
            *atletaalto = i;
        }
        if (dados[i][1] < dados[*atletabaixo][1]) {
            *atletabaixo = i;
        }
        if (dados[i][2] < dados[*atletaleve][2]) {
            *atletaleve = i;
        }
        if (dados[i][2] > dados[*atletapeso][2]) {
            *atletapeso = i;
        }
    }
    printf("\nNúmero do atleta mais alto: %.0f", dados[*atletaalto][0]);
    printf("\nNúmero do atleta mais baixo: %.0f", dados[*atletabaixo][0]);
    printf("\nNúmero do atleta mais leve: %.0f", dados[*atletaleve][0]);
    printf("\nNúmero do atleta com maior peso: %.0f", dados[*atletapeso][0]);
}


