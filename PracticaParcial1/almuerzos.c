#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "almuerzos.h"

void menuSEA(eMenu menu [],eEmpleado empleado[],eAlmuero almuerzo[],eSector sector[],int m,int c,int s,int a){
int opcion=0;

   while(opcion!=5){
        printf("\n============sistema para administrar Almuerzos y empleados================\n");
        printf("\n1)Empleados\n2)Almuerzos\n3)Sector\n4)Menu \n5)Salir");
        opcion=getInt("\n\nIntrodusca el Numero de la opcion :");
        system("cls");
    switch (opcion){
case 1:
    printf("menu Empleados");
    menuEm(menu,empleado,almuerzo,sector,m,c,s,a);
    break;
case 2:
    printf("menu Almuerzos");
    menuAl(menu,empleado,almuerzo,sector,m,c,s,a);
    break;
case 3:
    printf("\nOpcion No Disponible\n");
   break;
case 4:
 printf("\nOpcion No Disponible\n");
  break;
 default:
     if(opcion!=5){
printf("\nFUERA DE RANGO\n");
     }
break;
    }
}
}
void menuEm(eMenu menu [],eEmpleado empleado[],eAlmuero almuerzo[],eSector sector[],int m,int c,int s,int a){
int opcion=0;
    int marcador;
   while(opcion!=5){
        printf("\n============sistema para administrar su nomina de empleados================\n");
        printf("\n1)Alta\n2)BAJA\n3)Modificacion\n4)Lista \n5)Salir");
    opcion=getInt("\n\nIntrodusca el Numero de la opcion :");
    system("cls");
    switch (opcion){
case 1:
    altaEmpleados(empleado,sector,s,c);
    break;
case 2:

    marcador=ifAllEmpty(empleado,c);
    if(marcador==1){
    removeEmployee(empleado,c);
    }else{
    printf("\nNo Existe Registro\n");
    }break;

case 3:

   marcador=ifAllEmpty(empleado,c);
    if(marcador==1){
    modEmployees(empleado,c,sector,s);
    }else{
    printf("\nNo Existe Registro\n");
    }break;
case 4:
    marcador=ifAllEmpty(empleado,c);
    if(marcador==1){
    sortEmployees(empleado,c);
    printEmployees(empleado,c,sector,s);
    }else{
    printf("\nNo Existe Registro\n");
    }
break;
 default:
     if(opcion!=5){
printf("\nFUERA DE RANGO\n");
     }
break;
    }
}
}
void menuAl(eMenu menu [],eEmpleado empleado[],eAlmuero almuerzo[],eSector sector[],int m,int c,int s,int a){
int opcion=0;
    //int marcador;
   while(opcion!=4){
        printf("\n============sistema para administrar Almuerzos================\n");
        printf("\n1)Alta\n2)Informar\n3)Listar\n4)Salir");
    opcion=getInt("\n\nIntrodusca el Numero de la opcion :");
    system("cls");
    switch (opcion){
case 1:
altaAlmuerzos(empleado,sector,menu,almuerzo, s, c, m,a);
   // addEmployee(menu,empleado,sector,m,c,a);
    break;
case 2:
    listaSAlmu(empleado,menu,almuerzo,c,m,a);
  /*  marcador=ifAllEmpty(Employe,len);
    if(marcador==1){
    removeEmployee(Employe,len);
    }else{
    printf("\nNo Existe Registro\n");
    }*/break;
case 3:
    filtrarAlmu(empleado,menu,almuerzo, c,m,a);
  /*  marcador=ifAllEmpty(Employe,len);
    if(marcador==1){
    modEmployees(Employe,len);
    }else{
    printf("\nNo Existe Registro\n");
    }*/break;
 default:
     if(opcion!=4){
printf("\n\nFUERA DE RANGO\n\n");
     }
break;
    }
}
}

