#ifndef FILE_SYSTEM_H_INCLUDED
#define FILE_SYSTEM_H_INCLUDED

bool geraArquivo(char diretorio[], char conteudo[]);
bool geraEImplementaArquivo(char diretorio[], char conteudo[]);
bool geraArquivoNumero(char diretorio[], int valor);
bool geraArquivoNumeroFlutuante(char diretorio[], float valor);
bool temArquivo(char diretorio[]);
int retornaArquivoInteiro(char diretorio[]);
float retornaArquivoFloat(char diretorio[]);
void leArquivo(char diretorio[]);

#endif // FILE_SYSTEM_H_INCLUDED
