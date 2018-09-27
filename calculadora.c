

#include "calculadora.h"


void opcao_resolucao(){

    char* c2 = (char*) malloc(50*(sizeof(char)));
do{
    free(c2);
    c2 = (char*) malloc(50*(sizeof(char)));
    printf("Digite uma expressao valida:");
    scanf("%[^\n]%*c", c2);
    printf("\n");
    
    }
    while(!valida_expressao(c2));
    char* posfix =  infix_to_posfix(c2);
    printf("\nExpressao Posfixa:%s\n\n", posfix);

    free(c2);
    float result = resolve_expressao(posfix);
    if(result != null){
    printf("Resultado da expressao e: %lf\n\n", result);
    }
    free(posfix);
    
}



double conversao_string_para_float(char* c){

int i  = 0, ctd_virgula = 0;
int j  = 1;
double resultado = 0;
if(c != NULL){
while(c[i] != ',' && c[i] != '.' && c[i] != '\0'){
     //Loop que conta o numero de casas ate a virgula
        ctd_virgula++;
        i++;
    }

i = 0;
//printf("\nnumero de casas ate a virugla: %d\n",ctd_virgula);
   
while(c[i] != ',' && c[i] != '.' && c[i] != '\0'){
    // Calcula o resultado do char ate a vírgula.
        resultado = resultado + ((c[i]- '0') * pow(10, (ctd_virgula - 1)));
        i++;
        ctd_virgula--;
    }

if(c[i] == ',' || c[i] == '.'){
    i++;
    while(c[i] != '\0'){
// Calcula o resultado do char após a virgula.
    resultado = resultado + ((c[i]- '0') * pow(10, (-j)));
    j++;
    i++;
    }
}

return resultado;
}
else{
    return 0;
}

}




int valida_expressao(char c[]){
   

    t_pilha* pilha = aloca_pilha(pilha);
    int i = 0;
      
    while( c[i] != '\0'){
     

            if (c[i] == '('){
                push_char(pilha, '(');
            }
           else if (c[i] == '['){                       
                push_char(pilha, '[');
            }

            else if(c[i] == '{'){
                push_char(pilha, '{');
            }

            else if(c[i] == ')'){
                if(pilha->topo == NULL){
                printf("Expressao invalida\n");
                free(c);
                free(pilha);
                return 0;                
                }
                else{
                    if(pilha->topo->c == '('){
                        pop(pilha);    
                }
                    else{
                        printf("Expressao invalida.\n");
                        free(c);
                        free(pilha);
                        return 0;
                }
                }
                
            }

            else if(c[i] == ']'){
                if(pilha->topo == NULL){
                printf("Expressao invalida\n");
                free(c);
                free(pilha);
                return 0;
                }else{
                    if(pilha->topo->c == '['){
                        pop(pilha);    
                    }else{
                        printf("Expressao invalida.\n");
                        free(c);
                        free(pilha);
                        return 0;
                }
                
            }
            }

            
            else if(c[i] == '}'){
                if(pilha->topo == NULL){
                printf("Expressao invalida\n");
                free(c);
                return 0;
                }else{
                if(pilha->topo->c == '{'){
                pop(pilha);    
                }else{
                    printf("Expressao invalida.\n");
                    free(c);
                    return 0;
                }
            }
                }
            else{
              //  printf("espaco\n");


            }

             i++;
    }



if(pilha->topo == NULL){
printf("Expressao valida.\n");

free(pilha);
return 1;}
else{
    // free(c);
    printf("Expressao invalida.\n");
    free(pilha);
    free(c);
    return 0;
}

}

