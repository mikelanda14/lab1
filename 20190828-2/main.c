#include <stdio.h>
#include <stdlib.h>

int factorial(int);
int main()
{
    int valor,result;
    printf("ingrese numero: ");
    scanf("%d",&valor);
    result=factorial(valor);
    printf("El factorial de %d es %d",valor,result);
    return 0;
}
int factorial(int n){
int resp;
if(n==1){
return 1;
}
resp=n*factorial(n-1);
return resp;
}
