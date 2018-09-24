#
#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__



#include "pilha.h"

int menu_calculadora();

int valida_expressao(char c[]);

float string2float(char expressao);

char* infix_to_posfix(char expressao[]);

float resolucao_expressao(char expressao[]);

int menu_calculadora();

void opcao_letras();

void opcao_numeros();

void opcao_calculadora();


#endif // __CALCULADORA_H__
