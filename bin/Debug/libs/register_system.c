#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 Modulo que lida com arquivo de cadastro.
*/
bool cadastrarMaquina(){
    const char *nomeArquivoCadastro = "files/activate.txt";

    FILE *cadastro = fopen(nomeArquivoCadastro, "w");

    if(cadastro == NULL){
        return false;
    }

    fprintf(cadastro, "status=activate");
    fclose(cadastro);

}

bool verificarCadastro(){
        const char *nomeCadastro = "files/activate.txt";
        FILE *cadastro = fopen(nomeCadastro, "r");

        if(cadastro == NULL){
            fclose(cadastro);
            printf("CADASTRO NAO ENCONTRADO!\n");
            sleep(1);
            printf("REDIRECIONANDO PARA A TELA DE CADASTRO...\n");
            sleep(1);
            if(cadastrarMaquina()) {
                system("cls");
                printf("CADASTRO FOI SUCEDIDO!\n");
                printf("REDIRECIONANDO SISTEMA PARA O MENU PRINCIPAL DO PROGRAMA...\n");
                sleep(2);
                system("cls");
                return true;
            } else {
                return false;
            }
    }
}
