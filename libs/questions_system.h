#ifndef QUESTIONS_SYSTEM_H_INCLUDED
#define QUESTIONS_SYSTEM_H_INCLUDED

bool geraArquivoAvaliacao(int avaliacao, int questionario);
bool geraArquivoAvaliacaoTema(opt, tema);

char *opcaoAvaliacao(int index);

int obterAvaliacao(int index);
int recuperaNumeroAvaliacao(int avaliacao, int questionario);
int recuperaNumeroAvaliacaoTema(int avaliacao, char tema[]);

void abaQuestionario();
void abaQuestionarioTema(char *tema);
void atualizaNumeroAvaliacao(int avaliacao, int questionario);
void atualizaNumeroAvaliacaoTema(int avaliacao, char tema[]);
void questionario(int questao);

#endif // QUESTIONS_SYSTEM_H_INCLUDED
