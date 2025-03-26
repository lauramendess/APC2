/*
Universidade Federal de Catal�o
Aluna: Laura Mendes Gon�alves
Matr�cula: 202301133
Professor(a): Luanna Lopes Lobato e Jos� J�nior
Lista de Exerc�cios 5 de APC2 e LAB2

Atividade 3: Sua empresa foi contratada para o desenvolvimento de um sistema que corrige as provas de m�ltipla escolha (com
05 op��es de resposta e apenas uma correta). Cada prova tem 10 quest�es, cada uma valendo 1.0. O primeiro
conjunto de dados a ser lido ser� o gabarito para a corre��o da prova. Os outros dados consistem da matricula
dos alunos e suas respectivas respostas, e o �ltimo n�mero, do aluno fict�cio, ser� 9999, esses dados ser�o
armazenados no vetor usando Struct. O sistema deve calcular e imprimir:
� para cada aluno, o seu n�mero de matricula e a sua nota.
� a porcentagem de aprova��o, sabendo-se que a nota m�nima para aprova��o � 7.0;
� a nota que teve a maior frequ�ncia absoluta.*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define QUESTOES 10
#define ALUNOS 20
#define NOTA_MINIMA 7.0

//defini��o de uma estrutura para armazenar informa��es das provas.
struct provas{
    char gabarito[QUESTOES];
    char respostas[QUESTOES];
    int matricula[ALUNOS];
    float notas[ALUNOS];
    float aprovacao[ALUNOS];
    int notafrequente;
};

//prot�tipos das fun��es utilizadas no programa.
void lergabarito(struct provas *Provas);
void lermatriculas(struct provas *Provas);
void lerrespostas(struct provas *Provas);
void freqabsoluta(struct provas *Provas);
void imprime(struct provas *Provas);

//fun��o principal.
int main(){
    setlocale(LC_ALL, "Portuguese");
    
    struct provas Provas;
    
    printf("-----BEM VINDO AO SISTEMA DE CORRE��O DE PROVAS DA ESCOLA MUNDO M�GICO!-----\n\n");
    
    // Chama as fun��es para ler o gabarito, matr�culas, respostas, calcular frequ�ncia e imprimir.
    lergabarito(&Provas);
    lermatriculas(&Provas);
    lerrespostas(&Provas);
    freqabsoluta(&Provas);
    imprime(&Provas);
    
}
//fun��o para ler o gabarito da prova.
void lergabarito(struct provas *Provas){
    int i;
    
    printf("Insira o gabarito da prova, entre A-E:\n");
    for(i = 0; i < QUESTOES; i++){
        printf("Quest�o %d = ", i + 1);
        scanf(" %c", &(Provas->gabarito[i]));
        Provas->gabarito[i] = toupper(Provas->gabarito[i]);
        
        //verifica se a op��o inserida � v�lida.
        if((Provas->gabarito[i] != 'A') && (Provas->gabarito[i] != 'B') && (Provas->gabarito[i] != 'C') && (Provas->gabarito[i] != 'D') && (Provas->gabarito[i] != 'E')){
            printf("Voc� inseriu uma op��o inv�lida de respostas! Insira novamente:\n");
            i--;
        }
    }
}
//fun��o para ler as matr�culas dos alunos.
void lermatriculas(struct provas *Provas){
    int i, j;
    int aux; 
    
    printf("\nInsira o N� da matr�cula dos discentes:\n");
    for (i = 0; i < ALUNOS; i++){
        printf("Aluno %d = ", i + 1);
        scanf("%d", &aux); 
        
        //verifica se as matr�culas s�o v�lidas.
        if(i == ALUNOS - 1 && aux != 9999){
            printf("A matr�cula do �ltimo discente deve ser 9999!\n");
            i--;
        }
        else if (i != ALUNOS - 1 && aux == 9999){
            printf("O n�mero de matr�cula 9999 deve ser atribu�do apenas ao �ltimo aluno!\n");
            i--;
        }
        else {
          for (j = 0; j < i; j++) {
            if (Provas->matricula[j] == aux) {
              printf("Esse n�mero de matr�cula j� foi inserido anteriormente. Por favor, digite outro!\n");
              i--; 
              break; 
            }
          }
          if (j == i) {
            Provas->matricula[i] = aux;
          }
        }
    }   
}
//fun��o para ler as respostas dos alunos.
void lerrespostas(struct provas *Provas){
    int i, j;
    
    printf("\nInsira as respostas de cada discente com base ao seu N� de matr�cula:\n");
    for(i = 0; i < ALUNOS; i++){
      printf("\nAluno com o N� de matr�cula = %d", Provas->matricula[i]);
      float nota = 0;
      
        for(j = 0; j < QUESTOES; j++){
           printf("\nQuest�o %d = ", j + 1);
           scanf(" %c", &(Provas->respostas[j]));
           Provas->respostas[j] = toupper(Provas->respostas[j]);
           
           //verifica se a op��o inserida � v�lida.
           if((Provas->respostas[j] != 'A') && (Provas->respostas[j] != 'B') && (Provas->respostas[j] != 'C') && (Provas->respostas[j] != 'D') && (Provas->respostas[j] != 'E')){
              printf("Voc� inseriu uma op��o inv�lida de respostas! Insira novamente:\n");
              j--;
           }
           else if(Provas->respostas[j] == Provas->gabarito[j])
               nota += 1.0;
               
        }
        Provas->notas[i] = nota;
        Provas->aprovacao[i] = (Provas->notas[i] / QUESTOES) * 100;
    }
}
//fun��o para calcular a frequ�ncia absoluta das notas.
void freqabsoluta(struct provas *Provas){
   int i, k;
   float frequencia = 0.0; 
   int cont[11] = {0}; 

   for (i = 0; i < ALUNOS; i++){
    int aux = (int)(Provas->notas[i]);
    for(k = 0; k < ALUNOS; k++) { 
        if (aux == (int)(Provas->notas[k])) {
            cont[aux]++; 
        }
    }
   
    float frequenciaabs = (float)cont[aux] / ALUNOS;
 
    if (frequenciaabs > frequencia) {
        frequencia = frequenciaabs;
        Provas->notafrequente = aux; //Provas->notafrequente recebe aux que tem a nota mais frequente.
    }
  }
}
//fun��o para imprimir as informa��es dos alunos.
void imprime(struct provas *Provas){
    int i;
    
    //imprime uma tabela com as seguintes informa��es:
    printf("\n%-15s%-15s%-12s\n", "Matr�cula", "Nota", "% de Aprova��o");
    for (i = 0; i < ALUNOS; i++) {
     printf("%-15d%-14.1f%-.1f%%\n", Provas->matricula[i], Provas->notas[i], Provas->aprovacao[i]);
   }
   
   //imprime a nota mais frequente:
   printf("\nNota mais frequente: %.1f\n", (float)Provas->notafrequente);
}
