//////////////////////////////
// Bertera_Lautaro_35969305 //
//    2do PARCIAL IDS       //
//////////////////////////////

//Nota: Estan detalladas las diferentes partes del codigo con titulos y las funciones propias con su respectiva info.
//      Sume una libreria que no vimos en clase "<stdlib.h>" lo aprendi por mi cuenta.( cuando ingresas usuario puse que se limpie la consola, queda bien) y tenia que incluir esta biblioteca sino tiraba un warning.
//      Vi que usaban snake_case pero utilize por costumbre de JS camelCase, salvo en las constantes simbolicas,


//LIBRERIAS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//CONSTANTES SIMBOLICAS o MACROS
#define CAL_MAX  200
#define USER  "ADMIN"
#define PASS  "4dm1n%100"


//STRUCT
struct fecha{
    int dia;
    int mes;
    int anio;
};

struct comentario { // Hay un vector "comentarios" con "s" de nombre parecido aclaro por las dudas
    int codigoEvento;
    char nombre[60];
    struct fecha fechaEvento;
    char atencion;
    int clasificacion;
};


//PROTOTIPADO DE FUNCIONES PROPIAS
//Cada una cuenta con objetivos, parametros que recibe, valor que devuelve
void bienvenida();
void agregarComen(struct comentario comentarios[], int contadorComen);
void validador(char user[], char pass[]);
void menuReportes(struct comentario comentarios[], int contadorComen);
float cuentaPromedio(struct comentario comentarios[], int contadorComen);
struct fecha diaMayorCal(struct comentario comentarios[], int contadorComen);
void cantTipoB(struct comentario comentarios[], int contadorComen);
void verDetalle(struct comentario comentarios[], int contadorComen);


//FUNCION PRINCIPAL (llama al menu y definiciones)
int main(){
    int contadorComen = 0;
    int opcion;
    char user[10];
    char pass[10];
    struct comentario comentarios[CAL_MAX];

    bienvenida();

    do{
        printf("\t- MENU PRINCIPAL - \n\n\n Ingrese en numero del 1 al 3 la opcion deseada: \n \t 1- Ingresar comentario\n \t 2- Ver reportes \n \t 3- SALIR \n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarComen(comentarios, contadorComen);
                contadorComen = contadorComen + 1;
                break;
            case 2:
                validador(user,pass);
                menuReportes(comentarios, contadorComen);
                break;
            case 3:
                printf(" - - - - - - Saliendo - - - - - -  \n");
                break;
            default:
                printf("Opcion incorrecta, ingrese un numero del 1 al 3 \n");
                break;
            }
    }while(opcion !=3);



    printf("Fin del programa, gracias por  elegirnos en la gestion de comentarios\n");
    return 0;
}


//FUNCIONES PROPIAS
//Funcion bienvenida: da un saludo al iniciar el programa.
//No recibe nada por parametros.
//No devuelve nada ya que es de tipo void.
void bienvenida(){
    printf("Bienvenido al Software de gestion y almacenamiento de comentarios.\nV2.0\n\n\n\n\n\n");
}

//Funcion agregar comentario: Crea un nuevo comentario y lo suma al vector de comentarios.
//Recibe por parametro el vector de comentarios comentarios[] y el contador de comentarios totales contadorComen.
//No devuelve nada ya que es de tipo void.
void agregarComen(struct comentario comentarios[], int contadorComen){
    if(contadorComen>=CAL_MAX){
        printf("Maxima cantidad de comentarios alcanzada");
    }else{
    printf("\n---Ha seleccionado la opcion Agregar comentarios, acontinuacion se le pedira que complete los 5 campos--- \n\n");
    struct comentario aux;

    printf("Ingrese codigo de evento en numeros enteros hasta 4 digitos \n");
    scanf("%d",&aux.codigoEvento);
    fflush(stdin);
    printf("ingrese Nombre\n");
    fgets(aux.nombre,sizeof(aux.nombre),stdin);

    fflush(stdin);
    printf("Ingrese la fecha del evento:\n");
    printf("ingrese dia\n");
    scanf("%d",&aux.fechaEvento.dia);
    printf("ingrese mes\n");
    scanf("%d",&aux.fechaEvento.mes);
    printf("ingrese anio\n");
    scanf("%d",&aux.fechaEvento.anio);

    fflush(stdin);
    printf("Ingrese que le parecio la atencion con una letra en mayuscula\n\tB (buena), R (regular) y M (mala):\n");
    scanf("%c",&aux.atencion);

    printf("Ingrese la calificacion del servicio en formato numero entero del 1 al 10\n");
    scanf("%d",&aux.clasificacion);

    comentarios[contadorComen] = aux;
    }
}

//Funcion validador: Valida el usuario administrador con USER & PASS para entrar al menu administrador.
//Recibe por parametro los strigns de user y pass inicializados en la funcion main.
//No devuelve nada ya que es de tipo void.
void validador(char user[], char pass[]){
    printf("\n Para acceder a esta opcion del menu debe ingresar USER & PASS \n");
    do{
        printf("\n\t - Nuevo intento - \n");
        printf("\n Ingrese USER:");
        fflush(stdin);
        scanf("%10s",user);

        printf("\n Ingrese PASS:");
        fflush(stdin);
        scanf("%10s",pass);
    }while(strcmp(user,USER) !=0 || strcmp(pass,PASS)!=0);
    system("cls"); // esto lo busque por mi cuenta! Me gusto el efecto que da. Parece que estas entrando en otra interfaz cuando pones tu usuario, algo estetico digamos no soluciona nada en si.
}

