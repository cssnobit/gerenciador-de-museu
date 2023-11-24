#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "file_system.h"

/*
    MÓDULO QUE LIDA COM A PARTE DE ARQUIVOS
*/


// IMPRIME NA TELA O CONTEUDO DENTRO DO ARQUIVO EXISTENTE
void leArquivo(char diretorio[]) {

    FILE *arquivo = fopen(diretorio, "r");

    if(arquivo != NULL){
        char linha[100];

        while(fgets(linha, sizeof(linha), arquivo) != NULL){
            printf("%s", linha);
        }
        fclose(arquivo);
    }

}

// RETORNA VERDADEIRO OU FALSO EM RELACAO A EXISTENCIA DO ARQUIVO
bool temArquivo(char diretorio[]) {
    FILE *arquivo = fopen(diretorio, "r");

    if(arquivo == NULL){
        return false;
    }
    fclose(arquivo);
    return true;
}

// A DIFERENÇA DELE PARA O "geraArquivo" É A FORMA DE COMO ABRE O ARQUIVO
// EVITANDO A SOBREESCRITA DO ARQUIVO
bool geraEImplementaArquivo(char diretorio[], char conteudo[]){

    FILE *arquivo = fopen(diretorio, "a");

    if(arquivo == NULL){
        fclose(arquivo);
        return false;
    }

    fprintf(arquivo, "%s" ,conteudo);
    fclose(arquivo);
    return true;

}

// GERA O ARQUIVO
bool geraArquivo(char diretorio[], char conteudo[]) {

    FILE *arquivo = fopen(diretorio, "w");

    if(arquivo == NULL){
        fclose(arquivo);
        return false;
    }

    fprintf(arquivo, "%s" ,conteudo);
    fclose(arquivo);
    return true;

}

// GERA ARQUIVO DO TIPO INTEIRO
bool geraArquivoNumero(char diretorio[], int valor) {
    FILE *arquivo = fopen(diretorio, "w");

    if(arquivo == NULL){
        return false;
    }

    fprintf(arquivo, "%d", valor);
    fclose(arquivo);
    return true;

}

// GERA ARQUIVO DO TIPO FLUTUANTE
bool geraArquivoNumeroFlutuante(char diretorio[], float valor) {
    FILE *arquivo = fopen(diretorio, "w");

    if(arquivo == NULL){
        return false;
    }

    fprintf(arquivo, "%f", valor);
    fclose(arquivo);
    return true;

}

// RETORNA O VALOR INTEIRO LIDO DO ARQUIVO
int retornaArquivoInteiro(char diretorio[]) {
    FILE *arquivo = fopen(diretorio, "r");
    int valor = 0;

    if(arquivo != NULL){
        fscanf(arquivo, "%d", &valor);
    }
    fclose(arquivo);

    return valor;
}

// RETORNA O VALOR FLUTUANTE LIDO DO ARQUIVO
float retornaArquivoFloat(char diretorio[]){
    FILE *arquivo = fopen(diretorio, "r");
    float valor = 0;

    if(arquivo != NULL){
        fscanf(arquivo, "%f", &valor);
    }
    fclose(arquivo);

    return valor;
}
