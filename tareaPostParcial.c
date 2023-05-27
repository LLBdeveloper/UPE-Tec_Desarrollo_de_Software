#include    <stdio.h>

struct fecha {
    int dia;
    int mes;
    int anio;
};

struct fecha ingresarFechaAct();
struct fecha ingresarFechaNac();
void imprimirFecha();
int calcularEdad();

int main(){
    struct fecha fechaAct, fechaNac;

    fechaAct=ingresarFechaAct();
    fechaNac=ingresarFechaNac();

    imprimirFecha(fechaNac);

    int resultado = calcularEdad(fechaAct, fechaNac);
    printf("\n tu edad es: %d", resultado);
    return 0;
}

struct fecha ingresarFechaAct(){
    struct fecha aux1;

    printf("\nIngresar fecha actual");

    printf("\nIngresar dia");
    scanf("%d", &aux1.dia);

    printf("Ingresar mes");
    scanf("%d", &aux1.mes);

    printf("Ingresar anio");
    scanf("%d", &aux1.anio);
    return aux1;
};

struct fecha ingresarFechaNac(){
    struct fecha aux2;

    printf("\nIngresar fecha de nacimiento");

    printf("\nIngresar dia");
    scanf("%d", &aux2.dia);

    printf("Ingresar mes");
    scanf("%d", &aux2.mes);

    printf("Ingresar anio");
    scanf("%d", &aux2.anio);

    return aux2;
};

void imprimirFecha(struct fecha f){
    printf("\n\n naciste en el anio %d, el mes %d, el dia %d ", f.anio, f.mes, f.dia);
}

int calcularEdad(struct fecha f1, struct fecha f2){
    int resultado;
     resultado = f1.anio - f2.anio;
    return resultado;
}