int initEmployees(eEmpleado empleado[], int len){
    int i;
        for(i=0;i<len;i++)
            {
            empleado[i].isEmpty=1;
            }
        return 0;
}
int altaEmpleados(eEmpleado empleado[],eSector sector[],int s,int len){
int i;
   for(i=0; i<len; i++)
    {

        if(empleado[i].isEmpty==1){

        empleado[i].legajo=generarId(empleado,len);
        miFgets(empleado[i].apellido,51,"Apellido :");
        miFgets(empleado[i].nombre,51,"Nombre :");
        empleado[i].salario=getFloat("Introdusca El Salario :");
        empleado[i].salario=valSalary(empleado[i].salario);//validacion <0
        empleado[i].sexo=getChar("introdusca el sexo como \'m\'o\'f\' :");
        empleado[i].sexo=valSexo(empleado[i].sexo);//val m o f
        empleado[i].fechaInge.anio=getInt("Introdusca el Anio de ingreso del empleado :");
        empleado[i].fechaInge.anio=valAnio(empleado[i].fechaInge.anio);//val rango de anios
        empleado[i].fechaInge.mes=getInt("Introdusca el Mes de ingreso del empleado :");
        empleado[i].fechaInge.mes=valMes(empleado[i].fechaInge.mes);//val rango de mes
        empleado[i].fechaInge.dia=getInt("Introdusca el Dia de ingreso del empleado :");
        empleado[i].fechaInge.dia=valDia(empleado[i].fechaInge.dia);
        imprimirSubmenu(sector,s);
        empleado[i].idSector=valSector(sector,s);
        empleado[i].isEmpty=0;
         system("cls");
            break;}
    }
 return 0;
}
int generarId(eEmpleado empleado[],int len){
    int marcador,i;

    marcador=0;
    for(i=0;i<len;i++){
        if((marcador<empleado[i].legajo) && (empleado[i].isEmpty==0)){
            marcador=empleado[i].legajo;
        }
        }
    return marcador+1;
}
void printEmployees(eEmpleado empleado[], int len,eSector sector[],int s){
    int i,j;

    printf("\n======================Listato=============================");
           printf("\n\tID\tApellido\tNombre\t\tsexo\tFecha de ingreso\tSalario\t\tSector\n");
    for(i=0;i<len;i++){
        if(empleado[i].isEmpty==0){


            printf("\n\t%d\t%s",empleado[i].legajo,empleado[i].apellido);
            printf("\t%s\t%c\t%d:%d:%d",empleado[i].nombre,empleado[i].sexo,empleado[i].fechaInge.dia,empleado[i].fechaInge.mes,empleado[i].fechaInge.anio);
            printf("\t\t%.2f\t",empleado[i].salario);
            for(j=0;j<s;j++){
               if(empleado[i].idSector==sector[j].idSector){
                printf("\t%s",sector[j].descripcion);
               }
            }

        }


    }
}
int ifAllEmpty(eEmpleado empleado[],int len){
int i;
int marcador=0;
        for(i=0;i<len;i++){
        if(empleado[i].isEmpty!=1){
            marcador=1;
        break;
        }
    }return marcador;
}
int sortEmployees(eEmpleado empleado[], int len){
             int i,j;
             eEmpleado aux;

             for(i=0;i<len-1;i++){
                for(j=i+1;j<len;j++){
                    if(strcmp(empleado[i].apellido,empleado[j].apellido)>0){
                            aux=empleado[i];
                            empleado[i]=empleado[j];
                            empleado[j]=aux;
                        }
                    if(strcmp(empleado[i].apellido,empleado[j].apellido)==0){
                            if(strcmp(empleado[i].nombre,empleado[j].nombre)>0){
                            aux=empleado[i];
                            empleado[i]=empleado[j];
                            empleado[j]=aux;
                            }
                        }

                }
             }

return 0;

}
 int valSector(eSector sector[],int s){
    int i,sec,flag=0;
    sec=getInt("\nDigite el sector del empleado :");
    while(flag==0 ){

    for(i=0;i<s;i++){
        if(sec==sector[i].idSector){
                flag=1;
            break;
            }
    }if(flag==0){
            sec=getInt("no existe el sector, introdusca un sector valido");
                }
    }return sec;
    }
