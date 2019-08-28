#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor,i,res;
    res=1;

    printf("ingrese numero:");
    scanf("%d",&valor);

    i=valor;
    while(i>0){
        res=res*i;
        i--;

    }
    printf("el factorial de numero %d es %d",valor,res);
    return 0;
}
