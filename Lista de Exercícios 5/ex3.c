/*
Universidade Federal de Catalao
Aluna: Laura Mendes Goncalves
Matricula: 202301133
Professor(a): Luanna Lopes Lobato e Jose Junior
Lista de Exercicios 5 de APC2 e LAB2

Atividade 3: Sua empresa foi contratada para o desenvolvimento de um sistema que corrige as provas de multipla escolha (com
05 opcoes de resposta e apenas uma correta). Cada prova tem 10 questoes, cada uma valendo 1.0. O primeiro
conjunto de dados a ser lido sera o gabarito para a correcao da prova. Os outros dados consistem da matricula
dos alunos e suas respectivas respostas, e o ultimo numero, do aluno ficticio, sera 9999, esses dados serao
armazenados no vetor usando Struct. O sistema deve calcular e imprimir:
- para cada aluno, o seu numero de matricula e a sua nota.
- a porcentagem de aprovacao, sabendo-se que a nota minima para aprovacao e 7.0;
- a nota que teve a maior frequencia absoluta.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define QUESTOES 10
#define ALUNOS 20
#define NOTA_MINIMA 7.0

// definicao de uma estrutura para armazenar informacoes das provas.
struct provas{
    char gabarito[QUESTOES];
    char respostas[QUESTOES];
    int matricula[ALUNOS];
    float notas[ALUNOS];
    float aprovacao[ALUNOS];
    int notafrequente;
};

// prototipos das funcoes utilizadas no programa.
void lergabarito(struct provas *Provas);
void lermatriculas(struct provas *Provas);
void lerrespostas(struct provas *Provas);
void freqabsoluta(struct provas *Provas);
void imprime(struct provas *Provas);

// funcao principal.
int main(){
    struct provas Provas;
    
    printf("-----BEM VINDO AO SISTEMA DE CORRECAO DE PROVAS DA ESCOLA MUNDO MAGICO!-----\n\n");
    
    // Chama as funcoes para ler o gabarito, matriculas, respostas, calcular frequencia e imprimir.
    lergabarito(&Provas);
    lermatriculas(&Provas);
    lerrespostas(&Provas);
    freqabsoluta(&Provas);
    imprime(&Provas);
    
}

// funcao para ler o gabarito da prova.
void lergabarito(struct provas *Provas){
    int i;
    
    printf("Insira o gabarito da prova, entre A-E:\n");
    for(i = 0; i < QUESTOES; i++){
        printf("Questao %d = ", i + 1);
        scanf(" %c", &(Provas->gabarito[i]));
        Provas->gabarito[i] = toupper(Provas->gabarito[i]);
        
        // verifica se a opcao inserida e valida.
        if((Provas->gabarito[i] != 'A') && (Provas->gabarito[i] != 'B') && (Provas->gabarito[i] != 'C') && (Provas->gabarito[i] != 'D') && (Provas->gabarito[i] != 'E')){
            printf("Voce inseriu uma opcao invalida de respostas! Insira novamente:\n");
            i--;
        }
    }
}
// funcao para ler as matriculas dos alunos.
void lermatriculas(struct provas *Provas){
    int i, j;
    int aux; 
    
    printf("\nInsira o No da matricula dos discentes:\n");
    for (i = 0; i < ALUNOS; i++){
        printf("Aluno %d = ", i + 1);
        scanf("%d", &aux); 
        
        // verifica se as matriculas sao validas.
        if(i == ALUNOS - 1 && aux != 9999){
            printf("A matricula do ultimo discente deve ser 9999!\n");
            i--;
        }
        else if (i != ALUNOS - 1 && aux == 9999){
            printf("O numero de matricula 9999 deve ser atribuido apenas ao ultimo aluno!\n");
            i--;
        }
        else {
          for (j = 0; j < i; j++) {
            if (Provas->matricula[j] == aux) {
              printf("Esse numero de matricula ja foi inserido anteriormente. Por favor, digite outro!\n");
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

// funcao para ler as respostas dos alunos.
void lerrespostas(struct provas *Provas){
    int i, j;
    
    printf("\nInsira as respostas de cada discente com base ao seu No de matricula:\n");
    for(i = 0; i < ALUNOS; i++){
      printf("\nAluno com o No de matricula = %d", Provas->matricula[i]);
      float nota = 0;
      
        for(j = 0; j < QUESTOES; j++){
           printf("\nQuestao %d = ", j + 1);
           scanf(" %c", &(Provas->respostas[j]));
           Provas->respostas[j] = toupper(Provas->respostas[j]);
           
           // verifica se a opcao inserida e valida.
           if((Provas->respostas[j] != 'A') && (Provas->respostas[j] != 'B') && (Provas->respostas[j] != 'C') && (Provas->respostas[j] != 'D') && (Provas->respostas[j] != 'E')){
              printf("Voce inseriu uma opcao invalida de respostas! Insira novamente:\n");
              j--;
           }
           else if(Provas->respostas[j] == Provas->gabarito[j])
               nota += 1.0;
               
        }
        Provas->notas[i] = nota;
        Provas->aprovacao[i] = (Provas->notas[i] / QUESTOES) * 100;
    }
}

// funcao para calcular a frequencia absoluta das notas.
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
        Provas->notafrequente = aux; // Provas->notafrequente recebe aux que tem a nota mais frequente.
    }
  }
}

// funcao para imprimir as informacoes dos alunos.
void imprime(struct provas *Provas){
    int i;
    
    // imprime uma tabela com as seguintes informacoes:
    printf("\n%-15s%-15s%-12s\n", "Matricula", "Nota", "% de Aprovacao");
    for (i = 0; i < ALUNOS; i++) {
     printf("%-15d%-14.1f%-.1f%%\n", Provas->matricula[i], Provas->notas[i], Provas->aprovacao[i]);
   }
   
   // imprime a nota mais frequente:
   printf("\nNota mais frequente: %.1f\n", (float)Provas->notafrequente);
}