void imprimirSubmenu(eSector sector[],int s){
    int i;
        for(i=0;i<s;i++){
                        printf("\n%d)%s",sector[i].idSector,sector[i].descripcion);
                        }
}
int  removeEmployee(eEmpleado empleado[],int len){
        int i,auxBaja,flag=0;
        char check;
        auxBaja=getInt("Introdusza el Id del empleado a dar de Baja :");
        for(i=0;i<len;i++){
            if(auxBaja==empleado[i].legajo){
                flag=1;
                printf("\nEl nombre y apellido del empleado a dar de baja : %s\t%s\n",empleado[i].nombre,empleado[i].apellido);
                   check=getChar("\nEsta seguro que desea eliminar el registro\nintrodusca \'s\' para continuar, \'n\'para abandonar :");
                    if(check=='s'||check=='S'){
                empleado[i].isEmpty=1;
                printf("\nbaja exitosa\n");
                break;}
            }

        }
        if(flag==0){
                printf("Legajo no encontrado");
            }
        return 0;
}
int modEmployees(eEmpleado empleado[],int c,eSector sector[],int s){
    int i,j,auxMod,opcioMod=0,flag=0;
    auxMod=getInt("introdusca el Id del empleado a modificar");

    for(i=0;i<c;i++){
        if(auxMod==empleado[i].legajo){
            flag=1;
            while(opcioMod!=7){
                    system("cls");
            printf("Datos del empleado a modificar");

            printf("\n\t%d\t%s\t%s\t%c\t%d:%d:%d\t%.2f\t",empleado[i].legajo,empleado[i].nombre,empleado[i].apellido,empleado[i].sexo,empleado[i].fechaInge.dia,empleado[i].fechaInge.mes,empleado[i].fechaInge.anio,empleado[i].salario);
             for(j=0;j<s;j++){
               if(empleado[i].idSector==sector[j].idSector){
                printf("\t%s",sector[j].descripcion);
               }}
            printf("\n1)Nombre\n2)Apellido\n3)Sexo\n4)Fecha de ingreso\n5)Salary\n6)Sector\n7)Salir de modificar");
              opcioMod=getInt("\nDigite el dato que Nesecita Modificar :");

                switch (opcioMod){
            case 1:
                        miFgets(empleado[i].nombre,51,"Nombre :");

                break;
            case 2:
                miFgets(empleado[i].apellido,51,"Apellido :");

                break;
            case 3:

                empleado[i].sexo=getChar("introdusca el sexo como \'m\'o\'f\' :");
                empleado[i].sexo=valSexo(empleado[i].sexo);//val m o f
            break;
            case 4:
        empleado[i].fechaInge.anio=getInt("Introdusca el Anio de ingreso del empleado :");
        empleado[i].fechaInge.anio=valAnio(empleado[i].fechaInge.anio);//val rango de anios
        empleado[i].fechaInge.mes=getInt("Introdusca el Mes de ingreso del empleado :");
        empleado[i].fechaInge.mes=valMes(empleado[i].fechaInge.mes);//val rango de mes
        empleado[i].fechaInge.dia=getInt("Introdusca el Dia de ingreso del empleado :");
        empleado[i].fechaInge.dia=valDia(empleado[i].fechaInge.dia);
            break;
            case 5:
                        empleado[i].salario=getFloat("Introdusca El Salario :");
        empleado[i].salario=valSalary(empleado[i].salario);//validacion <0
                break;
            case 6:
                imprimirSubmenu(sector,s);
        empleado[i].idSector=valSector(sector,s);
        empleado[i].isEmpty=0;
                break;
            default:
                if(opcioMod!=7){
                printf("FUERA DE RANGO");
                }
                break;
                }
            }
            }
}
    if(flag==0){
        printf("\nno encontro el ID solicitado\n");
    }
    return 0;
}

int altaAlmuerzos(eEmpleado empleado[],eSector sector[],eMenu menu[],eAlmuero almuerzo[],int s,int c,int m,int a){
int i;
   for(i=0; i<a; i++)
    {

        if(almuerzo[i].isEmpty==1){

        almuerzo[i].idAlmuerzo=generarIdAl(almuerzo,a);

        almuerzo[i].fechaAlmuerzo.anio=getInt("Introdusca el Anio del almuerzo :");
        almuerzo[i].fechaAlmuerzo.anio=valAnio(almuerzo[i].fechaAlmuerzo.anio);//val rango de anios
        almuerzo[i].fechaAlmuerzo.mes=getInt("Introdusca el Mes del almuerzo :");
        almuerzo[i].fechaAlmuerzo.mes=valMes(almuerzo[i].fechaAlmuerzo.mes);//val rango de mes
        almuerzo[i].fechaAlmuerzo.dia=getInt("Introdusca el Dia del almuerzo :");
        almuerzo[i].fechaAlmuerzo.dia=valDia(almuerzo[i].fechaAlmuerzo.dia);
        almuerzo[i].legajoEmple=valEmpleado(empleado,c);
        almuerzo[i].idMenu=valMenu(menu,m);
        almuerzo[i].isEmpty=0;
         system("cls");
            break;}
    }
 return 0;
}
int valEmpleado(eEmpleado empleado[],int c){
    int i,sec,flag=0;
    sec=getInt("\nDigite el legajo del empleado :");
    while(flag==0 ){

    for(i=0;i<c;i++){
        if(sec==empleado[i].legajo){

                flag=1;
            break;
            }
    }if(flag==0){
            sec=getInt("no existe el Legajo, introdusca un legajo valido");
                }
    }return sec;
    }
