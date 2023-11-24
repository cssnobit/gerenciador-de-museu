#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ticket_system.h"

/*
    MÓDULO RESPONSÁVEL POR CUIDAR DA PARTE DOS INGRESSOS
*/

const char *tipoEntradas[] = {"INTEIRA", "MEIA", "ISENTO"};

char* obterTipoEntrada(int index) {
    return tipoEntradas[index];
}

// FUNÇÃO PARA "PERSISTIR" O NUMERO DE BILHETES
int obterNumeroIngressos(int index) {
    char diretorioIngressos[30];

    // O valor passado no parâmetro será convertido para acessar o arquivo
    // do tema, armazenado no diretório "files/ingressos"

    sprintf(diretorioIngressos, "files/ingressos/ingressos_tema%d.txt", index+1);
    int qtdIngresso = retornaArquivoInteiro(diretorioIngressos);

    return qtdIngresso;
}

void vendaBilhete() {
    bool ativo = true;
    while(ativo) {
        limpar();
        esperaRapido();
        exibeNome();
        int tema = 0;

        printf("TEMAS:\n");
        linha();
        printf("\t## PRECO ATUAL: R$%.2f\n\n", obterPreco());
        for(int i=0; i<4; i++){
            printf("\t%d- %s - QUANTIDADE DE INGRESSO DISPONIVEL: %d.\n", i+1, obterTema(i), obterNumeroIngressos(i));
        }
        printf("\n\t0- SAIR.\n");
        linha();

        printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
        scanf("%d", &tema);

        limpar();

        // VALIDA A ENTRADA DO USUÁRIO
        if(tema == 0){
            printf("REDIRECIONANDO PARA O MENU DE BILHETERIA\n");
            esperaRapido();
            ativo = false;
            continue;
        } else if (tema > 0 && tema <= 4) {
            // VERIFICA SE A QUANTIDADE DE INGRESSO ESTÁ DISPONÍVEL
            if(obterNumeroIngressos(tema-1) <= 0){
                printf("QUANTIDADE DE INGRESSO DO TEMA %s ESTA ESGOTADO!\n", obterTema(tema-1));
                esperaRapido();
            } else {
                while(true) {

                    int entrada = 0;

                    printf("TIPOS DE ENTRADA:\n");
                    linha();
                    for(int i=0; i<3; i++){
                        printf("\t%d- %s.\n", i+1, obterTipoEntrada(i));
                    }
                    printf("\n\t0- SAIR.\n");
                    linha();

                    printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
                    scanf("%d", &entrada);

                    if(entrada > 0){
                            confirmaCompra(tema-1, entrada-1);
                            break;

                    } else if(entrada == 0) {
                        printf("COMPRA CANCELADA! REDIRECIONANDO PARA O MENU DE BILHETERIA\n");
                        esperaRapido();
                        break;
                    } else {
                        printf("OPCAO INVALIDA!\n");
                        esperaRapido();
                    }
                }
            }

        } else {
            printf("OPCAO INVALIDA!\n");
            esperaRapido();
        }

    }
}

bool atualizaPreco() {
    limpar();
    float preco = 0;
    printf("DIGITE O PRECO INTEIRO DO INGRESSO\n> ");
    scanf("%f", &preco);

    if(preco > 0){
        geraArquivoNumeroFlutuante("files/preco.txt", preco);
        return true;
    }
    return false;

}

// "PERSISTE" O PRECO DO BILHETE
float obterPreco() {
    char diretorioPreco[] = {"files/preco.txt"};
    return retornaArquivoFloat(diretorioPreco);
}

// RESPONSÁVEL POR CRIAR A ESTRUTURA DO INGRESSO PARA DEPOIS SER GERADO O ARQUIVO
bool confirmaCompra(int tema, int entrada) {
    float preco = obterPreco();
    int ultimoId = recuperaId();
    char bilhete[500];
    char diretorio[50];

    if(entrada == 1){
        preco = preco / 2;
    } else if(entrada == 2) {
        preco = 0.0;
    }

    limpar();

    sprintf(bilhete, "------BILHETE------\n\n"
                     "ID DO CLIENTE: %d.\n\nTEMA: %s.\nTIPO ENTRADA: %s.\nVALOR TOTAL: R$%.2f.\n\n"
                     "------BILHETE------\n\n", ultimoId, obterTema(tema), obterTipoEntrada(entrada), preco);

    sprintf(diretorio, "files/ingressos_vendidos/ingresso_id%d.txt", ultimoId);

    printf("%s", bilhete);

    printf("-- PRESSIONE QUALQUER TECLA PARA CONFIRMAR A COMPRA --");
    getche();

    ultimoId++;
    geraArquivoNumero("files/last_id.txt", ultimoId);
    decrementaIngresso(tema);

    geraArquivo(diretorio, bilhete);
}

