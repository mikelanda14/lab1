#include <stdio.h>
#include <stdlib.h>

void muestra(int *x, int y);

void main(void){
    int x, y;

    printf("Ingrese un numero entero");
    scanf("%d", &x);

    printf("Ingrese un numero entero");
    scanf("%d", &y);

    muestra(&x, y);

    printf("\n-----valores dentro de main----");
    printf("\nx vale %d \ny vale %d", x, y);
     printf("\n-----valores de la memoria en  main----");
    printf("\nx vale %d \ny vale %d", &x, &y);
}

void muestra(int *x, int y){
    *x = y;

    printf("\n-----valores dentro de la funcion----");
    printf("\nx vale %d \ny vale %d", *x, y);

    printf("\n-----valores de la dirrecion de memoria para las variables en function----");
    printf("\nx vale %d \ny vale %d", &*x, &y);
}



/*
#include <stdio.h>
#include <stdlib.h>

void muestra(int x,int y);

void main(void){
    int x, y;

    printf("Ingrese un numero entero");
    scanf("%d", &x);

    printf("Ingrese un numero entero");
    scanf("%d", &y);

    muestra(x, y);

    printf("\n-----valores dentro de main----");
    printf("\nx vale %d \ny vale %d", x, y);
}

void muestra(int x, int y){
    x = y;

    printf("\n-----valores dentro de la funcion----");
    printf("\nx vale %d \ny vale %d", x, y);
}
*/
