#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "libs/style_system.c"
#include "libs/temas_system.c"
#include "libs/file_system.c"
#include "libs/ticket_system.c"
#include "libs/exposicao_system.c"
#include "libs/questions_system.c"
#include "libs/relatorio_system.c"

/*
    O ARQUIVO PRINCIPAL (MAIN) É RESPONSÁVEL EM DELEGAR
    AS FUNÇÕES DE ACORDO COM A OPÇÃO
*/

const char *opcoesMenu[] = {"BILHETERIA", "EXIBICAO OBRAS",
"GERAR RELATORIO", "QUESTIONARIO", "VALIDAR INGRESSO"};

// Opção de exibição de temas, na qual inclui o sistema de questionário
void menuObras() {
    bool ativo = true;

    while(ativo) {
        limpar();
        esperaRapido();
        exibeNome();

        int tema = 0;

        printf("OPCOES DE DESCRICAO DO TEMA\n");
        linha();
        for(int i=0; i<4; i++){
            printf("\t%d- %s.\n", i+1, obterTema(i));
        }
        printf("\n\t0- SAIR\n");
        linha();

        printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
        scanf("%d", &tema);

        limpar();

        if(tema == 0){
            printf("OPCAO DE SAIR SELECIONADO! REDIRECIONANDO PARA O MENU PRINCIPAL\n");
            esperaRapido();

            ativo = false;
            continue;
        }

        if(tema > 0 && tema <= 4) {
            bool vendoTema = true;
            while(vendoTema) {
                limpar();
                printf("DESCRICAO DO TEMA %s:\n\n", obterTema(tema-1));
                descricaoTema(tema);
                int item = 0;

                limpar();

                printf("OPCOES DE ITENS DO TEMA %s\n", obterTema(tema-1));
                linha();
                for(int i=0; i<3; i++){
                    printf("\t%d- %s.\n", i+1, obterItensObra(tema, i));
                }
                printf("\n\t4- AVALIE O TEMA\n");
                printf("\n\t0- SAIR\n");
                linha();

                printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
                scanf("%d", &item);

                limpar();

                if(item == 0) {
                    printf("REDIRECIONANDO PARA O MENU DE EXIBICAO DOS TEMAS\n");
                    esperaRapido();
                    vendoTema = false;
                    continue;
                } else if(item > 0 && item <= 3){
                    descricaoItem(tema, item);
                    limpar();
                    printf("VOLTANDO PARA A DESCRICAO PRINCIPAL DO TEMA\n");
                    esperaRapido();
                } else if(item == 4) {
                    printf("REDIRECIONANDO PARA O QUESTIONARIO DO TEMA\n");
                    esperaRapido();
                    abaQuestionarioTema(obterTema(tema-1));
                } else {
                    printf("OPCAO INVALIDA!\n");
                    esperaRapido();
                }
            }
        } else {
            printf("OPCAO INVALIDA!\n");
            esperaRapido();
        }
    }
}

// Opção de 2 relatorios: tema e museu
void menuRelatorio() {
    limpar();

    bool ativo = true;

    while(ativo) {
        limpar();
        esperaRapido();
        exibeNome();

        int opt = 0;

        printf("OPCOES DE RELATORIO\n");
        linha();
        printf("\t1- RELATORIO SOBRE OS TEMAS.\n\t2- RELATORIO SOBRE O MUSEU.\n");

        printf("\n\t0- SAIR\n");
        linha();

        printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
        scanf("%d", &opt);

        limpar();

        switch(opt){
        case 1:
            printf("REDIRECIONANDO PARA O GERADOR DE RELATORIO DOS TEMAS\n");
            esperaRapido();
            limpar();
            gerarRelatorioTema();

            printf("RELATORIO DOS TEMAS GERADOS!\n");
            break;
        case 2:
            printf("REDIRECIONANDO PARA O GERADOR DE RELATORIO DO MUSEU\n");
            esperaRapido();
            limpar();
            gerarRelatorioMuseu();

            printf("RELATORIO DO MUSEU GERADO!\n");
            break;
        case 0:
            printf("REDIRECIONANDO PARA O MENU PRINCIPAL\n");
            esperaRapido();

            ativo = false;
            break;
        default:
            printf("OPCAO INVALIDA!\n");
            esperaRapido();
            break;
        }
    }
}

// Buscador de ingresso, está dentro do módulo "ticket_system.c"
void menuValidaIngresso() {

    validaIngresso();
    esperaRapido();
}

