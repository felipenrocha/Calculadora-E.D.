#
#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__



#include "pilha.h"



int avalia_expressao(char* c);

int isOperand(char c); // Retorna True quando o char e um operando;

int isSymbol(char c); // Retorna True quando o char e um símbolo;

int isFechaParentese(char c); // Retorna True quando o char e um parentese de fechamento;

int isAbreParentese(char c); // Retorna True quando o char e um parentese de abertura;

int preferenciaSimbolo(char c); // Retorna a preferencia dos simbolos (+,-,*,/);

double conversao_string_para_float(char* c); //Converte uma string char* c p/ float; Ex.: "2,5" -> 2.500000

int valida_expressao(char c[]);

float string2float(char expressao);

char* infix_to_posfix(char expressao[]);

float resolucao_expressao(char expressao[]);

void copia_elemento(t_pilha_float* pilha);

float resolve_expressao(char* c);


int menu_calculadora();

//void opcao_letras();

void opcao_resolucao();

void opcao_calculadora();




#endif // __CALCULADORA_H__
