#ifndef __PILHA_H__
#define __PILHA_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define null -1234567891

//typedef struct celula t_celula;


typedef struct celula_char {

   // t_celula* anterior;
    struct celula_char* proximo;
    char c;

}t_celula_char;

typedef struct celula_float {
    struct celula_float* proximo;
    double num;

}t_celula_float;

typedef struct pilha {

    t_celula_char* topo;
    int tamanho;

}t_pilha;

typedef struct pilha_float {

    t_celula_float* topo;
    int tamanho;
}t_pilha_float;

t_pilha* aloca_pilha();

t_pilha_float* aloca_pilha_float();

t_celula_char* aloca_celula_char(char c);


void imprime_pilha(t_pilha_float* pilha);

void push(t_pilha* pilha, char c);

void pop(t_pilha* pilha);

void push_float(double num, t_pilha_float* pilha_float);

t_celula_float* aloca_celula_float(double num);


void push_char(t_pilha* pilha, char c);

char pop_char(t_pilha* pilha);

double pop_float(t_pilha_float* pilha_float);

char* aloca_expressao();

void apaga_pilha_float(t_pilha_float* pilha);

void apaga_pilha_char(t_pilha* pilha);




#endif