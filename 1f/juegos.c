#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juegos.h"


int initClientes(eClientes cliente[], int c){
    int i;
        for(i=0;i<c;i++)
            {
            cliente[i].isEmpty=1;
            }
        return 0;
}
int initAlquiler(eAlquileres alquiler[], int a){
    int i;
        for(i=0;i<a;i++)
            {
            alquiler[i].isEmpty=1;
            }
        return 0;
}
void menuCJA(eClientes clientes[],eJuegos juego[],eAlquileres alquiler[],int c,int ju,int a){
int opcion=0;

   while(opcion!=5){
        printf("\n============sistema para administrar CLIENTES JUEGOS Y ALQUILERES================\n");
        printf("\n1)Clientes\n2)Juejos\n3)Alquileres\n4)Informar\n5)Salir");
        opcion=getInt("\n\nIntrodusca el Numero de la opcion :");
        system("cls");
    switch (opcion){
case 1:
    printf("\nClientes");
    menuCli(clientes,juego,alquiler,c,ju,a);
    break;
case 2:
    sortJUEGOS(juego,ju);
    printJuegos(juego,ju);

    break;
case 3:
    printf("\nAlquileres");
    altaAlquileres(juego,clientes,alquiler,ju,c,a);

   break;
   case 4:
    printf("\n================LISTADO DE ALQUILERES===========");
    printAlquileres(juego,clientes,alquiler,ju,c,a);

   break;

 default:
     if(opcion!=5){
printf("\nFUERA DE RANGO\n");
     }
break;
    }
}
}
void menuCli(eClientes cliente[],eJuegos juego[],eAlquileres alquiler[],int c,int ju,int a){
int opcion=0;
    int marcador;
   while(opcion!=5){
        printf("\n============Sistema para administrar sus CLIENTES================\n");
        printf("\n1)Alta\n2)Modificacion \n3)BAJA\n4)Lista \n5)Salir");
    opcion=getInt("\n\nIntrodusca el Numero de la opcion :");
    system("cls");
    switch (opcion){
case 1:
    altaClientes(cliente,c);
    break;
case 2:

    marcador=ifAllEmpty(cliente,c);
    if(marcador==1){
    modClientes(cliente,c);
    }else{
    printf("\nNo Existe Registro\n");
    }
    break;

case 3:
marcador=ifAllEmpty(cliente,c);
    if(marcador==1){
        removeCliente(cliente,c);
    }else{
    printf("\nNo Existe Registro\n");
    }
    break;
case 4:
    marcador=ifAllEmpty(cliente,c);
    if(marcador==1){
    sortClientes(cliente,c);
    printClientes(cliente,c);
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
int altaClientes(eClientes cliente[],int c){
    int i;
   for(i=0; i<c; i++)
    {

        if(cliente[i].isEmpty==1){

        cliente[i].codigoCliente=generarId(cliente,c);
        miFgets(cliente[i].apellido,31,"Apellido :");
        miFgets(cliente[i].nombre,31,"Nombre :");
        cliente[i].sexo=getChar("introdusca el sexo como \'m\'o\'f\' :");
        cliente[i].sexo=valSexo(cliente[i].sexo);//val m o f
        miFgets(cliente[i].domiciolio,51,"Domicilio :");
        miFgets(cliente[i].telefono,21,"Telefono :");
        cliente[i].isEmpty=0;
         system("cls");
            break;}
    }

return 0;
}

int generarId(eClientes cliente[],int c){
    int marcador,i;

    marcador=0;
    for(i=0;i<c;i++){
        if((marcador<cliente[i].codigoCliente) && (cliente[i].isEmpty==0)){
            marcador=cliente[i].codigoCliente;
        }
        }
    return marcador+1;
}
int ifAllEmpty(eClientes cliente[],int c){
int i;
int marcador=0;
        for(i=0;i<c;i++){
        if(cliente[i].isEmpty!=1){
            marcador=1;
        break;
        }
    }return marcador;
}
void printClientes(eClientes cliente[], int c){
    int i;

    printf("\n======================Listato=============================");
           printf("\n\tID\tApellido\tNombre\tsexo\tTelefono\tDomicilio\n");
    for(i=0;i<c;i++){
        if(cliente[i].isEmpty==0){


            printf("\n\t%d\t%s",cliente[i].codigoCliente,cliente[i].apellido);
            printf("\t%s\t%c",cliente[i].nombre,cliente[i].sexo);
            printf("\t\t%s\t%s",cliente[i].telefono,cliente[i].domiciolio);

            }

        }


    }
int sortClientes(eClientes cliente[], int c){
             int i,j;
             eClientes aux;

             for(i=0;i<c-1;i++){
                for(j=i+1;j<c;j++){
                    if(strcmp(cliente[i].apellido,cliente[j].apellido)>0){
                            aux=cliente[i];
                            cliente[i]=cliente[j];
                            cliente[j]=aux;
                        }
                    if(strcmp(cliente[i].apellido,cliente[j].apellido)==0){
                            if(strcmp(cliente[i].nombre,cliente[j].nombre)>0){
                            aux=cliente[i];
                            cliente[i]=cliente[j];
                            cliente[j]=aux;
                            }
                        }

                }
             }

return 0;

}
int  removeCliente(eClientes cliente[],int c){
        int i,auxBaja,flag=0;
        char check;
        auxBaja=getInt("Introdusza el codigo del Cliente a dar de Baja :");
        for(i=0;i<c;i++){
            if(auxBaja==cliente[i].codigoCliente){
                flag=1;
                printf("\nEl nombre y apellido del CLIENTE a dar de baja : %s\t%s\n",cliente[i].nombre,cliente[i].apellido);
                   check=getChar("\nEsta seguro que desea eliminar el registro\nintrodusca \'s\' para continuar, \'n\'para abandonar :");
                    if(check=='s'||check=='S'){
                cliente[i].isEmpty=1;
                printf("\nbaja exitosa\n");
                break;}
            }

        }
        if(flag==0){
                printf("codigo no encontrado");
            }
        return 0;
}
int modClientes(eClientes cliente[],int c){
    int i,auxMod,opcioMod=0,flag=0;
    auxMod=getInt("introdusca el Codigo de cliente a modificar");

    for(i=0;i<c;i++){
        if(auxMod==cliente[i].codigoCliente){
            flag=1;
            while(opcioMod!=6){
                    system("cls");
            printf("Datos del cliente a modificar");

            printf("\n\t%d\t%s\t%s\t%c\t%s\t%s",cliente[i].codigoCliente,cliente[i].nombre,cliente[i].apellido,cliente[i].sexo,cliente[i].telefono,cliente[i].domiciolio);

            printf("\n1)Nombre\n2)Apellido\n3)Sexo\n4)Telefono\n5)Domicilio\n6)Salir de modificar");
              opcioMod=getInt("\nDigite el dato que Nesecita Modificar :");

                switch (opcioMod){
            case 1:
               miFgets(cliente[i].nombre,31,"Nombre :");
                break;
            case 2:
                 miFgets(cliente[i].apellido,31,"Apellido :");
                break;
            case 3:
            cliente[i].sexo=getChar("introdusca el sexo como \'m\'o\'f\' :");
                cliente[i].sexo=valSexo(cliente[i].sexo);//val m o f
             break;
            case 4:
                miFgets(cliente[i].telefono,21,"Telefono :");
            break;
            case 5:
                miFgets(cliente[i].domiciolio,51,"Domicilio :");
                break;
                default:
                if(opcioMod!=6){
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
void printJuegos(eJuegos juego[], int jue){
    int i;

    printf("\n======================Listato JUEGOS========================");
           printf("\n\tCodigo de juego \tDescripcion\t Importe\n");
    for(i=0;i<jue;i++){
    printf("\n\t%d\t%s\t%.2f",juego[i].codigoJuego,juego[i].descripcion,juego[i].importe);
           }
}
int sortJUEGOS(eJuegos juego[], int ju){
             int i,j;
             eJuegos aux;

             for(i=0;i<ju-1;i++){
                for(j=i+1;j<ju;j++){
                    if(strcmp(juego[i].descripcion,juego[j].descripcion)>0){
                            aux=juego[i];
                            juego[i]=juego[j];
                            juego[j]=aux;
                        }
                   }
             }

return 0;

}
int altaAlquileres(eJuegos juego[],eClientes cliente[],eAlquileres alquiler[],int ju,int c,int a){
int i;
   for(i=0; i<a; i++)
    {

        if(alquiler[i].isEmpty==1){

        alquiler[i].codigoAlquiler=generarIdAl(alquiler,a);

        alquiler[i].fechaAlquiler.anio=getInt("Introdusca el Anio del alquiler :");
        alquiler[i].fechaAlquiler.anio=valAnio(alquiler[i].fechaAlquiler.anio);//val rango de anios
        alquiler[i].fechaAlquiler.mes=getInt("Introdusca el Mes del alquiler :");
        alquiler[i].fechaAlquiler.mes=valMes(alquiler[i].fechaAlquiler.mes);//val rango de mes
        alquiler[i].fechaAlquiler.dia=getInt("Introdusca el Dia del alquiler :");
        alquiler[i].fechaAlquiler.dia=valDia(alquiler[i].fechaAlquiler.dia);

        alquiler[i].codigoCliente=valCliente(cliente,c);
        alquiler[i].codigoJuego=valJuego(juego,ju);
        alquiler[i].isEmpty=0;
         system("cls");
            break;}
    }
 return 0;
}
int generarIdAl(eAlquileres alquiler[],int a){
    int marcador,i;

    marcador=0;
    for(i=0;i<a;i++){
        if((marcador<alquiler[i].codigoAlquiler) && (alquiler[i].isEmpty==0)){
            marcador=alquiler[i].codigoAlquiler;
        }
        }
    return marcador+1;
}

int valCliente(eClientes cliente[],int c){
    int i,sec,flag=0;
    sec=getInt("\nDigite el codigo del Cliente :");
    while(flag==0 ){

    for(i=0;i<c;i++){
        if(sec==cliente[i].codigoCliente){

                flag=1;
            break;
            }
    }if(flag==0){
            sec=getInt("no existe el Codigo , introdusca un Codigo valido");
                }
    }return sec;
    }
int valJuego(eJuegos juego[],int ju){
    int i,sec,flag=0;
    for(i=0;i<ju;i++){
            printf("\n\t%d\t%s",juego[i].codigoJuego,juego[i].descripcion);
    }
    sec=getInt("\nDigite el Id del Juego :");
    while(flag==0 ){

    for(i=0;i<ju;i++){
        if(sec==juego[i].codigoJuego){

                flag=1;
            break;
            }
    }if(flag==0){
            sec=getInt("\nno existe el codigo , introdusca un Codigo valido valido");
                }
    }return sec;
    }
void printAlquileres(eJuegos juego[],eClientes clientes[],eAlquileres alquiler[],int ju,int c,int a){

int i,j,k;
printf("\nCodigo alquiler\tFecha\tCodigo de juego\tCodigo de cliente\tCliente\tCodigo juego\tDescripcion");
for (i=0;i<a;i++){
        if(alquiler[i].isEmpty==0){
    printf("\n%d\t%d:%d:%d",alquiler[i].codigoAlquiler,alquiler[i].fechaAlquiler.dia,alquiler[i].fechaAlquiler.mes,alquiler[i].fechaAlquiler.anio);
   // printf("\t%d\t%d",alquiler[i].codigoJuego,alquiler[i].codigoCliente);
    for(j=0;j<c;j++){
    if(alquiler[i].codigoCliente==clientes[j].codigoCliente){
            printf("\t%d",alquiler[i].codigoCliente);
    printf("\t%s\t%s",clientes[j].apellido,clientes[j].nombre);
     for(k=0;k<ju;k++){
        if(alquiler[i].codigoJuego==juego[k].codigoJuego){
            printf("\t%d",alquiler[i].codigoJuego);
            printf("\t%s",juego[k].descripcion);

            }
    }break;}
}}}

}
