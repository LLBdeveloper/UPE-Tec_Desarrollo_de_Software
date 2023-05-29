
/*
Crear un programa que permita guardar un listado de hasta 50 amigos,
donde se almacene el nombre completo y su fecha de nacimiento.

Se deberá permitir el ingreso hasta que por nombre se ingrese 1.

Al finalizar el ingreso se mostrará un listado completo.

El nombre + apellido tendrá un largo máximo de 30 caracteres que deberá
truncar y controlar en caso de ser necesario.
*/

#include <stdio.h>
#include <string.h>

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct amigo{;
    char nombre[30];
    struct fecha nac;
};

int main(){
    struct amigo amigui[50];
    int i = 0;

    while(i<50){

        printf("-Ingrese amigo-\n");
        printf("\nNombre completo: ");
        scanf("%s", &amigui[i].nombre);

        if (strcmp(amigui[i].nombre, "1") == 0) {
        break;
        }

        printf("\n-Ingrese fecha de nacimiento- ");
        printf("\nDia:");
        scanf("%d", &amigui[i].nac.dia);
        printf("\nMes:");
        scanf("%d", &amigui[i].nac.mes);
        printf("\nAnio:");
        scanf("%d", &amigui[i].nac.anio);
        i++;

    }

    for(int x=0; x<i; x++){
        printf("\nAmigo ingresado: %s\nFecha de nacimiento: %d/%d/%d \n", amigui[x].nombre, amigui[x].nac.dia, amigui[x].nac.mes, amigui[x].nac.anio);
    }

    return 0;
}


/*

        if(amigui[i].nombre[0] !="1"){
            break;
        }




 */
