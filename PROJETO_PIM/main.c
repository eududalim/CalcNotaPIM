#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20


void CabecalhoPrincipal (char *NomeProf){
    printf("\n\t\t ________________________________________________");
    printf("\n\t\t||                                              ||");
    printf("\n\t\t||                                              ||");
    printf("\n\t\t||         SISTEMA DE CALCULOS DE NOTAS         ||\n");
    printf("\t\t||\t    Professor(a) %15s        ||", NomeProf);
    printf("\n\t\t||                                              ||");
    printf("\n\t\t||______________________________________________||");
    printf("\n\n\n");
}


void Instrucoes (){

/**<  Intruções */
        printf("\n\n\t\t==== INTRUCOES ====");
        printf("\n\n Professor, este programa foi feito para lhe ");
        printf("\n auxiliar no calculo das notas de seus alunos, ");
        printf("\n de maneira facil e simples. Voce podera cadastrar  ");
        printf("\n o nome, matricula e notas de seus alunos e obter \n os resultados de forma organizada. ");
        printf("\n\n\n\n Por meio deste, podera :\n ");
        printf("\n\n - Registrar as notas de quatro provas (P1, P2, P3 \n E P4), alem de uma prova substitutiva \n (para substituir a menor nota).");
        printf("\n\n - calcular a media de cada um dos alunos, \n que eh igual a media ponderada das quatro provas, \n e depois de todas as notas cadastradas ");
        printf("\n\n - Visualizar relatorio de desempenho geral");
        printf("\n\n\n\n Passo a Passo: ");
        printf("\n\n 1.  Digite o nome do aluno ");
        printf("\n\n 2.  Digite o numero de matricula do aluno ");
        printf("\n\n 3.  Registre as notas de cinco provas. ");
        printf("\n\n 4.  Digite o peso de cada nota. ");
        printf("\n\n 5.  Enquanto quiser continuar a registrar \n mais alunos, esolha a opcao 2. ");
        printf("\n\n 6.  Assim que terminar o cadastro de alunos, \n no menu principal, escolha a opcao 3, SAIR, \n e Podera entao visualisar o relatorio de \n desempenho e finalizar o programa. ");
        printf("\n\n\n\n\n===================================================\n=================================================== ");
        printf(" \n ");
}


struct Cadastros {
    char aprovado, nome[30];
    int matricula;
    float nota;
};


void Substituicao (float *np1, float *np2, float *np3, float *np4, float *nps){

    if(*np1 < *np2){
        if(*np1 < *np3){
            if(*np1 < *np4){
                *np1 = *nps;
            }
        }
    }

    if(*np2 < *np1){
        if(*np2 < *np3){
            if(*np2 < *np4){
                *np2 = *nps;
            }
        }
    }

    if(*np3 < *np2){
        if(*np3 < *np1){
            if(*np3 < *np4){
                *np3 = *nps;
            }
        }
    }

    if(*np4 < *np2){
        if(*np4 < *np3){
            if(*np4 < *np1){
                *np4 = *nps;
            }
        }
    }
}


float CalcMedia (float p1, float p2, float p3, float p4) {
    float mediaAluno;
    int peso1, peso2, peso3, peso4;

    printf("\nDigite peso das Notas P1, P2, P3 e P4: ");
    scanf("%d %d %d %d", &peso1, &peso2, &peso3, &peso4);

    mediaAluno = ((p1 * peso1) + (p2 * peso2) + (p3 * peso3) + (p4 * peso4)) / 10 ;

    return mediaAluno;
}




int main()
{
    struct Cadastros aluno [MAX];
    char opcao, NomeProf[30];
    float np1, np2, np3, np4, nps, mediaAluno, mediaSala = 0;
    int reprovados = 0, aprovados = 0, sala = 0;
    int i;


    printf("\nNome do professor: ");
    gets(NomeProf);
    system("cls");

    do{

    CabecalhoPrincipal(NomeProf);


    printf("\n\t 1 - Intrucoes");
    printf("\n\t 2 - Calcular notas  ");
    printf("\n\t 3 - SAIR ");
    printf("\n\n Selecione uma opcao: ");
    scanf("%d", &opcao);

    /**<  INICIO ESCOLHA CASO  */
    switch (opcao){
    case 1:
        Instrucoes();        /**< FUNÇÃO QUE CHAMA A IMPRESSÃO DAS INTRUÇÕES */
        break;

    case 2:                           /**< INICIO DO PROGRAMA DE CALCULO */
    printf("\n\nNome do Aluno: ");

    getchar();
    gets(aluno[sala].nome);

    printf("Matricula: ");
    scanf("%d", &aluno[sala].matricula);

    printf("\nNota P1:  ");
    scanf("%f", &np1);

    printf("Nota P2:  ");
    scanf("%f", &np2);

    printf("Nota P3:  ");
    scanf("%f", &np3);

    printf("Nota P4:  ");
    scanf("%f", &np4);

    printf("Nota Prova Substitutiva:  ");
    scanf("%f", &nps);


    Substituicao(&np1, &np2, &np3, &np4, &nps);

    mediaAluno = CalcMedia(np1, np2, np3, np4);

    printf("\nMedia do aluno: %.2f", mediaAluno);

    aluno[sala].nota = mediaAluno;

    mediaSala += mediaAluno ;


    if(mediaAluno < 5.0){
        printf("\nAluno REPROVADO. \n\n");
        reprovados++ ;
        aluno[sala].aprovado = 'N';
    }else{
        printf("\nAluno APROVADO. \n\n");
        aprovados++ ;
        aluno[sala].aprovado = 'S';
    }
    break;

    case 3:
        break;                      /**< OPÇÃO PARA FINALIZAR */

    default :
        printf("\nOpcao invalida!\n");
        getchar();

    }
    /**<  FIM ESCOLHA CASO  */


    if(opcao == 2){
        sala++ ;
        }

    printf("\n\n\n");
    system("pause");
    system("cls");


    }while(opcao != 3);

    CabecalhoPrincipal(NomeProf);

    /**< RELATORIO GERAL FINAL */
    printf("\n\n\t\t ===  RELATORIO GERAL  ===");
    printf("\n\nTotal de Alunos: %d", aprovados + reprovados);
    printf("\n\nMedia da Sala: %.2f", mediaSala / sala);
    printf("\nAprovados: %d", aprovados);
    printf("\n\n\n\t\t MEDIA DOS ALUNOS: \n");


    for(i=0 ; i<sala ; i++){                /**< IMPRESSÃO DOS DADOS DE CADA ALUNO */
    printf("\n%10d  \t|  %15s \t| %6.2f", aluno[i].matricula, aluno[i].nome, aluno[i].nota );

        if(aluno[i].aprovado == 'S'){
            printf("\t APROVADO");
            }else{
            printf("\t REPROVADO");
            }

    }


    printf("\n\n\n");
    system("pause");
    return 0;
}