int valMenu(eMenu menu[],int m){
    int i,sec,flag=0;
    for(i=0;i<m;i++){
        printf("\n%d)%s :%.2f",menu[i].idMenu,menu[i].descripMenu,menu[i].importe);
    }
    sec=getInt("\nDigite el Id del menu :");
    while(flag==0 ){

    for(i=0;i<m;i++){
        if(sec==menu[i].idMenu){

                flag=1;
            break;
            }
    }if(flag==0){
            sec=getInt("no existe el Menu, introdusca un menu valido");
                }
    }return sec;
    }
int initAlmu(eAlmuero almuerzo[], int a){
    int i;
        for(i=0;i<a;i++)
            {
            almuerzo[i].isEmpty=1;
            }
        return 0;
}
int generarIdAl(eAlmuero almuerzo[],int a){
    int marcador,i;

    marcador=0;
    for(i=0;i<a;i++){
        if((marcador<almuerzo[i].idAlmuerzo) && (almuerzo[i].isEmpty==0)){
            marcador=almuerzo[i].idAlmuerzo;
        }
        }
    return marcador+1;
}

void listaSAlmu(eEmpleado empleado[],eMenu menu[],eAlmuero almuerzo[],int c,int m,int a){

int i,j,k;
for (i=0;i<a;i++){
        if(almuerzo[i].isEmpty==0){
    printf("\n%d\t%d:%d:%d",almuerzo[i].idAlmuerzo,almuerzo[i].fechaAlmuerzo.dia,almuerzo[i].fechaAlmuerzo.mes,almuerzo[i].fechaAlmuerzo.anio);
    for(j=0;j<c;j++){
    if(almuerzo[i].legajoEmple==empleado[j].legajo){
    printf("\t%s\t%s",empleado[j].apellido,empleado[j].nombre);
     for(k=0;k<m;k++){
        if(almuerzo[i].idMenu==menu[k].idMenu){
            printf("\t%s",menu[k].descripMenu);
            }
    }break;}
}}}
float promeImpor=0,totalImporte=0;
int contador=0,contSoPro=0,contBaPro=0;
  for(i=0;i<a;i++){
        contador++;
    for(j=0;j<m;j++){
        if(almuerzo[i].idMenu==menu[j].idMenu)
            totalImporte+=menu[j].importe;
    }
  }printf("\n\tTotal importes :%.2f",totalImporte);
  printf("\n\tTotal de almuerzos vendidos :%d",contador);
    promeImpor=(float)totalImporte/contador;
    printf("\n\tPromedio de importes por almuerzos vendidos :%.2f",promeImpor);
   for(i=0;i<a;i++){
        for(j=0;j<m;j++){
    if(almuerzo[i].idMenu==menu[j].idMenu){
            if(menu[j].importe>promeImpor){
                contSoPro++;
            }
        if(menu[j].importe<promeImpor){
                contBaPro++;
            }
    }}
   }
    printf("\n\tTotal de almuerzos vendidos por debajo del promedio de importe :%d",contBaPro);
     printf(      "\n\tTotal de almuerzos vendidos por debajo del promedio de importe :%d",contSoPro);
}