// Sistema que atualiza preço, atualiza numero de ingresso e vende ingresso
void menuBilheteria() {
    bool ativo = true;
    char *opcoesBilheteria[] = {"VENDA DE BILHETE", "ATUALIZAR NUMEROS DE BILHETES", "ATUALIZAR PRECO DOS BILHETES"};

    while(ativo) {
        limpar();
        esperaRapido();
        exibeNome();

        int opt = 0;

        printf("OPCOES BILHETERIA\n");
        linha();
        for(int i=0; i<3; i++){
            printf("\t%d- %s.\n", i+1, opcoesBilheteria[i]);
        }
        printf("\n\t0- SAIR\n");
        linha();

        printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
        scanf("%d", &opt);

        limpar();

        switch(opt){
        case 0:
            printf("OPCAO DE SAIR SELECIONADO! REDIRECIONANDO PARA O MENU PRINCIPAL\n");
            esperaRapido();

            ativo = false;
            break;
        case 1:
            printf("REDIRECIONANDO PARA ABA DE: %s\n", opcoesBilheteria[opt-1]);
            esperaRapido();

            vendaBilhete();
            break;
        case 2:
            printf("REDIRECIONANDO PARA ABA DE: %s\n", opcoesBilheteria[opt-1]);
            esperaRapido();

            if(atualizaIngresso()){
                printf("INGRESSOS ATUALIZADOS!\n");
                esperaRapido();
            } else {
                printf("NAO FOI POSSIVEL ATUALIZAR O NUMERO DE INGRESSO\n");
                esperaRapido();
            }
            break;
        case 3:
            printf("REDIRECIONANDO PARA ABA DE: %s\n", opcoesBilheteria[opt-1]);
            esperaRapido();

            if(atualizaPreco()) {
                printf("PRECO ATUALIZADO!\n");
                esperaRapido();
            } else {
                printf("NAO FOI POSSIVEL ATUALIZAR O PRECO!\n");
                esperaRapido();
            }
            break;
        default:
            printf("OPCAO INVALIDA!\n");
            esperaRapido();

            break;
        }
    }
}

 menuQuestionario() {
    bool ativo = true;

    while(ativo) {
        limpar();
        esperaRapido();
        exibeNome();

        int opt = 0;

        printf("MENU QUESTIONARIO\n");
        linha();

        printf("\t1- AVALIE O MUSEU.\n");

        printf("\n\t0- SAIR\n");
        linha();

        printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
        scanf("%d", &opt);

        limpar();

        switch(opt){
        case 0:
            printf("OPCAO DE SAIR SELECIONADO! REDIRECIONANDO PARA O MENU PRINCIPAL\n");
            esperaRapido();

            ativo = false;
            break;
        case 1:
            printf("REDIRECIONANDO PARA ABA DE: AVALIACAO DO MUSEU\n");
            esperaRapido();

            abaQuestionario();
            break;
        default:
            printf("OPCAO INVALIDA!\n");
            esperaRapido();

            break;
        }
    }
 }

// Para exibir na tela o array de "opções" de menu
void exibeOpcoes(){
    for(int i=0; i<5; i++){
        printf("\t%d- %s.\n", i+1, opcoesMenu[i]);
    }
}

int main() {

    printf("INICIALIZANDO O PROGRAMA...\n");
    espera();

    while(true) {
        limpar();
        exibeNome();

        int opt = 0;

        printf("MENU PRINCIPAL\n");
        linha();
        exibeOpcoes();
        printf("\n\t0- SAIR\n");
        linha();

        printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
        scanf("%d", &opt);

        limpar();

        switch(opt){
        case 1:
            printf("REDIRECIONANDO PARA ABA DE: %s\n", opcoesMenu[opt-1]);
            esperaRapido();

            menuBilheteria();
            break;
        case 2:
            printf("REDIRECIONANDO PARA ABA DE: %s\n", opcoesMenu[opt-1]);
            esperaRapido();

            menuObras();
            break;
        case 3:
            printf("REDIRECIONANDO PARA ABA DE: %s\n", opcoesMenu[opt-1]);
            esperaRapido();

            menuRelatorio();
            break;
        case 4:
            printf("REDIRECIONANDO PARA ABA DE: %s\n", opcoesMenu[opt-1]);
            esperaRapido();

            menuQuestionario();
            break;
        case 5:
            printf("REDIRECIONANDO PARA ABA DE: %s\n", opcoesMenu[opt-1]);
            esperaRapido();

            menuValidaIngresso();
            break;
        case 0:
            printf("OPCAO DE SAIR SELECIONADO! PROGRAMA ENCERRADO\n");
            esperaRapido();

            exit(1);
            break;
        default:
            printf("OPCAO INVALIDA!\n");
            esperaRapido();

            break;
        }
    }

    return 0;
}
