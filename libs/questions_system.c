#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "questions_system.h"

/*
    LIDA COM OS QUESTIONÁRIOS DO SISTEMA
*/

static int muitoRuim = 0;
static int ruim = 0;
static int maisOuMenos = 0;
static int bom = 0;
static int muitoBom = 0;

// questionário em si
void abaQuestionario(char *tema) {
    int opt = 0;
    bool valido = false;
    while(!valido){
        int cont = 1;
        while(cont <= 5){
            limpar();
            printf("## ");
            questionario(cont);
            if(cont == 1){
                printf(" %s", tema);
            }
            printf("\n");
            linha();
            for(int i=0; i<5; i++){
                printf("\t%d- %s.\n", i+1, opcaoAvaliacao(i));
            }
            printf("\nDIGITE '0' PARA CANCELAR A AVALIACAO.\n");
            linha();

            printf("DIGITE O NUMERO CORRESPONDENTE\n> ");
            scanf("%d", &opt);

            if(opt > 0 && opt <= 5){
                printf("VOCE AVALIOU COMO: %s.\n", opcaoAvaliacao(opt-1));
                valido = true;
                esperaRapido();
                limpar();
                if(cont == 1){
                    atualizaNumeroAvaliacaoTema(opt, tema);
                    geraArquivoAvaliacaoTema(opt, tema);
                } else {
                    atualizaNumeroAvaliacao(opt, cont);
                    geraArquivoAvaliacao(opt, cont);
                }
                cont++;
            } else if(opt == 0){
                limpar();
                printf("OPERACAO CANCELADA!\n");
                espera();
                if(cont > 1){
                    printf("AGRADECEMOS SUA AVALIACAO!\n");
                    espera();
                }
                valido = true;
                break;
            } else {
                limpar();
                printf("OPCAO INVALIDA!\n");
                espera();
            }
        }

        if(cont == 6){
            printf("AGRADECEMOS SUA AVALIACAO!\n");
            espera();
        }

    }
}

// imprime na tela o conteúdo dos questionários
void questionario(int questao){
    char *nomeArquivo[20];

    sprintf(nomeArquivo, "files/questionarios/questao%d.txt", questao);
    leArquivo(nomeArquivo);
}

// retorna uma string de avaliação
char *opcaoAvaliacao(int index){
    char *avaliacao[] = {"MUITO RUIM", "RUIM", "MAIS OU MENOS", "BOM", "MUITO BOM"};

    return avaliacao[index];
}

// armazena as avaliações do tema
bool geraArquivoAvaliacaoTema(int avaliacao, char tema[]){
    char *nomeArquivo[50];
    sprintf(nomeArquivo, "files/avaliacoes/avaliacao_tema/%s/avaliacao_opcao%d.txt", tema, avaliacao);
    int valorAvaliacao = obterAvaliacao(avaliacao);

    return geraArquivoNumero(nomeArquivo, valorAvaliacao);
}

// armazena as avaliações do museu
bool geraArquivoAvaliacao(int avaliacao, int questionario){
    char *nomeArquivo[40];
    sprintf(nomeArquivo, "files/avaliacoes/avaliacao_museu/questionario%d/avaliacao_opcao%d.txt", questionario, avaliacao);
    int valorAvaliacao = obterAvaliacao(avaliacao);

    return geraArquivoNumero(nomeArquivo, valorAvaliacao);
}

// RETORNA O NUMERO DE AVALIAÇÃO
int obterAvaliacao(int index){

    switch(index){
    case 1:
        return muitoRuim;
        break;
    case 2:
        return ruim;
        break;
    case 3:
        return maisOuMenos;
        break;
    case 4:
        return bom;
        break;
    case 5:
        return muitoBom;
        break;
    default:
        return 0;
        break;
    }
}

// PERSISTE O NUMERO DE AVALIAÇÃO DO MUSEU NO ARQUIVO
int recuperaNumeroAvaliacao(int avaliacao, int questionario) {

    char *nomeArquivo[40];
    sprintf(nomeArquivo, "files/avaliacoes/avaliacao_museu/questionario%d/avaliacao_opcao%d.txt", questionario, avaliacao);
    int numeroAvaliacao = retornaArquivoInteiro(nomeArquivo);

    return numeroAvaliacao;
}

// PERSISTE O NUMERO DE AVALIAÇÃO DO TEMA NO ARQUIVO
int recuperaNumeroAvaliacaoTema(int avaliacao, char tema[]) {

    char *nomeArquivo[50];
    sprintf(nomeArquivo, "files/avaliacoes/avaliacao_tema/%s/avaliacao_opcao%d.txt", tema, avaliacao);
    int numeroAvaliacao = retornaArquivoInteiro(nomeArquivo);

    return numeroAvaliacao;
}

// ATUALIZA O NUMERO DE AVALIAÇÃO DO MUSEU, SOBRESCREVENDO O ARQUIVO ATUAL
void atualizaNumeroAvaliacao(int avaliacao, int questionario){

    switch(avaliacao){
    case 1:
        muitoRuim = recuperaNumeroAvaliacao(avaliacao, questionario);
        muitoRuim++;
        break;
    case 2:
        ruim = recuperaNumeroAvaliacao(avaliacao, questionario);
        ruim++;
        break;
    case 3:
        maisOuMenos = recuperaNumeroAvaliacao(avaliacao, questionario);
        maisOuMenos++;
        break;
    case 4:
        bom = recuperaNumeroAvaliacao(avaliacao, questionario);
        bom++;
        break;
    case 5:
        muitoBom = recuperaNumeroAvaliacao(avaliacao, questionario);
        muitoBom++;
        break;
    default:
        break;
    }
}

// ATUALIZA O NUMERO DE AVALIAÇÃO DO TEMA, SOBRESCREVENDO O ARQUIVO ATUAL
void atualizaNumeroAvaliacaoTema(int avaliacao, char tema[]){

    switch(avaliacao){
    case 1:
        muitoRuim = recuperaNumeroAvaliacaoTema(avaliacao, tema);
        muitoRuim++;
        break;
    case 2:
        ruim = recuperaNumeroAvaliacaoTema(avaliacao, tema);
        ruim++;
        break;
    case 3:
        maisOuMenos = recuperaNumeroAvaliacaoTema(avaliacao, tema);
        maisOuMenos++;
        break;
    case 4:
        bom = recuperaNumeroAvaliacaoTema(avaliacao, tema);
        bom++;
        break;
    case 5:
        muitoBom = recuperaNumeroAvaliacaoTema(avaliacao, tema);
        muitoBom++;
        break;
    default:
        break;
    }
}