//Funcion menu reportes de administrador o menu2: inicia un do while que contiene un switch con las opciones para ver estadisticas de administrador.
//Recibe por parametro el vector de comentarios comentarios[] y el contador de comentarios totales contadorComen.
//No devuelve nada ya que es de tipo void.
void menuReportes(struct comentario comentarios[], int contadorComen){
    int opcion2;
    float promedio;
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - \n- - - Bienvenido al panel de administrador - - - \n- - - - - - - - - - - - - - - - - - - - - - - - \n\n");

    do{
        printf("\t- MENU ADMINISTRADOR - \n\n\n Ingrese en numero del 1 al 5 la opcion deseada: \n\n \t 1- Promedio de calificaciones\n \t 2- Dia con mayor calificacion \n \t 3- Cantidad de compras con clasificacion del tipo de atencion B \n \t 4- Detalle por Nro. de compra \n \t 5- SALIR AL MENU PRINCIPAL \n");
        scanf("%d", &opcion2);

        switch (opcion2) {
            case 1:
                if(contadorComen !=0){
                    promedio = cuentaPromedio(comentarios, contadorComen);
                    printf("\n\nPromedio de calificaciones: %.2f \n\n\n\n--------------------------------------------\n\n", promedio);
                    }else{
                        printf("\n\nTodavia no hay ningun comentario \n\n");
                }
                break;
            case 2:
                if (contadorComen != 0) {
                    struct fecha diaMaxCali = diaMayorCal(comentarios, contadorComen);
                    printf("Dia con mayor calificacion: %d/%d/%d\n", diaMaxCali.dia, diaMaxCali.mes, diaMaxCali.anio);
                    }else{
                        printf("\n\nTodavia no hay ningun comentario \n\n");
                }
                break;
            case 3:
                if (contadorComen != 0) {
                    cantTipoB(comentarios, contadorComen);
                    }else{
                        printf("\n\nTodavia no hay ningun comentario\n\n");
                }
                break;
            case 4:
                  if(contadorComen !=0){
                    printf("Detalle por Nro. de compra \n");
                    verDetalle(comentarios, contadorComen);
                    }else{
                        printf("\n\nTodavia no hay ningun comentario \n\n");
                }
                break;
            case 5:
                printf(" - - - - - - Saliendo - - - - - -  \n");
                break;
            default:
                printf("Opcion incorrecta, ingrese un numero del 1 al 3 \n");
                break;
            }
        }while(opcion2 !=5);
}

//Funcion cuenta promedio: hace la cuenta para sacar el promedio de de las clasifiaciones que hicieron los usuarios.
//Recibe por parametro el vector de comentarios comentarios[] y el contador de comentarios totales contadorComen.
//Devuelve un float que es el resultado de la cuenta.
float cuentaPromedio(struct comentario comentarios[], int contadorComen){

        int sumaCalifi=0;
        int cantidadCalifi = contadorComen;

        for(int i=0; i<contadorComen; i++){
            sumaCalifi += comentarios[i].clasificacion;
        }

        float resultado = sumaCalifi / cantidadCalifi;

        return resultado;
}

//Funcion dia de mayor calificacion: bucle for que encuentra el dia que se realizo la mayor calificacion.
//Recibe por parametro el vector de comentarios comentarios[] y el contador de comentarios totales contadorComen.
//Devuelve un struct fecha con el dia que fue la mayor calificacion.
struct fecha diaMayorCal(struct comentario comentarios[], int contadorComen) {
    int maxCalificacion = 0;
    struct fecha diaMaxCali;

    diaMaxCali = comentarios[0].fechaEvento;

    for (int i = 0; i < contadorComen; i++) {
        if (comentarios[i].clasificacion > maxCalificacion) {
            maxCalificacion = comentarios[i].clasificacion;
            diaMaxCali = comentarios[i].fechaEvento;
        }
    }

    return diaMaxCali;
}

//Funcion cantidad de clasificacion tipo B: bucle for que cuenta las clasificiones por parte del usuario de tipo B.
//Recibe por parametro el vector de comentarios comentarios[] y el contador de comentarios totales contadorComen.
//No devuelve nada ya que es de tipo void.
void cantTipoB(struct comentario comentarios[], int contadorComen) {
    int contadorr=0;

    for (int i=0; i < contadorComen; i++) {
        if (comentarios[i].atencion == 'B') {
            contadorr++;
        }
    }
    printf("Cantidad de compras con clasificacion del tipo de atencion B: %d\n", contadorr);
}

//Funcion ver detalle de comentario: encuentra por medio del ID codigo evento el comentario  buscado y muestra todos sus detalles.
//Recibe por parametro el vector de comentarios comentarios[] y el contador de comentarios totales contadorComen.
//No devuelve nada ya que es de tipo void.
void verDetalle(struct comentario comentarios[], int contadorComen){
    int codIngresado;
    system("cls"); // Aca tambien quedaba bueno que para ingresar el codigo de evento se limpe la consola
    printf("\nPara ver detale de un comentario ingrese \nel CODIGO DE EVENTO de cuatro digitos:\n");
    scanf("%d", &codIngresado);

    for(int i=0; i<contadorComen; i++){
        if(codIngresado == comentarios[i].codigoEvento){
           printf("####### {{ %d }} ########", comentarios[i].codigoEvento); //Aca dividi en 3 print por que se me hacia mas facil seguir el formato
           printf("Nombre completo: {{%s}} Fecha: {{%d / %d / %d}}", comentarios[i].nombre, comentarios[i].fechaEvento.dia, comentarios[i].fechaEvento.mes, comentarios[i].fechaEvento.anio);
           printf("Atencion: {{%c}} Clasificacion: {{%d}}",comentarios[i].atencion, comentarios[i].clasificacion);
        }
    }
}
