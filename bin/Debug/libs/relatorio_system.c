#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "relatorio_system.h"

/*
    GERA RELATÓRIOS
*/

// GERA RELATORIO DO TEMA
void gerarRelatorioTema() {

    int opinioes[5];

    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            char *nomeArquivo[50];
            sprintf(nomeArquivo, "files/avaliacoes/avaliacao_tema/%s/avaliacao_opcao%d.txt", obterTema(i), j+1);
            int opiniao = retornaArquivoInteiro(nomeArquivo);
            opinioes[j] = opiniao;
        }

        int totOpinioes = 0;
        for(int i=0; i<5; i++){
            totOpinioes += opinioes[i];
        }

        printf("## GERANDO RELATORIO DO TEMA %s\n", obterTema(i));
        espera();
        linha();
        char *nomeRelatorio[30];
        sprintf(nomeRelatorio, "relatorios/relatorio_tema/relatorio_tema%d.csv", i+1);

        remove(nomeRelatorio);

        if(geraEImplementaArquivo(nomeRelatorio, "CLASSIFICACAO, AVALIACOES, PORCENTAGEM(%)\n")){

            printf("RELATORIO TEMA %s:\n", obterTema(i));

            float percentual = 0;
            for(int i=0; i<5; i++){
                char estruturaRelatorio[50];
                if(opinioes[i] == 0){
                    percentual = 0;
                    sprintf(estruturaRelatorio, "%s, %d,%.1f%%\n", opcaoAvaliacao(i), 0, percentual);
                    geraEImplementaArquivo(nomeRelatorio, estruturaRelatorio);
                    printf("%s - %d - %.1f%%\n", opcaoAvaliacao(i), 0, percentual);
                } else {
                    percentual = (float)opinioes[i] / totOpinioes * 100;
                    sprintf(estruturaRelatorio, "%s, %d,%.1f%%\n", opcaoAvaliacao(i), opinioes[i], percentual);
                    geraEImplementaArquivo(nomeRelatorio, estruturaRelatorio);
                    printf("%s - %d - %.1f%%\n", opcaoAvaliacao(i), opinioes[i], percentual);
                }
            }
            linha();
            printf("\nRELATORIO DE %s GERADO NO DIRETORIO DO SISTEMA EM: %s\n", obterTema(i),nomeRelatorio);
        }
        printf("\n--- TECLE QUALQUER BOTAO PARA PROSSEGUIR COM A GERACAO DO RELATORIO ---\n");
        getche();
        limpar();
    }
}

// GERA RELATORIO DO MUSEU
void gerarRelatorioMuseu() {

int opinioes[5];

    for(int i=2; i<=5; i++){
        for(int j=1; j<=5; j++){
            char *nomeArquivo[50];
            sprintf(nomeArquivo, "files/avaliacoes/avaliacao_museu/questionario%d/avaliacao_opcao%d.txt", i, j);
            int opiniao = retornaArquivoInteiro(nomeArquivo);
            opinioes[j-1] = opiniao;
        }

        int totOpinioes = 0;
        for(int i=0; i<5; i++){
            totOpinioes += opinioes[i];
        }

        printf("## GERANDO RELATORIO DO QUESTIONARIO %d\n", i);
        espera();
        linha();
        char *nomeRelatorio[30];
        sprintf(nomeRelatorio, "relatorios/relatorio_museu/relatorio_questionario%d.csv", i);

        remove(nomeRelatorio);

        if(geraEImplementaArquivo(nomeRelatorio, "CLASSIFICACAO, AVALIACOES, PORCENTAGEM(%)\n")){

            printf("RELATORIO QUESTIONARIO %d:\n", i);

            float percentual = 0;
            for(int i=0; i<5; i++){
                char estruturaRelatorio[50];
                if(opinioes[i] == 0){
                    percentual = 0;
                    sprintf(estruturaRelatorio, "%s, %d,%.1f%%\n", opcaoAvaliacao(i), 0, percentual);
                    geraEImplementaArquivo(nomeRelatorio, estruturaRelatorio);
                    printf("%s - %d - %.1f%%\n", opcaoAvaliacao(i), 0, percentual);
                } else {
                    percentual = (float)opinioes[i] / totOpinioes * 100;
                    sprintf(estruturaRelatorio, "%s, %d,%.1f%%\n", opcaoAvaliacao(i), opinioes[i], percentual);
                    geraEImplementaArquivo(nomeRelatorio, estruturaRelatorio);
                    printf("%s - %d - %.1f%%\n", opcaoAvaliacao(i), opinioes[i], percentual);
                }
            }
            linha();
            printf("\nRELATORIO DO QUESTIONARIO %d GERADO NO DIRETORIO DO SISTEMA EM: %s\n", i,nomeRelatorio);
        }
        printf("\n--- TECLE QUALQUER BOTAO PARA PROSSEGUIR COM A GERACAO DO RELATORIO ---\n");
        getche();
        limpar();
    }
}
