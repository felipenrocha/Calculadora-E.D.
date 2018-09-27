#include "calculadora.h"

int main (){
    char menu;  
do{

printf("%%%%%%%%%%%%%%%%%%%%%%%% Menu Calculadora %%%%%%%%%%%%%%%%%%%%%%%%\n\n");

printf("a) Digite 'A' para opcao de Conversao Infixa para Posfixa\n");

printf("b) Digite 'B' para o modo Calculadora\n");

printf("c) Digite 'Q' para sair\n");

printf("->");

scanf("%c", &menu);
scanf("%*c");

if(menu == 'a' || menu =='A'){
    opcao_resolucao();

}else if(menu == 'b' || menu == 'B'){
    opcao_calculadora();
}
}while(menu != 'q' && menu != 'Q');
    
    return  0;
}


// end main 