void push_char(t_pilha* pilha, char c){
    float n = null;
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

char* infix_to_posfix(char expressao[]){

    t_pilha* pilha = aloca_pilha(pilha);
    char* saida = (char*) malloc(50*sizeof(char));

    int tmp = 0;
    int i = 0;
    
    while(expressao[i] != '\0'){

        
        if(isOperand(expressao[i])){
            if(i!= 0 && !isOperand(expressao[i-1]) && expressao[i-1] != ',' && expressao[i-1] != '.'){
  
            saida[tmp]= ' ';
            tmp++;
            }
            saida[tmp] = expressao[i];
            tmp++;
        }

        else if(isSymbol(expressao[i])){
            while(pilha->topo != NULL && (preferenciaSimbolo(pilha->topo->c) >= preferenciaSimbolo(expressao[i]))){
                saida[tmp] = ' ';
                tmp++;
                saida[tmp] = pilha->topo->c;
                tmp++;   
                pop(pilha);
                
             
            }
        
         push_char(pilha, expressao[i]);
        }


        else if(isAbreParentese(expressao[i])){
            push_char(pilha, expressao[i]);
        }


        else if(isFechaParentese(expressao[i])){
            while(!isAbreParentese(pilha->topo->c)){
                saida[tmp] = ' ';
                tmp++;
                saida[tmp] = pilha->topo->c;
                tmp++;
                pop(pilha);
            }
            pop(pilha);
        }




        i++;
    }
    while(pilha->topo != NULL){
        if(isSymbol(pilha->topo->c)){
                saida[tmp] = ' ';
                tmp++;
                saida[tmp] = pilha->topo->c;
                tmp++;
        }
        pop(pilha);
    }

    apaga_pilha_char(pilha);
    free(pilha);
   
    saida[tmp] = '\0';

    

    return saida;

}  

int isOperand(char c){
    if((c >= 48 && c<=57) || c == ',' || (c>= 65 && c<= 90) || (c>=97 && c<=122)){
        return 1;
    }else{
        return 0;
    }

}
int isSymbol(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return 1;
    }else{
        return 0;
    }
}

int isFechaParentese(char c){

    if(c == ')' || c == ']' || c == '}'){
        return 1;
    }else{
        return 0;
    }
}

int isAbreParentese(char c){
    if(c == '(' || c == '[' || c == '{'){
        return 1;
    }else{
        return 0;
    }

}

int preferenciaSimbolo(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }else{
        return 0;
    }

}


float resolve_expressao(char* c){
  
    int i  = 0;

    char* string2float;

    t_pilha_float* pilha_operando = aloca_pilha_float();

    double resultado, x, y;


    while(c[i] != '\0'){

       // printf("\nnumero de iteracoes: %d\n", i);
       


        if((c[i]>= 'A' && c[i]<= 'Z') || (c[i]>='a' && c[i]<='z')){
        // Caso haja letras na expressao, a resolução e invalida. 
            printf("Resolucao de expressao invalida (A expressao possui letras).\n");
            return null;
        }
        else if(isOperand(c[i])){
            string2float = (char*) malloc(10*sizeof(char)); // Variavel responsavel por guardar as strings que serão convertidas;
            int j = 0;
            while(c[i] != ' '){
                //Separa os strings e os converte p/ floats.

                string2float[j] = c[i];
                i++;
                j++;
            }

            string2float[j] = '\0';

            double number = conversao_string_para_float(string2float);

            push_float(number, pilha_operando);
            
            free(string2float);
            
            i--;
        }
        else if(isSymbol(c[i])){
            switch(c[i]){
                case '+':
                x = pop_float(pilha_operando);
				y = pop_float(pilha_operando);
                push_float((x+y), pilha_operando);
                break;
                  

                case '-':
                   	x = pop_float(pilha_operando);
					y = pop_float(pilha_operando);
					push_float((y-x), pilha_operando);
					break;

                case '*':
                    x = pop_float(pilha_operando);
					y = pop_float(pilha_operando);
                    push_float(( x * y ), pilha_operando);
                    break;

                case '/':
                    x = pop_float(pilha_operando);
					y = pop_float(pilha_operando);
                    push_float((y / x), pilha_operando);
                    break;
            }

        }
    
    
    i++;

    }   
resultado = pop_float(pilha_operando);
apaga_pilha_float(pilha_operando);
free(pilha_operando);

return resultado;
}


