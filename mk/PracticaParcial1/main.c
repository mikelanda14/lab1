#include <stdio.h>
#include <stdlib.h>
#include "almuerzos.h"
#define MENU 5
#define CANTEMPLE 5
#define SECTOR 5
#define ALMU 15
int main()
{

    eMenu menu[MENU]={{1,"pizza",125},
                      {2,"sushi",145},
                      {3,"pasta",125},
                      {4,"merienda",125},
                      {5,"choclo",125}};

    eEmpleado empleado[CANTEMPLE]={{1,"landa","mike", "M" , 120000,2019,10,1,2,0},
                                   {2,"leal","antoni", "F" , 35000,2018,3,1,3,0},
                                   {3,"fox","jaimes", "M" , 50000,2017,6,2,4,0},
                                   {4,"eintina","albert","F" , 54000,1999,2,3,0},
                                   {5,"Curie","Marie", "F" , 200000,1978,4,2,1,0}};
    eAlmuero almuerzo[ALMU]={{1,1,4,5,5,2001,0},
                            {2,2,4,5,5,2001,0},
                            {3,2,5,11,6,2003,0},
                            {4,3,5,2,2,2015,0},
                            {5,4,1,2,3,2005,0},
                            {6,1,2,5,5,2001,0},
                            {7,2,4,5,5,2007,0},
                            {8,2,5,11,6,2008,0},
                            {9,3,5,2,2,2016,0},
                            {10,5,1,2,3,2004,0},
                            {11,1,2,5,5,2001,0},
                            {12,2,4,5,5,2001,0},
                            {13,2,5,11,6,2003,0},
                            {14,3,5,2,2,2015,0},
                            {15,5,1,2,3,2005,0}};
    eSector sector[SECTOR]={{1,"investigacion"},
                            {2,"desarrollo"},
                            {3,"mercadeo"},
                            {4,"RRHH"},
                            {5,"Soporte Tech"}};
    //initEmployees(empleado,CANTEMPLE);
   // initAlmu(almuerzo,ALMU);
    menuSEA(menu,empleado,almuerzo,sector,MENU,CANTEMPLE,SECTOR,ALMU);
    return 0;
}
