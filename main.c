#include "calculadora.h"

int main (){
    char menu;  
do{

printf("%%%%%%%%%%%%%%%%%%%%%%%% Menu Calculadora %%%%%%%%%%%%%%%%%%%%%%%%\n\n");

printf("a) Digite 'A' para opção de Conversao Infixa para Posfixa (Com Letras)\n");

printf("b) Digite 'B' para opção de Conversao Infixa para Posfixa (Com Números)\n");

printf("c) Digite 'C' para o modo Calculadora\n");

printf("d) Digite 'Q' para sair\n");

printf("->");

scanf("%c", &menu);
scanf("%*c");

if(menu == 'a' || menu == 'A'){

    opcao_letras();

}else if(menu == 'b' || menu =='B'){
    opcao_numeros();

}else if(menu == 'c' || menu == 'C'){
    opcao_calculadora();
}
}while(menu != 'q' && menu != 'Q');
    
    return  0;
}


// end main 