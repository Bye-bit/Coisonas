#include <stdio.h>


double potencia_recursiva(int x, int n);



int main()
{
    int x = 2;
    for(int n = -10; n <= 10; n++)
    {
        printf("o resultado de %d^%d = %.2f\n",x,n,potencia_recursiva(x,n));
    }
}

double potencia_recursiva(int x, int n) {
    if(n == 0)
    {
        return 1;
    }
    if(n < 0)
    {
        return potencia_recursiva(1.0/x,-n);
    }
    return x * potencia_recursiva(x,n-1);
}