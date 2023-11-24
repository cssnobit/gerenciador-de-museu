#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "exposicao_system.h"

/*
    MÓDULO QUE ATUA NA PARTE DE DESCRIÇÃO DOS TEMAS E DE SEUS ITENS
*/

// EXIBE NA TELA OS CONTEÚDOS DOS ARQUIVOS DOS TEMAS
void descricaoTema(int tema){

    char diretorio[50];
    sprintf(diretorio, "temas/descricao_tema%d.txt", tema);

    leArquivo(diretorio);

    printf("\n\n--- AO FINALIZAR A LEITURA, TECLE QUALQUER BOTAO ---\n");
    getche();
}

// EXIBE NA TELA OS CONTEÚDOS NOS ARQUIVOS DOS ITENS DOS TEMAS
void descricaoItem(int tema, int item) {
    char diretorio[50];
    sprintf(diretorio, "temas/itens_tema%d/item_%d.txt", tema, item);

    leArquivo(diretorio);

    printf("\n\n--- AO FINALIZAR A LEITURA, TECLE QUALQUER BOTAO ---\n");
    getche();
}

// RETORNA UMA STRING DE ACORDO COM O TEMA E O ÍNDICE
char* obterItensObra(int tema, int item) {
    char *obras1[] = {"AVIAO 14-BIS", "RELOGIO DE PULSO", "BALOES DIRIGIVEIS"};
    char *obras2[] = {"TARSILA DO AMARAL", "O MANIFESTRO ANTROPOFAGO", "ESCULTURA DE VICTOR BRECHERET"};
    char *obras3[] = {"BREAKING DANCE", "NOVA TOCHA OLIMPICA DE 2024", "CURIOSIDADE DA CIDADE DE PARIS"};
    char *obras4[] = {"HORIZON WORLDS", "MICROSOFT MESH", "SECOND LIFE"};

    switch(tema){
    case 1:
        return obras1[item];
    break;
    case 2:
        return obras2[item];
    break;
    case 3:
        return obras3[item];
    break;
    case 4:
        return obras4[item];
    break;
    }
}
