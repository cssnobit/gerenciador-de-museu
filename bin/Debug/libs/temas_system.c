#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "temas_system.h"

/*
    M�DULO QUE ARMAZENA COISAS RELACIONADAS AO TEMA
*/

const char *temas[] = {"150 ANOS DE SANTOS DUMMONT", "100 ANOS DA SEMANA DE ARTE MODERNA",
"JOGOS OLIMPICOS DE PARIS 2024", "METAVERSO"};

// RETORNA UMA "STRING" DO ARRAY DE TEMAS ATRAV�S DO �NCIDE
char* obterTema(int index) {
    return temas[index];
}
