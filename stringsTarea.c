// Realizar un programa que permita adivinar una palabra secreta con un máximo de 5 intentos.
#include <stdio.h>
#include <string.h>

int main(){
    char respuesta[10];
    char ayuda[25]= "T _ _ _ _ _ O";
    int intentos=0;
    char pista[10];

    while(intentos<5){
        printf("Adivina la palabra:\n\n?Cual es el dispositivo que sirve para ingresar datos en el computador ademas del mouse? \n");
        fflush(stdin) ;
        fgets(respuesta, sizeof(respuesta), stdin);
        intentos++;
        printf("Tu respuesta es:\n %s \n \n", respuesta);

        if( strcmp(respuesta, "teclado\n") == 0){
            printf("\n!!!!!!!!!!!\n!!!!!!!!!\n!!!!!!!!!!\nFELICITACIONES ADIVINASTEIS!!!!\n!!!!!!!!!!!\n!!!!!!!!!\n!!!!!!!!!!\n\n\n");
            break;
        }

        if(intentos>=2){
            printf("\n Necesitas una pista?\nResponder SI / NO");
            fflush(stdin) ;
            fgets(pista, sizeof(pista), stdin);
            if(strcmp(pista, "si\n") == 0){
                printf("\nPista:\n Tiene 7 letras y aca te muestro la primera y la ultima. \n%s \n \n", ayuda);
            }
        }

    }

    return 0;
}
