#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int getInt(char mensaje[]){
int aux;
printf("%s",mensaje);
scanf("%d",&aux);
return aux;
}
float getFloat(char mensaje[]){
float aux;
printf("%s",mensaje);
scanf("%f",&aux);
return aux;
}
char getChar(char mensaje[]){
char letra;
printf("%s",mensaje);
fflush(stdin);
scanf("%c",&letra);
return letra;
}
