/*
Universidade Federal de Catalão
Aluna: Laura Mendes Gonçalves
Matrícula: 202301133
Professor(a): Luanna Lopes Lobato e José Júnior
Lista de Exercícios 5 de APC2 e LAB2

Atividade 3: Sua empresa foi contratada para o desenvolvimento de um sistema que corrige as provas de múltipla escolha (com
05 opções de resposta e apenas uma correta). Cada prova tem 10 questões, cada uma valendo 1.0. O primeiro
conjunto de dados a ser lido será o gabarito para a correção da prova. Os outros dados consistem da matricula
dos alunos e suas respectivas respostas, e o último número, do aluno fictício, será 9999, esses dados serão
armazenados no vetor usando Struct. O sistema deve calcular e imprimir:
– para cada aluno, o seu número de matricula e a sua nota.
– a porcentagem de aprovação, sabendo-se que a nota mínima para aprovação é 7.0;
– a nota que teve a maior frequência absoluta.*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define QUESTOES 10
#define ALUNOS 20
#define NOTA_MINIMA 7.0

//definição de uma estrutura para armazenar informações das provas.
struct provas{
    char gabarito[QUESTOES];
    char respostas[QUESTOES];
    int matricula[ALUNOS];
    float notas[ALUNOS];
    float aprovacao[ALUNOS];
    int notafrequente;
};

//protótipos das funções utilizadas no programa.
void lergabarito(struct provas *Provas);
void lermatriculas(struct provas *Provas);
void lerrespostas(struct provas *Provas);
void freqabsoluta(struct provas *Provas);
void imprime(struct provas *Provas);

//função principal.
int main(){
    setlocale(LC_ALL, "Portuguese");
    
    struct provas Provas;
    
    printf("-----BEM VINDO AO SISTEMA DE CORREÇÃO DE PROVAS DA ESCOLA MUNDO MÁGICO!-----\n\n");
    
    // Chama as funções para ler o gabarito, matrículas, respostas, calcular frequência e imprimir.
    lergabarito(&Provas);
    lermatriculas(&Provas);
    lerrespostas(&Provas);
    freqabsoluta(&Provas);
    imprime(&Provas);
    
}
//função para ler o gabarito da prova.
void lergabarito(struct provas *Provas){
    int i;
    
    printf("Insira o gabarito da prova, entre A-E:\n");
    for(i = 0; i < QUESTOES; i++){
        printf("Questão %d = ", i + 1);
        scanf(" %c", &(Provas->gabarito[i]));
        Provas->gabarito[i] = toupper(Provas->gabarito[i]);
        
        //verifica se a opção inserida é válida.
        if((Provas->gabarito[i] != 'A') && (Provas->gabarito[i] != 'B') && (Provas->gabarito[i] != 'C') && (Provas->gabarito[i] != 'D') && (Provas->gabarito[i] != 'E')){
            printf("Você inseriu uma opção inválida de respostas! Insira novamente:\n");
            i--;
        }
    }
}
//função para ler as matrículas dos alunos.
void lermatriculas(struct provas *Provas){
    int i, j;
    int aux; 
    
    printf("\nInsira o Nº da matrícula dos discentes:\n");
    for (i = 0; i < ALUNOS; i++){
        printf("Aluno %d = ", i + 1);
        scanf("%d", &aux); 
        
        //verifica se as matrículas são válidas.
        if(i == ALUNOS - 1 && aux != 9999){
            printf("A matrícula do último discente deve ser 9999!\n");
            i--;
        }
        else if (i != ALUNOS - 1 && aux == 9999){
            printf("O número de matrícula 9999 deve ser atribuído apenas ao último aluno!\n");
            i--;
        }
        else {
          for (j = 0; j < i; j++) {
            if (Provas->matricula[j] == aux) {
              printf("Esse número de matrícula já foi inserido anteriormente. Por favor, digite outro!\n");
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
//função para ler as respostas dos alunos.
void lerrespostas(struct provas *Provas){
    int i, j;
    
    printf("\nInsira as respostas de cada discente com base ao seu Nº de matrícula:\n");
    for(i = 0; i < ALUNOS; i++){
      printf("\nAluno com o Nº de matrícula = %d", Provas->matricula[i]);
      float nota = 0;
      
        for(j = 0; j < QUESTOES; j++){
           printf("\nQuestão %d = ", j + 1);
           scanf(" %c", &(Provas->respostas[j]));
           Provas->respostas[j] = toupper(Provas->respostas[j]);
           
           //verifica se a opção inserida é válida.
           if((Provas->respostas[j] != 'A') && (Provas->respostas[j] != 'B') && (Provas->respostas[j] != 'C') && (Provas->respostas[j] != 'D') && (Provas->respostas[j] != 'E')){
              printf("Você inseriu uma opção inválida de respostas! Insira novamente:\n");
              j--;
           }
           else if(Provas->respostas[j] == Provas->gabarito[j])
               nota += 1.0;
               
        }
        Provas->notas[i] = nota;
        Provas->aprovacao[i] = (Provas->notas[i] / QUESTOES) * 100;
    }
}
//função para calcular a frequência absoluta das notas.
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
//função para imprimir as informações dos alunos.
void imprime(struct provas *Provas){
    int i;
    
    //imprime uma tabela com as seguintes informações:
    printf("\n%-15s%-15s%-12s\n", "Matrícula", "Nota", "% de Aprovação");
    for (i = 0; i < ALUNOS; i++) {
     printf("%-15d%-14.1f%-.1f%%\n", Provas->matricula[i], Provas->notas[i], Provas->aprovacao[i]);
   }
   
   //imprime a nota mais frequente:
   printf("\nNota mais frequente: %.1f\n", (float)Provas->notafrequente);
}