void opcao_calculadora(){
    
double operando, x,y;

char* c = (char*) malloc(50*sizeof(char));

printf("Modo Calculadora\n");

printf("Digite Q para sair.\n");

t_pilha_float* pilha = aloca_pilha_float();

do{
    
    free(c);
    c = (char*) malloc(10*sizeof(char));
    printf("\n\nPilha: \n");
    imprime_pilha(pilha);
    printf("\n");
    printf("Tamanho da pilha: %d\n", pilha->tamanho);

    printf("->");
    scanf("%[^\n]%*c", c);
    int a = avalia_expressao(c);
    //printf("%d", a);
    if(a == 1){
        //Push Float
        char* string2float = (char*) malloc(10*(sizeof(char)));
        int i = 0;
        while(c[i] != ' ' && c[i] != '\0'){
            string2float[i] = c[i];
            i++;
        }
        string2float[i] = '\0';
        operando = conversao_string_para_float(string2float);
        push_float(operando, pilha);
        free(string2float);
    }
    else if(a == 2){
        //Operacoes normais;
        int i = 0;
        if(pilha->tamanho > 1){
            while(c[i] != ' ' && c[i] != '\0'){
                switch(c[i]){ 
                    case '+':
                        x = pop_float(pilha);
                        y = pop_float(pilha);
                        push_float((x+y), pilha);
                        break;
                    
                    case '-':
                        x = pop_float(pilha);
                        y = pop_float(pilha);
                        push_float((y-x), pilha);
                        break;

                    case '*':
                        x = pop_float(pilha);
                        y = pop_float(pilha);
                        push_float(( x * y ), pilha);
                        break;


                    case '/':
                        x = pop_float(pilha);
                        y = pop_float(pilha);
                        push_float((y / x), pilha);
                        break;

            
            }
                i++;
        }
        }
        else{
            printf("\n------Numero de Operandos insuficiente!------\n");
            }   
    }

    else if(a == 3){
        //Operacoes especiais
        int i = 0;
        if(pilha->tamanho > 1){
            while(c[i] != ' ' && c[i] != '\0'){
                switch(c[i]){
                    case '+':
                        while(pilha->tamanho != 1){
                            x = pop_float(pilha);
                            y = pop_float(pilha);
                            push_float((x+y), pilha);}
                        break;
                    
                    case '-':
                        while(pilha->tamanho != 1){
                            x = pop_float(pilha);
                            y = pop_float(pilha);
                            push_float((y-x), pilha);}
                        break;

                    case '*':
                        while(pilha->tamanho != 1){
                            x = pop_float(pilha);
                            y = pop_float(pilha);
                            push_float(( x * y ), pilha);}
                        break;


                    case '/':
                        while(pilha->tamanho != 1){
                            x = pop_float(pilha);
                            y = pop_float(pilha);
                            push_float((y / x), pilha);}
                        break;

            
            }
                i++;
            }  

        }else{
            printf("\n------Numero de Operandos insuficiente!------\n");
        }
    }else if(a == 4){
        copia_elemento(pilha);
    }
    else if(a == 5){
        char* string2float = (char*) malloc(10*(sizeof(char)));
        int i = 1,j=0;
        while(c[i] != ' ' && c[i] != '\0'){
            // Copia o numero após o sinal negativo
            string2float[j] = c[i];
            j++;
            i++;
        }
        string2float[j] = '\0';
        operando = (conversao_string_para_float(string2float) * -1);
        push_float(operando, pilha);
        free(string2float);
    }

}while(avalia_expressao(c) != 0);
apaga_pilha_float(pilha);
free(pilha);
free(c);
}


int avalia_expressao(char* c){

    for(int i = 0; c[i] != '\0'; i++){
        if(c[i] == 'q' || c[i] == 'Q'){
            return 0;
        }
        else if(c[i] == 'c' || c[i] == 'C'){
            return 4;
        }
        else if(isOperand(c[i])){
            return 1;

        }
        else if(isSymbol(c[i])){
           if(c[i+1] == '!'){
               return 3;
               }
            else if(c[i] == '-' && isOperand(c[i+1])){
                return 5;
            }   
           else{
               return 2;
               }

        }

    }
    
}



void copia_elemento(t_pilha_float* pilha){
    if(pilha->tamanho == 2){
    int ctd;
    double operando;
    ctd = pop_float(pilha);
    operando = pop_float(pilha);
    for(int i = 0; i < ctd; i++){
        push_float(operando, pilha);
    }
    }else{
        printf("\nNumero incompativel de Operandos.\n");
    }

}

