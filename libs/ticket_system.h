#ifndef TICKET_SYSTEM_H_INCLUDED
#define TICKET_SYSTEM_H_INCLUDED

int obterNumeroIngressos(int index);
void vendaBilhete();
bool atualizaIngresso();
char* obterTipoEntrada(int index);
bool confirmaCompra(int tema, int entrada);
float obterPreco();
bool atualizaPreco();
int recuperaId();
void decrementaIngresso(int index);
void validaIngresso();

#endif // TICKET_SYSTEM_H_INCLUDED
