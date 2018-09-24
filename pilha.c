#include "pilha.h"
#include <math.h>



//t_produto_char* aloca_produto_char(char c);


t_celula_char* aloca_celula_char(char c);

void imprime_pilha(t_pilha_float* pilha);


t_pilha* aloca_pilha(){

t_pilha* pilha = (t_pilha*) malloc(sizeof(t_pilha));

    pilha->tamanho = 0;
    pilha->topo = NULL;

    return pilha;
}


void push(t_pilha* pilha, char c){

    t_celula_char* nova = aloca_celula_char(c);
    
    if(pilha->topo == NULL){
        pilha->topo = nova;
        pilha->topo->proximo = NULL;
        pilha->tamanho++;
    }else{

        t_celula_char* tmp;
        tmp = pilha->topo;
        pilha->topo = nova; 
        pilha->topo->proximo = tmp;
        pilha->tamanho++;
    }


}

t_celula_char* aloca_celula_char(char c){

    t_celula_char* ptr = (t_celula_char*) malloc(sizeof(t_celula_char));
    ptr->c = c;
    ptr->proximo = NULL;
    return ptr;
}



void pop(t_pilha* pilha){

    //somente para char

    if(pilha->topo == NULL){
        printf("Pilha vazia.\n");
    }
    else{
        t_celula_char* tmp = pilha->topo;
        pilha->topo = pilha->topo->proximo;
       // free(tmp->produto->c);
      //  free(tmp->produto);
        free(tmp);
        }

}
char pop_char(t_pilha* pilha){

    if(pilha->topo == NULL){
        printf("Pilha vazia.");
        return 0;
    }else{
        t_celula_char* tmp = pilha->topo;
        pop(pilha);
        char c = tmp->c;
        free(tmp);
        return c;
    }
    

}
t_pilha_float* aloca_pilha_float(){

    t_pilha_float* pilha_float = (t_pilha_float*) malloc(sizeof(t_pilha_float));

    pilha_float->tamanho = 0;
    pilha_float->topo = NULL;

    return pilha_float;

}

t_celula_float* aloca_celula_float(double num){

t_celula_float* ptr = (t_celula_float*) malloc(sizeof(t_celula_float));
    ptr->num = num;
    ptr->proximo = NULL;
    return ptr;

}

void push_float(double num, t_pilha_float* pilha_float){
  t_celula_float* nova = aloca_celula_float(num);
    
    if(pilha_float->topo == NULL){
        pilha_float->topo = nova;
        pilha_float->topo->proximo = NULL;
        pilha_float->tamanho++;
    }else{

        t_celula_float* tmp;
        tmp = pilha_float->topo;
        pilha_float->topo = nova; 
        pilha_float->topo->proximo = tmp;
        pilha_float->tamanho++;
    }



}

double pop_float(t_pilha_float* pilha){

  if(pilha->topo == NULL){
        printf("Pilha vazia.\n");
        exit(-1);
    }
    else{
        t_celula_float* tmp = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        double num = tmp->num;
        pilha->tamanho--;  
        free(tmp);
        return num;
        }


}

void imprime_pilha(t_pilha_float* pilha){
    int tamanho = 1;
    if(pilha->topo == NULL){
        printf("Pilha Vazia!\n");
    }else{
        t_celula_float *ptr = pilha->topo;

        while(ptr != NULL){
            printf("%d. %lf\n",tamanho, ptr->num);
            ptr = ptr->proximo;
            tamanho++;
        }

    }
}

void apaga_pilha_float(t_pilha_float* pilha){

    t_celula_float* ptr = pilha->topo;
    t_celula_float* tmp;

    while(ptr != NULL){
        tmp = ptr;
        ptr = ptr->proximo;
        free(tmp);        
    }

    free(ptr);


}

void apaga_pilha_char(t_pilha* pilha){

    t_celula_char* ptr = pilha->topo;
    t_celula_char* tmp;

    while(ptr != NULL){
        tmp = ptr;
        ptr = ptr->proximo;
        free(tmp);      
    }
    free(ptr);

}