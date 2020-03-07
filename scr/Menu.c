#include "libs/Menu.h"
void displayMenu(){
    printf("\n ||Bienvenido a la calculadora matricial||");
    printf("\n Coded by Leiva");
    printf("\n 1º- Introduccir una matriz");
    printf("\n 2º- Lista de matrices guardadas");
    printf("\n 3º- Eliminar una matriz guardada");
    printf("\n 4º- Sumar dos matrices");
    printf("\n 5º- Restar dos matrices");
    printf("\n 6º- Multiplicar dos matrices");
    printf("\n 7º- Obtener la reducida de gauss de una matriz");
    printf("\n 0º- CERRAR PROGRAMA");
    printf("\n Eliga una opción:");

}    
int selectMenu(){
    int res;
    displayMenu();
    scanf("%d", &res);
    return res;
}