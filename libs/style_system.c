#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "style_system.h"

/*
    MÓDULO QUE ESTILIZA O PROGRAMA, DANDO UM POUCO MAIS DE DINÂMICA
*/


// limpa a tela
void limpar(){
    system("cls");
}

// imprime uma linha que separa os textos
void linha() {
    printf("-----------------------------------------\n");
}

// nome principal
void exibeNome() {
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("| M U S E U   M U L T I T E M A T I C O |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n\n");
    espera();
}

// congela a tela por 1 segundo
void esperaRapido(){
    sleep(1);
}

// congela a tela por 2 segundos
void espera(){
    sleep(2);
}
