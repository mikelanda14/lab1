#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char getChar(char mensaje[]){
    char valor;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&valor);

return valor;
}
int getInt(char mensaje[]){
int valor;

printf("%s",mensaje);
fflush(stdin);
scanf("%d",&valor);

return valor;
}
float getFloat(char mensaje[]){
float valor;

printf("%s",mensaje);
fflush(stdin);
scanf("%f",&valor);

return valor;
}
void miFgets(char nombre[], int cantidad,char mensaje[]){
    printf("%s",mensaje);
    fflush(stdin);
    fgets(nombre, cantidad-2, stdin);
nombre=strtok(nombre,"\n");
    nombre[cantidad-1] = '\0';
}
int valAnio(int anio){
    while(anio<1930 || anio>2050 ){
        anio=getInt("el anio esta fuera de rango  ");
    }return anio;
    }
int valMes(int mes){
    while(mes<1 || mes>12 ){
        mes=getInt("el Mes esta fuera de rango  ");
    }return mes;
    }
int valDia(int dia){
    while(dia<1 || dia>30 ){
        dia=getInt("el Dia esta fuera de rango  ");
    }return dia;
    }
float valSalary(float sala){
    while(sala<1){
        sala=getFloat("Salario deve ser mayor que 0\'cero\' :");
    }return sala;
    }
char valSexo(char sexo){
    while(sexo!='f'&& sexo!='F'&& sexo!='m'&& sexo!='M'){
        sexo=getChar("solo \'f\'o\'m\'");
    }sexo=toupper(sexo);
    return sexo;
    }

