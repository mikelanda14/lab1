#include <stdio.h>
#include <stdlib.h>
#include "juegos.h"
#define JUEGOS 5
#define CLIENTES 10
#define ALQUILER 5

int main()
{

    eJuegos juego[JUEGOS]={{101,"Tron",99.95},
                           {102,"GTA",65.50},
                           {103,"Zorro",45.50},
                           {104,"Monkey2",44.50},
                           {105,"Ender",78.99}};
    eClientes cliente[CLIENTES]={{1, "landa" , "mike" , 'M' , "la plata 3543" , "1111-2222" ,0 },
                                    {2 , "skywaker" , "luke" , 'M' , "Tatoine 123" , "5555-4444" , 0 },
                                    {3 , "Flint" , "richard" , 'M' , "Solaris 1984" , "3333-4444" , 0 },
                                    {4 , "Princes" , "Leia" , 'F' , "dagoba 1981" , "8888-4444" , 0 },
                                    {5 , "Vega" ,"Diego" , 'M' , "Mexico 442" , "1111-1111" , 0 },
                                    {6 , "Curie" , "Marie" , 'F' , "Francia 1112" , "1223-2343" , 0 },
                                    {7 , "Marvel" , "Cata" , 'F' , "MilkyWAY" , "2332-4456" , 0 },
                                    {8 , "Diana" , "Clakent" , 'F' , "Grecia" , "7565-7754" , 0 },
                                    {9 , "Zorro" , "Bandi" , 'F' , "ferra 122", "9909-9988" , 0 },
                                    {10 , "Tobie" , "LALA" , 'M' , "trecemedi 123" , "7774-8843" , 0 }};


    eAlquileres alquiler[ALQUILER];
    //initClientes(cliente,CLIENTES);
    initAlquiler( alquiler, ALQUILER);
    menuCJA(cliente,juego,alquiler,CLIENTES,JUEGOS,ALQUILER);
    return 0;
}