// OPÇÃO DE ATUALIZAR INGRESSO
bool atualizaIngresso() {
    bool ativo = true;
    char diretorioIngressos[30];

    while(ativo) {
        limpar();
        esperaRapido();
        exibeNome();
        int opt = 0;

        printf("TEMAS PARA ATUALIZAR O NUMERO DE INGRESSO:\n");
        linha();
        for(int i=0; i<4; i++){
            printf("\t%d- %s - QUANTIDADE DE INGRESSO DISPONIVEL: %d.\n", i+1, obterTema(i), obterNumeroIngressos(i));
        }
        printf("\n\t0- SAIR.\n");
        linha();

        printf("DIGITE O NUMERO CORRESPONDENTE A OPCAO\n> ");
        scanf("%d", &opt);

        limpar();

        if(opt > 0 && opt <= 4){
            limpar();

            int qtdIngresso = 0;

            sprintf(diretorioIngressos, "files/ingressos/ingressos_tema%d.txt", opt);

            printf("DIGITE A QUANTIDADE DE INGRESSO DO TEMA: %s\n> ", obterTema(opt-1));
            scanf("%d", &qtdIngresso);

            return geraArquivoNumero(diretorioIngressos, qtdIngresso);

        } else if(opt == 0) {
            printf("REDIRECIONANDO PARA O MENU DE BILHETERIA\n");
            esperaRapido();
            ativo = false;
            continue;
        } else {
            printf("OPCAO INVALIDA!\n");
            esperaRapido();
        }
    }
}

// ESTA FUNÇÃO É RESPONSÁVEL POR DIMINUIR O NUMERO DE INGRESSO VENDIDO
// DE ACORDO COM O TEMA
void decrementaIngresso(int tema) {
    char diretorioIngressos[30];

    sprintf(diretorioIngressos, "files/ingressos/ingressos_tema%d.txt", tema+1);
    int qtdIngresso = obterNumeroIngressos(tema);
    qtdIngresso--;

    geraArquivoNumero(diretorioIngressos, qtdIngresso);
}

// ESSA FUNÇÃO É RESPONSÁVEL POR PERSISTIR O ULTIMO ID, ONDE O PROGRAMA PODERÁ RETOMAR
// A CONTAGEM DA ÚLTIMA COMPRA
int recuperaId() {
    int ultimoId = retornaArquivoInteiro("files/last_id.txt");
    if(ultimoId <= 0)
        return 1;

    return ultimoId;
}

// OPÇÃO DE VALIDAR INGRESSO
void validaIngresso(){
    const char *nomeArquivo[30];
    int buscarId = 0;

    while(true){
        limpar();
        exibeNome();
        linha();
        printf("DIGITE '0' PARA CANCELAR A OPERACAO\n\n");
        linha();
        printf("DIGITE O ID DO BILHETE\n> ");
        scanf("%d", &buscarId);

        if(buscarId == 0){
            limpar();
            printf("OPERACAO CANCELADA!\n");
            printf("REDIRECIONANDO AO MENU PRINCIPAL\n");
            esperaRapido();
            break;
        }

        sprintf(nomeArquivo, "files/ingressos_vendidos/ingresso_id%d.txt", buscarId);

        limpar();
        printf("BUSCANDO ID %d...\n", buscarId);
        espera();
        limpar();

        if(!temArquivo(nomeArquivo)){
            printf("NAO FOI ENCONTRADO CORRESPONDENCIAS DO ID %d.\n", buscarId);
        } else {
            printf("ID %d FOI ENCONTRADO!\n", buscarId);
            esperaRapido();
            limpar();
            printf("IMPRIMINDO BILHETE DO ID %d\n\n", buscarId);
            espera();
            leArquivo(nomeArquivo);
        }

        printf("\n\n## TECLE QUALQUER COISA PARA PROSSEGUIR ##\n");
        getche();

        limpar();
    }
}