void filtrarAlmu(eEmpleado empleado[],eMenu menu[],eAlmuero almuerzo[],int c,int m,int a){

int i,j,k,menuS,empleId,op=0,flag=0,anio,mes,dia;
while(op!=7){
    printf("\n================Filtrado por entrada de datos===================\n");
    printf("\n1)almuerzos<=125\n2)almuersos>=125\n3)nombres por menu\n4)menus por legajo\n5)Filtrados por fecha\n6)filtrado por un menu y una fecha\n7)Salir");
    op=getInt("\nDigite La opcion :");
    system("cls");
    switch (op){
case 1:
    printf("\n\tmenu de precio igual o inferior a 125");
    for(i=0;i<m;i++){
        if(menu[i].importe<=125){
            printf("\n\t\t\t%s",menu[i].descripMenu);
        }
    }
    break;
case 2:
    printf("\n\tmenu de precio igual o mayor a 125");
    for(i=0;i<m;i++){
        if(menu[i].importe>=125){
            printf("\n\t\t\t%s",menu[i].descripMenu);
        }
    }
    break;
case 3:

        menuS=valMenu(menu,m);
        flag=0;
    printf("\n\tLos empleados que consumieron el menu Digitado ");
    for(i=0;i<m;i++){
        if(almuerzo[i].idMenu==menuS){
            for(j=0;j<c;j++){
                if(almuerzo[i].legajoEmple==empleado[j].legajo){
            flag=1;
            printf("\n\t\t\t%s\t%s",empleado[j].nombre,empleado[j].apellido);

        }}}
        }if(flag==0){
        printf("\n \'0\' (CERO)empleado a consumido este menu");
    }

    break;
case 4:
    empleId=valEmpleado(empleado,c);

        flag=0;
        for(i=0;i<m;i++){
            if(empleado[i].legajo==empleId){
                    printf("empleado %s\t%s consumio",empleado[i].nombre,empleado[i].apellido);
                for(j=0;j<a;j++){
                if(almuerzo[j].legajoEmple==empleado[i].legajo){
                    for(k=0;k<m;k++){
                    if(almuerzo[j].idMenu==menu[k].idMenu){
                    flag=1;
                    printf("\n\t%s  %d:%d:%d",menu[k].descripMenu,almuerzo[j].fechaAlmuerzo.dia,almuerzo[j].fechaAlmuerzo.mes,almuerzo[j].fechaAlmuerzo.anio);}

        }}}}}
        if(flag==0){
        printf("\n No a consumido almuerzo");
    }

    break;
case 5:
    anio=getInt("Introdusca el Anio de Consumo del almuerzo :");
        anio=valAnio(anio);//val rango de anios
        mes=getInt("Introdusca el Mes Consumo del almuerzo :");
        mes=valMes(mes);//val rango de mes
        dia=getInt("Introdusca el Dia Consumo del almuerzo :");
        dia=valDia(dia);
        flag=0;
        printf("\nen la fecha %d:%d:%d fueron consumidos los menues",dia,mes,anio);
        for(i=0;i<a;i++){
            if(dia==almuerzo[i].fechaAlmuerzo.dia && mes==almuerzo[i].fechaAlmuerzo.mes && anio==almuerzo[i].fechaAlmuerzo.anio){
               flag=1;

                for(j=0;j<m;j++){
                    if(almuerzo[i].idMenu==menu[j].idMenu){
                        printf("\n%s",menu[j].descripMenu);
                    }
                }
            }
        }if (flag==0){
            printf("\nningun menu\n");}

    break;
case 6:

    anio=getInt("Introdusca el Anio de Consumo del almuerzo :");
        anio=valAnio(anio);//val rango de anios
        mes=getInt("Introdusca el Mes Consumo del almuerzo :");
        mes=valMes(mes);//val rango de mes
        dia=getInt("Introdusca el Dia Consumo del almuerzo :");
        dia=valDia(dia);
        menuS=valMenu(menu,m);
        flag=0;
        printf("\nen la fecha %d:%d:%d fueron consumidos los menues",dia,mes,anio);
        for(i=0;i<a;i++){
            if(dia==almuerzo[i].fechaAlmuerzo.dia && mes==almuerzo[i].fechaAlmuerzo.mes && anio==almuerzo[i].fechaAlmuerzo.anio&&almuerzo[i].idMenu==menuS){
               flag=1;

                for(j=0;j<m;j++){
                    if(empleado[j].legajo==almuerzo[i].legajoEmple){
                        printf("\n%s\t%s",empleado[j].nombre,empleado[j].apellido);

                    }
                }
            }
        }if (flag==0){
            printf("\nningun menu\n");}


    break;
default:
    if(op!=7){
        printf("\nfuera de rango\n");
    }
    break;


    }
}


}
